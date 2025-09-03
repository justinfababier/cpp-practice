#ifndef DRONE_H
#define DRONE_H

class Drone {   // Drone class
    private:    // Private members are only accessible within the class
        // Attributes of the drone
        double altitude;
        double velocity;
        double mass;
        double gravity;
        double maxThrust;

    public:     // Public members can be accessed outside the class
        // Constructor to initialize the drone's properties
        Drone(double mass_, double maxThrust_ = 20.0, double gravity_ = 9.81):
            altitude(0.0),  // Initializes altitude to 0.0
            velocity(0.0),  // Initializes velocity to 0.0
            mass(mass_),    // Initializes mass based on mass_
            gravity(gravity_),      // Sets gravity based on gravity_ (default 9.81)
            maxThrust(maxThrust_)   // Sets maxThrust based on maxThrust_ (default 20.0)
        {}

    // Getter function for altitude (constant, no modification allowed)
    double getAltitude() const {
        return altitude;    // Return current altitude of drone
    }

    // Method to update the drone's altitude and velocity based on thrust and time
    void update(double thrust, double dt) {
        // Clamp thrust within the valid range (0 to maxThrust)
        if (thrust > maxThrust) {
            thrust = maxThrust; // If thrust exceeds maxThrust, set it to maxThrust
        }
        else if (thrust < 0.0) {
            thrust = 0.0;       // If thrust is less than 0, set it to 0
        }

        // Calculate acceleration using Newton's second law: F = ma => a = (F - mg) / m
        double accel = (thrust - mass * gravity) / mass;

        // Update velocity and altitude based on acceleration and time delta (dt)
        velocity += accel * dt;     // Velocity change over time
        altitude += velocity * dt;  // Altitude change based on velocity

        // Ensure altitude does not go below 0 (the ground level)
        if (altitude < 0.0) {
            altitude = 0.0; // Set altitude to 0 if it goes below ground
            velocity = 0.0; // Set velocity to 0 if the drone hits the ground
        }
    }

    // Method to reset the drone's position and velocity to the initial state
    void reset() {
        altitude = 0.0; // Reset altitude to 0
        velocity = 0.0; // Reset velocity to 0
    }
};

#endif