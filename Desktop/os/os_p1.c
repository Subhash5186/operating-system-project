#include <stdio.h>

int main()
{
    int chef, r, ingredients, sum = 0, count = 0;

    printf("enter no. of chefs ");

    scanf("%d", &chef);

    printf("enter  atmost no. of ingredients a chef  can have ");

    scanf("%d", &r);

    ingredients = (chef * (r - 1)) + 1;

    int ingredients_allocated[chef];

    for (int i = 0; i < chef; i++)
    {
        printf("enter ingredients_allocated for chef %d ", i + 1);
        scanf("%d", &ingredients_allocated[i]);
        /* if(ingredients_allocated[i]>r){
             printf("Chef can take atmost r ingredients ")
             return 0;
         }*/
    }
    for (int i = 0; i < chef; i++)
    {
        sum = sum + ingredients_allocated[i];
    }

    if ((sum - chef + 1) > ingredients)
    {
        printf("some chef are requesting more ingredients than the atmost value that is %d so there will be deadlock", r);
        return 0;
    }
    int ingredients_available = 0;
    int a = ingredients - sum;
    if (a > 0)
    {
        int ingredients_available = ingredients - sum;
    }
    else
    {
        int ingredients_available = ingredients - (sum - chef);
    }

    for (int i = 0; i < chef; i++)
    {
        printf("ingredients available is %d\n", ingredients_available);
        printf("chef %d done cooking\n", i + 1);
        ingredients_available = ingredients_allocated[i] + ingredients_available;
        count++;
    }

    return 0;
}
