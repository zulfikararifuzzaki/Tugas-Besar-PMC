from tkinter import *
from output import *
from ctypes import *

func_lib = CDLL(r"D:\Tugas-Besar-PMC-Output-input-combine\funlib.so")

def input_circuit():
    if (Rcode == 4):
        if(Ccode == 4):
            circuit_code = 1
            RC_picFile = RC_picFile1
        elif(Ccode == 5):
            circuit_code = 2
            RC_picFile = RC_picFile2
        elif(Ccode == 6):
            circuit_code = 3
            RC_picFile = RC_picFile3
        elif(Ccode == 7):
            circuit_code = 4
            RC_picFile = RC_picFile4
    elif (Rcode == 5):
        if(Ccode == 4):
            circuit_code = 5
            RC_picFile =RC_picFile5
        elif(Ccode == 5):
            circuit_code = 6
            RC_picFile = RC_picFile6
        elif(Ccode == 6):
            circuit_code = 7
            RC_picFile = RC_picFile7
        elif(Ccode == 7):
            circuit_code = 8
            RC_picFile = RC_picFile8
    elif (Rcode == 6):
        if(Ccode == 4):
            circuit_code = 9
            RC_picFile = RC_picFile9
        elif(Ccode == 5):
            circuit_code = 10
            RC_picFile = RC_picFile10
        elif(Ccode == 6):
            circuit_code = 11
            RC_picFile = RC_picFile11
        elif(Ccode == 7):
            circuit_code = 12
            RC_picFile = RC_picFile12
    elif (Rcode == 7):
        if(Ccode == 4):
            circuit_code = 13
            RC_picFile = RC_picFile13
        elif(Ccode == 5):
            circuit_code = 14
            RC_picFile = RC_picFile14
        elif(Ccode == 6):
            circuit_code = 15
            RC_picFile = RC_picFile15
        elif(Ccode == 7):
            circuit_code = 16
            RC_picFile = RC_picFile16
    frame1.destroy()
    
    C_button4 = Button(root, text='Submit', width=25, command=lambda :submit(Rcode,Ccode,circuit_code)) 
    C_button4.grid(column = 0,row = 4)
    
    RC_pic = Canvas(root,width = 800,height = 400)
    RC_pic.grid(column = 0, row = 0)
    RC_pic.create_image(10,10,anchor = NW,image = RC_picFile)
    in_label = Label(root, text = "Masukkan Nilai Komponen-komponen\nsatuan R = Ohm dan C = nanoFarad",)
    in_label.grid(column = 1,row = 0)
    v_label = Label(root, text = "V")
    v_label.grid(column = 1,row = 1)
    v_entry = Entry(root,textvariable = v_var)
    v_entry.grid(column = 1, row = 2)
    r1_label = Label(root, text = "R1")
    r1_label.grid(column = 1,row = 3)
    r1_entry = Entry(root,textvariable = r1_var)
    r1_entry.grid(column = 1, row = 4)
    r2_label = Label(root, text = "R2")
    r2_label.grid(column = 1,row = 5)
    r2_entry = Entry(root,textvariable = r2_var)
    r2_entry.grid(column = 1, row = 6)
    r3_label = Label(root, text = "R3")
    r3_label.grid(column = 1,row = 7)
    r3_entry = Entry(root,textvariable = r3_var)
    r3_entry.grid(column = 1, row = 8)
    c1_label = Label(root, text = "C1")
    c1_label.grid(column = 1,row = 9)
    c1_entry = Entry(root,textvariable = c1_var)
    c1_entry.grid(column = 1, row = 10)
    c2_label = Label(root, text = "C2")
    c2_label.grid(column = 1,row = 11)
    c2_entry = Entry(root,textvariable = c2_var)
    c2_entry.grid(column = 1, row = 12)
    c3_label = Label(root, text = "C3")
    c3_label.grid(column = 1,row = 13)
    c3_entry = Entry(root,textvariable = c3_var)
    c3_entry.grid(column = 1, row = 14)
    user_label = Label(root, text = "Pilihan Komponen yang ingin Dianalisis")
    user_label.grid(column = 1,row = 15)
    user_entry = Entry(root,textvariable = user_var)
    user_entry.grid(column = 1, row = 16)

def submit(Rc,Cc,CircuitCode):
    v = v_var.get()
    r1 = r1_var.get()
    r2 = r2_var.get()
    r3 = r3_var.get()
    c1 = c1_var.get()
    c2 = c2_var.get()
    c3 = c3_var.get()
    user_in = user_var.get()
    print(v)
    print(Rc)
    print(str(Rc))
    print(Cc)
    file = open('input_rangkaian_a.txt','w')
    file.write(v+"\n")
    file.write(str(Rc)+" "+r1+" "+r2+" "+r3+"\n")
    file.write(str(Cc)+" "+c1+" "+c2+" "+c3+"\n")
    file.write(user_in)
    file.close()
    file = open('input_rangkaian_b.txt','w')
    file.write(v+"\n")
    if(Rc==5):
        file.write(str(Rc)+" "+r3+" "+r1+" "+r2+"\n")
    else:
        file.write(str(Rc)+" "+r1+" "+r2+" "+r3+"\n")
    if(Cc==5):
        file.write(str(Cc)+" "+c3+" "+c1+" "+c2)
    elif(Cc==6):
        file.write(str(Cc)+" "+c2+" "+c1+" "+c3)
    else:
        file.write(str(Cc)+" "+c1+" "+c2+" "+c3)
    file.close()
    func_lib.executeAllProcess()
    #frame2.destroy();
    exemainloop();



