#include <stdio.h>
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
