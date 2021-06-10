class ISplitter
{
public:
    virtual void split() = 0;
    virtual ~ISplitter() {}
};

class BinarySplitter : public ISplitter
{
public:
    void split() override
    {
    }
};

class TxtSplitter : public ISplitter
{
public:
    void split() override
    {
    }
};

class PictureSplitter : public ISplitter
{
public:
    void split() override
    {
    }
};

class VideoSplitter : public ISplitter
{
public:
    void split() override
    {
    }
};