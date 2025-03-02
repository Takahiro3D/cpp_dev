#include "myabs.hpp"

int myabs(int value){
	if (value < 0){
		value = value * (-1);
	} else {
		return value;
	}
	return value;
}
