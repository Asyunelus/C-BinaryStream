#pragma once
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

	void close();
};