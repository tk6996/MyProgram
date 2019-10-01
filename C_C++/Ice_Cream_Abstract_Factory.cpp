#include <iostream>

using namespace std;
enum Trademark
{
    WALL,
    NESTLE,
    MILO
};
class IceCream
{
protected:
    Trademark tm;
    int cost;

public:
    virtual void eat() = 0;
};
class WallCup : public IceCream
{
public:
    WallCup();
    void eat() override;
};
class ClassisVanilla : public IceCream
{
public:
    ClassisVanilla();
    void eat() override;
};
class MochiVanilla : public IceCream
{
public:
    MochiVanilla();
    void eat() override;
};
class MiloCup : public IceCream
{
public:
    MiloCup();
    void eat() override;
};
class IceCreamFactory
{
public:
    enum Type
    {
        WALLCUP,
        CLASSISVANILLA,
        MOCHIVANILLA,
        MILOCUP
    };
    static IceCreamFactory *stores(Trademark);
    virtual IceCream *buyIceCream(Type) = 0;
};
class WallFactory : public IceCreamFactory
{
    IceCream *buyIceCream(Type) override;
};
class NestleFactory : public IceCreamFactory
{
    IceCream *buyIceCream(Type) override;
};
class MiloFactory : public IceCreamFactory
{
    IceCream *buyIceCream(Type) override;
};
IceCreamFactory *IceCreamFactory::stores(Trademark name = Trademark::WALL)
{
    switch (name)
    {
    case Trademark::WALL:
        cout << "You are WallStore.\n";
        return new WallFactory();
    case Trademark::NESTLE:
        cout << "You are NestleStore.\n";
        return new NestleFactory();
    case Trademark::MILO:
        cout << "You are MiloStore.\n";
        return new MiloFactory();
    default:
        cout << "This stores don't have.\n";
        break;
    }
    return nullptr;
}
IceCream *WallFactory::buyIceCream(Type name = IceCreamFactory::Type::WALLCUP)
{
    switch (name)
    {
    case IceCreamFactory::Type::WALLCUP:
        cout << "You are buy Wallcup.\n";
        return new WallCup();
    case IceCreamFactory::Type::CLASSISVANILLA:
        cout << "You are buy Classisvanilla.\n";
        return new ClassisVanilla();
    default:
        cout << "Thisicecream hasn't store.\n";
        break;
    }
    return nullptr;
}
IceCream *NestleFactory::buyIceCream(Type name = IceCreamFactory::Type::MOCHIVANILLA)
{
    switch (name)
    {
    case IceCreamFactory::Type::MOCHIVANILLA:
        cout << "You are buy Mochivanilla.\n";
        return new MochiVanilla();
    default:
        cout << "Thisicecream hasn't store.\n";
        break;
    }
    return nullptr;
}
IceCream *MiloFactory::buyIceCream(Type name = IceCreamFactory::Type::MOCHIVANILLA)
{
    switch (name)
    {
    case IceCreamFactory::Type::MILOCUP:
        cout << "You are buy Milocup.\n";
        return new MiloCup();
    default:
        cout << "Thisicecream hasn't store.\n";
        break;
    }
    return nullptr;
}
WallCup::WallCup()
{
    tm = Trademark::WALL;
    cost = 20;
}
void WallCup::eat()
{
    cout << "You eat Wallcup.";
}
ClassisVanilla::ClassisVanilla()
{
    tm = Trademark::WALL;
    cost = 15;
}
void ClassisVanilla::eat()
{
    cout << "You eat Classisvanilla.";
}
MochiVanilla::MochiVanilla()
{
    tm = Trademark::NESTLE;
    cost = 20;
}
void MochiVanilla::eat()
{
    cout << "You eat Mochivanilla.";
}
MiloCup::MiloCup()
{
    tm = Trademark::NESTLE;
    cost = 25;
}
void MiloCup::eat()
{
    cout << "You eat Milocup";
}
int main(void)
{
    if(IceCreamFactory *fac = IceCreamFactory::stores(NESTLE))
    {
        if(IceCream *ice = fac->buyIceCream(IceCreamFactory::Type::MOCHIVANILLA))
            {
                if(ice)ice->eat();
                delete ice;
            }
        delete fac;
    }
    return 0;
}