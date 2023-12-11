from django.http import HttpResponse
from django.shortcuts import render,redirect
from hospital.models import *
from time import sleep
from django.contrib import messages
from .forms import *
def main_signup_dark(requests,person):
    data ={
        "Url":person,
        "person":person.title(),
    }
    return render(requests,"sign-up-dark.html",data)
def main_signup_light(requests,person):
    data ={
        "Url":person,
        "person":person.title(),
    }
    return render(requests,"sign-up-light.html",data)
def register_person_dark(requests,person):
    if(requests.method=="POST"):
        email= requests.POST.get('email')
        password = requests.POST.get('password')
        if not person == "":
            if(person=="doctor"):
                if Doctor.objects.filter(Email=email).exists():
                    messages.error(requests, 'Credentials exists already!')
                    data ={
                        "Url":person,
                        "person":person.title(),
                    }
                    return redirect(f"/signup-dark/{data['Url']}",data)  
                else:
                    doc=Doctor(Email=email,password=password)
                    doc.save()
            if(person=="patient"):
                if Patient.objects.filter(Email=email).exists():
                    messages.error(requests, 'Credentials exists already!')
                    data ={
                        "Url":person,
                        "person":person.title(),
                    }
                    return redirect(f"/signup-dark/{data['Url']}",data)  
                else:
                    pat=Patient(Email=email,password=password)
                    pat.save()
                    ehr = EHR(patient=pat,allergies="Peanut and blood allergies",diet_rescrictions="No oily foods and minimum fat.",Test_conucted="None",prescriptions="Brufen",Drug_history="None",Family_history="None")
                    ehr.save()
                    
            if(person=="nurse"):
                if Nurse.objects.filter(Email=email).exists():
                    messages.error(requests, 'Credentials exists already!')
                    data ={
                        "Url":person,
                        "person":person.title(),
                    }
                    return redirect(f"/signup-dark/{data['Url']}",data)  
                else:
                    Nur=Nurse(Email=email,password=password)
                    Nur.save() 
            messages.success(requests, f'{person} added successfully!')
            return redirect(f"/login-dark/{person}",{'messages':messages})
        else:
            messages.error(requests, f'Password cannot be empty!')
            return redirect(f"/signup-light/{person}",{'messages':messages})
def register_person_light(requests,person):
    if(requests.method=="POST"):
        email= requests.POST.get('email')
        password = requests.POST.get('password')
        if not password =="":
            if(person=="doctor"):
                if Doctor.objects.filter(Email=email).exists():
                    messages.error(requests, 'Credentials exists already!')
                    data ={
                        "Url":person,
                        "person":person.title(),
                    }
                    return redirect(f"/signup-light/{data['Url']}",data)  
                else:
                    doc=Doctor(Email=email,password=password)
                    doc.save()
            if(person=="patient"):
                if Patient.objects.filter(Email=email).exists():
                    messages.error(requests, 'Credentials exists already!')
                    data ={
                        "Url":person,
                        "person":person.title(),
                    }
                    return redirect(f"/signup-light/{data['Url']}",data)  
                else:
                    pat=Patient(Email=email,password=password)
                    pat.save()
                    ehr = EHR(patient=pat,allergies="Peanut and blood allergies",diet_restriction="No oily foods and minimum fat.",Test_conducted
                            ="None",prescriptions="Brufen",Drug_history="None",Family_history="None")
                    ehr.save()
            if(person=="nurse"):
                if Nurse.objects.filter(Email=email).exists():
                    messages.error(requests, 'Credentials exists already!')
                    data ={
                        "Url":person,
                        "person":person.title(),
                    }
                    return redirect(f"/signup-light/{data['Url']}",data)  
                else:
                    nur=Nurse(Email=email,password=password)
                    nur.save()
            messages.success(requests, f'{person} added successfully!')
            return redirect(f"/login-light/{person}",{'messages':messages})
        else:
            messages.error(requests, f'Password cannot be empty!')
            return redirect(f"/signup-light/{person}",{'messages':messages})
