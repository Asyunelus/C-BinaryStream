#pragma once
/* bofstream (binary output stream)
 * Made By Asyunelus (https://github.com/Asyunelus)
 * ofstream을 이용, binary 형태의 저장을 편하게 하는 클래스
 */

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

	bool is_open();

	void flush();
	void close();
};
