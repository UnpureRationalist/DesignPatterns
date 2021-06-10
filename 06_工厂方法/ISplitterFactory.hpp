#pragma once

//抽象类
class ISplitter
{
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

//工厂基类
class SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter() = 0;    // 纯虚函数
    virtual ~SplitterFactory() {}
};