def Ehr_display(requests,person,id1):
    id=requests.GET.get('id')
    if person =="patient":
        pat=Patient.objects.get(id=id1)
    else:
       pat=Patient.objects.get(id=id) 
    data={
        'ehr':EHR.objects.get(patient=pat),
        'pat':pat,
        'person':person,
        'id1':id1
    }
    return render(requests,"Ehr.html",data)
def main_login_dark(requests,person):
    data ={
        "Url":person,
        "person":person.title(),
    }
    return render(requests,"login-dark.html",data)
def login_person_dark(requests,person):
    if requests.method =="POST":
        email=requests.POST.get("email")
        password=requests.POST.get("password")
        
        if person=="doctor":
            if Doctor.objects.filter(Email=email,password=password).exists():
                messages.success(requests, 'Login successfull!')
                return redirect(f"/dashboard-light/{person}",person)
            else:
                data ={
                    "Url":person,
                    "person":person.title(),
                    "message":"Invalid username or password !",
                    "error":True,
                }
                messages.error(requests, 'Invalid username or password!')
                return redirect(f"/login-dark/{data['Url']}",data)
        elif person=="patient":
            if Patient.objects.filter(Email=email,password=password).exists():
                messages.success(requests, 'Login successfull!')
                return redirect(f"/dashboard-light/{person}",person)
            else:
                data ={
                    "Url":person,
                    "person":person.title(),
                    "message":"Invalid username or password !",
                    "error":True,
                }
                messages.error(requests, 'Invalid username or password!')
                return redirect(f"/login-dark/{data['Url']}",data)
        elif person=="nurse":
            if Nurse.objects.filter(Email=email,password=password).exists():
                messages.success(requests, 'Login successfull!')
                return redirect(f"/dashboard-light/{person}",person)
            else:
                data ={
                    "Url":person,
                    "person":person.title(),
                    "message":"Invalid username or password !",
                    "error":True,
                }
                messages.error(requests, 'Invalid username or password!')
                return redirect(f"/login-dark/{data['Url']}",data)
def login_person_light(requests,person):
    if requests.method =="POST":
        email=requests.POST.get("email")
        password=requests.POST.get("password")
        
        if person=="doctor":
            if Doctor.objects.filter(Email=email,password=password).exists():
                messages.success(requests, 'Login successfull!')
                pat=Doctor.objects.get(Email=email,password=password)
                return redirect(f"/dashboard-light/{person}/?id={pat.id}")
            else:
                data ={
                    "Url":person,
                    "person":person.title(),
                    "message":"Invalid username or password !",
                    "error":True,
                }
                messages.error(requests, 'Invalid username or password!')
                return redirect(f"/login-light/{data['Url']}",data)
        elif person=="patient":
            if Patient.objects.filter(Email=email,password=password).exists():
                pat=Patient.objects.get(Email=email,password=password)
                messages.success(requests, 'Login successfull!')
                return redirect(f"/dashboard-light/{person}/?id={pat.id}")
            else:
                data ={
                    "Url":person,
                    "person":person.title(),
                    "message":"Invalid username or password !",
                    "error":True,
                }
                messages.error(requests, 'Invalid username or password!')
                return redirect(f"/login-light/{data['Url']}",data)
        elif person=="nurse":
            if Nurse.objects.filter(Email=email,password=password).exists():
                messages.success(requests, 'Login successfull!')
                pat=Nurse.objects.get(Email=email,password=password)
                return redirect(f"/dashboard-light/{person}/?id={pat.id}")
            else:
                data ={
                    "Url":person,
                    "person":person.title(),
                    "message":"Invalid username or password !",
                    "error":True,
                }
                messages.error(requests, 'Invalid username or password!')
                return redirect(f"/login-light/{data['Url']}",data)
def main_login_light(requests,person):
    data ={
        "Url":person,
        "person":person.title(),
    }
    return render(requests,"login-light.html",data)
def main_dashboard_dark(requests,person):
    data ={
        "Url":person,
        "person":person.title(),
    }
    return render(requests,"dashboard-dark.html",data)
def homepage(requests):
    now = timezone.localtime(timezone.now())
    formatted_time = now.strftime('%H:%M:%S')
    appointments_to_date = Appointment.objects.filter(scedule_date__lt=now.date(),status='requested')
    appointments_to_time = Appointment.objects.filter(scedule_date=now.date(),scedule_time__lt=formatted_time,status='requested')
    appointments_to_delete = appointments_to_date | appointments_to_time
    appointments_to_delete.delete()
    return render(requests,"homepage.html")
