#include "Prototype.hpp"

//具体类
class BinarySplitter : public ISplitter
{
public:
    ISplitter *clone() override
    {
        return new BinarySplitter(*this); // 拷贝构造自己 clone
    }

    void split() override
    {
    }
};

class TxtSplitter : public ISplitter
{
public:
    virtual ISplitter *clone() override
    {
        return new TxtSplitter(*this);
    }

    void split() override
    {
    }
};

class PictureSplitter : public ISplitter
{
public:
    virtual ISplitter *clone() override
    {
        return new PictureSplitter(*this);
    }

    void split() override
    {
    }
};

class VideoSplitter : public ISplitter
{
public:
    virtual ISplitter *clone() override
    {
        return new VideoSplitter(*this);
    }

    void split() override
    {
    }
};