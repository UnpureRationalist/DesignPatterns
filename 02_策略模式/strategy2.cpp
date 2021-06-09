class Context
{
};

// 税务计算策略 基类
class TaxStrategy
{
public:
    virtual double Calculate(const Context &context) = 0;
    virtual ~TaxStrategy() {}
};

// 中国税法
class CNTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //***********
    }
};

class USTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //***********
    }
};

class DETax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //***********
    }
};

//扩展
//*********************************
class FRTax : public TaxStrategy
{
public:
    virtual double Calculate(const Context &context)
    {
        //.........
    }
};

class SalesOrder
{
private:
    TaxStrategy *strategy;  // 指针(或引用) 支持多态

public:
    // 使用工厂模式创建对象
    SalesOrder(StrategyFactory *strategyFactory)
    {
        this->strategy = strategyFactory->NewStrategy();
    }
    ~SalesOrder()
    {
        delete this->strategy;  // 释放内存
    }

public:
    double CalculateTax()
    {
        //...
        Context context;    // 构建上下文

        double val = strategy->Calculate(context); //多态调用
        //...
    }
};
