#pragma once

#include "Sprite.h"
#include "Telegram.h"
#include "Rect.h"

class Object
{
public:
	static const Point ORIGINPIX;	//����ԭ�������λ��
	static const int MAPPIECEPIX;	//��ͼ������ش�С
	Object(std::wstring objName, Sprite currentSprite,int layout, Point pixelPos, 
		int objType = 0);
	Object();
	virtual ~Object();
	Sprite const& GetCurrentSprite() const;
	Sprite& HavaCurrentSprite();
	void SetCurrentSprite(IN Sprite val);
	Point const& GetClientPos() const;
	void SetClientPos(Point val);
	int const& GetLayout() const;
	void SetLayout(int val);
	std::wstring const& GetObjName() const;
	void SetObjName(std::wstring val);
	virtual bool HandleMessage(const Telegram& telegram);
	Point CalPixelPos(int mapPosX, int mapPosY);
	Point CalMapPos(Point pixelPos);
	int GetPixelPosX() const;
	void SetPixelPosX(float val);
	int GetPixelPosY() const;
	void SetPixelPosY(float val);
	bool OrderCompare(Object* const& rhs);
	LGRect const& GetRectCollision() const;
	int const& GetObjectType() const;
	void SetObjectType(int val);
	virtual void Update(float deltaTime);
	virtual bool UpdateAnimateFrame(float deltaTime, const int* frame = NULL, int frameCount = 0);	//������ѭ��һ�飬����true
	void UpdateRectCollision(int offsetX = 0, int offsetY = 0, int offsetWidth = 0, int offsetHeight = 0);
	void UpdateMapPos();
	int const& GetObjID() const;
	bool const& GetVisiable() const;
	void SetVisiable(bool val);
	bool const& GetDirty() const;
	void SetDirty(bool val); //trueΪ���øþ������ȫ�࣬false��ոþ�������������
	std::vector<LGRect> const& GetRectDirty() const;
	void SetRectDirty(LGRect val);//���ü��뾫�����������Σ�����������μ�⼯��
	void SetDirtySource(bool setRectDirty = true); //���øþ�������Ϊ����Σ������þ���ľ��μ�������μ�⼯��
	void UpdateSpriteRect();
	LGRect GetSpriteRect();
	bool const& GetHasInit() const;
	void SetHasInit(bool val);
	virtual int const& GetMapPosX() const;
	virtual void SetMapPosX(int val);
	virtual int const& GetMapPosY() const;
	virtual void SetMapPosY(int val);
protected:
	//ԭ�������½�
	int m_mapPosX;
	int m_mapPosY;
	Sprite m_currentSprite;
	int m_Layout;
	std::wstring m_objName;
	Point m_pixelPos;
	LGRect m_RectCollision;
	int m_ObjectType;
	static int NextID;
	int m_ID;
	bool m_dirty;
	std::vector<LGRect> m_RectDirty;
	LGRect m_SpriteRect;
	bool m_visiable;
private:
	float m_addToOneSum;
	int m_frameIndex;
	bool m_hasInit;
};