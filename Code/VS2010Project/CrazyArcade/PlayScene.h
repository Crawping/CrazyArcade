#pragma once

#include "LGHead.h"
#include "Scene.h"
#include "Block.h"
#include "Role.h"
#include "Bubble.h"

const int XLENGTH = 15;
const int YLENGTH = 13;

class PlayScene : public Scene
{
	SINGLETON_NOCTOR(PlayScene);
public:
	void Enter(LGCenter*);
	void Execute(LGCenter*, float deltaTime = 0.0f);
	void Exit(LGCenter*);
	void LoadScene();
	void UnloadScene();
	bool OnMessage(LGCenter* agent, const Telegram& msg);
	void ChangeMap(int posX, int posY, MapType::E_MapType blockType);
	void Explosion(int x, int y, int power);
	bool DestoryMapPos(int x, int y, Bubble::E_StateType stateType,Bubble::E_Direction direction);
private:
	void CreateMapBlock();
	void CreateRoad(const int& x, const int& y, const std::wstring& picPath, const int& col);
	void KeyboardControl();
	void CollisionDetection(Role* obj, float deltaTime);
private:
	MapType::E_MapType m_MapBlock[XLENGTH][YLENGTH]; //�����ͼ��ԭ�������½�
	Role* m_pPlayer;
};