def main_dashboard_light(requests,person):
    id = requests.GET.get('id')        
    data ={
        "Url":person,
        "person":person.title(),
        "id":id,
    }
    if(person=='doctor'):
        doctor=Doctor.objects.get(id=id)
        patients=Patient.objects.filter(Doctor=doctor)
        nurse=Nurse.objects.filter(doctor=doctor)
        print(nurse)
        ehr_requests=Edit_Ehr_requests.objects.filter(nurse=nurse.first())
        # nurse=Nurse.objects.filter(doctor=doctor)
        if nurse:
            data.update({'nurse':True})
            data.update({'nurse_id':nurse.first().id})
        else:
            data.update({'nurse':False})
        if not patients.exists():
            data.update({"pat":False})
        else:
            data.update({"pat":True})
        if ehr_requests.exists():
            data.update({'nurse_req':True}) 
        else:
            data.update({'nurse_req':False})
        appoint=Appointment.objects.filter(doctor=doctor)
        if not appoint.exists():
            data.update({"appoint":False})
        else:
            data.update({"appoint":True})
    elif person == 'patient':
        appoint=Appointment.objects.filter(patient=Patient.objects.get(id=id))
        doctor=Patient.objects.get(id=id).Doctor
        if  doctor.exists():
            data.update({'doc':True})
        else:
            data.update({'doc':False})
        if not appoint.exists():
            data.update({"appoint":False})
        else:
            data.update({"appoint":True})
    elif person=='nurse':
        nurse=Nurse.objects.get(id=id)
        doc=nurse.doctor
        pat=Patient.objects.filter(Doctor=doc).exclude(id__in=Edit_Ehr_requests.objects.filter(nurse=nurse).values('patient__id'))
        req_ehrs=Edit_Ehr_requests.objects.filter(nurse=nurse)
        ehrs=Edit_Ehr_requests.objects.filter(nurse=nurse,status='approved')
        if doc:
            data.update({'doc':True})
            if pat.exists():
                data.update({'req':True})
            else:
                data.update({'req':False})
            if req_ehrs.exists():
                data.update({'ehr_reqs':True})
            else:
                data.update({'ehr_reqs':False})
            if ehrs.exists():
                data.update({'approve':True})
            else:
                data.update({'approve':False})
            data.update({'doctor':doc})
        else:
            data.update({'doc':False})
        
    return render(requests,"dashboard-light.html",data)
def select_Doctor(requests):
    id=requests.GET.get('id')
    patient=Patient.objects.get(id=id)
    form = select_doctor(patient,requests.POST or None)
    if requests.method =="POST":
        id=requests.GET.get('id')
        doc_email=requests.POST.get('emails')
        doc=Doctor.objects.get(Email=doc_email)
        patient.Doctor.add(doc)
        messages.success(requests, 'Doctor addded Successfully!')
        return redirect(f"/dashboard-light/patient/?id={id}")
    data={
        "form": form,"id":id,
    }
    return render(requests, "temp-form.html", data)
def select_doctor_for_chat(requests,purpose):
    id=requests.GET.get('id')
    pat=Patient.objects.get(id=id)
    form=select_Doctor_for_chat(requests.POST or None,instance=pat)
    if requests.method == "POST":
       doc=Doctor.objects.get(id=requests.POST.get('doctor'))
       return redirect(f"/chat/patient/{id}/?id={doc.id}") 
    data={
        'form':form,
    }
    return render(requests,"temp-form.html",data)
def select_patient(request,purpose):
    id=request.GET.get('id')
    doc=Doctor.objects.get(id=id)
    if request.method=="POST":
        pat_email=request.POST.get('emails')
        pat=Patient.objects.get(Email=pat_email)
        if purpose=="view":
            return redirect(f"/ehr/doctor/{id}/?id={pat.id}")
        elif purpose=="edit":
            return redirect(f"/edit-ehr/doctor/{id}/?id={pat.id}")
        elif purpose=="chat":
            return redirect(f"/chat/doctor/{id}/?id={pat.id}")
    pat=Patient.objects.filter(Doctor=doc)
    form = select_Patient(pat)
    data={
        "form": form,"id":id,
    }
    return render(request, "temp-form.html", data)
