#ifndef DATA_H
#define DATA_H

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

#endif