#pragma once
#include "Object.h"
#include "Vec2.h"

class GaugeBar :
    public Object
{
public://������, �Ҹ���
public://�Լ�
    void SetGauge();
    void Reset(int maxEx);
    void Increse(int ex);
public://�Լ�
    int currentExperience;
    int maxExperience;
};