#include <stdio.h>
#include "addressbook.h"

int main(){
	struct AddressBook addressBook;
	int choice;

	addressBook.contactCount = 0;

	pull_file_data(&addressBook, "database.csv");

	while(1){

		printf("\n");
		printf("========Address Book========\n");
		
		printf("1. Add contact\n");

		printf("2. Search contact\n");

		printf("3. Delete contact\n");

		printf("4. Edit contact\n");

		printf("5. List contacts\n");

		printf("6. Save and Exit\n");
		
		printf("Enter choice : ");
		scanf("%d",&choice);
		printf("\n");

		switch(choice){

			case 1 :
				add_contact(&addressBook);
				break;

			case 2 :
				search_contact(&addressBook);
				break;

			case 3 :
				delete_contact(&addressBook);
				break;

			case 4 :
				edit_contact(&addressBook);
				break;

			case 5 :
				list_contacts(&addressBook);
				break;

			case 6 :
				push_data_to_file(&addressBook, "database.csv");
				printf("Address Book saved. Exiting....\n\n");
			        return 0;

			default :
				printf("Invalid choice. Try again....\n");
		}
	}
}	

