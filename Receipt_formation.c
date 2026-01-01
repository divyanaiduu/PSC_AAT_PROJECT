#include <stdio.h>

int main()
{
    int choice;
    char customerName[50];

    printf("===============================================================================\n");
    printf(" TECH WORLD ELECTRONICS & SERVICE HUB\n");
    printf(" #131, Brigade Road, Bengaluru - 560025 | Ph: +91 9876543210\n");
    printf("===============================================================================\n");

    printf("\n RECEIPT GENERATION SYSTEM - MAIN MENU\n");
    printf(" -------------------------------------\n");
    printf(" 1. Electronics Purchase Receipt\n");
    printf(" 2. Technical Service Receipt\n");
    printf(" 3. Combined Receipt (Both)\n");
    printf(" 4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        char laptopModel[] = "Dell Inspiron 3520";
        char headsetModel[] = "JBL Tune 510BT";
        char chargerModel[] = "Samsung 25W Fast Charger";

        float priceLaptop = 75000.00;
        float priceHeadset = 5500.00;
        float priceCharger = 2500.00;

        float subtotal, gst, total;

        printf("\nEnter Customer Name: ");
        getchar();
        fgets(customerName, sizeof(customerName), stdin);
        subtotal = priceLaptop + priceHeadset + priceCharger;
        gst = subtotal * 0.18;
        total = subtotal + gst;

        printf("\n---------------- ELECTRONICS PURCHASE RECEIPT ----------------\n");
        printf("Customer Name : %s\n", customerName);


        printf("Laptop  (%s)   : Rs %.2f\n", laptopModel, priceLaptop);
        printf("Headset (%s)  : Rs %.2f\n", headsetModel, priceHeadset);
        printf("Charger (%s)  : Rs %.2f\n", chargerModel, priceCharger);
        printf("--------------------------------------------------------------\n");
        printf("Subtotal       : Rs %.2f\n", subtotal);
        printf("GST (18%%)      : Rs %.2f\n", gst);
        printf("TOTAL AMOUNT   : Rs %.2f\n", total);
        printf("--------------------------------------------------------------\n");
    }

    else if (choice == 2)
    {
        char services[4][30] = {
            "Screen Replacement",
            "Battery Change",
            "Software Installation",
            "Cleaning Service"};

        float serviceCharges[4] = {4500, 1800, 1500, 1300};
        float totalServiceCost = 0, discount, gst, finalAmount;

        printf("\nEnter Customer Name: ");

        getchar();
        fgets(customerName, sizeof(customerName), stdin);
        for (int i = 0; i < 4; i++)
        totalServiceCost += serviceCharges[i];

        discount = (totalServiceCost > 2000) ? totalServiceCost * 0.10 : 0;
        gst = (totalServiceCost - discount) * 0.18;
        finalAmount = totalServiceCost - discount + gst;

        printf("\n---------------- TECHNICAL SERVICE RECEIPT ----------------\n");
        printf("Customer Name : %s\n", customerName);
        for (int i = 0; i < 4; i++)
        printf("%d. %-25s Rs %.2f\n", i + 1, services[i], serviceCharges[i]);

        printf("-----------------------------------------------------------\n");
        printf("Service Total  : Rs %.2f\n", totalServiceCost);
        printf("Discount (10%%) : Rs %.2f\n", discount);
        printf("GST (18%%)      : Rs %.2f\n", gst);
        printf("FINAL AMOUNT   : Rs %.2f\n", finalAmount);
        printf("-----------------------------------------------------------\n");
    }

    else if (choice == 3)
    {
        float elecTotal = (75000 + 5500 + 2500) * 1.18;
        float serviceCharges[4] = {4500, 1800, 1500, 1300};
        float serviceSubtotal = 0;

        printf("\nEnter Customer Name: ");
        getchar();
        fgets(customerName, sizeof(customerName), stdin);
        for (int i = 0; i < 4; i++)
        serviceSubtotal += serviceCharges[i];

        float serviceDiscount = serviceSubtotal * 0.10;
        float serviceTotal = (serviceSubtotal - serviceDiscount) * 1.18;

        printf("\n================ COMBINED RECEIPT =================\n");
        printf("Customer Name      : %s\n", customerName);
        printf("Electronics Total  : Rs %.2f\n", elecTotal);
        printf("Service Total      : Rs %.2f\n", serviceTotal);
        printf("GRAND TOTAL        : Rs %.2f\n", elecTotal + serviceTotal);
        printf("==================================================\n");
    }

    else if (choice == 4)
    {
        printf("\nExit... Thank you!\n");
    }
    else
    {
        printf("\nInvalid Choice!\n");
    }

    return 0;
}
