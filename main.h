#include <stdio.h>
#include <math.h>
#include <ProjectConfig.h>

#ifdef LAB3_ZAD1_SOLUTION
    #include "Lab3_z1.h"
    void (*solve)(void) = solveLab3Z1; 
#endif