def select_patient_Nurse(request,purpose):
    id=request.GET.get('id')    
    nurse=Nurse.objects.get(id=id)
    if purpose=="view":
        nurse_doc=nurse.doctor
        pat=Patient.objects.filter(Doctor=nurse_doc)
        form=select_Patient(pat,request.POST or None)
    elif purpose=="edit":
        ehrs=Edit_Ehr_requests.objects.filter(nurse=nurse,status='approved')
        patient_ids = ehrs.values('patient__id')
        selected_patients = Patient.objects.filter(id__in=patient_ids)
        form=select_Patient(selected_patients,request.POST or None)
    if request.method == 'POST':
        pat_email=request.POST.get('emails')
        pat=Patient.objects.get(Email=pat_email)
        if purpose=="edit":
            return redirect(f"/edit-ehr/nurse/{id}/?id={pat.id}")
        return redirect(f"/ehr/nurse/{id}/?id={pat.id}")
    data={"form":form,
          "id":id}
    return render(request, "temp-form.html", data)
def edit_ehr(request,person,id1):
    id=request.GET.get('id')
    pat= Patient.objects.get(id=id)
    ehr=EHR.objects.get(patient=pat)
    form=Edit_Ehr(request.POST or None ,instance=ehr) 
    if form.is_valid():
        form.save()  
        messages.success(request, 'Ehr Edited Successfully!')  
        return redirect(f"/dashboard-light/{person}/?id={id1}")
    data= {
        'form':form,
    }
    return render(request, "temp-form.html", data)
def submit_Feedback(request,person):
    id=request.GET.get('id')
    form=FeedBack(request.POST or None) 
    if form.is_valid():
        if person=="doctor":
            doc=Doctor.objects.get(id=id)
            form.instance.Email=doc.Email
            form.instance.person_type="doctor" 
            form.save()  
            messages.success(request, 'Feedback Submitted Succesfully!')  
            return redirect(f"/dashboard-light/doctor/?id={id}")
        elif person=="patient":
            pat=Patient.objects.get(id=id)
            form.instance.Email=pat.Email
            form.instance.person_type="patient" 
            form.save()  
            messages.success(request, 'Feedback Submitted Succesfully!')  
            return redirect(f"/dashboard-light/patient/?id={id}")
        else: 
            nur=Nurse.objects.get(id=id)
            form.instance.Email=nur.Email
            form.instance.person_type="patient"
            form.save()  
            messages.success(request, 'Feedback Submitted Succesfully!')  
            return redirect(f"/dashboard-light/nurse/?id={id}")
    data= {
        'form':form,
    }
    return render(request, "temp-form.html", data)
def view_appointment(requests,person):
    id=requests.GET.get('id')
    if person == 'doctor':
        appointments=Appointment.objects.filter(doctor=Doctor.objects.get(id=id))
    else:
        appointments=Appointment.objects.filter(patient=Patient.objects.get(id=id))
    data={
        'appointments':appointments,
        'id':id,
        'requested': any(appointment.status == 'requested' for appointment in appointments),
        'approved':any(appointment.status == 'approved' for appointment in appointments),
        'denied':any(appointment.status == 'denied' for appointment in appointments),
        'person': person
    }
    return render(requests, "appointment-display.html",data)
def view_Ehrs(requests,person):
    id=requests.GET.get('id')
    if person == 'doctor':
        requested=Edit_Ehr_requests.objects.filter(nurse=Nurse.objects.get(doctor=Doctor.objects.get(id=id)))
    else:
        requested=Edit_Ehr_requests.objects.filter(nurse=Nurse.objects.get(id=id))
    data={
        'ehr_requests':requested,
        'id':id,
        'requested': any(request.status == 'requested' for request in requested),
        'approved':any(request.status == 'approved' for request in requested),
        'denied':any(request.status == 'denied' for request in requested),
        'person': person
    }
    return render(requests, "ehr-req.html",data)
