//Question 1: Circuit Analysis (3 resistors in || with V source)  w/ Prompted Input 

#include <stdio.h>

int main(void)
{
    // Constants from question: I2 = 3A for the example.
    const float Iin = 12.0f;   
    const float R1  = 3.0f;    
    const float R2  = 8.0f;    

    // User input for I2 
    float I2;
    printf("Enter I2 (amps) value and press 'Enter': ");
    if (scanf("%f", &I2) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    
    float V2 = I2 * R2; // Calculating V2 via Ohm's Law 

    // Voltage = same for parallel branches ( = V1, V2, V3 & Vin)
    float Vin = V2;
    float V1  = Vin;
    float V3  = Vin;
 
    float I1 = V1 / R1; //Finding I1 via Ohm's Law 
    float I3 = Iin - I1 - I2; // KCL: I3 = Iin - I1 - I2

     
    if (I3 == 0.0f) {  // Establishing div by zero error
        printf("\nResults:\n");
        printf("V_in = %0.2f V\n", Vin);
        printf("I1   = %0.2f A\n", I1);
        printf("I2   = %0.2f A\n", I2);
        printf("I3   = %0.2f A\n", I3);
        printf("R_L  = undefined (I3 = 0)\n"); 
        printf("P_L  = %0.2f W\n", V3 * I3);
        return 0;
    }
    
	float RL = V3 / I3; // RL via Ohm's Law
    float PL = V3 * I3; // P = I • V -> Power Across the Load Resistor. 

    
	//Print Values for I1, I2, I3 and PL based on values for inputed I2
	printf("\nResults:\n");
    printf("V_in = %0.2f V\n", Vin);
    printf("I1   = %0.2f A\n", I1);
    printf("I2   = %0.2f A\n", I2);
    printf("I3   = %0.2f A\n", I3);
    printf("R_L  = %0.2f Ohms\n", RL);
    printf("P_L  = %0.2f W\n", PL);

    return 0;
}
