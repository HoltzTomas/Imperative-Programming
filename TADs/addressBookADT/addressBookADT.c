#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include "addressBookADT.h"
#define BLOCK 20

typedef struct node1 {
    tContact contact_struct; // Estructura dada en el .h
    struct node1* tail;
} TContactNode;

typedef struct node2 {
    char* name;
    TContactNode* contact_list;
    struct node2* tail;
} TGroupNode;

typedef struct addressBookCDT {
    TGroupNode* first;
    TGroupNode* actual_group;
    TContactNode* actual_contact;
} addressBookCDT;

addressBookADT newAddressBook(void) {
    return calloc(1, sizeof(addressBookCDT));
}

static char* copyWithBlocks(char* s) {
    char* res = NULL;
    int i;
    for ( i = 0; s[i] != '\0'; i++ ) {
        if ( i % BLOCK == 0 ) {
            res = realloc(res, i + BLOCK);
        }
        res[i] = s[i];
    }
    res = realloc(res, i + 1);
    res[i] = '\0';
    return res;
}

static TGroupNode* addGroupRec (TGroupNode* groups, const char * groupName, int* flag) {
    int res;
    if ( groups == NULL || (res = strcasecmp(groups->name, groupName)) > 0 ) {
        *flag = 1;
        TGroupNode* new = malloc(sizeof(TGroupNode));
        new->contact_list = NULL;
        new->name = copyWithBlocks(groupName);
        new->tail = groups;
        return new;
    }
    if ( res < 0 ) { // Si ya estaba, no lo agrego
        groups->tail = addGroupRec(groups->tail, groupName, flag);
    }
    return groups;
}

int addGroup(addressBookADT address, const char * groupName) {
    int flag = 0;
    address->first = addGroupRec(address->first, groupName, &flag);
    return flag;
}

static TContactNode* addContactRec(TContactNode* contact_list, tContact contact, int* flag) {
    int res;
    if ( contact_list == NULL || (res = strcasecmp(contact_list->contact_struct.name, contact.name)) > 0 ) { // Lo copio
        *flag = 1;
        TContactNode* new = malloc(sizeof(TContactNode));
        new->tail = contact_list;
        new->contact_struct.name = copyWithBlocks(contact.name);
        new->contact_struct.phoneNumber = copyWithBlocks(contact.phoneNumber);
        return new;
    }
    if ( res < 0 ) { 
        contact_list->tail = addContactRec(contact_list->tail, contact, flag);
    }
    return contact_list; // Si ya estaba, me vuelvo ( res == 0 )
}

static int searchGroupRec(TGroupNode* groups, const char * groupName, tContact contact) {
    int res;
    if ( groups == NULL || (res = strcasecmp(groups->name, groupName)) > 0 ) { // Si se pasó, no estaba el grupo
        return 0;
    }
    if ( res == 0 ) { 
        int flag = 0;
        groups->contact_list = addContactRec(groups->contact_list, contact, &flag);
        return flag;
    }
    return searchGroupRec(groups->tail, groupName, contact);
}

int addContact(addressBookADT address, const char * groupName, tContact contact) {
    return searchGroupRec(address->first, groupName, contact);
}

void toBegin(addressBookADT address) {
    address->actual_group = address->first;
}

int hasNext(addressBookADT address) {
    return address->actual_group != NULL;
}

char * next(addressBookADT address) {
    if ( !hasNext(address) ) {
        exit(1);
    }
    char* res = copyWithBlocks(address->actual_group->name);
    address->actual_group = address->actual_group->tail;
    return res;
}

static void toBeginRec(TContactNode** actual, TGroupNode* groups, const char * groupName) {
    int res;
    if ( groups == NULL || (res = strcasecmp(groups->name, groupName)) > 0 ) { // Me pasé
        return;
    }
    if ( res == 0 ) { // Es el grupo, arranco la iteracion en el primero
        *actual = groups->contact_list;
        return;
    }
    toBeginRec(actual, groups->tail, groupName);
}

void toBeginForGroup(addressBookADT address, const char * groupName) {
    toBeginRec(&(address->actual_contact), address->first, groupName);
}

int hasNextForGroup(addressBookADT address) {
    return address->actual_contact != NULL;
}

tContact nextForGroup(addressBookADT address) {
    if ( !hasNextForGroup(address) ) {
        exit(1);
    }
    char* name = copyWithBlocks(address->actual_contact->contact_struct.name);
    char* number = copyWithBlocks(address->actual_contact->contact_struct.phoneNumber);
    address->actual_contact = address->actual_contact->tail;
    tContact res = {name, number};
    return res;
}