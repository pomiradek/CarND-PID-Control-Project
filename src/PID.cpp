#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
    this->Kp = Kp;
    this->Ki = Ki;
    this->Kd = Kd;
    
    // how far we are from the center of the road
    p_error = 0.0;
    // cumulative sum of all of our cross check errors
    i_error = 0.0;
    // how much we changed from since our crosstrack error (cte - prev cte)
    d_error = 0.0;
}

void PID::UpdateError(double cte) {
    d_error = cte - p_error;
    p_error = cte;
    i_error += cte;
}

double PID::TotalError() {
    return -Kp*p_error - Ki*i_error - Kd*d_error; 
}

