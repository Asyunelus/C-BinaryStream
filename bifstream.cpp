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

	char* result = new char[Length];
	is.read(result, Length);
	return result;
}

void bifstream::close()
{
	is.close();
}
