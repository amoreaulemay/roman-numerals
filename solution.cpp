//
//  solution.cpp
//  roman-numerals
//
//  Created by Alexandre Moreau-Lemay on 23/09/2023.
//

#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

int char_to_value(char c)
{
    switch (c)
    {
        case 'I': return I;
        case 'V': return V;
        case 'X': return X;
        case 'L': return L;
        case 'C': return C;
        case 'D': return D;
        case 'M': return M;
        default: return -1;
    }
}

void roman_number_entry(char **input)
{
    char c;
    int len = 0;
    int capacity = 10; // Initialize with some capacity
    *input = (char*) malloc(capacity * sizeof(char));
    
    if (*input == NULL)
    {
        printf("Failed to allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    
    printf("Enter a roman numeral: ");
    while (true)
    {
        c = getchar();
        
        // Breaking the loop on a new line or EOF
        if (c == EOF || c == '\n')
        {
            break;
        }
        
        if (len >= capacity - 1)
        { // Leave room for null terminator
            capacity *= 2;
            char *newInput = (char *)realloc(*input, capacity);
            if (newInput == NULL)
            {
                printf("Failed to allocate memory.\n");
                free(*input);
                exit(EXIT_FAILURE);
            }
            *input = newInput;
        }
        
        (*input)[len] = c;
        len++;
    }
    
    (*input)[len] = '\0';  // Null-terminate the string
}

bool validate_roman_numeral_characters(const char *str, regex_t *regex)
{
    int reti = regexec(regex, str, 0, NULL, 0);
    return reti == 0;
}

bool validate_roman_number(const char *str)
{
    if (str == NULL)
    {
        return false;
    }
    
    char last_char = 0;
    int last_value = 0;
    
    while (*str)
    {
        int value = char_to_value(*str);
        if (value == -1) return false;
        
        if (last_value && last_value < value)
        {
            if (!(last_value * 5 == value || last_value * 10 == value))
            {
                return false;
            }
        }
        
        last_char = *str;
        last_value = value;
        str++;
    }
    
    return true;
}

int roman_to_integer(const char *str)
{
    int total = 0;
    int last_value = 0;
    
    while (*str)
    {
        int value = char_to_value(*str);
        if (value == -1) return -1;
        
        total += value;
        if (last_value && last_value < value)
        {
            total -= 2 * last_value;
        }
        
        last_value = value;
        str++;
    }
    
    return total;
}

int main(void)
{
    char *input = NULL;
    regex_t regex;
    
    // Compile the regex once
    const char *pattern = "^[IVXLCDM]+$";
    if (regcomp(&regex, pattern, REG_EXTENDED))
    {
        fprintf(stderr, "Could not compile regex\n");
        exit(EXIT_FAILURE);
    }
    
    while (true)
    {
        roman_number_entry(&input);
        
        if (!validate_roman_numeral_characters(input, &regex) || !validate_roman_number(input))
        {
            printf("The entered value is not a valid Roman numeral!\n");
            continue;
        }
        
        int integer_value = roman_to_integer(input);
        if (integer_value == -1)
        {
            printf("An error occurred while converting the Roman numeral to an integer.\n");
            continue;
        }
        
        printf("The integer value of the Roman numeral is: %d\n", integer_value);
        break;
    }
    
    free(input);
    regfree(&regex);  // Don't forget to free the regex
    return 0;
}


