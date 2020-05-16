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
	os.write(value.c_str(), value.length());
}

void bofstream::flush()
{
	os.flush();
}

void bofstream::close()
{
	os.close();
}
