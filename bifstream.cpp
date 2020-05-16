#include "stdafx.h"

bifstream::bifstream()
{
}

bifstream::bifstream(std::string filePath)
{
	open(filePath);
}

bifstream::~bifstream()
{
}

void bifstream::open(std::string filePath)
{
	is.imbue(std::locale(std::locale::empty(), new std::codecvt_utf8<wchar_t, 0x10ffff, std::generate_header>));
	is.open(filePath, std::ios::binary);
}

short bifstream::readInt16()
{
	short result;
	is.read(reinterpret_cast<char*>(&result), sizeof(short));
	return result;
}

int bifstream::readInt32()
{
	int result;
	is.read(reinterpret_cast<char*>(&result), sizeof(int));
	return result;
}

long long bifstream::readInt64()
{
	long long result;
	is.read(reinterpret_cast<char*>(&result), sizeof(long long));
	return result;
}

float bifstream::readSingle()
{
	float result;
	is.read(reinterpret_cast<char*>(&result), sizeof(float));
	return result;
}

double bifstream::readDouble()
{
	double result;
	is.read(reinterpret_cast<char*>(&result), sizeof(double));
	return result;
}

std::string bifstream::readString()
{
	int Length = readInt32();
	std::string result;
	result.resize(Length);
	is.read(&result[0], Length);
	return result;
}

std::wstring bifstream::readWideString()
{
	int Length = readInt32();
	std::string result;
	result.resize(Length);
	is.read(&result[0], Length);
	std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
	std::wstring wresult = converter.from_bytes(result);
	return wresult;
}

void bifstream::close()
{
	is.close();
}