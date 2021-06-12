#include <deque>
#include <stack>
#include <queue>
using namespace std;

// 目标接口（新接口）
class ITarget
{
public:
    virtual void process() = 0;

    virtual ~ITarget()
    {

    }
};

// 遗留接口（老接口）
class IAdaptee
{
public:
    virtual void foo(int data) = 0;
    virtual int bar() = 0;

    virtual ~IAdaptee()
    {

    }
};

// 遗留类型
class OldClass : public IAdaptee
{
    //....
    void foo(int data) override
    {
    }

    int bar() override
    {
    }
};
 
// 对象适配器  推荐！！！
class Adapter : public ITarget
{ //继承
protected:
    IAdaptee *pAdaptee; //组合

public:
    Adapter(IAdaptee *pAdaptee)
    {
        this->pAdaptee = pAdaptee;
    }

    virtual void process()
    {
        int data = pAdaptee->bar();
        pAdaptee->foo(data);
    }
};

// 类适配器
class Adapter : public ITarget,
                protected OldClass
{ //多继承

public:
    Adapter()
    {

    }

    void process() override
    {
    }

    void foo(int data) override
    {
    }

    int bar() override
    {
    }
};

int main()
{
    IAdaptee *pAdaptee = new OldClass();

    ITarget *pTarget = new Adapter(pAdaptee);
    pTarget->process();
    
    // 适配器
    stack<int, vector<int>> stk;

    queue<int, vector<int>> q;

    return 0;
}

// class stack
// {
//     deqeue container;
// };

// class queue
// {
//     deqeue container;
// };