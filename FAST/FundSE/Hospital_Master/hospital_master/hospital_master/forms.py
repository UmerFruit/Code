from django import forms
from django.forms.widgets import DateInput,TimeInput
from django.utils import timezone
from django.core.exceptions import ValidationError
from hospital.models import *

class select_doctor(forms.Form):
    def __init__(self, patient, *args, **kwargs):
        super(select_doctor, self).__init__(*args, **kwargs)
        patient_doctors = patient.Doctor.all()
        queryset = Doctor.objects.exclude(pk__in=patient_doctors)

        self.fields['emails'].queryset = queryset

    emails = forms.ModelChoiceField(
        queryset=Doctor.objects.none(), 
        empty_label="Choose a Doctor!",
        required=True,
        widget=forms.Select(),
        to_field_name='Email'
    )

    fields = ('emails',)

class SelectNurseForm(forms.Form):
    emails = forms.ModelChoiceField(
        queryset=Nurse.objects.filter(doctor__isnull=True),
        empty_label="Choose a Nurse!",
        required=True,
        widget=forms.Select(),
        to_field_name='Email'
    )

    class Meta:
        fields = ('emails',)

class select_Doctor_for_chat(forms.ModelForm):
    doctor = forms.ModelChoiceField(queryset=Doctor.objects.all())

    class Meta:
        model = Patient
        exclude = ('Email','password','Doctor')  # Since you want to exclude 'Email' and 'password'

    def __init__(self, *args, **kwargs):
        super(select_Doctor_for_chat, self).__init__(*args, **kwargs)
        # Customize the queryset based on the patient instance (if available)
        if 'instance' in kwargs:
            patient = kwargs['instance']
            self.fields['doctor'].queryset = patient.Doctor.all()
class select_Patient(forms.Form):
    emails = forms.ModelChoiceField(
        queryset=Patient.objects.none(),  # Use .none() initially to create an empty queryset
        empty_label="Choose a Patient!",
        required=True,
        widget=forms.Select(),
        to_field_name='Email' 
    )
    fields=('emails',)
    def __init__(self, patient, *args, **kwargs):
        super(select_Patient, self).__init__(*args, **kwargs)
        # Filter patients based on the doctor
        patients = patient
        
        # Create a list of tuples for the email choices

        # Add a ChoiceField to the form for email selection
        self.fields['emails'].queryset = patients
    fields=('emails',)
class Edit_Ehr(forms.ModelForm):
    class Meta:
        model=EHR
        exclude=('patient',)
class FeedBack(forms.ModelForm):
    class Meta:
        model=Feedback
        fields=('feedback',)
class appointments_request(forms.ModelForm):
    class Meta:
        model = Appointment
        exclude = ('patient', 'status')  # Include other fields as needed
        widgets={
            "scedule_date":DateInput(attrs={'type': 'date'}),
            "scedule_time":TimeInput(attrs={'type': 'time'}),
        }

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        # Limit doctor choices to only those associated with the patient
        if 'instance' in kwargs and hasattr(kwargs['instance'], 'patient'):
            patient = kwargs['instance'].patient
            self.fields['doctor'].queryset = patient.Doctor.all()
    def clean_scedule_date(self):
        scedule_date = self.cleaned_data['scedule_date']

        # Check if the selected date is in the future
        if scedule_date < timezone.now().date():
            raise ValidationError("Please select a future date.")

        return scedule_date

    def clean_scedule_time(self):
        scedule_time = self.cleaned_data['scedule_time']

        # Convert selected time to timezone-aware datetime
        selected_datetime = timezone.datetime.combine(timezone.now().date(), scedule_time)
        selected_datetime = timezone.make_aware(selected_datetime)

        # Check if the selected time is in the future
        if selected_datetime < timezone.now():
            raise ValidationError("Please select a future time.")

        return scedule_time
class MessageForm(forms.ModelForm):
    class Meta:
        model = Message
        fields = ['content',]
        widgets = {
            'content': forms.Textarea(attrs={'rows': 3, 'cols': 30, 'placeholder': 'Type your message'}),
        }
class Ehr_Edit_Request(forms.ModelForm):
    class Meta:
        model = Edit_Ehr_requests
        fields = [ 'patient',]

    def __init__(self,nurse, *args, **kwargs):
        super(Ehr_Edit_Request, self).__init__(*args, **kwargs)

        # Customize the patient field queryset
        self.fields['patient'].queryset = self.get_filtered_patients(nurse)

    def get_filtered_patients(self,nurse):
        # Get the doctor associated with the nurse
        doctor = nurse.doctor if nurse else None

        # Get patients associated with the doctor but not in Edit_Ehr_requests with the specific nurse
        patients_not_in_edit_ehr = Patient.objects.filter(Doctor=doctor).exclude(
            id__in=Edit_Ehr_requests.objects.filter(nurse=nurse).values('patient__id')
        )

        return patients_not_in_edit_ehr

        