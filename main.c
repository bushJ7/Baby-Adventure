/**
 * @file    main.c
 * @author  Baby-Adventure
 * @version v1.0
 * @date    7-July-2026
 * @brief   Hospital Patient Record Management System.
 *
 * This program is a console-based hospital management system developed
 * using the C programming language. It allows hospital staff to manage
 * patient records efficiently by providing the following features:
 *
 * - Add new patient records.
 * - Display all patient records.
 * - Search patients by ID.
 * - Update patient health status.
 * - Assign doctors to patients.
 * - Calculate patient service and medicine bills.
 * - Generate patient discharge summaries.
 * - Save and load patient records using a text file.
 *
 * The system uses structures to organize patient, doctor, and billing
 * information, and file handling to maintain records between program runs.
 *
 * @attention
 * This project was developed as part of the Computer Fundamental course
 * at CamTech University.
 */
 
#include <stdio.h>
#include "data.h"
#include "patient.h"
#include "billing.h"
#include "file.h"
 
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
                add_patient(patient,&patient_amount); //lyheang
                break;
            case 2:
                display(patient,patient_amount);
                break;
            case 3:{
                search_patient(patient,patient_amount); //sithikar
                break;
            }
            case 4:{
                update_status(patient,patient_amount); //kim nai
                break;
            }
            case 5:{
                assign_doctor(patient,patient_amount,hospitalDoctors,amount_of_DR);
                break;
            }
            case 6:{
                calculate_bill(patient,patient_amount); //kim Eng
                break;
            }
            case 7:
                discharge(patient,patient_amount); //ronith
                break;
            case 8:
                record_info(patient,patient_amount); //ronith
                break;
 
        }
    } while(choice != 8);
    return 0;
}