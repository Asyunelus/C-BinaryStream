#pragma once
class bofstream
{
	std::ofstream os;
public:
	bofstream();
	bofstream(std::string filePath);
	virtual ~bofstream();

	void open(std::string filePath);

	void writeInt16(short value);
	void writeInt32(int value);
	void writeInt64(long long value);
	void writeSingle(float value);
	void writeDouble(double value);
	void writeString(std::string value);
	void writeWideString(std::wstring value);

	void flush();
	void close();
};
