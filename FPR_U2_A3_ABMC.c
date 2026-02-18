#include <stdio.h>

int main(void) {
    int opcion;
    int moneda;
    float precio = 0.0f;
    float total = 0.0f;
    float cambio = 0.0f;

    /* Ciclo principal: se repite hasta que el usuario elija salir */
    do {
        /* Mostrar menú */
        printf("\n=== DESPACHADOR AUTOMATICO ===\n");
        printf("1) Producto 1 - $12\n");
        printf("2) Producto 2 - $15\n");
        printf("3) Producto 3 - $18\n");
        printf("4) Producto 4 - $10\n");
        printf("5) Producto 5 - $8\n");
        printf("6) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        /* Validar salida */
        if (opcion == 6) {
            printf("Saliendo del sistema...\n");
        } else {
            /* Asignar precio segun opcion */
            switch (opcion) {
                case 1: precio = 12.0f; break;
                case 2: precio = 15.0f; break;
                case 3: precio = 18.0f; break;
                case 4: precio = 10.0f; break;
                case 5: precio = 8.0f;  break;
                default: precio = -1.0f; break;
            }

            /* Validar seleccion */
            if (precio == -1.0f) {
                printf("Seleccion incorrecta. Intente nuevamente.\n");
            } else {
                /* Reiniciar total para esta operacion */
                total = 0.0f;

                /* Solicitar monedas hasta cubrir el precio */
                while (total < precio) {
                    printf("Ingrese moneda (1, 2, 5, 10): ");
                    scanf("%d", &moneda);

                    if (moneda == 1 || moneda == 2 || moneda == 5 || moneda == 10) {
                        total = total + (float)moneda;
                        printf("Total acumulado: $%.2f\n", total);
                    } else {
                        printf("Moneda no valida. Solo se aceptan 1, 2, 5 y 10.\n");
                    }
                }

                /* Validar pago y calcular cambio si aplica */
                if (total == precio) {
                    printf("Pago exacto. Producto entregado.\n");
                } else {
                    cambio = total - precio;
                    printf("Pago recibido. Producto entregado.\n");
                    printf("Su cambio es: $%.2f\n", cambio);
                }
            }
        }

    } while (opcion != 6);

    return 0;
}
