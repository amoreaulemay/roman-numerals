/// # Roman Numerals Converter in C
///
/// Exercise Overview
///
/// The goal of this exercise is to build a simple Roman numerals converter in the C programming language. This program will perform two major tasks:
///
///     1. Validate that a given string contains valid Roman numerals.
///     2. Convert a string of Roman numerals to an integer.
///
/// This exercise will help you understand string manipulation, regular expressions, and basic algorithmic thinking in C.

/// # Prerequisites
/// - Basic understanding of the C programming language, including pointers and arrays.
/// - Familiarity with standard libraries in C, such as stdio.h and stdlib.h.

// Libraries you need to do this challenge.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <stdbool.h>
#include <string.h>

// Useful constants
#define I 1
#define V 5
#define X 10
#define L 50
#define C 100
#define D 500
#define M 1000

/// # TASK 1: Collecting User Input
///
/// Write a function `void roman_number_entry(char **input)` that:
/// - Prompts the user to enter a string of Roman numerals
/// - Collects this string character by character, storing it in a dynamically allocated array.
/// - Makes sure the array resizes if it runs out of space.

void roman_number_entry(char **input)
{
    // TODO: Implement this function.
}

/// # Task 2: Validate Roman Numeral Characters
///
/// Write a function bool `validate_roman_numeral_characters(const char *str)` that:
/// - Uses regular expressions to ensure that the string only contains the characters for Roman numerals (I, V, X, L, C, D, M).

bool validate_roman_numeral_characters(const char *str, regex_t *regex)
{
    // TODO: Implement this function.
    return false;
}

/// # Task 3: Validate Roman Numerals
///
/// Write a function `bool validate_roman_number(const char *str)` that:
/// - Checks for invalid Roman numeral combinations.
/// - For example, it should reject strings like "IIII" or "VV" or "XXXX".
/// - It should also reject invalid subtractive combinations like "IC" or "DM".

bool validate_roman_number(const char *str)
{
    // TODO: Implement this function.
    return false;
}

/// # Task 4: Convert Roman Numerals to Integer
///
/// Write a function `int roman_to_integer(const char *str)` that:
/// - Converts the validated Roman numeral string to its integer equivalent.
/// - Returns `-1` if the conversion fails for some reason.

int roman_to_integer(const char *str)
{
    // TODO: Implement this function.
    return 0;
}

/// # Task 5: Putting it all together
///
/// In the `main()` function:
/// - Collect the user input.
/// - Validate the Roman numeral string both in terms of character content and combination logic.
/// - If the string is valid, convert it to an integer and print the integer.
/// - If the string is invalid, prompt the user to enter it again.

int main(void)
{
    // TODO: Implement this function.
    return 0;
}



