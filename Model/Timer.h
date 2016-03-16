/*
 * Timer.h
 *
 *  Created on: Feb 16, 2016
 *      Author: dvil4688
 */

#ifndef MODEL_TIMER_H_
#define MODEL_TIMER_H_
#include <time.h>

class Timer
{
private:
	clock_t executionTime;
public:
	Timer();
	virtual ~Timer();
	void startTimer();
	void stopTimer();
	void resetTimer();
	void displayTimerInfo();
	long getExecutionTimeInMicroSeconds();
};

#endif /* MODEL_TIMER_H_ */
