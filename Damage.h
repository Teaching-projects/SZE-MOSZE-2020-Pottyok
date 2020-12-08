/**
 * \class Damage
 * 
 * \brief Damage struct
 * 
 * \author Pénzes Péter, Nagy Bálint, Őri Tamás
 * 
 * Created on: 2020/12/01 14:30
*/
#ifndef DAMAGE_HEADER
#define DAMAGE_HEADER

struct Damage
{
public:
    float physical; ///< A phisycal damage
    float magical; ///< A magical damage

    float sum(float defense = 0 /** [in] A levonni kívánt defense érték, alapértelmezetten 0 */)
    {
        return std::max<float>((this->physical - defense), 0.00) + this->magical;
    }  ///< Összesíti a damaget
    void progress(float physical_plus /** [in] Hozzáadni kívánt physical damage */, float magical_plus /** [in] Hozzáadni kívánt magical damage */)
    {
        this->physical += physical_plus;
        this->magical += magical_plus;
    } ///< A damage értékek növelése

    Damage &operator+=(const Damage &damage /** [in] Hozzáadni kívánt Damage */)
    {
        this->physical += damage.physical;
        this->magical += damage.magical;
        return *this;
    } ///< += operator Damage-val

    Damage &operator*=(const Damage &damage  /** [in] Hozzászorozni kívánt Damage */)
    {
        this->physical *= damage.physical;
        this->magical *= damage.magical;
        return *this;
    }///< *= operator Damage-val

    friend Damage operator+(Damage damage /** [in] Adott Damage */, const Damage &other /** [in] Hozzáadni kívánt Damage */)
    {
        damage += other;
        return damage;
    }///< + operator Damage-val

    Damage operator+(const int &other /** [in] Hozzáadni kívánt Damage */)
    {
        this->magical += other;
        this->physical += other;
        return *this;
    }///< + operator int-el
};

#endif