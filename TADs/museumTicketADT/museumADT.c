#include <stdlib.h>
#include "museumADT.h"
#include <string.h>
#include <strings.h>
#include <assert.h>

typedef struct tTicket {
    char* visitorName;
    struct tTicket * next;
} tTicket;

typedef tTicket * tTicketList;

typedef struct node {
    tTicketList tickets;
    tTicketList current;
    size_t dailyAmount;
} tDay;

struct museumTicketCDT {
    tDay days[366];
    int ticketsCounter;
};

static tTicketList addTicketRec(tTicketList tickets, char *visitor, int *outputFlag);
static void freeTicketList(tTicketList ticket);

void toBeginByDay(museumTicketADT museumTicketADT, size_t dayOfYear) {
    museumTicketADT->days[dayOfYear - 1].current = museumTicketADT->days[dayOfYear - 1].tickets;
    return;
}

size_t hasNextByDay(museumTicketADT museumTicketADT, size_t dayOfYear) {
    assert(dayOfYear > 0 && dayOfYear <= 366);

    return museumTicketADT->days[dayOfYear - 1].current != NULL;
}

char * nextByDay(museumTicketADT museumTicketADT, size_t dayOfYear) {

    assert(dayOfYear > 0 && dayOfYear <= 366);

    assert(hasNextByDay(museumTicketADT, dayOfYear));

    char * aux = museumTicketADT->days[dayOfYear - 1].current->visitorName;
    museumTicketADT->days[dayOfYear - 1].current = museumTicketADT->days[dayOfYear - 1].current->next;
    return aux;
}

int addTicket(museumTicketADT museumTicketADT, size_t dayOfYear,  char * visitor) {

    if(dayOfYear < 1 || dayOfYear > 366 || visitor == NULL)
        return 0;

    int flag = 0;
    museumTicketADT->days[dayOfYear-1].tickets = addTicketRec(museumTicketADT->days[dayOfYear-1].tickets, visitor, &flag);
    museumTicketADT->days[dayOfYear-1].dailyAmount += flag;
    museumTicketADT->ticketsCounter += flag;
    return flag ? museumTicketADT->days[dayOfYear-1].dailyAmount : 0;
}

static tTicketList addTicketRec(tTicketList tickets, char *visitor, int *outputFlag) {

    int res;

    if(tickets == NULL || (res = strcasecmp(tickets->visitorName, visitor)) > 0) {
        *outputFlag = 1;
        tTicketList new = calloc(1, sizeof(tTicket));
        new->visitorName = visitor;
        new->next = tickets;
        return new;
    }

    if(res < 0)
        tickets->next = addTicketRec(tickets->next, visitor, outputFlag);  

    return tickets;
}

int dayTickets(const museumTicketADT museumTicketADT, size_t dayOfYear) {
    return museumTicketADT->days[dayOfYear - 1].dailyAmount;
}

int yearTickets(const museumTicketADT museumTicketADT) {
    return museumTicketADT->ticketsCounter;
}

void freeMuseumTicket(museumTicketADT museumTicketADT) {

    for (int i = 0; i < 366; i++)
    {
        freeTicketList(museumTicketADT->days[i].tickets);

    }
    
    free(museumTicketADT);
}

static void freeTicketList(tTicketList ticket) {
    if(ticket == NULL)
        return;
    
    freeTicketList(ticket->next);
    free(ticket);
}

museumTicketADT newMuseumTicket(void) {
    return calloc(1, sizeof(struct museumTicketCDT));
}
