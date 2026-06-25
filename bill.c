#include <stdio.h>

// Diagnosis list and prices
char *diagnoses[10] = {
    "Flu", "Diabetes", "Hypertension", "Asthma", "COVID-19",
    "Allergy", "Migraine", "Tuberculosis", "Cancer Screening", "Heart Disease"
};
float prices[10] = {50, 200, 150, 120, 300, 80, 100, 250, 400, 500};

// Function to calculate bill
void calculateBill() {
    int choice;
    char more;
    float totalBill = 0.0;

    printf("\nChoose your Diagnoses:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d. %s - $%.2f\n", i + 1, diagnoses[i], prices[i]);
    }

    // Let user select diagnoses
    do {
        printf("\nEnter diagnosis number to check: ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 10) {
            totalBill += prices[choice - 1];
            printf("Added %s ($%.2f)\n", diagnoses[choice - 1], prices[choice - 1]);
        } else {
            printf("Invalid choice!\n");
        }

        printf("Do you want to add another diagnosis? (y/n): ");
        scanf(" %c", &more);

    } while (more == 'y' || more == 'Y');

    // Final bill
    printf("\nFinal Bill: $%.2f\n", totalBill);
}

int main() {
    
    calculateBill();
    return 0;
}
