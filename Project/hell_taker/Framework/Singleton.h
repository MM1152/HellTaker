#pragma once
#include "stdafx.h"

template <typename T>
class Singleton {
protected:
	Singleton() = default;

	Singleton(const T& instance) = delete;
	T operator = (T instance) = delete;
	
public:
	static T& Instance() {
		static T instance;
		return instance;
	}
};