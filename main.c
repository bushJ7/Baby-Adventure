#include <stdio.h>
#include <string.h>
const int MAX_SIZE = 100;
#define MAX_SIZE 100   
typedef struct {
    char dr_name[40];
    char specialty[40];
} Doctor;

typedef struct {
    float medicineCost;
    float serviceFee;
    float totalBill;
} Bill;

typedef struct {
    char patient_id[10];
    char name[50];
    int age;
    char symptom[40];
    char status[30];
    char diagnose[30];
    Bill bill;
    Doctor dr;
} Patient;

void prompt_id(char id[]){
    printf("enter patient id: ");
    fgets(id, 10, stdin);
    id[strcspn(id, "\n")] = '\0';
}
void add_patient(Patient patient[], int *size);
void search_patient(Patient patient[], int size);
void discharge(Patient patient[], int size);
void load_data(Patient patient[], int *size);
void record_info(Patient patient[], int size);
void assign_doctor(Patient patient[], int size, Doctor Dr[], int dr_amount);
void calculate_bill(Patient patient[], int size);
void update_status(Patient patient[], int size);
int find_index(Patient patient[], int size, char target_id[]){
    for(int i = 0; i < size; i++){
        if(strcmp(patient[i].patient_id, target_id) == 0){
            return i;
        }
    }
    return -1;
}
void display(Patient patient[], int size);
int main()
{
    printf("Program is running!\n");
    return 0;
}
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

void display(Patient patient[], int size) {
    if (size == 0) {
        printf("No patient records found.\n");
        return;
    }

    printf("\n");
    printf("+-----------+----------------------+-----+------------------------+------------+----------------------+-------------+--------------+--------------+\n");
    printf("| %-9s | %-20s | %-3s | %-22s | %-10s | %-20s | %-11s | %-12s | %-12s |\n",
           "ID", "Name", "Age", "Symptom", "Status", "Doctor", "Service Fee", "Medicine", "Total Bill");
    printf("+-----------+----------------------+-----+------------------------+------------+----------------------+-------------+--------------+--------------+\n");
    for (int i = 0; i < size; i++) {
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
    }
    printf("+-----------+----------------------+-----+------------------------+------------+----------------------+-------------+--------------+--------------+\n");
}

void add_patient(Patient patient[], int *size){
    if(*size >= MAX_SIZE) 
    {
        printf("the patient's data is full!\n");
        return;
    }

    int curren_index = *size;

    printf("=========================\n");
    printf("enter your name: ");
    fgets(patient[curren_index].name, sizeof(patient[curren_index].name), stdin);
    patient[curren_index].name[strcspn(patient[curren_index].name, "\n")] = '\0';

    printf("enter your id: ");
    fgets(patient[curren_index].patient_id, sizeof(patient[curren_index].patient_id), stdin);
    patient[curren_index].patient_id[strcspn(patient[curren_index].patient_id, "\n")] = '\0';

    printf("enter your age: ");
    scanf("%d", &patient[curren_index].age);
    while (getchar() != '\n');

    printf("enter symptom: ");
    fgets(patient[curren_index].symptom, sizeof(patient[curren_index].symptom), stdin);
    patient[curren_index].symptom[strcspn(patient[curren_index].symptom, "\n")] = '\0';

    strcpy(patient[curren_index].status, "waiting");
    patient[curren_index].bill.medicineCost = 0;
    patient[curren_index].bill.serviceFee = 0;
    patient[curren_index].bill.totalBill = 0;

    strcpy(patient[curren_index].dr.dr_name, "N/A");
    strcpy(patient[curren_index].diagnose, "N/A");
    *size = *size + 1;
    printf("patient info added successfully!\n");
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

void record_info(Patient patient[], int size){
    FILE *ptr = fopen("patient_information.txt","w");
    if(ptr == NULL){
        printf("Cannot open file!\n");
        return;
    }
    // Header
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