#include "pch.h"
#include "Scene.h"
#include "Object.h"
#include "EventMgr.h"
Scene::Scene()
{
}

Scene::~Scene()
{
	Release();
}

void Scene::Update()
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if(!m_vecObj[i][j]->GetIsDead())
				m_vecObj[i][j]->Update();
		}
	}
}

void Scene::FinalUpdate()
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			m_vecObj[i][j]->FinalUpdate();
		}
	}
}

void Scene::Render(HDC _dc)
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size();)
		{
			if (!m_vecObj[i][j]->GetIsDead())
			{
				m_vecObj[i][j]->Render(_dc);
				++j;
			}
			else
				m_vecObj[i].erase(m_vecObj[i].begin() + j);
		}
	}
}

void Scene::Release()
{
	for (UINT i = 0; i < (UINT)OBJECT_GROUP::END; ++i)
	{
		for (size_t j = 0; j < m_vecObj[i].size(); ++j)
		{
			if (m_vecObj[i][j])
			{
				EventMgr::GetInst()->DeleteObject(m_vecObj[i][j]);
			}
		}
		m_vecObj[i].clear();
	}
}

void Scene::EraseObject(OBJECT_GROUP group, Object * obj)
{
	assert(obj);
	if (m_vecObj[(UINT)group].end() != find(m_vecObj[(UINT)group].begin(), m_vecObj[(UINT)group].end(), obj))
	{
		m_vecObj[(UINT)group].erase(find(m_vecObj[(UINT)group].begin(), m_vecObj[(UINT)group].end(), obj));

	}
}

Vec2 Scene::GetProximateDir()
{
	Vec2 p_Pos = m_vecObj[(UINT)OBJECT_GROUP::PLAYER][0]->GetPos();
	int pm1 = rand() % 2 == 1 ? 1: -1;
	int pm2 = rand() % 2 == 1 ? 1: -1;
	Vec2 enemyPos = Vec2(rand() * pm1, rand() * pm2);
	int minDist = 1980;
	int currentDist;
	for (auto iter = m_vecObj[(UINT)OBJECT_GROUP::MONSTER].begin(); iter != m_vecObj[(UINT)OBJECT_GROUP::MONSTER].end(); ++iter)
	{

		currentDist = Vec2::GetDistance(p_Pos, (*iter)->GetPos());
		if (currentDist < minDist)
		{
			minDist = currentDist;
			enemyPos = (*iter)->GetPos();
		}
	}
	return Vec2(enemyPos.x - p_Pos.x, enemyPos.y - p_Pos.y);

}

