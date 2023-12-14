#pragma once
#include "Object.h"
#include "Vec2.h"

class GaugeBar :
    public Object
{
public://생성자, 소멸자
public://함수
    void SetGauge();
    void Reset();
    void Increse(int ex);
public://함수
    int currentExperience;
};