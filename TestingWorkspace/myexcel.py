import xlsxwriter
def read_strings(n):
    string_list = []  # Create an empty list to store strings
    while(1):
        user_input = input("Enter Name: ")
        if user_input != '' and user_input != ' ':
            string_list.append(user_input)
            break
    while(1):    
        user_input = input("Enter Roll_num: ")
        if user_input != '' and user_input != ' ':
            string_list.append(user_input)
            break
    i = 0
    while i<n:
        user_input = input("Enter Marks of Q" + str(i+1) + ": ")
        if user_input == '' or user_input == ' ':
            i = i-1
        else: 
            string_list.append(user_input)
        i = i+1
    decision = input("Enter comment? (0/1)")
    while decision == '' or decision == ' ':
        decision = input("Enter comment? (0/1)")
    if decision == '1':
        user_input = input("Enter Comment: ")
    else:
        user_input = ""
    string_list.append(user_input)

    return string_list

import os.path

path=os.path(" \markstest5.xlsx")

n = 4 #NUMBER OF QUESTIONS OF THE ASSIGNMENT
workbook = xlsxwriter.Workbook(path)
worksheet = workbook.add_worksheet("Section A")
check = '1'
row = 1
while check == '1':
    worksheet.write(0, 0, "Name")
    worksheet.write(0, 1, "Roll#")
    for i in range(1, n+1):
        worksheet.write(0, i+1, "Q"+str(i))
    data = ['John Doe', '12345', '90', '85', '95', '1', 'Great job!']
    for idx in range(0,n+3):
        worksheet.write(row,idx,data[idx])
    row = row + 1
    check = input("Continue? (0/1)")
    while check == '' or check == ' ':
        check = input("Continue? (0/1)")

workbook.close()