# Assignment-1
# Consider telephone book database of N clients. Make use of a hash table implementation to 
# quickly look up client‘s telephone number.

SIZE = 10
ch = 0
databasee = [None] * SIZE

def hash(val): return val % SIZE

def insert_data(record):
	hashed_index = hash(record[1])
	for i in range(SIZE):
		if databasee[hashed_index] is None:
			databasee[hashed_index] = record
			print("Record added to database.")
			return
		hashed_index = (hashed_index + 1) % SIZE
	print("Database is full.")

def search(ph_number):
    hashed_index = hash(ph_number)
    i = 0
    while i < SIZE:
        record = databasee[hashed_index]
        if record is None:
            break
        if record[1] == ph_number:
            print("Record Found: ", databasee[hashed_index])
            return
        hashed_index = (hashed_index + 1) % SIZE
        i += 1
    print("No Such Data.")


def display(): print(databasee)
	
while True:
    print("\n1. Enter Data.")
    print("2. Search Data.")
    print("3. Display Data.")
    print("0. Exit.")
    ch = int(input("Enter Your Choice: "))
    if(ch == 1):
        record = []
        record.append(input("Enter Name             : "))
        record.append(int(input("Enter Telephone Number : ")))
        insert_data(record)
    elif(ch == 2):
        search(int(input("Enter Telephone Number : ")))
    elif(ch == 3):
        display()
    elif(ch == 0):
        exit(0)

'''
1. Enter Data.
2. Search Data.
3. Display Data.
0. Exit.
Enter Your Choice: 1
Enter Name             : Tony
Enter Telephone Number : 89274981
Record added to database.

1. Enter Data.
2. Search Data.
3. Display Data.
0. Exit.
Enter Your Choice: 1
Enter Name             : Steve
Enter Telephone Number : 73672645
Record added to database.

1. Enter Data.
2. Search Data.
3. Display Data.
0. Exit.
Enter Your Choice: 1
Enter Name             : Wanda
Enter Telephone Number : 89805312
Record added to database.

1. Enter Data.
2. Search Data.
3. Display Data.
0. Exit.
Enter Your Choice: 3
[None, ['Tony', 89274981], ['Wanda', 89805312], None, None, ['Steve', 73672645], None, None, None, None]

1. Enter Data.
2. Search Data.
3. Display Data.
0. Exit.
Enter Your Choice: 2
Enter Telephone Number : 89274981
Record Found :  ['Tony', 89274981]

1. Enter Data.
2. Search Data.
3. Display Data.
0. Exit.
Enter Your Choice: 0
'''