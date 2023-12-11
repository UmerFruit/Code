"""
URL configuration for hospital_master project.

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.2/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from django.urls import path
from hospital_master import views
from django.contrib.admin.views.decorators import staff_member_required
from django.views.decorators.cache import cache_page
admin.site.enable_nav_sidebar = False
urlpatterns =[
    path('admin/', admin.site.urls),
    path('', views.homepage),
    path('signup-dark/<str:person>',views.main_signup_dark),
    path('signup-light/<str:person>',views.main_signup_light),
    path('login-dark/<str:person>',views.main_login_dark),
    path('register-dark/<str:person>',views.register_person_dark),
    path('Logging-dark/<str:person>',views.login_person_dark),
    path('Logging-light/<str:person>',views.login_person_light),
    path('ehr/<str:person>/<int:id1>/',views.Ehr_display),
    path('edit-ehr/<str:person>/<int:id1>/',views.edit_ehr),
    path('select-doctor/',views.select_Doctor),
    path('select-patient/<str:purpose>/',views.select_patient),
    path('login-light/<str:person>',views.main_login_light),
    path('dashboard-dark/<str:person>',views.main_dashboard_dark),
    path('dashboard-light/<str:person>/',views.main_dashboard_light),
    path('feedback/<str:person>/',views.submit_Feedback),
    path('request-appointment/',views.req_appointment),
    path('register-light/<str:person>',views.register_person_light),
    path('appointments/<str:person>/',views.view_appointment),
    path('edit-request/<str:person>/',views.view_Ehrs),
    path('update-status/<int:id>/<int:id1>/',views.update_status),
    path('update-status-edit/<int:id>/<int:id1>/',views.update_status_edit),
    path('chat/<str:person>/<int:user_id>/',views.chat),
    path('chat-nurse/<str:person>/<int:user_id>/',views.chat_nurse),
    path('select-doctor/<str:purpose>/',views.select_doctor_for_chat),
    path('select-nurse/',views.select_nurse),
    path('select-patient-nurse/<str:purpose>/',views.select_patient_Nurse),
    path('request-edit/',views.select_Edit_request),]



admin.autodiscover()
admin.site.login = staff_member_required(admin.site.login)
admin.site.site_header = 'Hospital Master'  # This is the header that appears at the top of the admin pages
admin.site.site_title = 'Hospital Master'