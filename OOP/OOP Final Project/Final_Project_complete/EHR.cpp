/*
 * EHR.cpp
 *
 *  Created on: 10-May-2023
 *      Author: umerfarooq
 */
#include "EHR.h"
void EHR::setAllergies(char* a)
{
    for (int i = 0; i < 200; i++)
    {
        this->allergies[i] = a[i];
    }
}
void EHR::setConsultation(char* cn)
{
    for (int i = 0; i < 200; i++)
    {
        this->consultation[i] = cn[i];
    }
}
void EHR::setDiet(char* d)
{
    for (int i = 0; i < 200; i++)
    {
        this->diet[i] = d[i];
    }
}

char *EHR::getAllergies()
{
    return allergies;
}

char *EHR::getConsultation()
{
    return consultation;
}

char *EHR::getDiet()
{
    return diet;
}

char *EHR::getPrescriptions()
{
    return prescriptions;
}

void EHR::setPrescriptions(char* p)
{
    for (int i = 0; i < 200; i++)
    {
        this->prescriptions[i] = p[i];
    }
}
ostream &operator<<(ostream &out, EHR &t)
{
    out << "Reason for Visit : \n"
        << t.consultation << endl
        << endl;
    out << "Prescriptions : \n"
        << t.prescriptions << endl
        << endl;
    for (int i = 0; i < 4; i++)
        out << "Time for Appointment " << i << " :\n"
            << t.appointments[i] << endl
            << endl;

    out << "Allergies : \n"
        << t.allergies << endl
        << endl;
    out << "Diet Restrictions : \n"
        << t.diet << endl
        << endl;
    return out;
}