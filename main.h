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
#elif defined(LAB3_ZAD2_SOLUTION)
    #include "Lab3_z2.h"
    void (*solve)(void) = solveLab3Z2; 
#elif defined(LAB3_ZAD3_SOLUTION)
    #include "Lab3_z3.h"
    void (*solve)(void) = solveLab3Z3; 
#elif defined(LAB3_ZAD4_SOLUTION)
    #include "Lab3_z4.h"
    void (*solve)(void) = solveLab3Z4; 
#elif defined(LAB3_ZAD5_SOLUTION)
    #include "Lab3_z5.h"
    void (*solve)(void) = solveLab3Z5; 
#elif defined(LAB4_ZAD1_SOLUTION)
    #include "Lab4_z1.h"
    void (*solve)(void) = solveLab4Z1; 
#elif defined(LAB4_ZAD2_SOLUTION)
    #include "Lab4_z2.h"
    void (*solve)(void) = solveLab4Z2; 
#elif defined(LAB4_ZAD3_SOLUTION)
    #include "Lab4_z3.h"
    void (*solve)(void) = solveLab4Z3; 
#elif defined(LAB4_ZAD4_SOLUTION)
    #include "Lab4_z4.h"
    void (*solve)(void) = solveLab4Z4; 
#endif