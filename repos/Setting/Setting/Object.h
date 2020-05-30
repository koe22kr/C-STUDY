#pragma once
#include <Windows.h>
#include "Bitmap.h"
#include <vector>

using namespace std;

class Object
{
public:

    void Init() {};
    void Frame() {};
    void Rander() {};
    void Release() {};

    Bitmap* m_bitmap;
    Bitmap* m_mask;

    void Draw_obj() {};
    void Draw_mask() {};
    void Delete() {};

    int isprite_data() {};
    float fsprite_data() {};
    
    int m_Max_rt_num;
    int m_Cur_rt_num;
    vector<RECT> m_RtArray;
    


    Object();
    virtual ~Object();
};

