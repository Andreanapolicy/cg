#pragma once

class CAnimationController
{
public:
	CAnimationController();
	~CAnimationController();
	void Reset();
	void Tick();
	DWORD GetTimeDelta() const;

private:
	DWORD m_lastTick;
	DWORD m_delta;
};
