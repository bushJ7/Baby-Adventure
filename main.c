#include <stdio.h>
#include <string.h>
const int MAX_SIZE = 100;
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
void search_patient(Patient patient[],int size){
    char target_id[10];
    prompt_id(target_id);
    int i = find_index(patient,size,target_id);
    if (i==-1){
        printf("patient not found\n");
        return;
    }
    printf("+-----------+----------------------+-----+------------------------+------------+----------------------+-------------+- -------------+--------------+\n");
    printf("| %-9s | %-20s | %-3s | %-22s | %-10s | %-20s | %-11s | %-12s | %-12s |\n",
           "ID", "Name", "Age", "Symptom", "Status", "Doctor", "Service Fee", "Medicine", "Total Bill");
    printf("+-----------+----------------------+-----+------------------------+------------+----------------------+-------------+--------------+--------------+\n");
    printf("| %-9s | %-20s | %-3d | %-22s | %-10s | %-20s | %-11.2f | %-12.2f | %-12.2f |\n",
            patient[i].patient_id,
            patient[i].name,
            patient[i].age,
            patient[i].symptom,
            patient[i].status,
            patient[i].dr.dr_name,
            patient[i].bill.serviceFee,
            patient[i].bill.medicineCost,
            patient[i].bill.totalBill);
    printf("+-----------+----------------------+-----+------------------------+------------+----------------------+-------------+--------------+--------------+\n");
}
void update_status(Patient patient[],int size){
    char target_id[10];
    prompt_id(target_id);
    printf("\n--- Update Patient Health Status ---\n");
    int index = find_index(patient, size, target_id);
    if (index == -1) {
        printf("Patient record not found.\n");
        return;
    }

    if (strcmp(patient[index].status, "Discharged") == 0) {
        printf("Validation Error: Patient already discharged from facility.\n");
        return;
    }

    printf("Enter New Status (e.g., Stable, Critical, Under Observation): ");
    fgets(patient[index].status, sizeof(patient[index].status), stdin);
    patient[index].status[strcspn(patient[index].status, "\n")] = '\0';
    printf("Success: Status updated to '%s'.\n", patient[index].status);
}