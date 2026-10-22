#include "sensors.hh"
#include <cstring>
#include <cstdio>

Sensors::Sensors() {
    // zero everything
    for(int i=0;i<3;i++){ gyro_rate[i]=0; accel[i]=0; }
    health_counter = 0;
    mode = OFF;
    sun_visible = false;
    strcpy(status_msg, "OK");

    for(int i=0;i<2;i++){
        pkt_array[i].temp = 20.0 + i;
        pkt_array[i].volt = 3.3;
        pkt_array[i].fault = 0;
    }

    timestamp = 0.0;
    reset_health_request = 0;

}

void Sensors::init() {
    // Nothing to do for init yet
}

void Sensors::update() {
	mode = ACTIVE;

	// simple deterministic patterns
	static double t = 0.0;
	t += 0.1;

	gyro_rate[0] = 0.015 * sin(0.2 * t);
	gyro_rate[1] = 0.008 * cos(0.17 * t);
	gyro_rate[2] = 0.004 * sin(0.1 * t + 1.0);
	
	accel[0] = 0.1 * sin(0.2 * t);
	accel[1] = 0.1 * cos(0.2 * t);
	accel[2] = 0.05;

    // health counter logic
    if (reset_health_request) {
        health_counter = 0;
        reset_health_request = 0;
    } else {
        health_counter++;
    }

    // toggle sun visibility slowly
    sun_visible = ((int)t % 30 < 5) ? true : false;

    // update packets
    for(int i=0;i<2;i++){
        pkt_array[i].temp += 0.01;  // slow drift
        pkt_array[i].volt = 3.3;    // fixed
        pkt_array[i].fault = (i==1 && ((int)t % 20 == 0)) ? 1 : 0;
    }

    // Status message
    if (((int)(t*10) % 20) == 0)
        strcpy(status_msg, "OK");
    else if (((int)(t*10) % 25) == 0)
        strcpy(status_msg, "WARN");
    else
        strcpy(status_msg, "NOM");

    timestamp = t;

	// ------------------------------------------------------------------
	// Periodic message to show user that SIM_SENSORS is running
	// ------------------------------------------------------------------
	static int print_counter = 0;
	print_counter++;

	// Print once every ~100 updates
	if (print_counter >= 100) {
		 fprintf(stdout,
			"[SIM_SENSORS] t=%.1f  Gyro=(%.4f %.4f %.4f)  Status=%s\n",
			timestamp, gyro_rate[0], gyro_rate[1], gyro_rate[2], status_msg
		);
		print_counter = 0;
	}

	static bool prev_enabled = false;
	double mag = fabs(gyro_rate[0]) + fabs(gyro_rate[1]) + fabs(gyro_rate[2]);

	if (mag > 0.02 && !prev_enabled) {
		fprintf(stdout,
			"[SIM_SENSORS] Gyro magnitude = %.6f - exceeds limit(0.02)\n", mag);
	} else if (mag <= 0.02 && prev_enabled) {
		fprintf(stdout,
			"[SIM_SENSORS] Gyro magnitude = %.6f\n", mag);
	}
	prev_enabled = (mag > 0.02);

}