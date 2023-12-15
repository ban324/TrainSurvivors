#include "pch.h"
#include "GaugeBar.h"
#include "Vec2.h"

void GaugeBar::SetGauge()
{
	SetScale(Vec2(currentExperience * 500 / maxExperience, 30));
	SetPos(Vec2(200 + (currentExperience * 500/ (maxExperience * 2)), 30));
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
