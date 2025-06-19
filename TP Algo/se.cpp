#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un processus
typedef struct {
    int id; // identifiant du processus
    int arrival_time; // temps d'arrivée
    int execution_time; // temps d'exécution
    int priority; // priorité
    int waiting_time; // temps d'attente
} Process;

// Fonction pour dessiner le diagramme d'exécution pour la technique FIFO
void drawFIFO(Process processes[], int n) {
    printf("Diagramme d'execution FIFO:\n");
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d | ", processes[i].id);
        processes[i].waiting_time = current_time - processes[i].arrival_time;
        current_time += processes[i].execution_time;
    }
    printf("\n");
}

// Fonction pour dessiner le diagramme d'exécution pour la technique Round Robin (Tourniquet)
void drawRoundRobin(Process processes[], int n, int quantum) {
    printf("Diagramme d'execution Round Robin (quantum = %d):\n", quantum);
    int remaining_time[n];
    for (int i = 0; i < n; i++) {
        remaining_time[i] = processes[i].execution_time;
    }
    int current_time = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0) {
                done = 0;
                if (remaining_time[i] > quantum) {
                    printf("P%d | ", processes[i].id);
                    processes[i].waiting_time += current_time;
                    current_time += quantum;
                    remaining_time[i] -= quantum;
                } else {
                    printf("P%d | ", processes[i].id);
                    processes[i].waiting_time += current_time;
                    current_time += remaining_time[i];
                    remaining_time[i] = 0;
                }
            }
        }
        if (done == 1) {
            break;
        }
    }
    printf("\n");
}

// Fonction pour dessiner le diagramme d'exécution pour la technique Priorité avec Réquisition
void drawPriorityPreemption(Process processes[], int n) {
    printf("Diagramme d'execution Priorite avec requisition:\n");
    int current_time = 0;
    while (1) {
        int highest_priority = -1;
        int next_process = -1;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].execution_time > 0) {
                if (highest_priority == -1 || processes[i].priority < highest_priority) {
                    highest_priority = processes[i].priority;
                    next_process = i;
                }
            }
        }
        if (next_process == -1) {
            break;
        }
        printf("P%d | ", processes[next_process].id);
        processes[next_process].waiting_time += current_time;
        current_time++;
        processes[next_process].execution_time--;
    }
    printf("\n");
}

// Fonction pour calculer le temps d'attente moyen
float calculateAverageWaitingTime(Process processes[], int n) {
    float total_waiting_time = 0;
    for (int i = 0; i < n; i++) {
        total_waiting_time += processes[i].waiting_time;
    }
    return total_waiting_time / n;
}

int main() {
    int n;
    printf("Entrer le nombre de processus: ");
    scanf("%d", &n);

    Process processes[n];
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Entrer le temps d'arrivee du processus P%d: ", i + 1);
        scanf("%d", &processes[i].arrival_time);
        printf("Entrer le temps d'execution du processus P%d: ", i + 1);
        scanf("%d", &processes[i].execution_time);
        printf("Entrer la priorite du processus P%d: ", i + 1);
        scanf("%d", &processes[i].priority);
        processes[i].waiting_time = 0;
    }

    // Dessiner les diagrammes d'exécution et calculer les temps d'attente pour chaque technique
    drawFIFO(processes, n);
    drawRoundRobin(processes, n, 2); // Exemple de quantum = 2, à adapter selon vos besoins
    drawPriorityPreemption(processes, n);

    // Calculer le temps d'attente moyen pour chaque technique
    float avg_waiting_time_fifo = calculateAverageWaitingTime(processes, n);
    printf("Temps d'attente moyen FIFO: %.2f\n", avg_waiting_time_fifo);

    float avg_waiting_time_rr = calculateAverageWaitingTime(processes, n);
    printf("Temps d'attente moyen Round Robin: %.2f\n", avg_waiting_time_rr);

    float avg_waiting_time_priority = calculateAverageWaitingTime(processes, n);
    printf("Temps d'attente moyen Priorite avec requisition: %.2f\n", avg_waiting_time_priority);

    // Déterminer la meilleure technique en comparant les temps d'attente moyens
    if (avg_waiting_time_fifo <= avg_waiting_time_rr && avg_waiting_time_fifo <= avg_waiting_time_priority) {
        printf("La meilleure technique est FIFO.\n");
    } else if (avg_waiting_time_rr <= avg_waiting_time_fifo && avg_waiting_time_rr <= avg_waiting_time_priority) {
        printf("La meilleure technique est Round Robin.\n");
    } else {
        printf("La meilleure technique est Priorite avec requisition.\n");
    }

    return 0;
}

