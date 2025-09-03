#include <iostream>
#include <iomanip>
#include <chrono>
#include <thread>
#include "PID.h"
#include "Drone.h"

int main() {
    Drone drone(1.0, 20.0);
    PID pid(0.5, 0.2, 0.1, 0.0, 20.0);

    drone.reset();

    double setpoint = 50.0;
    double dt = 0.1;
    int steps = 100;

    for (int i = 0; i < steps; ++i) {
        double altitude = drone.getAltitude();
        
        double thrust = pid.compute(setpoint, altitude, dt);

        drone.update(thrust, dt);

        std::cout << "Time: " << std::setprecision(3) << i * dt 
                  << " s, Altitude: " << drone.getAltitude()
                  << " m, Thrust: " << thrust << " N" << std::endl;
    }

    return 0;
}