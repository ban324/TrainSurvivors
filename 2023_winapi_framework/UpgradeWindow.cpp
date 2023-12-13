#include "pch.h"
#include "UpgradeWindow.h"
#include "Vec2.h"

bool UpgradeWindow::IsRange(const POINT mousePoint)
{
    Vec2 vPos = GetPos();
    Vec2 vScale = GetScale();
    Vec2 leftupPos = Vec2({ vPos.x - (vScale.x / 2), vPos.y - (vScale.y / 2) });
    Vec2 rightdownPos = Vec2({ vPos.x + (vScale.x / 2), vPos.y + (vScale.y / 2) });

    Vec2 mousePos = mousePoint;
    if (mousePos.x > leftupPos.x && mousePos.x < rightdownPos.x)
    {
        if (mousePos.y < leftupPos.y && mousePos.y > rightdownPos.y)
        {
            return true;
        }
    }
    return false;
}