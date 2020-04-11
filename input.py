from tkinter import *

def init_output():
    c = 3

def input_circuit():
    if (Rcode == 4):
        if(Ccode == 4):
            circuit_code = 1
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 5):
            circuit_code = 2
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 6):
            circuit_code = 3
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 7):
            circuit_code = 4
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
    elif (Rcode == 5):
        if(Ccode == 4):
            circuit_code = 5
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 5):
            circuit_code = 6
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 6):
            circuit_code = 7
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 7):
            circuit_code = 8
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
    elif (Rcode == 6):
        if(Ccode == 4):
            circuit_code = 9
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 5):
            circuit_code = 10
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 6):
            circuit_code = 11
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 7):
            circuit_code = 12
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
    elif (Rcode == 7):
        if(Ccode == 4):
            circuit_code = 13
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 5):
            circuit_code = 14
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 6):
            circuit_code = 15
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")
        elif(Ccode == 7):
            circuit_code = 16
            RC_picFile = PhotoImage(file = "circuit_images/ggg3.png")

    RC_pic = Canvas(root,width = 800,height = 400)
    RC_pic.grid()
    RC_picId = RC_pic.create_image(10,10,anchor = NW,image = RC_picFile)
    print(circuit_code)

    frame1.destroy()



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
frame1.grid()

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
C_pic.grid(column = 1,row = 5,sticky = W) 
C_picId = C_pic.create_image(10,10,anchor = NW,image = C_picFile1)

button = Button(frame1, text='Next', width=25, command=input_circuit) 
button.grid() 
mainloop()
