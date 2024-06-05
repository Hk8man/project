#pragma once
#include "Usercheck.h"

class RuntimeException {
private:
	string errorMsg;
public:
	RuntimeException(const string& err) { errorMsg = err; } string getMessage() const { return errorMsg; }
};

// TimeInvalid("msg")
class TimeInvalid : public RuntimeException {
public:
	TimeInvalid(const string& err) : RuntimeException(err) { }
};

class DataLoadError : public RuntimeException {
public:
	DataLoadError(const string& err) : RuntimeException(err) { }
};

class SelectionInvalid : public RuntimeException {
public:
	SelectionInvalid(const string& err) : RuntimeException(err) { }
};

class Noexisting : public RuntimeException {
public:
	Noexisting(const string& err) : RuntimeException(err) { }
};