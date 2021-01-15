#include <stdio.h>
#include <math.h>
#include <ProjectConfig.h>

#if defined(LAB3_ZAD1_SOLUTION)
    #include "Lab3_z1.h"
    void (*solve)(void) = solveLab3Z1; 
#elif defined(LAB3_ZAD1A_SOLUTION)
    #include "Lab3_z1a.h"
    void (*solve)(void) = solveLab3Z1a; 
#elif defined(LAB3_ZAD1B_SOLUTION)
    #include "Lab3_z1b.h"
    void (*solve)(void) = solveLab3Z1b; 
#endif