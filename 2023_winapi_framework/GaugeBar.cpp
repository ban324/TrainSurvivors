#include "pch.h"
#include "GaugeBar.h"
#include "Vec2.h"

void GaugeBar::SetGauge()
{
	SetScale(Vec2(currentExperience, 30));
}

void GaugeBar::Reset()
{
	currentExperience = 10;
	SetGauge();
}

void GaugeBar::Increse(int ex)
{
	currentExperience += ex;
	SetGauge();
}
