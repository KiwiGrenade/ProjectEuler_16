/*2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
What is the sum of the digits of the number 2/\1000?*/
#include <iostream>
#include <C:\gmp-6.1.2\gmp.h>                       //Include the GNU MP library
using namespace std;

int main()
{

    mpz_t number,digit,base,digitSum;               //set the variables
    long t;

    mpz_init (number);                              //initiate the variables
    mpz_init (digitSum);
    mpz_init (digit);


    //initiate the variable and set it's value
    mpz_init_set_str (base,"2",10);

    //set the number to the value of 2(base)^1000-1, dunno why
    mpz_mul_2exp (number,base,1000-1);

    //Now, here is the tricky par. We want to divide the number into digits, and
    //add them up, but i don't know how to count the NUMBER of digits, so i just
    //get 700 becouse the .number. clearly has less digits
    for (int i=0;i<700;i++)
    {
        mpz_tdiv_r_ui(digit,number,10);             //digit=number/10;
        mpz_add(digitSum,digitSum,digit);           //digitSum+=digit;
        mpz_tdiv_q_ui(number,number,10);            //number=number/10;
    }
    t=mpz_get_ui(digitSum);                         //convert digitSum to long int

    cout << t;                                      //send the t variable to stream output

    mpz_clear (number);                             //clear the space
    mpz_clear (digitSum);
    mpz_clear (digit);
    mpz_clear(base);

    return 0;
}
