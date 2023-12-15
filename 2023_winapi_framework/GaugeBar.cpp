#include "pch.h"
#include "GaugeBar.h"
#include "Vec2.h"

void GaugeBar::SetGauge()
{
	SetScale(Vec2(currentExperience * 500 / maxExperience, 10));
	SetPos(Vec2(200 + (currentExperience * 500/ (maxExperience * 2)), 10));
}

void GaugeBar::Reset(int maxEx)
{
	maxExperience = maxEx;
	currentExperience = 0;
	SetGauge();
}

void GaugeBar::Increse(int ex)
{
	currentExperience += ex;
	SetGauge();
}
