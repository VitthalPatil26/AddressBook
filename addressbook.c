#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "addressbook.h"

int search_flag = 0;

void add_contact(struct AddressBook *addressbook){
	
	char name[50];
	char mobile[15];
	char gmail[50];

	printf("Enter name : ");
	scanf(" %[^\n]",name);

	int valid = 1;

	for(int i = 0; name[i] != '\0'; i++){

		if(!isalpha(name[i]) && name[i] != ' '){

			valid = 0;
			break;

		}
	}
	if(valid == 0){

		printf("Invalid name\n");
		return;

	}

	while(1){

		printf("Enter mobile : ");
		scanf(" %[^\n]",mobile);
	
	
        	if(mobile_verify(mobile)){

                	printf("Valid mobile\n");
			break;

        	}
        	else{

                	printf("Invalid mobile. Try again...\n");

        	}
	}

	while(1){

		printf("Enter gmail : ");
		scanf(" %[^\n]",gmail);

		if(gmail_verify(addressbook, gmail)){

			printf("Valid gmail\n");
			break;

		}
		else{

			printf("Invalid gmail. Try again...\n");
		}
	}

	strcpy(addressbook->contacts[addressbook->contactCount].name, name);
	strcpy(addressbook->contacts[addressbook->contactCount].phone, mobile);
	strcpy(addressbook->contacts[addressbook->contactCount].email, gmail);

	addressbook->contactCount++;

	printf("Contact added successfully\n");

}

void list_contacts(struct AddressBook *addressBook){

	if(addressBook->contactCount == 0){

               printf("File is empty\n");
               return;

        }

	int i;

	for(i = 0; i < addressBook->contactCount; i++){

		printf("%s,", addressBook->contacts[i].name);

		printf("%s,", addressBook->contacts[i].phone);

		printf("%s", addressBook->contacts[i].email);

		printf("\n");

	}
}

void search_by_name(struct AddressBook *addressBook, char name[]){

	int record = 0;

        for(int i = 0; i < 100; i++){

                addressBook->i_record[i] = 0;

        }

        addressBook->ir_size = 0;

        search_flag = 0;

        for(int i = 0; i < addressBook->contactCount; i++){

                if(strcmp(addressBook->contacts[i].name, name) == 0){

                        addressBook->i_record[i] = 1;

                        addressBook->ir_size++;
                }
        }

        if(addressBook->ir_size == 0){
                printf("Contact not found\n");
                return;
        }

        if(addressBook->ir_size > 1)
                search_flag = 1;


        for(int i = 0; i < addressBook->contactCount; i++){

                if(addressBook->i_record[i] == 1){

                        record++;

                        printf("%d.",record);

                        printf("%s,", addressBook->contacts[i].name);

                        printf("%s,", addressBook->contacts[i].phone);

                        printf("%s\n", addressBook->contacts[i].email);

                }
        }
}

void search_by_phone(struct AddressBook *addressBook, char phone[]){
	
	int record = 0;

	for(int i = 0; i < 100; i++){

		addressBook->i_record[i] = 0;

	}

	addressBook->ir_size = 0;

	search_flag = 0;

      	for(int i = 0; i < addressBook->contactCount; i++){
    
		if(strcmp(addressBook->contacts[i].phone, phone) == 0){

			addressBook->i_record[i] = 1;

			addressBook->ir_size++;
		}
	}

	if(addressBook->ir_size == 0){
		printf("Contact not found\n");
		return;
	}

	if(addressBook->ir_size > 1)
		search_flag = 1;


	for(int i = 0; i < addressBook->contactCount; i++){
                                        
		if(addressBook->i_record[i] == 1){

			record++;

			printf("%d.",record);
   
			printf("%s,", addressBook->contacts[i].name);

			printf("%s,", addressBook->contacts[i].phone);

			printf("%s\n", addressBook->contacts[i].email);
		}
	}
}

void search_by_gmail(struct AddressBook *addressBook, char gmail[]){

	int record = 0;

        for(int i = 0; i < 100; i++){

                addressBook->i_record[i] = 0;

        }

        addressBook->ir_size = 0;

        search_flag = 0;

        for(int i = 0; i < addressBook->contactCount; i++){

                if(strcmp(addressBook->contacts[i].email, gmail) == 0){

                        addressBook->i_record[i] = 1;

                        addressBook->ir_size++;
                }
        }

        if(addressBook->ir_size == 0){
                printf("Contact not found\n");
                return;
        }

        if(addressBook->ir_size > 1)
                search_flag = 1;


        for(int i = 0; i < addressBook->contactCount; i++){

                if(addressBook->i_record[i] == 1){

                        record++;

                        printf("%d.",record);

                        printf("%s,", addressBook->contacts[i].name);

                        printf("%s,", addressBook->contacts[i].phone);

                        printf("%s\n", addressBook->contacts[i].email);
                }
        }
                       
}

