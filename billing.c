#include <stdio.h>
#include "billing.h"
#include "patient.h"
 
void calculate_bill(Patient patient[], int size){
    char target_id[10];
    prompt_id(target_id);
 
    int index = find_index(patient, size, target_id);  
 
    if(index == -1){
        printf("patient not found\n");
        return;
    }
 
    printf("enter service bill: ");
    scanf("%f", &patient[index].bill.serviceFee);
 
    printf("enter medecine bill: ");
    scanf("%f", &patient[index].bill.medicineCost);
 
    patient[index].bill.totalBill =
        patient[index].bill.serviceFee +
        patient[index].bill.medicineCost;
 
    printf("successfully calculate the bill\n");
}
 
