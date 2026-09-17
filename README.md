# AddressBook

A command-line contact management application written in C. Contacts are stored persistently in a CSV file and can be added, searched, edited, deleted, and listed through a simple menu-driven interface.

## Features

- **Add contact** — name, mobile number, and Gmail address, each validated on entry
- **Search contact** — by name, phone number, or email; handles duplicate matches by listing all of them with an index to select from
- **Edit contact** — update name, mobile, or email for an existing contact
- **Delete contact** — remove a contact, with disambiguation if multiple contacts match the search
- **List contacts** — print all saved contacts
- **Persistence** — contacts are loaded from database.csv on startup and saved back on exit

### Input validation

- **Mobile number**: must be exactly 10 digits and start with 6, 7, 8, or 9 (standard Indian mobile number format)
- **Gmail address**: must contain exactly one @ and end in @gmail.com, with basic structural checks (no spaces, no leading/trailing @/., etc.)
- **Name**: letters and spaces only

## Project structure

- main.c — Program entry point and menu loop
- addressbook.c — Core logic: add/search/edit/delete/list, validation, file I/O
- addressbook.h — Struct definitions and function declarations
- .gitignore
- README.md

## Building

Requires gcc (or any C compiler).

    gcc main.c addressbook.c -o addressbook

## Running

    ./addressbook

You'll see a menu with options to add, search, delete, edit, and list contacts, plus save and exit.

Contacts are saved to database.csv (created automatically in the working directory) when you choose the save option.

## Data format

Each line in database.csv is stored as:

    name,phone,email

## Possible future improvements

- Replace the fixed-size 100-contact array with dynamic memory allocation
- Add duplicate-contact prevention on add
- Add unit tests for the validation functions
