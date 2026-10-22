/********************************* TRICK HEADER *******************************                                                                                                 
PURPOSE:
    (Thruster sim for tvsio end-to-end demonstration)
REFERENCES:
    (
	(TVSIO - https://github.com/nasa/tvsio
    (Trick Simulation Environment) (NASA:JSC #37943)
	(cFS - https://etd.gsfc.nasa.gov/capabilities/core-flight-system/)
	)
PROGRAMMERS:
    ((James Pettit) (METECS) (Nov 2026) (Demo Rewrite))
*******************************************************************************/
#ifndef THRUSTERS_HH
#define THRUSTERS_HH

#include <cstring>

enum FireMode { DISCRETE = 0, PULSED = 1 };

struct ThrusterConfig {
    double max_force;
    int id;
};

class Thrusters {

public:

    /* Inputs from cFS */
    float thruster_cmd[4];     // (--) command magnitudes 0..1
    bool  enable_firing;
    FireMode  fire_mode;
    ThrusterConfig config;     // (--) single config struct

    /* Outputs back to cFS */
    double angular_momentum[3];
    float  propellant_mass;
    int    valve_state[4];     // (--) bool (0/1)
    char   info_msg[32];

    /* Internal state */
    double t;   // simulation time counter

    Thrusters();
    void init();
    void update();
};

#endif