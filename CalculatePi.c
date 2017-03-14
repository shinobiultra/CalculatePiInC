#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <sodium.h> //requiers libsodium crypto library
#include <math.h>

uint32_t randombytes_uniform();

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
    //printf("%d %d\n", counter, numCount);
    //printf("\n%d\n",counter);
    double pi = (double) sqrt(6/ratio);
    return pi;
}

int main (void){
    int i=0,counter=0,numCount=10;
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
        //printf("%d\n%d\n",a,b);
    }
    printf("Pi is cca %f !!", calculatePi(counter, numCount));
    
}