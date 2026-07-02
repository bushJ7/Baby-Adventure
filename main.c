#include <stdio.h>
#include <string.h>
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

    int index = find_index(patient, size, target_id);  // FIXED (avoid double call)

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

void add_patient(Patient patient[], int *size){
    if(*size >= MAX_SIZE)   // FIXED
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