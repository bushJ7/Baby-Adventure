#include <stdio.h>
#include "file.h"
 
void record_info(Patient patient[], int size){
    FILE *ptr = fopen("patient_information.txt","w");
    if(ptr == NULL){
        printf("Cannot open file!\n");
        return;
    }
    
    fprintf(ptr,
    "ID|Name|Age|Symptom|Status|Diagnosis|Doctor|Service Fee|Medicine|Total Bill\n");
    for(int i = 0; i < size; i++){
        fprintf(ptr,
        "%s|%s|%d|%s|%s|%s|%s|%.2f|%.2f|%.2f\n",
        patient[i].patient_id,
        patient[i].name,
        patient[i].age,
        patient[i].symptom,
        patient[i].status,
        patient[i].diagnose,
        patient[i].dr.dr_name,
        patient[i].bill.serviceFee,
        patient[i].bill.medicineCost,
        patient[i].bill.totalBill);
    }
    fclose(ptr);
}
 
void load_data(Patient patient[], int *patient_amount){
    FILE *ptr = fopen("patient_information.txt", "r");
    if(ptr == NULL){
        return;
    }
    char header[200];
    fgets(header, sizeof(header), ptr);   
    int i = 0;
    while(
        fscanf(ptr,
        "%9[^|]|%49[^|]|%d|%39[^|]|%29[^|]|%29[^|]|%39[^|]|%f|%f|%f\n",
        patient[i].patient_id,
        patient[i].name,
        &patient[i].age,
        patient[i].symptom,
        patient[i].status,
        patient[i].diagnose,
        patient[i].dr.dr_name,
        &patient[i].bill.serviceFee,
        &patient[i].bill.medicineCost,
        &patient[i].bill.totalBill
        ) == 10)
    {
        i++;
 
        if(i >= MAX_SIZE)
            break;
    }
 
    *patient_amount = i;
    fclose(ptr);
    printf("[System] Loaded %d patient records.\n", *patient_amount);
}