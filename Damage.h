#ifndef DAMAGE_HEADER
#define DAMAGE_HEADER

struct Damage{
    int physical;
    int magical;

    int sum(){
        return this->physical + this->magical;
    }
    int sum(int defense){
        return max((this->physical - defense),0) + this->magical;
    }
    void progress(int physical_plus, int magical_plus){
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
    
}

#endif