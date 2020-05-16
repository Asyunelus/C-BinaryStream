#include "stdafx.h"

bofstream::bofstream()
{
}

bofstream::bofstream(std::string filePath)
{
	open(filePath);
}

bofstream::~bofstream()
{
}

void bofstream::open(std::string filePath)
{
	os.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));
	os.open(filePath, std::ios::binary);
}

void bofstream::writeInt16(short value)
{
	os.write(reinterpret_cast<char*>(&value), sizeof(short));
}

void bofstream::writeInt32(int value)
{
	os.write(reinterpret_cast<char*>(&value), sizeof(int));
}

void bofstream::writeInt64(long long value)
{
	os.write(reinterpret_cast<char*>(&value), sizeof(long long));
}

void bofstream::writeSingle(float value)
{
	os.write(reinterpret_cast<char*>(&value), sizeof(float));
}

void bofstream::writeDouble(double value)
{
	os.write(reinterpret_cast<char*>(&value), sizeof(double));
}

void bofstream::writeString(std::string value)
{
	writeInt32(value.length());
	os.write(&value[0], value.length());
}

void bofstream::writeWideString(std::wstring wvalue)
{
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::string value = converter.to_bytes(wvalue);
	writeInt32(value.length());
	os.write(&value[0], value.length());
	os.flush();
}

void bofstream::flush()
{
	os.flush();
}

void bofstream::close()
{
	os.close();
}