void search_contact(struct AddressBook *addressBook){

	int choice;

	printf("\n1.search by name\n");

	printf("2.search by phone\n");

	printf("3.search by gmail\n");

	printf("Enter choice : ");
	scanf("%d",&choice);

	switch(choice)
	{
		case 1 : 
		
		{

            		char name[50];

            		printf("Enter name to search: ");
            		scanf(" %[^\n]", name);

            		search_by_name(addressBook, name);

            		break;
        	}

		case 2 :
		{
            		char phone[15];

            		printf("Enter phone to search: ");
            		scanf(" %[^\n]", phone);

            		search_by_phone(addressBook, phone);

            		break;
        	}

		case 3 :
		{
			
            		char gmail[50];

            		printf("Enter gmail to search: ");
            		scanf(" %[^\n]", gmail);

            		search_by_gmail(addressBook, gmail);

            		break;
        	}

		default :
	
			printf("Invalid choice\n");
		
	}
}

void delete_contact(struct AddressBook *addressBook){

	search_contact(addressBook);

	int selectIndex = -1;

	if(addressBook->ir_size == 0){
		printf("No contact selected for deletion\n");
		return;
	}

	int record;

	if(search_flag == 1){

		printf("Multiple contact found\n");

		while(1){

		int count = 0;

		selectIndex = -1;

		printf("Enter number to delete record : ");
		scanf("%d",&record);
void delete_contact(struct AddressBook *addressBook){

        search_contact(addressBook);

        int selectIndex = -1;

        if(addressBook->ir_size == 0){
                printf("No contact selected for deletion\n");
                return;
        }

        int record;

        if(search_flag == 1){

                printf("Multiple contact found\n");

                while(1){

                int count = 0;

                selectIndex = -1;

                printf("Enter number to delete record : ");
                scanf("%d",&record);

                for(int i = 0; i < addressBook->contactCount; i++){

                        if(addressBook->i_record[i] == 1){

                                count++;

                                if(record == count){

                                        selectIndex = i;

                                        break;

                                }
                        }

                }

                if(selectIndex != -1)
                        break;

                printf("Wrong serial number. Try again\n");
                }
        }
        else{
                for(int i = 0; i < addressBook->contactCount; i++){

                        if(addressBook->i_record[i] == 1){

                                selectIndex = i;

                                break;

                        }
                }
        }

        if(selectIndex == -1){
                printf("Record not found\n");
                return;
        }

        for(int i = selectIndex; i < addressBook->contactCount - 1; i++){

                addressBook->contacts[i] = addressBook->contacts[i+1];

        }

        addressBook->contactCount--;

        printf("Contact deleted successfully\n");

        for(int i = 0; i < 100; i++){

                addressBook->i_record[i] = 0;

        }

        addressBook->ir_size = 0;

        search_flag = 0;

}

		for(int i = 0; i < addressBook->contactCount; i++){

			if(addressBook->i_record[i] == 1){

				count++;

				if(record == count){

					selectIndex = i;

					break;

				}
			}

		}

		if(selectIndex != -1)
			break;

		printf("Wrong serial number. Try again\n");
		}
	}
	else{
		for(int i = 0; i < addressBook->contactCount; i++){

			if(addressBook->i_record[i] == 1){

				selectIndex = i;

				break;

			}
		}
	}

	if(selectIndex == -1){
		printf("Record not found\n");
		return;
	}

	for(int i = selectIndex; i < addressBook->contactCount - 1; i++){

		addressBook->contacts[i] = addressBook->contacts[i+1];

	}

	addressBook->contactCount--;

	printf("Contact deleted successfully\n");

	for(int i = 0; i < 100; i++){

		addressBook->i_record[i] = 0;

	}

	addressBook->ir_size = 0;

	search_flag = 0;

}

