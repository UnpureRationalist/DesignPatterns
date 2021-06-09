#include <string>
using std::string;

class FileSplitter
{
	string m_filePath;
	int m_fileNumber;
	ProgressBar *m_progressBar; // 具体的通知控件

public:
	FileSplitter(const string &filePath, int fileNumber, ProgressBar *progressBar) : m_filePath(filePath),
																					 m_fileNumber(fileNumber),
																					 m_progressBar(progressBar)
	{
	}

	void split()
	{

		//1.读取大文件

		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++)
		{
			//...
			float progressValue = m_fileNumber;
			progressValue = (i + 1) / progressValue;
			m_progressBar->setValue(progressValue); // 更新进度条
		}
	}
};