#include "time.h"
#include <thread>
#include <chrono>

namespace MSystem
{

	namespace
	{
		using Time = std::chrono::steady_clock::time_point; 
		static Time System_Start_Time;
	}
	MTime::MTime(const MaxDeltaTime maxDeltaTime)
		: _deltaTime(0.f)
		, _maxDeltaTime(maxDeltaTime)
		, _currentTime(Clock::now())
		, _previousTime(Clock::now())
	{
		System_Start_Time = Clock::now();
	}

	MTime::~MTime()
	{
	}

	void MTime::UpdateTime()
	{
		_previousTime = _currentTime;		
		_currentTime = Clock::now();

		std::chrono::duration<float> duration = _currentTime - _previousTime;
		_deltaTime = duration.count(); 
		if(_deltaTime > _maxDeltaTime)
		{
			_deltaTime = _maxDeltaTime;
		}
		
	}

	float MTime::GetDeltaTime() const
	{
		return _deltaTime;
	}

	float MTime::GetCurrentTime() const
	{
		std::chrono::duration<float> durationAfterStart = System_Start_Time - _currentTime;
		return durationAfterStart.count();
	}
}
