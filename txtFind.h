#ifndef TXT_FIND_H
#define TXT_FIND_H

/**
 * Input: Array of chars (String)
 * Output: num of this string chars
 * Of The Record: build the array from the stdin
*/
int GetLine(char s[]);
/**
 * Input: Array of chars (String)
 * Output: num of this word chars
 * Simultaneously: build the array from the stdin
*/ 
int GetWord(char s[]);
/**
 * Input: Strings pointers s1,s2
 * Output: If s1 is substring of s2 Then print 1 
 * Otherwise print 0
 * Simultaneously: build the array from the stdin
*/ 
int substring( char * str1, char * str2);
/**
 * Input: Strings pointers s1,s2 And Integer n
 * Output: If s2 is similar to s1 by removing at most n chars
 * If it does print 1
 * Otherwise print 0
*/
int similar (char *s, char *t, int n);
/**
 * Input: String and texts lines
 * Output: Lines that the string exists
*/
void print_lines(char * str);
/**
 * Input: string pointer and index range
 * Output: the whole string
*/
void print_strAsIs(char a[],int count);
/**
 * Input: string pointer and stdin
 * Output: All the similar word with difference of at least 1
*/
void print_similar_words(char * str);
/**
 * Input: string operation and string name
 * Output:If operation is a then print lines
 * otherwise operation is b then print similar words
*/
void SpecificTextParser();

#endif