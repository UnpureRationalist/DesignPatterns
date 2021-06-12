#include <atomic>
#include <memory>
#include <mutex>
using namespace std;

class Singleton
{
private:
    Singleton();
    Singleton(const Singleton &other); // 拷贝构造函数设置为私有 or =delete

    static std::atomic<Singleton *> m_instance;
    static std::mutex m_mutex;

public:
    static Singleton *getInstance();
    static Singleton *m_instance;
};

Singleton *Singleton::m_instance = nullptr; // 静态成员初始化

//线程非安全版本
Singleton *Singleton::getInstance()
{
    if (m_instance == nullptr)
    {
        m_instance = new Singleton(); // 保证只创建一个对象
    }
    return m_instance;
}

//线程安全版本，但锁的代价过高
Singleton *Singleton::getInstance()
{
    Lock lock; // 加锁
    if (m_instance == nullptr)
    {
        m_instance = new Singleton();
    }
    return m_instance;
}

// 很著名的一种实现方式----双检查锁  实际上不正确
// 双检查锁，但由于内存读写reorder不安全
Singleton *Singleton::getInstance()
{
    // 只有指针为空的情况下才需要加锁 降低代价
    if (m_instance == nullptr)
    {
        Lock lock;
        if (m_instance == nullptr) // 必须判断 双检查
        {
            m_instance = new Singleton();
            /**     理想执行顺序
             * 1. 分配内存
             * 2. 调用构造函数
             * 3. 返回指针
             * 
             *      reorder 之后可能顺序
             * 1. 分配内存
             * 2. 返回指针
             * 3. 调用构造函数
             * 
             * 假设线程 A 执行到 2. 时但是还未执行 3；
             * 线程 B 执行该段代码，发现了指针非空并返回，但是此时对象并没有构造，导致未定义行为。
             */
        }
    }
    return m_instance;
}

// C++ 11版本之后的跨平台实现 (volatile)
std::atomic<Singleton *> Singleton::m_instance;
std::mutex Singleton::m_mutex;

Singleton *Singleton::getInstance()
{
    Singleton *tmp = m_instance.load(std::memory_order_relaxed);
    std::atomic_thread_fence(std::memory_order_acquire); //获取内存fence
    if (tmp == nullptr)
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        tmp = m_instance.load(std::memory_order_relaxed);
        if (tmp == nullptr)
        {
            tmp = new Singleton;
            std::atomic_thread_fence(std::memory_order_release); //释放内存fence
            m_instance.store(tmp, std::memory_order_relaxed);
        }
    }
    return tmp;
}