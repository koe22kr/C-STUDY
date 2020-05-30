#pragma once
class Bitmap
{
public:
    void Init() {};
    void Frame() {};
    void Rander() 
    {
        Draw();
    };
    void Release() 
    {
        Delete();
    };

    void Draw() {};
    void Delete() {};


    Bitmap();
    virtual ~Bitmap();
};

