#pragma once
#include "Object.h"
#include <map>
class Bitmap_Mgr
{
public:

    void Init() {};
    void Frame() {};
    void Rander() {};
    void Release() {};
    
    void Draw() {};
    void Del_Obj() {};

    vector<Object> m_Object_Array;
    map<string,Bitmap> m_Bitmap_Map;

    Bitmap_Mgr();
    virtual ~Bitmap_Mgr();
};

