#include <string>
using std::string;

class Memento
{
    string state;
    //..    状态
public:
    Memento(const string &s) : state(s) {}

    string getState() const
    {
        return state;
    }

    void setState(const string &s)
    {
        state = s;
    }
};

class Originator
{
    string state;
    //.... 状态
public:
    Originator() {}
    Memento createMomento()
    {
        Memento m(state); // 创建一个状态 并返回对象（保存当前状态）
        return m;
    }
    void setMomento(const Memento &m)
    {
        state = m.getState();
    }
};

int main()
{
    Originator orginator;

    //捕获对象状态，存储到备忘录
    const Memento mem = orginator.createMomento();

    //... 改变orginator状态

    //从备忘录中恢复
    orginator.setMomento(mem);

    return 0;
}