def update_status(requests,id,id1):
    status=requests.GET.get('status')
    appoint=Appointment.objects.get(id=id)
    appoint.status=status
    appoint.save()
    return redirect(f"/appointments/doctor/?id={id1}")
def update_status_edit(requests,id,id1):
    status=requests.GET.get('status')
    appoint=Edit_Ehr_requests.objects.get(id=id)
    appoint.status=status
    appoint.save()
    return redirect(f"/edit-request/doctor/?id={id1}")
def req_appointment(requests):
    id=requests.GET.get('id')
    patient=Patient.objects.get(id=id)
    app = Appointment(patient=patient)
    form=appointments_request(requests.POST or None ,instance=app)
    if form.is_valid():
        form.instance.patient=patient
        form.instance.status="requested"
        form.save()
        messages.success(requests, 'Appointment requested Succesfully!')
        return redirect(f"/dashboard-light/patient/?id={id}")
    data= {
        'form':form,
    }
    return render(requests,"temp-form.html",data)
def chat(request,person, user_id):
    id=request.GET.get('id')
    sender = person
    form = MessageForm(request.POST or None)
    if person == "doctor":
        doctor=Doctor.objects.get(id=user_id)
        patient = Patient.objects.get(id=id)
        messages = Message.objects.filter(doctor=doctor,patient=patient).order_by('timestamp')
        data = {
            'messages':messages,
            'person':person,
            'form':form,
            'client':patient,
        }
    elif person == "patient":
        doctor=Doctor.objects.get(id=id)
        patient = Patient.objects.get(id=user_id)
        messages = Message.objects.filter(doctor=doctor,patient=patient).order_by('timestamp')
        data = {
            'messages':messages,
            'person':person,
            'form':form,
            'client':doctor,
        }
    if request.method=="POST":
        form.instance.patient=patient
        form.instance.doctor=doctor
        form.instance.sender=sender
        form.instance.timestamp=timezone.now()
        form.save()
        return redirect(f"/chat/{person}/{user_id}/?id={id}")
    else:
        data.update({'id':user_id})
        return render(request, 'chats.html', data)

def select_nurse(requests):
    id=requests.GET.get('id')
    form = SelectNurseForm()
    if requests.method =="POST":
        id=requests.GET.get('id')
        nur_email=requests.POST.get('emails')
        nurse=Nurse.objects.get(Email=nur_email)
        nurse.doctor=Doctor.objects.get(id=id)
        nurse.save()
        messages.success(requests, 'Nurse addded Successfully!')
        return redirect(f"/dashboard-light/doctor/?id={id}")
    data={
        "form": form,"id":id,
    }
    return render(requests, "temp-form.html", data)
def chat_nurse(request,person, user_id):
    id=request.GET.get('id')
    sender = person
    form = MessageForm(request.POST or None)
    if person == "doctor":
        doctor=Doctor.objects.get(id=user_id)
        nurse = Nurse.objects.get(id=id)
        messages = Message.objects.filter(doctor=doctor,nurse=nurse).order_by('timestamp')
        data = {
            'messages':messages,
            'person':person,
            'form':form,
            'client':nurse,
        }
    elif person == "nurse":
        doctor=Doctor.objects.get(id=id)
        nurse = Nurse.objects.get(id=user_id)
        messages = Message.objects.filter(doctor=doctor,nurse=nurse).order_by('timestamp')
        data = {
            'messages':messages,
            'person':person,
            'form':form,
            'client':doctor,
        }
    if request.method=="POST":
        form.instance.nurse=nurse
        form.instance.doctor=doctor
        form.instance.sender=sender
        form.instance.timestamp=timezone.now()
        form.save()
        return redirect(f"/chat-nurse/{person}/{user_id}/?id={id}")
    else:
        data.update({'id':user_id})
        return render(request, 'chats.html', data)
      
def select_Edit_request(request):
    id=request.GET.get('id')
    nurse=Nurse.objects.get(id=id)
    form = Ehr_Edit_Request(nurse,request.POST or None)
    if request.method == 'POST': 
        form.instance.status='requested'
        form.instance.nurse=nurse
        form.save()
        messages.success(request, 'Edit Requested Successfully!')
        return redirect(f"/dashboard-light/nurse/?id={id}") 

    return render(request, 'temp-form.html', {'form': form})
