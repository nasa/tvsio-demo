/********************************* TRICK HEADER *******************************                                                                                                 
PURPOSE:
    (Sensor sim for tvsio end-to-end demonstration)
REFERENCES:
    (
	(TVSIO - https://github.com/nasa/tvsio
    (Trick Simulation Environment) (NASA:JSC #37943)
	(cFS - https://etd.gsfc.nasa.gov/capabilities/core-flight-system/)
	)
PROGRAMMERS:
    ((James Pettit) (METECS) (Nov 2026) (Demo Rewrite))
*******************************************************************************/
#ifndef SENSORS_HH
#define SENSORS_HH

#include <cstring>
#include <cmath>

enum SensorMode { OFF = 0, STANDBY = 1, ACTIVE = 2 };

struct SensorPacket {
    double temp;
    double volt;
    int fault;
};

class Sensors {

public:
    double gyro_rate[3];
    double accel[3];
    int health_counter;
    SensorMode mode;
    bool sun_visible;
    char status_msg[32];
    SensorPacket pkt_array[2];
    double timestamp;
    int reset_health_request;

    Sensors();
    void init();
    void update();
};

#endif