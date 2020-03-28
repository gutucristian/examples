#include "vector.hpp"
#include <stdio.h>

using Data = IVector<1,2,3,4>;
static_assert(IMean<Data>::value == 2.5,"no ok in IMean");
static_assert(myabs(IStDev<Data>::value - 1.118034) < 0.001,"not ok in Stdev");

