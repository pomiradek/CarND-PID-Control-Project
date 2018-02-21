# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Describe the effect each of the P, I, D components had in your implementation

### P component
Is proportional to the cross-track error and controls how much to steer to the middle of the road.
Low P value - results in slow changes in the the steering and tha car is not able to go throught the sharp turns because of this small output response.
Hight P value - results in big change of the controll parametr and makes the driving of the vehicle unstable

### I component
The contribution from the integral term is proportional to both the magnitude of the error and the duration of the error. The integral in a PID controller is the sum of the instantaneous error over time and gives the accumulated offset that should have been corrected previously. The accumulated error is then multiplied by the integral gain (Ki) and added to the controller output.
Helps the vehicle keep closer to desired middle of the track. When set to zero, the vehicle is little bit shifted from the middle of the road.
Hight I gain - vehicle is unstable
Low I gain - it takes too long to get to the middle of the road

### D component
The derivative of the process error is calculated by determining the slope of the error over time and multiplying this rate of change by the derivative gain Kd. 
It aims at flattening the error trajectory into a horizontal line, damping the force applied, and so reduces overshoot. This component helps to stabilize P component in long term and reduce the oscillation cause by the P component.
Low D gain results in underdamped - vehicle still oscillates
High D gain results in overdamped - long time to correct the offset from the middle of the road
When set correctly the system is critically-damped.

## Describe how the final hyperparameters were chosen
I have followed the [youtube video instructions](https://www.youtube.com/watch?v=YamBuzDjrs8). So than I decided to manually tune the PID parameters. 
At first I have set all the P, I, D weights to zeroes. Than I have increased the P weight until I've got a reasonable
good oscillation of the vehicle. Than I added the D weight. I started will low values which resulted in oscillation after some time. So I started to increase this value and tuning the P weight as well.
When I set the D weight too hight, it started oscillation at begining. So I had to fine some good combination of P and D values. With I weight still set to yero it was working pretty good, but the vehicle was not in the middle.
So I had to added some I weight. I started with 1 and the vehicle was oscillating at the begining of teh run. So than I realized that it is sum of all cte, so I have to set some really small number.
So I was looking for some small number where it stops oscillating. After some combinations of P, I, D weight I have found a reasonably good solution which is able to achieve speed of 35 mph.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets 
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

There's an experimental patch for windows in this [PR](https://github.com/udacity/CarND-PID-Control-Project/pull/3)

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

Tips for setting up your environment can be found [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d)

