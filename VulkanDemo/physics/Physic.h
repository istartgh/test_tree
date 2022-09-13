//
//  main.cpp
//  VulkanDemo
//
//  Created by star03 on 2022/8/31.
//

class Position_XYZ {
public:
    Position_XYZ() = default;
    Position_XYZ(float posx, float posy, float posz) : m_posx(posx), m_posy(posy), m_posz(posz){}
    ~Position_XYZ() = default;
    
    float m_posx;
    float m_posy;
    float m_posz;
};

//向量
class VectorQuantity {
public:
    VectorQuantity() = default;
    VectorQuantity(float lengthx, float lengthy, float lengthz) : m_lengthx(lengthx), m_lengthy(lengthy), m_lengthz(lengthz) {}
    ~VectorQuantity() = default;
    //大小
    float m_lengthx;
    float m_lengthy;
    float m_lengthz;
    //方向
//    Position_XYZ m_pos;
};

//class Force {
//public:
//    //大小
//
//    //方向
//
//};

class Something {
public:
    //位置
    Position_XYZ m_pos;
    //质量
    long int m_quality;
    //速度
    VectorQuantity m_velocity;
    
    void UpdatePos(VectorQuantity force, long time);
    
};
