#ifndef DAMAGE_HEADER
#define DAMAGE_HEADER

#include <iostream>

struct Damage{
    public:
        float physical;
        float magical;

        float sum(float defense = 0){
            return std::max<float>((this->physical - defense),0.00) + this->magical;
        }
        void progress(float physical_plus, float magical_plus){
            this->physical  += physical_plus;
            this->magical   += magical_plus;
        }

        Damage &operator+=(const Damage &damage)
        {
            physical += damage.physical;
            magical += damage.magical;
            return *this;
        }

        Damage &operator*=(const Damage &damage)
        {
            physical *= damage.physical;
            magical *= damage.magical;
            return *this;
        }

        friend Damage operator+(Damage damage, const Damage &other)
        {
            damage += other;
            return damage;
        }
    
};

#endif