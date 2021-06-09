#include <string>
#include <iostream>
#include "FileSplitter2.hpp"
using std::string;

// 多继承 (一般不推荐使用)
class MainForm : public Form, public IProgress
{
	TextBox *txtFilePath;
	TextBox *txtFileNumber;

	ProgressBar *progressBar;

public:
	void Button1_Click()
	{

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		ConsoleNotifier cn;

		FileSplitter splitter(filePath, number);
		
		// 将对象添加到观察者 list 中
		splitter.addIProgress(this); //订阅通知
		splitter.addIProgress(&cn);	 //订阅通知

		splitter.split();

		splitter.removeIProgress(this);
	}

	virtual void DoProgress(float value)
	{
		progressBar->setValue(value);
	}
};

class ConsoleNotifier : public IProgress
{
public:
	virtual void DoProgress(float value)
	{
		std::cout << ".";
	}
};
