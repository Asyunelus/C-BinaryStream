#pragma once
/* bifstream (binary input stream)
 * Made By Asyunelus (https://github.com/Asyunelus)
 * ifstream�� �̿�, binary ������ �ε��� ���ϰ� �ϴ� Ŭ����
 */
class bifstream
{
	std::ifstream is;
public:
	bifstream();
	bifstream(std::string filePath);
	virtual ~bifstream();

	void open(std::string filePath);

	short readInt16();
	int readInt32();
	long long readInt64();
	float readSingle();
	double readDouble();
	std::string readString();
	std::wstring readWideString();

	bool is_open();

	void close();
};