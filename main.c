#include <stdio.h>
#include <string.h>
const int MAX_SIZE = 100;   
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

void prompt_id(char id[]);
void add_patient(Patient patient[], int *size);
void search_patient(Patient patient[], int size);
void discharge(Patient patient[], int size);
void load_data(Patient patient[], int *size);
void record_info(Patient patient[], int size);
void assign_doctor(Patient patient[], int size, Doctor Dr[], int dr_amount);
void calculate_bill(Patient patient[], int size);
void update_status(Patient patient[], int size);
int find_index(Patient patient[], int size, char target_id[]);
void display(Patient patient[], int size);
int main()
{
    Patient patient[MAX_SIZE];
    Doctor hospitalDoctors[5] = {
    {"Dr. Alex Smith" ,"Practitioner"},
    {"Dr. Morgan Jones", "Cardiologist"},
    {"Dr. Taylor Reed", "Pediatrician"},
    {"Dr. Jordan Lee", "Orthopedist"},
    {"Dr. Casey Park", "Neurologist"}
};
    int amount_of_DR = 5;
    int patient_amount = 0;
    load_data(patient,&patient_amount);
    int choice;
    do {
        printf("\n=========================================\n");
        printf("     HOSPITAL PATIENT RECORD SYSTEM      \n");
        printf("=========================================\n");
        printf("1. Add New Patient Record\n");
        printf("2. display all the patient\n");
        printf("3. Search Patient Record\n");
        printf("4. Update Patient Status\n");
        printf("5. Assign Doctor to Patient\n");
        printf("6. Calculate Patient Bill\n");
        printf("7. Discharge Patient & Print Report\n");
        printf("8. Save and Exit\n");
        printf("-----------------------------------------\n");
        printf("Enter your choice (1-7): ");
        scanf("%d", &choice);
        while (getchar() != '\n');
        switch(choice) {
            case 1:
                add_patient(patient,&patient_amount);
                break;
            case 2:
                display(patient,patient_amount);
                break;
            case 3:{
                search_patient(patient,patient_amount);
                break;
            }
            case 4:{
                update_status(patient,patient_amount);
                break;
            }
            case 5:{
                assign_doctor(patient,patient_amount,hospitalDoctors,amount_of_DR);
                break;
            }
            case 6:{
                calculate_bill(patient,patient_amount);
                break;
            }
            case 7:
                discharge(patient,patient_amount);
                break;
            case 8:
                record_info(patient,patient_amount);
                break;

        }
    } while(choice != 8);
    return 0;
}
int find_index(Patient patient[], int size, char target_id[]){
    for(int i = 0; i < size; i++){
        if(strcmp(patient[i].patient_id, target_id) == 0){
            return i;
        }
    }
    return -1;
}
void prompt_id(char id[]){
    printf("enter patient id: ");
    fgets(id, 10, stdin);
    id[strcspn(id, "\n")] = '\0';
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

void assign_doctor(Patient patient[],int size,Doctor Dr[],int dr_amount){
    char target_id[10];
    prompt_id(target_id);
    if(find_index(patient,size,target_id)==-1){
        printf("patient not found!\n");
        return;
    }
    int index = find_index(patient,size,target_id);
    printf("-------Doctor Lists---------\n");
    for(int i=0;i<dr_amount;i++){
        printf("%d. %s (%s)\n",i+1,Dr[i].dr_name,Dr[i].specialty);
    }
    int dr_option;
    printf("choose the doctor (1-5)");
    scanf("%d",&dr_option);
    while (getchar() != '\n');
    dr_option--;
    strcpy(patient[index].dr.dr_name,Dr[dr_option].dr_name);
    printf("doctor assigned successfully\n");
}