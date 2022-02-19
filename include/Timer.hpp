#pragma once


#define TEN_SECONDS 10000


class Timer {
private:
	unsigned long delay;
	unsigned long start;

public:
	Timer(unsigned long delay);
	
	unsigned long getDelay() const;
	void setDelay(unsigned long delay);

	bool isDone() const;
	void restart();
	unsigned long getElapsedTime() const;
};