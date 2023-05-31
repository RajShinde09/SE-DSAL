#!/usr/bin/env python
# coding: utf-8

# In[ ]:


size=int(input("Enter the size of Hashtable: "))
num_l=[-1 for i in range(size)]
num_q=[-1 for i in range(size)]
name_l=["empty" for i in range(size)]
name_q=["empty" for i in range(size)]

def hash_key(num):
    return num%size

def quadratic_key(key):
    i=0
    k=((i**2)+key)%size
    while(num_q[key]!=-1):
        i+=1
        k=((i**2)+key)%size
        
def linear(num,name,key):
    success=False
    for i in range(key,size):
        if(num_l[key]==-1):
            num_l[key]=num
            name_l[key]=name
            print("Data added successfully!!")
            success=True
            break
            
    if(success==False):
        for i in range(0,key):
            if(num_l[key]==-1):
                num_l[key]=num
                name_l[key]=name
                print("Data added...")
                success=True
                break
                
def quadratic(num,name,key):
    k=quadratic_key(key)
    num_q[k]=num
    name_q[k]=name
    print("data added")
    
def add_data(n):
    for i in range(n):
        name=input("Enter name: ")
        num=int(input("Enter roll no: "))
        key=hash_key(num)
        
        if(num_l[key]==-1):
            num_l[key]=num
            name_l[key]=name
            
        else:
            print("Collision Occured..")
            linear(num,name,key)
            
        if(num_q[key]==-1):
            num_q[key]=num
            name_q[key]=name
            
        else:
            print("Collision Occured..")
            quadratic(num,name,key)
            
def search():
    name=input("Enter name for search: ")
    comparisons_l=0
    comparisons_q=0
    found_l=False
    found_q=False
    
    for i in name_l:
        comparisons_l+=1
        if(name==i):
            print("Data found")
            print(f"{name_l} ===> {num_l[comparisons_l-1]}")
            found_l=True
            break
            
    for i in name_q:
        comparisons_q+=1
        if(name==i):
            print("Data found")
            print(f"{name_q} ===> {num_q[comparisons_q-1]}")
            found_q=True
            break
            
    if(found_l and found_q):
        print(f"No of comparisons in linear probing: {comparisons_l}")
        print(f"No of comparisons in Quadratic probing: {comparisons_q}")
        
    else:
        print("No data found")
        
def display():
    print("Linear Probing: ")
    print(f"{name_l} ===> {num_l}")
    print("Quadratic Probing: ")
    print(f"{name_q} ===> {num_q}")
    
n=int(input("Enter the no of elements: "))
if(n<size):
    add_data(n)
display()
search()
            
        


# In[ ]:




