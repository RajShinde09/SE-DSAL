
Hashtable=[[]for i in range(10)]

def hashing(keyvalue):
    return keyvalue%len(Hashtable)

def insert(Hashtable,keyvalue,value):
    hash_key=hashing(keyvalue)
    Hashtable[hash_key].append(value)
    
def display(Hashtable):
    print("\tIndex\t\tNames")
    for i in range(len(Hashtable)):
        print("\t",i,end=" ")
        for j in Hashtable[i]:
            print("---->",end=" ")
            print(j,end=" ")
        print()
    
def delete(Hashtable,value):
    flag=0
    for i in range(len(Hashtable)):
        for j in Hashtable[i]:
            if(j==value):
                Hashtable[i].remove(j)
                print("Value deleted..")
                flag=1
    if(flag==0):
        print("Invalid")
        
def search(Hashtable,value):
    flag=0
    for i in range(len(Hashtable)):
        for j in Hashtable[i]:
            if(j==value):
                print("Value found")
                flag=1
    if(flag==0):
        print("Not Found")
        
        
print("\n1.Insert \n2.Display \n3.Delete \n4.Search")


while(ch):
    ch=int(input("Enter choice: "))
    if (ch==1):
        rn=int(input("Enter roll no: "))
        name=input("Enter name: ")
        insert(Hashtable,rn,name)
        
    elif(ch==2):
        display(Hashtable)
        
    elif(ch==3):
        name=input("Enter name: ")
        delete(Hashtable,name)
        
    elif(ch==4):
        name=input("Enter name: ")
        search(Hashtable,name)

