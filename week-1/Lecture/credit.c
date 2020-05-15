#include <stdio.h>
#include <cs50.h>
#include <math.h>

/* DATE: 5/15/2020 @ B | RO*/
/*Define function that check Credit card number*/

int digit_number = 0;
int sum_of_odds = 0;
int sum_of_evens = 0;

void check_card_number(long cn)
{
    printf("CREDIT CARD NUMBER: %li\n", cn);
    long cc = cn;
    while (cc)
    {
        int cif = cc % 10;
        printf("index: %d, value: %d\n", digit_number, cif);
        if (digit_number % 2 == 0)
        {
            sum_of_evens += cif;
        }
        else
        {
            int even_doubled = (cif * 2 > 9) ? ((cif * 2 / 10) + (cif * 2 % 10)) : (cif * 2);
            sum_of_odds += even_doubled;
        }
        cc /= 10;
        digit_number += 1;
    }
    printf("Odd sum: %d\nEven sum: %d", sum_of_odds, sum_of_evens);
    int first_digit = cn / pow(10, digit_number - 1);
    int first_two_digits = cn / pow(10, digit_number - 2);
    if (digit_number < 12)
    {
        printf("INVALID\n");
    }
    else if ((sum_of_odds + sum_of_evens) % 10 != 0)
    {
        printf("INVALID\n");
    }
    else if (first_digit == 4)
    {
        printf("VISA\n");
    }
    else if (first_two_digits == 34 || first_two_digits == 37)
    {
        printf("AMEX\n");
    }
    else if (first_two_digits > 50 && first_two_digits < 56)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int main(void)
{
    long card_number = get_long("Input your credit card \n");
    check_card_number(card_number);
    return 0; // explicitly return 0
}

/* define a function to checksum using Luhn algorithm

* Get number of digits in number?
* iterate through each digit

Based on definitions check first 2 digits and print
if not is_valid_checksum : "INVALID\n"
else if (4): "VISA\n
else if (34 or 37) : "AMEX\n"
else if (51, 52, 53, 54, or 55): "MASTERCARD\n"
*/
