#include <stdio.h>
#include<string.h>
typedef struct {
    char dr_name[40];
    char specialty[40];
}Doctor;
typedef struct{
    float medicineCost;
    float serviceFee;
    float totalBill;
}Bill;
typedef struct{
    char patient_id[10];
    char name[50];
    int age;
    char symptom[40];
    char status[30];
    char diagnose[30];
    Bill bill;
    Doctor dr;
}Patient;
void prompt_id(char id[]);
void add_patient(Patient patient[],int *size);
void search_patient(Patient patient[],int size);
void discharge(Patient patient[],int size);
void load_data(Patient patient[],int *size);
void record_info(Patient patient[],int size);
void assign_doctor(Patient patient[],int size,Doctor Dr[],int dr_amount);
void calculate_bill(Patient patient[],int size);
void update_status(Patient patient[],int size);
int find_index(Patient patient[],int size,char target_id[]);
void display(Patient patient[],int size);
void main(){

}
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
}
void discharge(Patient patient[],int size){
    
    char target_id[10];
    prompt_id(target_id);
    if(find_index(patient,size,target_id)==-1){
        printf("patient not exist!\n");
        return ;
    }
    int index = find_index(patient,size,target_id);
    if(patient[index].bill.totalBill==0){
        printf("you hasn't calculate patient's bill yet!\n");
        return;
    }
    printf("enter final diagnose: ");
    fgets(patient[index].diagnose,sizeof(patient[index].diagnose),stdin);
    patient[index].diagnose[strcspn(patient[index].diagnose,"\n")] = '\0';
    strcpy(patient[index].status,"Discharged");
    printf("\n==================================================\n");
    printf("           PATIENT DISCHARGE SUMMARY REPORT       \n");
    printf("==================================================\n");
    printf(" Patient ID         : %s\n", patient[index].patient_id);
    printf(" Patient Name       : %s\n", patient[index].name);
    printf(" Age                : %d\n", patient[index].age);
    printf(" Status             : %s\n", patient[index].status);
    printf(" Responsible Doctor : %s\n", patient[index].dr.dr_name);
    printf(" Final Diagnosis    : %s\n", patient[index].diagnose);
    printf("--------------------------------------------------\n");
    printf(" FINANCIAL BREAKDOWN:\n");
    printf("   Medicine Charges : $%.2f\n", patient[index].bill.medicineCost);
    printf("   Service/Treat Fee: $%.2f\n", patient[index].bill.serviceFee);
    printf("--------------------------------------------------\n");
    printf(" TOTAL AMOUNT DUE : $%.2f\n", patient[index].bill.totalBill);
    printf("==================================================\n");
    printf("Patient file finalized successfully.\n");
}