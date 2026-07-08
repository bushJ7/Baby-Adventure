#ifndef PATIENT_H
#define PATIENT_H

#include <stdio.h>
#include <string.h>
#include "doctor.h"
extern const int MAX_SIZE;

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
int find_index(Patient patient[], int size, char target_id[]);
void add_patient(Patient patient[], int *size);
void search_patient(Patient patient[], int size);
void display(Patient patient[], int size);
void update_status(Patient patient[], int size);
void calculate_bill(Patient patient[], int size);
void discharge(Patient patient[], int size);
void assign_doctor(Patient patient[], int size, Doctor Dr[], int dr_amount);

#endif // 