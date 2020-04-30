from tkinter import *
import array as arr
import re
from matplotlib import pyplot as plt
from matplotlib import style


def createEquiCircuit(canvas,screen):
    canvas.delete("all");

    file = open("komponen_rangkaian_equivalen.txt","r")
    V = file.readline();
    R = file.readline();
    C = file.readline();
    file.close()
    
    V = re.split(" |\n",V);
    R = re.split(" |\n",R);
    C = re.split(" |\n",C);
    
    init_x = int(300);
    init_y = int(100);

    fac_res = 3;
    dx = 0.5*5*fac_res;
    dy = 0.5*20*fac_res;

    
    #CREATE RESISTOR
    node1x_res = 190
    node1y_res = 90
    node2x_res = node1x_res + fac_res*5
    node2y_res = node1y_res - fac_res*20
    node3x_res = node2x_res + fac_res*5
    node3y_res = node2y_res + fac_res*20
    node4x_res = node3x_res + fac_res*5
    node4y_res = node3y_res - fac_res*20
    node5x_res = node4x_res + fac_res*5
    node5y_res = node4y_res + fac_res*20
    node6x_res = node5x_res + fac_res*5
    node6y_res = node5y_res - fac_res*20
    node7x_res = node6x_res + fac_res*5
    node7y_res = node6y_res + fac_res*20
    canvas.create_line(init_x+node1x_res+dx, init_y+node1y_res-dy, init_x+node2x_res, init_y+node2y_res,fill="black", width=2)
    canvas.create_line(init_x+node2x_res, init_y+node2y_res, init_x+node3x_res, init_y+node3y_res, fill="black", width=2)
    canvas.create_line(init_x+node3x_res, init_y+node3y_res, init_x+node4x_res, init_y+node4y_res, fill="black", width=2)
    canvas.create_line(init_x+node4x_res, init_y+node4y_res, init_x+node5x_res, init_y+node5y_res, fill="black", width=2)
    canvas.create_line(init_x+node5x_res, init_y+node5y_res, init_x+node6x_res, init_y+node6y_res, fill="black", width=2)
    canvas.create_line(init_x+node6x_res, init_y+node6y_res, init_x+node7x_res-dx, init_y+node7y_res-dy, fill="black", width=2)

    #CREATE CAPASITOR
    fac_cap = 1.5
    node1x_cap = 380
    node1y_cap = 200
    node2x_cap = node1x_cap + fac_cap*60
    node2y_cap = node1y_cap
    node3x_cap = node1x_cap
    node3y_cap = node1y_cap + fac_cap*20
    node4x_cap = node2x_cap
    node4y_cap = node2y_cap + fac_cap*20
    canvas.create_line(init_x+node1x_cap, init_y+node1y_cap, init_x+node2x_cap, init_y+node2y_cap, fill="black", width=2)
    canvas.create_line(init_x+node3x_cap, init_y+node3y_cap, init_x+node4x_cap, init_y+node4y_cap, fill="black", width=2)

    #CREATE VOLTAGE
    r = 80
    node1x_vol = 30
    node2x_vol = node1x_vol + r
    tengahx = (node1x_vol + node2x_vol)/2
    node1y_vol = 180
    node2y_vol= node1y_vol + r
    tengahy = (node1y_vol + node2y_vol)/2
    
    
    canvas.create_oval(init_x+node1x_vol, init_y+node1y_vol,init_x+node2x_vol, init_y+node2y_vol, fill = "", outline="black", width=2)

    #WIRING
    canvas.create_line(init_x+node1x_res+dx,init_y+node1y_res-dy,init_x+tengahx, init_y+node1y_res-dy, fill="black", width=2);
    canvas.create_line(init_x+tengahx,init_y+node1y_res-dy,init_x+tengahx, init_y+node1y_vol, fill="black", width=2);
    canvas.create_line(init_x+tengahx, init_y+node2y_vol,init_x+tengahx,init_y+ node2y_vol+node1y_vol-node1y_res+dy, fill="black", width=2);
    canvas.create_line(init_x+tengahx,init_y+node2y_vol+node1y_vol-node1y_res+dy,init_x+((node1x_cap + node2x_cap)/2),init_y+node2y_vol+node1y_vol-node1y_res+dy, fill="black", width=2);
    canvas.create_line(init_x+((node1x_cap + node2x_cap)/2),init_y+node2y_vol+node1y_vol-node1y_res+dy,init_x+((node1x_cap + node2x_cap)/2),init_y+node4y_cap, fill="black", width=2);
    canvas.create_line(init_x+((node1x_cap + node2x_cap)/2),init_y+node1y_cap,init_x+((node1x_cap + node2x_cap)/2),init_y+node7y_res-dy, fill="black", width=2);
    canvas.create_line(init_x+((node1x_cap + node2x_cap)/2),init_y+node7y_res-dy,init_x+node7x_res-dx,init_y+node7y_res-dy, fill="black", width=2);

    #create label
    res_text = Label(screen,text="R = "+R[0]+" ohm", font=("arial",14))
    res_text.place(x=init_x+node3x_res+10,y=init_y+node2y_res-20) #x node pertama resistor, y node atas
    canvas.create_window(init_x+node3x_res+10, init_y+node2y_res-20, window=res_text)  
    cap_text = Label(screen,text="C = "+C[0]+" F", font=("arial",14))
    cap_text.place(x=init_x+node2x_cap+50,y=init_y+((node1y_cap+node2y_cap)/2)+15) #x node paling kanan kapasitor, y node atas
    canvas.create_window(init_x+node2x_cap+50, init_y+((node1y_cap+node2y_cap)/2)+15, window=cap_text) 
    pos_text = Label(screen,text="+",font=("arial",14))
    pos_text.place(x=init_x+tengahx,y=init_y+node1y_vol+25)
    canvas.create_window(init_x+tengahx, init_y+node1y_vol+25, window=pos_text) 
    neg_text = Label(screen,text="-",font=("arial",14))
    neg_text.place(x=init_x+tengahx,y=init_y+node2y_vol-25)
    canvas.create_window(init_x+tengahx, init_y+node2y_vol-25, window=neg_text)
    vol_text = Label(screen,text="V = "+V[0]+" V", font=("arial",14))
    vol_text.place(x=init_x+node2x_vol+50,y=init_y+tengahy)
    canvas.create_window(init_x+node2x_vol+50, init_y+tengahy, window=vol_text)

    return;

