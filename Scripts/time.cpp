#include "time.h"

#include <thread>
#include <chrono>
#include <assert.h>

namespace MSystem
{
	namespace
	{
		using Time = std::chrono::steady_clock::time_point;
		using Clock = std::chrono::steady_clock;
		using DurationF = std::chrono::duration<float>;

		static Time System_Start_Time;
	}
	MTime::MTime(const MaxDeltaTime maxDeltaTime)
		: _deltaTime(0.f)
		, _maxDeltaTime(maxDeltaTime)
		, _currentTime()
		, _previousTime()
		, _isActive(0)
	{
		;
	}

	MTime::~MTime()
	{
		ShutDown();
	}

	void MTime::StartUp()
	{
		if (_isActive)
			return;

		_currentTime = Clock::now();
		_previousTime = _currentTime;
		System_Start_Time = _currentTime;

		// Set System To Active
		_isActive = 1;
	}

	void MTime::UpdateTime()
	{
		if (!_isActive)
			return;

		_previousTime = _currentTime;		
		_currentTime = Clock::now();

		DurationF duration = _currentTime - _previousTime;
		_deltaTime = duration.count(); 
		if(_deltaTime > _maxDeltaTime)
		{
			_deltaTime = _maxDeltaTime;
		}
		
	}

	void MTime::ShutDown() noexcept
	{
		if (!_isActive)
			return;

		_isActive = 0;
		_deltaTime = 0;
		_maxDeltaTime = 0;
	}

	float MTime::GetDeltaTime() const
	{
		assert(_isActive);

		return _deltaTime;
	}

	float MTime::GetCurrentTime() const
	{
		assert(_isActive);

		DurationF durationAfterStart = System_Start_Time - _currentTime;
		return durationAfterStart.count();
	}
}
