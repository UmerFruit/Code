from django.db import models
from django.utils import timezone
class Doctor(models.Model):
    Email = models.EmailField(max_length=254)
    password = models.CharField(max_length=8)
    def __str__(self):
        return f'{self.Email}'
class Patient(models.Model):
    Email = models.EmailField(max_length=254)
    password = models.CharField(max_length=8)
    Doctor =models.ManyToManyField(Doctor,blank=True)
    def __str__(self):
        return f'{self.Email}'
class Nurse(models.Model):
    Email = models.EmailField(max_length=254)
    password = models.CharField(max_length=8)
    doctor=models.OneToOneField(Doctor,blank=True,on_delete=models.DO_NOTHING,null=True)
    def __str__(self):
        return f'{self.Email}'
class EHR(models.Model):
    patient = models.OneToOneField("Patient", on_delete=models.CASCADE)
    allergies=models.CharField( max_length=250)
    diet_restriction=models.CharField( max_length=250)
    Test_conducted = models.CharField(max_length=250)
    prescriptions= models.CharField(max_length=250)
    Drug_history=models.CharField( max_length=250)
    Family_history=models.CharField(max_length=250)
    def __str__(self):
        return f'{self.patient}'
class Feedback(models.Model):
    feedback=models.TextField(max_length=350)
    Email=models.EmailField(max_length=254)
    person_type=models.CharField(max_length=50)
    def __str__(self):
        return f'{self.feedback}'
class Appointment(models.Model):
    patient=models.ForeignKey("Patient",on_delete=models.DO_NOTHING)
    doctor=models.ForeignKey("doctor",on_delete=models.DO_NOTHING)
    scedule_date=models.DateField(null=False)
    scedule_time=models.TimeField(null=False)
    status=models.CharField(max_length=50)
    def __str__(self):
        return f'{self.status}'
class Message(models.Model):
    doctor = models.ForeignKey('Doctor',on_delete=models.DO_NOTHING,null=True)
    patient = models.ForeignKey('Patient', on_delete=models.DO_NOTHING,null=True)
    nurse = models.ForeignKey('Nurse',on_delete=models.DO_NOTHING,null=True)
    content = models.TextField()
    sender=models.CharField(max_length=50)
    timestamp = models.DateTimeField(default=timezone.now)

    def __str__(self):
        return f'{self.doctor} {self.patient} with {self.sender}'
class Edit_Ehr_requests(models.Model):
    nurse = models.ForeignKey("Nurse", on_delete=models.DO_NOTHING)
    patient = models.ForeignKey("Patient",on_delete=models.DO_NOTHING)
    status = models.CharField( max_length=50)
    def __str__(self) :
        return f'{self.nurse} with {self.patient}'
# Create your models here.