#---------------------- Another def -------------------------------------------------------------------------------

def createCircuit(canvas,screen):
    canvas.delete("all");

    file = open("input_rangkaian_a.txt","r")
    V = file.readline();
    R = file.readline();
    C = file.readline();
    file.close()

    V = re.split(" |\n",V);
    R = re.split(" |\n",R);
    C = re.split(" |\n",C);

    init_x = int(300);
    init_y = int(10);


    #create resistor
    fac_res = 2;
    dx = 0.5*5*fac_res;
    dy = 0.5*20*fac_res;

    node1x_res = arr.array('i',[]);
    node1y_res = arr.array('i',[]);
    node2x_res = arr.array('i',[]);
    node2y_res = arr.array('i',[]);
    node3x_res = arr.array('i',[]);
    node3y_res = arr.array('i',[]);
    node4x_res = arr.array('i',[]);
    node4y_res = arr.array('i',[]);
    node5x_res = arr.array('i',[]);
    node5y_res = arr.array('i',[]);
    node6x_res = arr.array('i',[]);
    node6y_res = arr.array('i',[]);
    node7x_res = arr.array('i',[]);
    node7y_res = arr.array('i',[]);

    if(R[0] == "4") :
        node1x_res.append(160) #wiring
        node1y_res.append(200) #wiring
        node1x_res.append(260)
        node1y_res.append(200)
        node1x_res.append(360) #the end wiring
        node1y_res.append(200)
    elif(R[0] == "7") :
        node1x_res.append(200)
        node1y_res.append(130)
        node1x_res.append(200) #wiring
        node1y_res.append(200) #wiring
        node1x_res.append(200)
        node1y_res.append(270)
    elif(R[0] == "5") :
        node1x_res.append(200) #wiring
        node1y_res.append(200)
        node1x_res.append(300)#the end wiring
        node1y_res.append(200)
        node1x_res.append(250)
        node1y_res.append(130)
    elif(R[0] == "6") :
        node1x_res.append(160) 
        node1y_res.append(130)
        node1x_res.append(160) #wiring
        node1y_res.append(200)
        node1x_res.append(360) #the end wiring
        node1y_res.append(200)
        
        

    for i in range (3) :
        node2x_res.append(node1x_res[i] + fac_res*5)
        node2y_res.append(node1y_res[i] - fac_res*20)
        node3x_res.append(node2x_res[i] + fac_res*5)
        node3y_res.append(node2y_res[i] + fac_res*20)
        node4x_res.append(node3x_res[i] + fac_res*5)
        node4y_res.append(node3y_res[i] - fac_res*20)
        node5x_res.append(node4x_res[i] + fac_res*5)
        node5y_res.append(node4y_res[i] + fac_res*20)
        node6x_res.append(node5x_res[i] + fac_res*5)
        node6y_res.append(node5y_res[i] - fac_res*20)
        node7x_res.append(node6x_res[i] + fac_res*5)
        node7y_res.append(node6y_res[i] + fac_res*20)
        canvas.create_line(init_x+node1x_res[i]+dx, init_y+node1y_res[i]-dy, init_x+node2x_res[i], init_y+node2y_res[i],fill="black", width=2)
        canvas.create_line(init_x+node2x_res[i], init_y+node2y_res[i], init_x+node3x_res[i], init_y+node3y_res[i], fill="black", width=2)
        canvas.create_line(init_x+node3x_res[i], init_y+node3y_res[i], init_x+node4x_res[i], init_y+node4y_res[i], fill="black", width=2)
        canvas.create_line(init_x+node4x_res[i], init_y+node4y_res[i], init_x+node5x_res[i], init_y+node5y_res[i], fill="black", width=2)
        canvas.create_line(init_x+node5x_res[i], init_y+node5y_res[i], init_x+node6x_res[i], init_y+node6y_res[i], fill="black", width=2)
        canvas.create_line(init_x+node6x_res[i], init_y+node6y_res[i], init_x+node7x_res[i]-dx, init_y+node7y_res[i]-dy, fill="black", width=2)

    #CREATE CAPASITOR
    fac_cap = 1
    node1x_cap = arr.array('i',[]);
    node1y_cap = arr.array('i',[]);
    node2x_cap = arr.array('i',[]);
    node2y_cap = arr.array('i',[]);
    node3x_cap = arr.array('i',[]);
    node3y_cap = arr.array('i',[]);
    node4x_cap = arr.array('i',[]);
    node4y_cap = arr.array('i',[]);

    if(C[0] == "4") :
        node1x_cap.append(500)#WIRING
        node1y_cap.append(230)
        node1x_cap.append(500)
        node1y_cap.append(300)
        node1x_cap.append(500)#WIRING
        node1y_cap.append(370)
    elif(C[0] == "7") :
        node1x_cap.append(400)
        node1y_cap.append(300)
        node1x_cap.append(500)#WIRING
        node1y_cap.append(300)
        node1x_cap.append(600)
        node1y_cap.append(300)
    elif (C[0] == "5"):
        node1x_cap.append(500)
        node1y_cap.append(250)
        node1x_cap.append(500)
        node1y_cap.append(330)
        node1x_cap.append(600)
        node1y_cap.append(290)
    elif(C[0] == "6"):
        node1x_cap.append(500) #wiring
        node1y_cap.append(230)
        node1x_cap.append(600)
        node1y_cap.append(230)
        node1x_cap.append(500) #wiring end
        node1y_cap.append(330)
        

    for i in range (3) :
        node2x_cap.append(node1x_cap[i] + fac_cap*60)
        node2y_cap.append(node1y_cap[i])
        node3x_cap.append(node1x_cap[i])
        node3y_cap.append(node1y_cap[i] + fac_cap*20)
        node4x_cap.append(node2x_cap[i])
        node4y_cap.append(node2y_cap[i] + fac_cap*20)
        canvas.create_line(init_x+node1x_cap[i], init_y+node1y_cap[i], init_x+node2x_cap[i], init_y+node2y_cap[i], fill="black", width=2)
        canvas.create_line(init_x+node3x_cap[i], init_y+node3y_cap[i], init_x+node4x_cap[i], init_y+node4y_cap[i], fill="black", width=2)

    #CREATE VOLTAGE
    r = 60
    node1x_vol = 30
    node2x_vol = node1x_vol + r
    tengahx = (node1x_vol + node2x_vol)/2
    node1y_vol = 270
    node2y_vol= node1y_vol + r
    tengahy = (node1y_vol + node2y_vol)/2

    canvas.create_oval(init_x+node1x_vol, init_y+node1y_vol,init_x+node2x_vol, init_y+node2y_vol, fill = "", outline="black", width=2)


    #labeling
    #resistor label
    res_text1 = Label(screen,text="R1 = "+R[1]+" ohm", font=("arial",10))
    res_text1.place(x=init_x+node3x_res[0]+10,y=init_y+node2y_res[0]-10) #x node pertama resistor, y node atas
    canvas.create_window(init_x+node3x_res[0]+10, init_y+node2y_res[0]-10, window=res_text1)
    res_text2 = Label(screen,text="R2 = "+R[2]+" ohm", font=("arial",10))
    res_text2.place(x=init_x+node3x_res[1]+10,y=init_y+node2y_res[1]-10) #x node pertama resistor, y node atas
    canvas.create_window(init_x+node3x_res[1]+10, init_y+node2y_res[1]-10, window=res_text2)
    res_text3 = Label(screen,text="R3 = "+R[3]+" ohm", font=("arial",10))
    res_text3.place(x=init_x+node3x_res[2]+10,y=init_y+node2y_res[2]-10) #x node pertama resistor, y node atas
    canvas.create_window(init_x+node3x_res[2]+10, init_y+node2y_res[2]-10, window=res_text3)
    #voltage label
    pos_text = Label(screen,text="+",font=("arial",12))
    pos_text.place(x=init_x+tengahx,y=init_y+node1y_vol+15)
    canvas.create_window(init_x+tengahx, init_y+node1y_vol+15, window=pos_text) 
    neg_text = Label(screen,text="-",font=("arial",12))
    neg_text.place(x=init_x+tengahx,y=init_y+node2y_vol-15)
    canvas.create_window(init_x+tengahx, init_y+node2y_vol-15, window=neg_text)
    vol_text = Label(screen,text="V = "+V[0]+" V", font=("arial",12))
    vol_text.place(x=init_x+node2x_vol+40,y=init_y+tengahy)
    canvas.create_window(init_x+node2x_vol+40, init_y+tengahy, window=vol_text)
    #capasaitor label
    cap_text1 = Label(screen,text="C1 = "+C[1]+" F", font=("arial",10))
    cap_text1.place(x=init_x+node3x_cap[0]+20,y=init_y+node3y_cap[0]+20)
    canvas.create_window(init_x+node3x_cap[0]+20, init_y+node3y_cap[0]+20, window=cap_text1)
    cap_text2 = Label(screen,text="C2 = "+C[2]+" F", font=("arial",10))
    cap_text2.place(x=init_x+node3x_cap[1]+20,y=init_y+node3y_cap[1]+20)
    canvas.create_window(init_x+node3x_cap[1]+20, init_y+node3y_cap[1]+20, window=cap_text2)
    cap_text3 = Label(screen,text="C3 = "+C[3]+" F", font=("arial",10))
    cap_text3.place(x=init_x+node3x_cap[2]+20,y=init_y+node3y_cap[2]+20)
    canvas.create_window(init_x+node3x_cap[2]+20, init_y+node3y_cap[2]+20, window=cap_text3)

    # wiring
    if(R[0] == "4") :
        canvas.create_line(init_x+node1x_res[0]+dx, init_y+node1y_res[0]-dy, init_x+tengahx, init_y+node1y_res[0]-dy, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node1y_res[0]-dy,init_x+tengahx, init_y+node1y_vol, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[0]-dx, init_y+node7y_res[0]-dy,init_x+node1x_res[1]+dx, init_y+node1y_res[1]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[1]-dx, init_y+node7y_res[1]-dy,init_x+node1x_res[2]+dx, init_y+node1y_res[2]-dy, fill="black", width=2)
        last_nodex = node7x_res[2]-dx
        last_nodey = node7y_res[2]-dy
    elif(R[0] == "7") :
        canvas.create_line(init_x+node1x_res[1]+dx, init_y+node1y_res[1]-dy, init_x+tengahx, init_y+node1y_res[1]-dy, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node1y_res[1]-dy,init_x+tengahx, init_y+node1y_vol, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[0]+dx, init_y+node1y_res[0]-dy,init_x+node1x_res[0]+dx-70, init_y+node1y_res[0]-dy, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[2]+dx, init_y+node1y_res[2]-dy,init_x+node1x_res[2]+dx-70, init_y+node1y_res[2]-dy, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[0]+dx-70, init_y+node1y_res[0]-dy,init_x+node1x_res[2]+dx-70, init_y+node1y_res[2]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[0]-dx, init_y+node7y_res[0]-dy,init_x+node7x_res[0]-dx+70, init_y+node7y_res[0]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[2]-dx, init_y+node7y_res[2]-dy,init_x+node7x_res[2]-dx+70, init_y+node7y_res[2]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[0]-dx+70, init_y+node7y_res[0]-dy,init_x+node7x_res[2]-dx+70, init_y+node7y_res[2]-dy, fill="black", width=2)
        last_nodex = node7x_res[1]-dx
        last_nodey = node7y_res[1]-dy
    elif(R[0] == "5") :
        canvas.create_line(init_x+node1x_res[0]+dx, init_y+node1y_res[0]-dy, init_x+tengahx, init_y+node1y_res[0]-dy, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node1y_res[0]-dy,init_x+tengahx, init_y+node1y_vol, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[0]-dx, init_y+node7y_res[0]-dy,init_x+node1x_res[1]+dx, init_y+node1y_res[1]-dy, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[2]+dx, init_y+node1y_res[2]-dy,init_x+node1x_res[0]+dx-70, init_y+node1y_res[2]-dy, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[0]+dx-70, init_y+node1y_res[2]-dy,init_x+node1x_res[0]+dx-70, init_y+node1y_res[0]-dy, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[2]+dx, init_y+node1y_res[2]-dy,init_x+node1x_res[0]+dx-70, init_y+node1y_res[2]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[2]-dx, init_y+node7y_res[2]-dy,init_x+node7x_res[1]-dx+70, init_y+node7y_res[2]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[1]-dx+70, init_y+node7y_res[2]-dy,init_x+node7x_res[1]-dx+70, init_y+node7y_res[1]-dy, fill="black", width=2)
        last_nodex = node7x_res[1]-dx
        last_nodey = node7y_res[1]-dy
    elif(R[0] == "6") :
        canvas.create_line(init_x+node1x_res[1]+dx, init_y+node1y_res[1]-dy, init_x+tengahx, init_y+node1y_res[1]-dy, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node1y_res[1]-dy,init_x+tengahx, init_y+node1y_vol, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[1]-dx, init_y+node7y_res[1]-dy,init_x+node1x_res[2]+dx, init_y+node1y_res[2]-dy, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[0]+dx, init_y+node1y_res[0]-dy,init_x+node1x_res[0]+dx-70, init_y+node1y_res[0]-dy, fill="black", width=2)
        canvas.create_line(init_x+node1x_res[0]+dx-70, init_y+node1y_res[0]-dy,init_x+node1x_res[0]+dx-70, init_y+node1y_res[1]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[0]-dx, init_y+node7y_res[0]-dy,init_x+node7x_res[0]-dx+70, init_y+node7y_res[0]-dy, fill="black", width=2)
        canvas.create_line(init_x+node7x_res[0]-dx+70, init_y+node7y_res[0]-dy,init_x+node7x_res[0]-dx+70, init_y+node7y_res[1]-dy, fill="black", width=2)
        last_nodex = node7x_res[2]-dx
        last_nodey = node7y_res[2]-dy
    if(C[0] == "4") :
        dy_cap = node1y_cap[0]-last_nodey
        canvas.create_line(init_x+last_nodex, init_y+last_nodey, init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+last_nodey, fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+last_nodey,init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node3y_cap[0],init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node1y_cap[1], fill="black", width=2) #penghubung c1 dan c2
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1],init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node1y_cap[2], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2],init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[2]+dy_cap, fill="black", width=2) #yang bawah
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[2]+dy_cap,init_x+tengahx, init_y+node3y_cap[2]+dy_cap, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node3y_cap[2]+dy_cap,init_x+tengahx, init_y+node2y_vol, fill="black", width=2)
    elif(C[0] == "7") :
        dy_cap = node1y_cap[1]-last_nodey
        canvas.create_line(init_x+last_nodex, init_y+last_nodey, init_x+((node1x_cap[1]+node2x_cap[1])/2), init_y+last_nodey, fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[1]+node2x_cap[1])/2), init_y+last_nodey,init_x+((node1x_cap[1]+node2x_cap[1])/2), init_y+node1y_cap[1], fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0],init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0]-70, fill="black", width=2)#atas
        canvas.create_line(init_x+((node1x_cap[2]+node2x_cap[2])/2), init_y+node1y_cap[2],init_x+((node1x_cap[2]+node2x_cap[2])/2), init_y+node1y_cap[2]-70, fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0]-70,init_x+((node1x_cap[2]+node2x_cap[2])/2), init_y+node1y_cap[2]-70, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node3y_cap[0],init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node3y_cap[0]+70, fill="black", width=2)#bawah
        canvas.create_line(init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2],init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2]+70, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node3y_cap[0]+70,init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2]+70, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1],init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1]+dy_cap, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1]+dy_cap,init_x+tengahx, init_y+node3y_cap[1]+dy_cap, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node3y_cap[1]+dy_cap,init_x+tengahx, init_y+node2y_vol, fill="black", width=2)    
    elif (C[0] == "5"):
        dy_cap = node1y_cap[0]-last_nodey
        canvas.create_line(init_x+last_nodex, init_y+last_nodey, init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+last_nodey, fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+last_nodey,init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node3y_cap[0],init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node1y_cap[1], fill="black", width=2) #penghubung c1 dan c2
        canvas.create_line(init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0]-40,init_x+((node1x_cap[2]+node2x_cap[2])/2), init_y+node1y_cap[0]-40, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node1y_cap[0]-40,init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node1y_cap[2], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1]+40,init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[1]+40, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[1]+40,init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1],init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1]+dy_cap, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1]+dy_cap,init_x+tengahx, init_y+node3y_cap[1]+dy_cap, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node3y_cap[1]+dy_cap,init_x+tengahx, init_y+node2y_vol, fill="black", width=2)
    elif(C[0] == "6"):
        dy_cap = node1y_cap[0]-last_nodey
        canvas.create_line(init_x+last_nodex, init_y+last_nodey, init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+last_nodey, fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+last_nodey,init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node3y_cap[0],init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node1y_cap[2], fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[0]+node2x_cap[0])/2), init_y+node1y_cap[0]-30,init_x+((node1x_cap[1]+node2x_cap[1])/2), init_y+node1y_cap[0]-30, fill="black", width=2)
        canvas.create_line(init_x+((node1x_cap[1]+node2x_cap[1])/2), init_y+node1y_cap[0]-30,init_x+((node1x_cap[1]+node2x_cap[1])/2), init_y+node1y_cap[1], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[0]+node4x_cap[0])/2), init_y+node3y_cap[0]+40,init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[0]+40, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[0]+40,init_x+((node3x_cap[1]+node4x_cap[1])/2), init_y+node3y_cap[1], fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2],init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2]+dy_cap, fill="black", width=2)
        canvas.create_line(init_x+((node3x_cap[2]+node4x_cap[2])/2), init_y+node3y_cap[2]+dy_cap,init_x+tengahx, init_y+node3y_cap[2]+dy_cap, fill="black", width=2)
        canvas.create_line(init_x+tengahx, init_y+node3y_cap[2]+dy_cap,init_x+tengahx, init_y+node2y_vol, fill="black", width=2)
    return;

