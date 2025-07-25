#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int hash(char str[], int d)
{
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) 
    {
        sum += (int)str[i];
    }
    int result = sum % d;
    printf("Hash Value: %d\n", result);
    return result;
}

int main() {
    char str[100]; 
    int d;
    printf("Enter hash size: ");
    scanf("%d",&d);
    printf("Enter a string: ");
    scanf("%s",&str); 
    hash(str, d);
    return 0;
}
