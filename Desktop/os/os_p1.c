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
    int sum1 = 0;
    int ingredients_required[chef];

    for (int i = 0; i < chef; i++)
    {
        printf(" the number of resources chef %d requires is   : ", i + 1);
        scanf("%d", &ingredients_required[i]);
        sum1 = sum1 + ingredients_required[i];
    }
    if (sum1 == r * chef)
    {
        for (int i = 0; i < chef; i++)
        {
            ingredients_allocated[i] = r - 1;
            printf("the resources allocated to  chef %d : %d \n", i + 1, ingredients_allocated[i]);
        }
    }

    if (sum1 < (r * chef) && sum1 > (r - 1) * chef)
    {
        for (int i = 0; i < chef; i++)
        {
            if (i == 0)
            {
                ingredients_allocated[i] = ingredients_required[i];
                printf("the resources allocated to  chef %d : %d \n", i + 1, ingredients_allocated[i]);
            }
            else
            {
                ingredients_allocated[i] = ingredients_required[i] - 1;
                printf("the resources allocated to  chef %d : %d \n", i + 1, ingredients_allocated[i]);
            }
        }
    }
    if (sum1 <= (r - 1) * chef)
    {
        for (int i = 0; i < chef; i++)
        {
            ingredients_allocated[i] = ingredients_required[i];
            printf("the resource allocated to each chef %d : %d \n", i + 1, ingredients_allocated[i]);
        }
    }

    for (int i = 0; i < chef; i++)
    {
        sum = sum + ingredients_allocated[i];
    }

    if ((sum + 1) > ingredients)
    {
        printf("some chef are requesting more ingredients than the atmost value that is %d ", r);
        printf("There will be deadlock");
        return 0;
    }
    int ingredients_available = ingredients - sum;
    printf("ingredients available is %d\n", ingredients_available);

    for (int i = 0; i < chef; i++)
    {

        printf("chef %d done cooking\n", i + 1);
        ingredients_available = ingredients_allocated[i] + ingredients_available;
        printf("ingredients available is %d\n", ingredients_available);
    }

    return 0;
}
