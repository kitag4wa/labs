#include <stdio.h>
#include <string.h>

struct ticket {
int train;
char station1[30];
char station2[30];
char dep_day[30];
char dep_time[30];
int coach;
int seat;
float price;
};

// функция проверки того, занято ли место
int is_seat_taken(struct ticket tickets[], int num_tickets, int coach, int seat) {
for (int i = 0; i < num_tickets; i++) {
if (tickets[i].coach == coach && tickets[i].seat == seat) {
return 1;
}
}
return 0;
}

// функция для поиска самого дорогого билета
void find_most_expensive_ticket(struct ticket tickets[], int num_tickets) {
float max_price = 0;
int ticket_index = 0;
for (int i = 0; i < num_tickets; i++) {
if (tickets[i].price > max_price) {
max_price = tickets[i].price;
ticket_index = i;
}
}

printf("\nСамый дорогой билет: \n");
printf("Номер поезда: %d\n", tickets[ticket_index].train);
printf("Станция отправления: %s\n", tickets[ticket_index].station1);
printf("Станция назначения: %s\n", tickets[ticket_index].station2);
printf("Дата отправления: %s\n", tickets[ticket_index].dep_day);
printf("Время отправления: %s\n", tickets[ticket_index].dep_time);
printf("Номер вагона: %d\n", tickets[ticket_index].coach);
printf("Номер места: %d\n", tickets[ticket_index].seat);
printf("Стоимость билета: %.2f\n", tickets[ticket_index].price);
}

int main() {
struct ticket tickets[100];
int num_tickets = 0;
int seats_info[10][30]; // массив для хранения информации о заполняемости мест

// инициализация массива seats_info
for (int i = 0; i < 10; i++) {
for (int j = 0; j < 30; j++) {
seats_info[i][j] = 0;
}
}

// цикл для ввода информации о билетах
while (1) {
printf("\nВведите информацию о билете (0 - выход): \n");
printf("Номер поезда: ");
scanf("%d", &tickets[num_tickets].train);
if (tickets[num_tickets].train == 0) {
break;
}

printf("Станция отправления: ");
scanf("%s", tickets[num_tickets].station1);
printf("Станция назначения: ");
scanf("%s", tickets[num_tickets].station2);
printf("Дата отправления: ");
scanf("%s", tickets[num_tickets].dep_day);
printf("Время отправления: ");
scanf("%s", tickets[num_tickets].dep_time);
printf("Номер вагона: ");
scanf("%d", &tickets[num_tickets].coach);
printf("Номер места: ");
scanf("%d", &tickets[num_tickets].seat);
printf("Стоимость билета: ");
scanf("%f", &tickets[num_tickets].price);

// проверяем, занято ли место
if (is_seat_taken(tickets, num_tickets, tickets[num_tickets].coach, tickets[num_tickets].seat)) {
printf("Место уже занято!\n");
continue;
}

// запоминаем, что место занято
seats_info[tickets[num_tickets].coach - 1][tickets[num_tickets].seat - 1] = 1;
num_tickets++;
}

// вызываем функцию для поиска самого дорогого билета
find_most_expensive_ticket(tickets, num_tickets);

return 0;
}


------------------
Номер поезда: 1
Станция отправления: Москва
Станция назначения: Санкт-Петербург
Дата отправления: 01.01.2023
Время отправления: 12:00
Номер вагона: 11
Номер места: 9
Цена билета: 1099.0
------------------
Номер поезда: 2
Станция отправления: Самара
Станция назначения: Сочи
Дата отправления: 12.01.2023
Время отправления: 09:00
Номер вагона: 22
Номер места: 8
Цена билета: 4300.0
------------------
Номер поезда: 3
Станция отправления: Волгоград
Станция назначения: Москва
Дата отправления: 08.02.2023
Время отправления: 13:00
Номер вагона: 33
Номер места: 7
Цена билета: 3700.0
------------------
Номер поезда: 4
Станция отправления: Краснодар
Станция назначения: Рязань
Дата отправления: 22.02.2023
Время отправления: 15:30
Номер вагона: 44
Номер места: 6
Цена билета: 2900.0
------------------