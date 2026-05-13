#include <stdio.h>
#include <string.h>
struct product{
    int ID;
    char name[100];
    float price;
    int stock;
};
int main() {
    struct product p[20];
    //Rice
    p[1].ID=101;
    strcpy(p[1].name,"Rice");
    p[1].price=50.00;
    p[1].stock=100;
    
    //Wheat
    strcpy(p[2].name,"Wheat");
    p[2].price=50.00;
    p[2].ID=102;
    p[2].stock=100;
    //Sugar
    strcpy(p[3].name,"Sugar");
    p[3].price=45.00;
    p[3].ID=103;
    p[3].stock=100;
    //Salt
    strcpy(p[4].name,"Salt");
    p[4].price=20.00;
    p[4].ID=104;
    p[4].stock=100;
    //Cooking oil
    strcpy(p[5].name,"Cooking oil");
    p[5].price=140.00;
    p[5].ID=105;
    p[5].stock=50;
    //Tea
    strcpy(p[6].name,"Tea");
    p[6].price=220.00;
    p[6].ID=106;
    p[6].stock=50;
    //Cricket Ball
    strcpy(p[7].name,"Cricket Ball");
    p[7].price=35.00;
    p[7].ID=107;
    p[7].stock=50;
    //Milk
    strcpy(p[8].name,"Milk");
    p[8].price=30.00;
    p[8].ID=108;
    p[8].stock=20;
    //Coffee
    strcpy(p[9].name,"Coffee");
    p[9].price=30.00;
    p[9].ID=109;
    p[9].stock=50;
    //Onion
    strcpy(p[10].name,"Onion");
    p[10].price=30.00;
    p[10].ID=110;
    p[10].stock=50;
    printf("Enter product ID\n");
    int id;
    scanf("%d",&id);
    for(int i = 1; i <= 10; i++)
{
    if(p[i].ID==id){

        printf("ID: %d\n", p[i].ID);
        printf("Name: %s\n", p[i].name);
        printf("Price: %.2f\n", p[i].price);
        printf("Stock: %d\n\n", p[i].stock);
    }
}

    return 0;
}
