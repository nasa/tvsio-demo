#include "thrusters.hh"
#include <cmath>
#include <cstring>
#include <cstdio>

Thrusters::Thrusters() {

    for(int i=0;i<4;i++){
        thruster_cmd[i] = 0.0f;
        valve_state[i] = 0;
    }

    enable_firing = false;
    fire_mode = DISCRETE;

    config.max_force = 1.0;
    config.id = 101;

    for(int i=0;i<3;i++)
        angular_momentum[i] = 0.0;

    propellant_mass = 5.0;  // start with 5 kg
    strcpy(info_msg, "IDLE");

    t = 0.0;
}

void Thrusters::init() {
    // Nothing special for initialization
}

void Thrusters::update() {

    t += 0.1;

    // ------------------------------
    // Detect activation state change
    // ------------------------------
    static bool prev_enabled = false;

    if (enable_firing && !prev_enabled) {
        std::printf("[SIM_THRUSTERS] Thrusters ACTIVATED\n");
    } else if (!enable_firing && prev_enabled) {
        std::printf("[SIM_THRUSTERS] Thrusters DEACTIVATED\n");
    }

    prev_enabled = enable_firing;

    // ------------------------------
    // If firing disabled, clear valves and set status
    // ------------------------------
    if (!enable_firing) {
        for (int i = 0; i < 4; i++) {
            valve_state[i] = 0;
        }
        strcpy(info_msg, "DISABLED");

        // Still do periodic “alive” print below.
    } 
    else 
    {
        // --------------------------------------------
        // Determine valve states from thruster commands
        // --------------------------------------------
        for (int i = 0; i < 4; i++) {
            valve_state[i] = (thruster_cmd[i] > 0.05f) ? 1 : 0;
        }

        // --------------------------------------------
        // Apply simple "force → angular momentum"
        // --------------------------------------------
        double total_thrust = 0.0;
        for (int i = 0; i < 4; i++) {
            double applied_force = config.max_force * thruster_cmd[i];
            total_thrust += applied_force;
            angular_momentum[i % 3] += applied_force * 0.01;
        }

        // --------------------------------------------
        // Propellant usage
        // --------------------------------------------
        propellant_mass -= total_thrust * 0.0005;
        if (propellant_mass < 0.0) {
            propellant_mass = 0.0;
        }

        // --------------------------------------------
        // Fire mode affects message
        // --------------------------------------------
        if (fire_mode == DISCRETE) {
            strcpy(info_msg, "DISCRETE_FIRE");
        } else {
            strcpy(info_msg, "PULSED_FIRE");
        }
    }

    // --------------------------------------------
    // Periodic status print (every ~100 updates)
    // --------------------------------------------
    static int print_counter = 0;
    print_counter++;

    if (print_counter >= 100) {
        fprintf(stdout,
            "[SIM_THRUSTERS] t=%.1f  ThrCmd=[%.2f %.2f %.2f %.2f]  Enable=%d  PropMass=%.3f\n",
            t,
            thruster_cmd[0], thruster_cmd[1], thruster_cmd[2], thruster_cmd[3],
            enable_firing,
            propellant_mass
        );
        print_counter = 0;
    }
}