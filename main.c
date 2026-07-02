#include <stdio.h>
struct Patient{
    int patient_id;
    char name[50];
    int age;
    char diagnosis[100];
    char doctor[50];
};
// ly heang
void add_patient(int size,int amount,struct Patient patients[]);
// ronith
void delete_patient(int id,int size,struct Patient patients[]);
// sithika
void search(int id,int size,struct Patient patients[]);
// kimnai
void update_status(int id,int size,struct Patient patients[]);


void calculate_bill(Patient patient[],int size){
    char target_id[10];
    prompt_id(target_id);
    if(find_index(patient,size,target_id)==-1){
        printf("patient not found\n");
        return;
    }
    int index = find_index(patient,size,target_id);
    printf("enter service bill: ");scanf("%f",&patient[index].bill.serviceFee);
    printf("enter medecine bill: ");scanf("%f",&patient[index].bill.medicineCost);
    patient[index].bill.totalBill = patient[index].bill.serviceFee + patient[index].bill.medicineCost;
    printf("successfully calculate the bill\n");