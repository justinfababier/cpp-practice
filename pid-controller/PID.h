#ifndef PID_H
#define PID_H

class PID {
    private:
        // PID gains
        double Kp; 
        double Ki; 
        double Kd; 

        // State variables
        double prevError;        // Last error for derivative
        double integral;         // Integral term accumulator

        // Output limits
        double outputMin;
        double outputMax;

        // Derivative filter
        double derivativeFilter; // Low-pass filter factor
        double derivative;       // Filtered derivative

    public:
        PID(double Kp_, double Ki_, double Kd_, double outputMin_ = -1e10, double outputMax_ = 1e10, double derivativeFilter_ = 0.1):
            Kp(Kp_), Ki(Ki_), Kd(Kd_),
            prevError(0.0),
            integral(0.0),
            outputMin(outputMin_),
            outputMax(outputMax_),
            derivativeFilter(derivativeFilter_),
            derivative(0.0)
        {}

        double compute(double setpoint, double measurement, double dt) {
            double error = setpoint - measurement;

            // Proportional term
            double P = Kp * error;

            // Integral term with conditional integration (anti-windup)
            if ((integral < outputMax || error < 0) && (integral > outputMin || error > 0)) {
                integral += error * dt;
            }
            double I = Ki * integral;

            // Derivative term (derivative of error)
            double rawDerivative = (error - prevError) / dt;
            derivative = derivativeFilter * derivative + (1 - derivativeFilter) * rawDerivative;
            double D = Kd * derivative;

            // Compute total output
            double output = P + I + D;

            // Clamp output
            if (output > outputMax) output = outputMax;
            if (output < outputMin) output = outputMin;

            // Save current error for next derivative calculation
            prevError = error;

            return output;
        }

        void reset() {
            prevError = 0.0;
            integral = 0.0;
            derivative = 0.0;
        }

        void setGains(double Kp_, double Ki_, double Kd_) {
            Kp = Kp_;
            Ki = Ki_;
            Kd = Kd_;
        }

        void setOutputLimits(double minOutput, double maxOutput) {
            outputMin = minOutput;
            outputMax = maxOutput;
        }

        void setDerivativeFilter(double filter) {
            derivativeFilter = filter;
        }
    };

#endif
