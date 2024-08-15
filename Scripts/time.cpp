#include "time.h"
#include <thread>
#include <chrono>

namespace MSystem
{
	MTime::MTime(const MaxDeltaTime maxDeltaTime)
		: _deltaTime(0.f)
		, _currentTime(0.f)
		, _previousTime(0.f)
		, _maxDeltaTime(maxDeltaTime)
	{
	}

	MTime::~MTime()
	{
	}

	void MTime::UpdateTime()
	{

	}

	float MTime::GetDeltaTime() const
	{
		return _deltaTime;
	}

	float MTime::GetCurrentTime() const
	{
		return _currentTime;
	}
}