def generateEquiGraph() :
    plt.close("all");
    #creating an array with 'd' as double float
    time1 = arr.array('d',[]); #array for time
    value1 = arr.array('d',[]); #array for voltage/current
    time2 = arr.array('d',[]); #array for time
    value2 = arr.array('d',[]); #array for voltage/current
    #reading file

    filename = "rangkaian_RC_test.csv";
    file = open(filename,'r');

    #reading entire line in file eksternal
    with open(filename,'r') as filehandle:
        for line in filehandle:
            #cek = re.split(" |\n",line); #splitting the line with the deliminator " " or "\n"
            token = re.split(";",line); #splitting the line with the deliminator ";"
            time1.append(float(token[0]));
            value1.append(float(token[1]));
            time2.append(float(token[2]));
            value2.append(float(token[3]));
    file.close();

    #displaying the graphic
    style.use('ggplot')

    fig,(ax1,ax2) = plt.subplots(2)
    ax1.scatter(time1, value1)#time vs voltage
    ax2.scatter(time2, value2)#time vs current
    fig.suptitle('Grafik Tegangan dan Arus pada Rangkaian Ekuivalen');
    ax1.set(xlabel = "time(s)",ylabel = "voltage(V)");
    ax2.set(xlabel = "time(s)",ylabel = "current(A)");
    plt.show()

    return;

