#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sodium.h> //requiers libsodium crypto library
#include <math.h>
int gcd(uint32_t a, uint32_t b){  //Calculates Greatest Common Denominator(dividor) of two ints
    int f,gcd;
    for(f=1;f<=a && f<=b;f++){
        if(a%f == 0 && b%f == 0){
            gcd = f;
        }
    }
    return gcd;
}
double calculatePi(int counter, int numCount){ //Calculates Pi based on the fact mentioned in README.md file 
    double ratio = (double) counter / numCount;
    return (double) sqrt(6/ratio);
}
int main (void){
    int i=0,counter=0,numCount=100;
    uint32_t a,b;
    /*  
    ---------------------------- USE ON LINUX IF YOU DON'T WANT TO USE LIBSODIUM
    unsigned int seed;
    FILE* urandom = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(int), 1, urandom);
    fclose(urandom);
    srand(seed);
    ----------------------------
    */
    //srand(time(NULL)); <-- USE IF NOT ON LINUX
    while(i < numCount){
        a = randombytes_uniform(120000);
        b = randombytes_uniform(120000);
        if (gcd(a,b) == 1){
            counter++;
        }
        i++;
    }
    printf("Pi is cca %f !!", calculatePi(counter, numCount));  
}