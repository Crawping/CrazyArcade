#pragma once

#include "LGHead.h"
#include "State.h"

class LGCenter;
class Object;

class Scene : public State<LGCenter>
{
public:
	Scene();
	virtual ~Scene();
	std::vector<Object*> const& GetAllObject_Sort();
	std::vector<Object*> const& GetAllObject();
	std::vector<Object*>& HaveAllObject();
	Object* HavaObject(std::wstring objName);
	Object* HavaObject(int objID);
	void InsertObject(Object* pInsertObj);
	bool DeleteObject(std::wstring objName);
	bool DeleteObject(int objID);
	bool const& GetGameEnd() const;
	void SetGameEnd(bool val);
	void hadLoadAll();
	std::vector<Object*> const& GetUnLoadObject() const;

	//-------------------------------������㷨-begin------------------------------
	std::vector<Object*> const& GetAllDirtyObject();
	void InsertDetectDirtyRect(LGRect dirtyRect); //���μ�������μ�⼯��
	void DirtyRectInfect(); // �����Ӱ�������ཻ����
	void ClearDirtyRect();
	void InsertDetectDirtyObject(Object* obj); //�����������μ�⼯��
	void ClearDirtyObject();
	//-------------------------------������㷨-end------------------------------
protected:
	bool SameName(Object* const& lhs, std::wstring const& name);
	bool ObjectSort(Object* const& lhs, Object* const& rhs);
private:
	std::vector<Object*> m_allObject;
	bool m_gameEnd;
	std::vector<LGRect> m_allDetectDirtyRect;
	std::vector<Object*> m_UnLoadObject;
	std::vector<Object*> m_allDirtyObject;
public:
	static Scene* m_currentScene;
};

