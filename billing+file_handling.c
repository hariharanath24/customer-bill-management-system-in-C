#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct product
{
    int ID;
    char name[100];
    float price;
    int stock;
};

struct customer
{
    int id;
    char n[100];
    long long int phonenumber;
    char address[100];
} s[100];

struct bill
{
    char prod[20];
    int quantity;
    float pr;
    float total;
};

void customeradd()
{
    int n;

    printf("Enter number of customers:\n");
    scanf("%d", &n);

    getchar();

    printf("Enter customer details\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nCustomer %d\n", i + 1);

        printf("Enter customer ID:\n");
        scanf("%d", &s[i].id);

        getchar();

        printf("Enter customer name:\n");
        fgets(s[i].n, sizeof(s[i].n), stdin);
        s[i].n[strcspn(s[i].n, "\n")] = 0;

        printf("Enter phone number:\n");
        scanf("%lld", &s[i].phonenumber);

        getchar();

        printf("Enter address:\n");
        fgets(s[i].address, sizeof(s[i].address), stdin);
        s[i].address[strcspn(s[i].address, "\n")] = 0;
    }

    printf("\nDisplaying customer details\n");

    for (int i = 0; i < n; i++)
    {
        printf("\nCustomer %d\n", i + 1);
        printf("ID: %d\n", s[i].id);
        printf("Name: %s\n", s[i].n);
        printf("Phone: %lld\n", s[i].phonenumber);
        printf("Address: %s\n", s[i].address);
    }
}

int main()
{
    struct bill b[10];
    struct product p[20];

    printf("PRODUCT LIST\n");

    printf("101 Rice\n102 Wheat\n103 Sugar\n104 Salt\n105 Cooking Oil\n106 Tea\n107 Cricket Ball\n108 Milk\n109 Coffee\n110 Onion\n");

    p[0].ID = 101; strcpy(p[0].name, "Rice"); p[0].price = 50.00; p[0].stock = 100;
    p[1].ID = 102; strcpy(p[1].name, "Wheat"); p[1].price = 45.00; p[1].stock = 100;
    p[2].ID = 103; strcpy(p[2].name, "Sugar"); p[2].price = 40.00; p[2].stock = 100;
    p[3].ID = 104; strcpy(p[3].name, "Salt"); p[3].price = 20.00; p[3].stock = 100;
    p[4].ID = 105; strcpy(p[4].name, "Cooking Oil"); p[4].price = 140.00; p[4].stock = 50;
    p[5].ID = 106; strcpy(p[5].name, "Tea"); p[5].price = 220.00; p[5].stock = 50;
    p[6].ID = 107; strcpy(p[6].name, "Cricket Ball"); p[6].price = 35.00; p[6].stock = 50;
    p[7].ID = 108; strcpy(p[7].name, "Milk"); p[7].price = 30.00; p[7].stock = 20;
    p[8].ID = 109; strcpy(p[8].name, "Coffee"); p[8].price = 300.00; p[8].stock = 50;
    p[9].ID = 110; strcpy(p[9].name, "Onion"); p[9].price = 30.00; p[9].stock = 50;

    customeradd();

    int t = 1, j = 0;
    float grandtotal = 0;

    FILE *fp;   

    printf("\nEnter 1 to continue shopping and 0 to exit\n");
    scanf("%d", &t);

    while (t)
    {
        int id, q;
        int found = 0;

        printf("\nEnter product ID:\n");
        scanf("%d", &id);

        for (int i = 0; i < 10; i++)
        {
            if (p[i].ID == id)
            {
                found = 1;

                printf("Product Name: %s\n", p[i].name);
                printf("Price: %.2f\n", p[i].price);
                printf("Available Stock: %d\n", p[i].stock);

                printf("Enter quantity:\n");
                scanf("%d", &q);

                if (q > p[i].stock)
                {
                    printf("Insufficient stock\n");
                    break;
                }

                strcpy(b[j].prod, p[i].name);
                b[j].quantity = q;
                b[j].pr = p[i].price;
                b[j].total = p[i].price * q;

                grandtotal += b[j].total;
                p[i].stock -= q;

                j++;

                printf("Product added to bill\n");
                break;
            }
        }

        if (!found)
        {
            printf("Invalid product ID\n");
        }

        printf("\nEnter 1 to continue shopping and 0 to exit\n");
        scanf("%d", &t);
    }

    // ================= BILL + FILE HANDLING =================

    printf("\n=========== BILL ===========\n");

    printf("%-20s %-10s %-10s %-10s\n",
           "Product", "Quantity", "Price", "Total");


    fp = fopen("bill.txt", "w");

    if (fp == NULL)
    {
        printf("File cannot be created\n");
        exit(1);
    }

    for (int i = 0; i < j; i++)
    {
        printf("%-20s %-10d %-10.2f %-10.2f\n",
               b[i].prod,
               b[i].quantity,
               b[i].pr,
               b[i].total);

        
        fprintf(fp, "%-20s %-10d %-10.2f %-10.2f\n",
                b[i].prod,
                b[i].quantity,
                b[i].pr,
                b[i].total);
    }

    printf("\nGrand Total = %.2f\n", grandtotal);

    
    fprintf(fp, "\nGrand Total = %.2f\n", grandtotal);


    fclose(fp);

   // printf("\nBill saved in bill.txt\n");
    printf("Thank You Visit Again\n");

    return 0;
}