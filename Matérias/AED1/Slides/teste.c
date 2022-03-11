#include <stdio.h> 
#include <string.h>
 
void changeString(char str[]); 
 
void main() { 
    char string[]="NO"; 
    printf("\nString: %s\n\n", string); 
    changeString(string); 
    printf("Changed String: %s\n\n", string); 
} 
 
void changeString(char str[]) { 
    strcpy(str,"YES"); 
    printf("Change to: %s\n\n", str); 
}