#pragma once

#include <iostream>
#include <chrono>


struct Timer
{

public:
	std::chrono::time_point<std::chrono::steady_clock> start;
//	std::chrono::time_point<std::chrono::steady_clock> end;
	std::chrono::duration<float> duration;

	Timer()
		: start(std::chrono::high_resolution_clock::now())
	{}

	~Timer()
	{
	//	end = std::chrono::high_resolution_clock::now();

		duration = std::chrono::high_resolution_clock::now() - start;
		std::cout << "timer took : " << duration.count() * 1000.0f << "ms\n";
	}

	//returns the count of the clock; is milliseconds
	inline float GetTime()
	{
		duration = std::chrono::high_resolution_clock::now() - start;
		return duration.count() * 1000.f;
	}


};