from django.contrib import admin
from .models import *

# Register your models here.
admin.site.register(Doctor)
admin.site.register(Patient)
admin.site.register(Nurse)
admin.site.register(EHR)
admin.site.register(Feedback)
admin.site.register(Appointment)
admin.site.register(Message)
admin.site.register(Edit_Ehr_requests)