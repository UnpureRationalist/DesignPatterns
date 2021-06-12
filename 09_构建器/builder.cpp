
class House
{
    //....
    // 构造函数内部不能调用虚函数（是静态绑定）
};

class HouseBuilder
{
public:
    House *GetResult()
    {
        return pHouse;
    }
    virtual ~HouseBuilder() {}
    virtual void BuildPart1() = 0;
    virtual void BuildPart2() = 0;
    virtual bool BuildPart3() = 0;
    virtual void BuildPart4() = 0;
    virtual void BuildPart5() = 0;

protected:
    House *pHouse; // 基类指针
};

class StoneHouse : public House
{
};

class StoneHouseBuilder : public HouseBuilder
{
public:
    virtual void BuildPart1() override
    {
        //pHouse->Part1 = ...;
    }
    virtual void BuildPart2() override
    {
    }
    virtual bool BuildPart3() override
    {
    }
    virtual void BuildPart4() override
    {
    }
    virtual void BuildPart5() override
    {
    }
};

class HouseDirector
{

public:
    HouseBuilder *pHouseBuilder;

    HouseDirector(HouseBuilder *pHouseBuilder)
    {
        this->pHouseBuilder = pHouseBuilder;
    }

    House *Construct()
    {

        pHouseBuilder->BuildPart1();

        for (int i = 0; i < 4; i++)
        {
            pHouseBuilder->BuildPart2();
        }

        bool flag = pHouseBuilder->BuildPart3();

        if (flag)
        {
            pHouseBuilder->BuildPart4();
        }

        pHouseBuilder->BuildPart5();

        return pHouseBuilder->GetResult();
    }
};