#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int ft_letter_check(char *str);// declaring input check function;

void ft_eat_food(int hp)
{
    struct available_food//declaring food struct;
    {
        char  *name;
        char  *state;
        int   hp_mod;
    };

    struct available_food encountered_food[] = //array of struct var to choose randomly;
    {
        {"stew", "hot", 20},
        {"mushroom", "poisonous", -5},
        {"meat", "rotten", -15},
        {"bread", "stale", 2},
        {"pizza slice", "mouldy and half-eaten", -60},
        {"noodle cup", "glowing green", -99},
        {"GARLIC BREAD", "LEGENDARY", 500},
        {"watermelon slices", "fresh", 45}
    };
    
    srand(time(NULL));
    const int chosen = rand() % 9;//food encounter is randomised;
    printf("You found [%s %s].\n", encountered_food[chosen].state, encountered_food[chosen].name);
    
    
    char food_choice[2];
    printf("Do you want to eat the food ? ");//player choice;
    if (ft_letter_check(food_choice))
    {
        hp = hp + encountered_food[chosen].hp_mod;//remember : adding a neg int == substraction;
        printf("You ate [%s %s]...\t", encountered_food[chosen].state, encountered_food[chosen].name);
        
        if(encountered_food[chosen].hp_mod < 0)
            printf("You lost %d HP !\n", encountered_food[chosen].hp_mod);
        else
            printf("You gained %d HP!\n", encountered_food[chosen].hp_mod);
        
    }
    else
        printf("You decided to not eat... Maybe later ?\n");
    printf("HP : %d\n", hp);
    //return(hp);
}