void edit_contact(struct AddressBook *addressBook){

	int selectIndex = -1;

	search_contact(addressBook);

	if(addressBook->ir_size == 0){
		
		printf("No contact to edit\n");
		return;

	}

	if(search_flag == 0){

		for(int i = 0; i < addressBook->contactCount; i++){

			if(addressBook->i_record[i] == 1){

      				selectIndex = i;
				break;
   
			}
		}
	}
	else{
		int record;
		int count = 0;

		printf("Multiple contact found\n");
		printf("Enter record to edit : ");
		scanf("%d",&record);

		for(int i = 0; i < addressBook->contactCount; i++){

			if(addressBook->i_record[i] == 1){

				count++;

				if(record == count){

					selectIndex = i;
					break;

				}
			}
		}
	}

	if(selectIndex == -1){

		printf("Invalid record number\n");
		return;

	}

	while(1){

		int choice;

		printf("\n=======Edit conttact========\n");

		printf("1. Edit name\n");

		printf("2. Edit mobile\n");

		printf("3. Edit email\n");

		printf("4. Exit....\n");

		printf("Enter choice : ");
		scanf("%d",&choice);

		switch(choice){

			case 1 :
				{
					char tempname[50];

					printf("Enter new name : ");
					scanf(" %[^\n]",tempname);
					strcpy(addressBook->contacts[selectIndex].name, tempname);
					printf("Nwe name updated successfully\n");

					break;

				}

			case 2 :
				{
					char tempmobile[15];
					
					while(1){

						printf("Enter new mobile : ");
                                        	scanf(" %[^\n]",tempmobile);

						if(mobile_verify(tempmobile)){

							strcpy(addressBook->contacts[selectIndex].phone, tempmobile);

							printf("Mobile updated successfully\n");

							break;

						}
						
						printf("Invalid mobile. Try again..\n");
					}	

					break;
				}

			case 3 :
				{
					char tempgmail[30];
			
					while(1){

						printf("Enter new gmail : ");
                                	        scanf(" %[^\n]",tempgmail);
				

						if(gmail_verify(addressBook, tempgmail)){

							strcpy(addressBook->contacts[selectIndex].email, tempgmail);

							printf("Gmail updated successfully\n");

							break;

						}
						
						printf("Invalid gmail. Try again...\n");

					}

					break;
				}

			case 4 : 
				{
					printf("Exit...\n");
					return;
				}
			default :
				{
					printf("Invalid choice\n");

				}
		}
	}

			



	printf("\nContact updated successfully\n");

	for(int i = 0; i < 100; i++){

		addressBook->i_record[i] = 0;

	}

	search_flag = 0;

	addressBook->ir_size = 0;

}

int mobile_verify(char mobile[]){
	
	int i;

	for(i = 0; mobile[i] != '\0'; i++){
		
		if(!isdigit(mobile[i])){

			return 0;

		}

	}

	if(i != 10)
		return 0;

	if(mobile[0] < '6' || mobile[0] > '9')
		return 0;


	return 1;

}

int gmail_verify(struct AddressBook *addressBook, char gmail[]){

	int i;
	int at = 0;
	int dot = 0;
	int at_pos = -1;
	int dot_pos = -1;

	if(gmail[0] == '\0')
		return 0;

	for(i = 0; gmail[i] != '\0'; i++){

		if(gmail[i] == ' '){

			return 0;

		}

		if(gmail[i] == '@'){

			at++;
			at_pos = i;

		}

		if(gmail[i] == '.'){

			dot++;
			dot_pos = i;

		}
	}

	if(at != 1)
		return 0;

	if(at_pos == 0)
	       return 0;

	if(at_pos == i-1)
               return 0;

	if(dot_pos < at_pos)
		return 0;

	if(at_pos == dot_pos + 1)
		return 0;

	if(dot_pos == 0)
		return 0;

	if(dot_pos == i - 1)
		return 0;

	if(i < 10 || strcmp(&gmail[i - 10], "@gmail.com") != 0)
		return 0;

			
	return 1;
}

void pull_file_data(struct AddressBook *addressBook, char *filename){

	FILE *fptr;

	fptr = fopen(filename, "r");

	if(fptr == NULL){
		printf("Unable to open file\n");
		return;
	}
	
	while(fscanf(fptr, "%[^,],%[^,],%[^\n]\n",
			addressBook->contacts[addressBook->contactCount].name,
			addressBook->contacts[addressBook->contactCount].phone,
			addressBook->contacts[addressBook->contactCount].email) == 3)
	{
		addressBook->contactCount++;
	}
	
	fclose(fptr);
}

void push_data_to_file(struct AddressBook *addressBook, char *filename){

	int i;

	FILE *fptr;

	fptr = fopen(filename, "w");

	if(fptr == NULL){
		printf("File unable to open\n");
		return;
	}

	for(i = 0; i < addressBook->contactCount; i++){

		fprintf(fptr, "%s,%s,%s\n",

				addressBook->contacts[i].name,
				addressBook->contacts[i].phone,
				addressBook->contacts[i].email);
	}
	fclose(fptr);

	printf("Data saved successfully\n");
}