def updateImage(Rchange,Cchange):
    global Rcode
    global Ccode
    Rcode = Rchange
    Ccode = Cchange

    if (Rchange == 4): 
        new_R = R_picFile1
    elif (Rchange == 5): 
        new_R = R_picFile2
    elif (Rchange == 6): 
        new_R = R_picFile3 
    else: 
        new_R = R_picFile4
    R_pic.itemconfig(R_picId, image=new_R)

    if (Cchange == 4): 
        new_C = C_picFile1
    elif (Cchange == 5): 
        new_C = C_picFile2
    elif (Cchange == 6): 
        new_C = C_picFile3 
    else: 
        new_C = C_picFile4
    C_pic.itemconfig(C_picId, image=new_C)




root = Tk() 
root.geometry('1300x900')
frame1 = Frame(root)
frame2 = Frame(root)
frame1.grid()

v_var = StringVar()
r1_var = StringVar()
r2_var = StringVar()
r3_var = StringVar()
c1_var = StringVar()
c2_var = StringVar()
c3_var = StringVar()
user_var = StringVar()

Rcode = 4
Ccode = 4 
R_picFile1 = PhotoImage(file = "circuit_images/R_1.png")
R_picFile2 = PhotoImage(file = "circuit_images/R_2.png")
R_picFile3 = PhotoImage(file = "circuit_images/R_3.png")
R_picFile4 = PhotoImage(file = "circuit_images/R_4.png")

C_picFile1 = PhotoImage(file = "circuit_images/C_1.png")
C_picFile2 = PhotoImage(file = "circuit_images/C_2.png")
C_picFile3 = PhotoImage(file = "circuit_images/C_3.png")
C_picFile4 = PhotoImage(file = "circuit_images/C_4.png")

RC_picFile1 = PhotoImage(file = "circuit_images/RC_1.png")
RC_picFile2 = PhotoImage(file = "circuit_images/RC_2.png")
RC_picFile3 = PhotoImage(file = "circuit_images/RC_3.png")
RC_picFile4 = PhotoImage(file = "circuit_images/RC_4.png")
RC_picFile5 = PhotoImage(file = "circuit_images/RC_5.png")
RC_picFile6 = PhotoImage(file = "circuit_images/RC_6.png")
RC_picFile7 = PhotoImage(file = "circuit_images/RC_7.png")
RC_picFile8 = PhotoImage(file = "circuit_images/RC_8.png")
RC_picFile9 = PhotoImage(file = "circuit_images/RC_9.png")
RC_picFile10 = PhotoImage(file = "circuit_images/RC_10.png")
RC_picFile11 = PhotoImage(file = "circuit_images/RC_11.png")
RC_picFile12 = PhotoImage(file = "circuit_images/RC_12.png")
RC_picFile13 = PhotoImage(file = "circuit_images/RC_13.png")
RC_picFile14 = PhotoImage(file = "circuit_images/RC_14.png")
RC_picFile15 = PhotoImage(file = "circuit_images/RC_15.png")
RC_picFile16 = PhotoImage(file = "circuit_images/RC_16.png")

R_label = Label(frame1, text = "Resistor:")
R_label.grid(column = 0,row = 0)
R_button1 = Button(frame1, text='Konfigurasi 1', width=25, command=lambda :updateImage(4,Ccode))
R_button1.grid(column = 0,row = 1) 
R_button2 = Button(frame1, text='Konfigurasi 2', width=25, command=lambda :updateImage(5,Ccode))
R_button2.grid(column = 0,row = 2) 
R_button3 = Button(frame1, text='Konfigurasi 3', width=25, command=lambda :updateImage(6,Ccode))
R_button3.grid(column = 0,row = 3) 
R_button4 = Button(frame1, text='Konfigurasi 4', width=25, command=lambda :updateImage(7,Ccode)) 
R_button4.grid(column = 0,row = 4)
R_pic = Canvas(frame1,width = 600,height = 400)
R_pic.grid(column = 0,row = 5,padx = 10) 
R_picId = R_pic.create_image(10,10,anchor = NW,image = R_picFile1)

C_label = Label(frame1, text = "Resistor:")
C_label.grid(column = 1,row = 0)
C_button1 = Button(frame1, text='Konfigurasi 1', width=25, command=lambda :updateImage(Rcode,4))
C_button1.grid(column = 1,row = 1) 
C_button2 = Button(frame1, text='Konfigurasi 2', width=25, command=lambda :updateImage(Rcode,5))
C_button2.grid(column = 1,row = 2) 
C_button3 = Button(frame1, text='Konfigurasi 3', width=25, command=lambda :updateImage(Rcode,6))
C_button3.grid(column = 1,row = 3) 
C_button4 = Button(frame1, text='Konfigurasi 4', width=25, command=lambda :updateImage(Rcode,7)) 
C_button4.grid(column = 1,row = 4)
C_pic = Canvas(frame1,width = 600,height = 400)
C_pic.grid(column = 2,row = 5,sticky = "ew") 
C_picId = C_pic.create_image(10,10,anchor = NW,image = C_picFile1)

button = Button(frame1, text='Next', width=25, command=input_circuit) 
button.grid() 
root.grid_columnconfigure((0, 1), weight=100)
mainloop()
