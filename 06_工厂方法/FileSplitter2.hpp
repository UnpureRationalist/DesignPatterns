#pragma once

#include "ISplitterFactory.hpp"

//具体类
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

//具体工厂
class BinarySplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter() override
    {
        return new BinarySplitter();
    }
};

class TxtSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter() override
    {
        return new TxtSplitter();
    }
};

class PictureSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter() override
    {
        return new PictureSplitter();
    }
};

class VideoSplitterFactory : public SplitterFactory
{
public:
    virtual ISplitter *CreateSplitter() override
    {
        return new VideoSplitter();
    }
};