def generateGraph (user_input):
    plt.close("all");
    #creating an array with 'd' as double float
    time = arr.array('d',[]); #array for time
    value = arr.array('d',[]); #array for voltage/current

    #reading file
    filename = "rangkaian_RC.csv";
    file = open(filename,'r');

    #reading entire line in file eksternal
    with open(filename,'r') as filehandle:
        for line in filehandle:
            #cek = re.split(" |\n",line); #splitting the line with the deliminator " " or "\n"
            token = re.split(";",line); #splitting the line with the deliminator ";"
            time.append(float(token[0]));
            value.append(float(token[1]));
    file.close();

    #displaying the graphic
    style.use('ggplot')
    plt.scatter(time, value)#, align='center'
    if((user_input == 'v') or (user_input == 'V')) :
        plt.title('Voltage vs Time');
        plt.ylabel('Voltage(V)');
        plt.xlabel('Time(s)');
    elif ((user_input == 'i') or (user_input == 'I')) :
        plt.title('Current vs Time');
        plt.ylabel('Current(A)');
        plt.xlabel('Time(s)');
    plt.show()

    return;
#------------------------------------------------------------------------------------------


def exemainloop():
    screen = Tk();
    #screen.geometry('900x900')
    screen.title("Gambar Rangkaian");

    canvas = Canvas(screen, width=1500, height=600)
    canvas.pack();
    
    def quit() :
        screen.destroy();
    b1 = Button(screen, text = "Show Equivalent Circuit",width=30,command=lambda :createEquiCircuit(canvas,screen))
    b2 = Button(screen, text = "Show Circuit",width=30,command=lambda : createCircuit(canvas,screen))
    b3 = Button(screen, text = "Generate Equivalent Graphic",width=30,command=generateEquiGraph)
    b4 = Button(screen, text = "Generate Graphic",width=30,command=lambda : generateGraph("V"))#gk bisa letakkan parameter sebagai command
    b_quit = Button(screen, text = "Quit",width=30,command=quit)
    b1.place(relx = 0.1, rely = 0.1, anchor = CENTER)
    b2.place(relx = 0.1, rely = 0.15, anchor = CENTER)
    b3.place(relx = 0.1, rely = 0.2, anchor = CENTER)
    b4.place(relx = 0.1, rely = 0.25, anchor = CENTER)
    b_quit.place(relx = 0.1, rely = 0.3, anchor = CENTER)
    mainloop()

