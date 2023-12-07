#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Medicine {
    char name[50];
    char symptoms[100];
    int availability;
    float price;
    struct Medicine* next;
};


struct BillItem {
    char name[50];
    int quantity;
    float price;
    struct BillItem* next;
};


struct Bill {
    struct BillItem* head;
    float totalAmount;
};


void initializeMedicineList(struct Medicine** head) {
    *head = NULL;
}


void initializeBill(struct Bill* bill) {
    bill->head = NULL;
    bill->totalAmount = 0;
}


void addMedicine(struct Medicine** head, char name[], char symptoms[], int availability, float price) {
    struct Medicine* newMedicine = (struct Medicine*)malloc(sizeof(struct Medicine));
    strcpy(newMedicine->name, name);
    strcpy(newMedicine->symptoms, symptoms);
    newMedicine->availability = availability;
    newMedicine->price = price;
    newMedicine->next = *head;
    *head = newMedicine;
}


struct Medicine* searchMedicine(struct Medicine* head, char name[]) {
    while (head != NULL) {
        if (strcmp(head->name, name) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


void displayMedicine(struct Medicine* medicine) {
    if (medicine != NULL) {
        printf("Name: %s\n", medicine->name);
        printf("Symptoms: %s\n", medicine->symptoms);
        printf("Availability: %d\n", medicine->availability);
        printf("Price: %.2f\n", medicine->price);
    } else {
        printf("Medicine not found.\n");
    }
}


void displayMedicineList(struct Medicine* head) {
    while (head != NULL) {
        displayMedicine(head);
        head = head->next;
    }
}

void addToBill(struct Bill* bill, char name[], int quantity, float price) {
    struct BillItem* newItem = (struct BillItem*)malloc(sizeof(struct BillItem));
    strcpy(newItem->name, name);
    newItem->quantity = quantity;
    newItem->price = price;
    newItem->next = bill->head;
    bill->head = newItem;
    bill->totalAmount += (quantity * price);
}


void displayBill(struct Bill* bill) {
    struct BillItem* currentItem = bill->head;
    while (currentItem != NULL) {
        printf("Item: %s | Quantity: %d | Price: %.2f\n", currentItem->name, currentItem->quantity, currentItem->price);
        currentItem = currentItem->next;
    }
    printf("Total Amount: %.2f\n", bill->totalAmount);
}


void findMedicinesBySymptoms(struct Medicine* head, char symptoms[]) {
    while (head != NULL) {
        if (strstr(head->symptoms, symptoms) != NULL) {
            displayMedicine(head);
        }
        head = head->next;
    }
}

int main() {
    struct Medicine* medicineList;
    initializeMedicineList(&medicineList);


    addMedicine(&medicineList, "Paracetamol", "Headache Fever", 100, 10.5);
    addMedicine(&medicineList, "Aspirin", "Pain Fever", 50, 5.0);
    addMedicine(&medicineList, "Ibuprofen", "Pain Fever", 75, 8.75);

    int choice;
    char medicineName[50];
    char symptoms[100];
    int quantity;

    struct Bill customerBill;
    initializeBill(&customerBill);

    do {
        printf("\n\n\n\t\t\t Medical Store Management System\t\t\t\n\n\n");
        printf("\t\t\t1. Search for a Medicine\t\t\t\n\n\n");
        printf("\t\t\t2. Display Medicine List\t\t\t\n\n\n");
        printf("\t\t\t3. Add Medicine to Bill\t\t\t\n\n\n");
        printf("\t\t\t4. Generate Bill\t\t\t\n\n\n");
        printf("\t\t\t5. Find Medicines by Symptoms\t\t\t\n\n\n");
        printf("\t\t\t6. Exit\t\t\t\n\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the medicine: ");
                scanf("%s", medicineName);
                struct Medicine* foundMedicine = searchMedicine(medicineList, medicineName);
                displayMedicine(foundMedicine);
                break;
            case 2:
                displayMedicineList(medicineList);
                break;
            case 3:
                printf("Enter the name of the medicine: ");
                scanf("%s", medicineName);
                struct Medicine* selectedMedicine = searchMedicine(medicineList, medicineName);
                if (selectedMedicine != NULL) {
                    printf("Enter the quantity: ");
                    scanf("%d", &quantity);
                    addToBill(&customerBill, selectedMedicine->name, quantity, selectedMedicine->price);
                    printf("%s added to the bill.\n", selectedMedicine->name);
                } else {
                    printf("Medicine not found.\n");
                }
                break;
            case 4:
                printf("\nCustomer Bill\n");
                displayBill(&customerBill);
                break;
            case 5:
                printf("Enter the symptoms: ");
                getchar();
                fgets(symptoms, sizeof(symptoms), stdin);
                if (symptoms[strlen(symptoms) - 1] == '\n') {
                    symptoms[strlen(symptoms) - 1] = '\0';
                }
                printf("\nMedicines for the given symptoms:\n");
                findMedicinesBySymptoms(medicineList, symptoms);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 6);

    return 0;
}
