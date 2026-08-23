#include<stdio.h>
#include<stdlib.h>

#define size 10

//slot status flags
#define empty 0
#define occupied 1
#define deleted 2


//prototypes
int hashFunc(int key);
void initializeTable();
int insert(int key,int val);
int search(int key, int *valueOut);
int deleteKey(int key);
void display();


//structure to represent each slot in the hash table
typedef struct{
        int key;
        int val;
        int status;
}hashSlot;

hashSlot hashTable[size];


int main(){
        int choice, key, value, searchValue;
        initializeTable();
        while(1){

                printf("\n1. insertion/upate\n2. search\n3. deletion\n4.display table\n5. exit\n enter your choice : ");

                if (scanf("%d", &choice)!=1) break;
                switch (choice) {
            case 1:
                printf("Enter key and value: ");
                scanf("%d %d", &key, &value);
                if (insert(key, value)) {
                    printf("Successfully inserted/updated.\n");
                } else {
                    printf("Error: Hash Table is full!\n");
                }
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(key, &searchValue)) {
                    printf("Key found! Value = %d\n",searchValue);
                } else {
                    printf("Key not found.\n");
                }
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                if (deleteKey(key)) {
                    printf("Key successfully deleted.\n");
                } else {
                    printf("Key not found.\n");
                }
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }




return 0;
}




//hash function using the division method
int hashFunc(int key){
        return abs(key) % size;
}

//initializing all slots of the hash table to empty
void initializeTable(){
        for(int i=0;i<size;i++){
                hashTable[i].status = empty;
                hashTable[i].key = 0;
                hashTable[i].val = 0;
        }
}

//inserting a key-value pair into the table using linear probing
int insert(int key,int val){
        int index = hashFunc(key);
        int originalIndex = index;


        //linear probing to find an available slot (empty or deleted)
        while(hashTable[index].status == occupied){
                //we update the value if key already exists
                if(hashTable[index].key == key){
                        hashTable[index].val = val;
                        return 1;
                }

                //moving linearly to the next slot
                index = (index + 1)%size;
                //if table is completely full
                if(index == originalIndex){
                        return 0;
                }
        }

        //inserting element into the found slot
        hashTable[index].key = key;
        hashTable[index].val = val;
        hashTable[index].status = occupied;
        return 1;
}


//searching for a key in the hash table
int search(int key, int *valueOut){
        int index = hashFunc(key);
        int originalIndex = index;

        //probing until an empty slot is reached
        while(hashTable[index].status != empty){
                if (hashTable[index].status == occupied && hashTable[index].key == key){
                        *valueOut = hashTable[index].val;
                        return 1; //for key found
                        }
                index = (index + 1)%size;

                //proned around completely without finding the key
                if(index == originalIndex){
                        break;
                }
        }
        return 0; // for key not found
}

//to delete a key from the hash table by marking it deleted
int deleteKey(int key){
        int index = hashFunc(key);
        int originalIndex = index;

        while(hashTable[index].status != empty){
                if(hashTable[index].status == occupied && hashTable[index].key == key){
                hashTable[index].status = deleted;
                return 1; //deletion successful

                }

                index = (index + 1)%size;

                if(index == originalIndex){
                        break;
                }
        }
        return 0; //for key not found

}


//to display the current status of the hash table



void display(){
        printf("hash table contains\n");

        for(int i=0;i<size;i++){
                if(hashTable[i].status == occupied){
                        printf("slot [%d]: occupied -> key: %d, value: %d\n",i,hashTable[i].key, hashTable[i].val);
                }
                else if (hashTable[i].status == deleted){
                        printf("slot [%d]: deleted\n",i);
                }
                else{
                        printf("slot [%d]: empty \n",i);
                }
        }
        printf("\n");
}
