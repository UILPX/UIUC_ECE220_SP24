#pragma once

#include <stdlib.h>
#include <stdio.h>

#ifndef SP_MAT
#define SP_MAT
#include "sparsemat.h"
#endif


void printt(sp_tuples * mat); // print matrix in tuples format to terminal


int matcmpt(sp_tuples * matA, sp_tuples * matB); //not implemented

