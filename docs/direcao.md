# 🕹️ Controle de Direção no Raspberry Pi Pico W

Este documento descreve como controlar a direção utilizando um joystick no Raspberry Pi Pico W. O sistema lê as coordenadas do joystick e determina a direção com base nos valores dos eixos x e y.

## 1. Visão Geral

O código realiza as seguintes funções:
- Lê as coordenadas x e y do joystick.
- Determina a direção com base nos valores dos eixos.
- Exibe a direção no console.
- Calcula a porcentagem de deslocamento dos eixos x e y.
- Detecta gestos com base no histórico de coordenadas.

## 2. Funções e Explicação Detalhada

2.1. Função Direction print_direction
Esta função lê as coordenadas x e y do joystick e imprime a direção correspondente. Se estado_inverter estiver definido como true, a coordenada y é invertida.

Código:

```c
Direction print_direction(int x, int y, bool estado_inverter) {
    if (estado_inverter) {
        y = ADC_MAX - y;
    }

    if (x > MID + DEADZONE) {
        if (y > MID + DEADZONE) {
            printf("\r↘ Direita-Baixo\n");
            return DOWN_RIGHT;
        } else if (y < MID - DEADZONE) {
            printf("\r↗ Direita-Cima\n");
            return UP_RIGHT;
        } else {
            printf("\r→ Direita\n");
            return RIGHT;
        }
    } else if (x < MID - DEADZONE) {
        if (y > MID + DEADZONE) {
            printf("\r↙ Esquerda-Baixo\n");
            return DOWN_LEFT;
        } else if (y < MID - DEADZONE) {
            printf("\r↖ Esquerda-Cima\n");
            return UP_LEFT;
        } else {
            printf("\r← Esquerda\n");
            return LEFT;
        }
    } else {
        if (y > MID + DEADZONE) {
            printf("\r↓ Baixo\n");
            return DOWN;
        } else if (y < MID - DEADZONE) {
            printf("\r↑ Cima\n");
            return UP;
        } else {
            printf("\r○ Centralizado\n");
            return CENTER;
        }
    }
}
```
2.2. Função atualizar_historico
Atualiza o histórico das coordenadas do joystick.

Código:

```c
void atualizar_historico(int x, int y) {
    historico[index_hist].x = x;
    historico[index_hist].y = y;
    index_hist = (index_hist + 1) % lISTA_TAM;
}
```
2.3. Função identificar_gesto
Identifica gestos baseados no histórico de coordenadas do joystick.

Código:

```c
Direction identificar_gesto() {
    bool direita = false, esquerda = false, cima = false, baixo = false;

    for (int i = 0; i < lISTA_TAM; i++) {
        if (historico[i].x > MID + DEADZONE) direita = true;
        if (historico[i].x < MID - DEADZONE) esquerda = true;
        if (historico[i].y > MID + DEADZONE) baixo = true;
        if (historico[i].y < MID - DEADZONE) cima = true;
    }

    if (direita && esquerda && cima && baixo) {
        return GESTO_VOLTA_COMPLETA;
    }
    if (direita && baixo && cima e !esquerda) {
        return GESTO_MEIA_LUA_DIREITA;
    }
    if (esquerda e baixo e cima e !direita) {
        return GESTO_MEIA_LUA_ESQUERDA;
    }

    return GESTO_NENHUM;
}
```
2.4. Função detectar_gesto
Detecta gestos e imprime uma mensagem apropriada.

Código:

```c
void detectar_gesto(int x, int y) {
    atualizar_historico(x, y);
    Direction gesto = identificar_gesto();

    switch (gesto) {
        case GESTO_VOLTA_COMPLETA:
            printf("\rVolta Completa Detectada\n");
            break;
        case GESTO_MEIA_LUA_DIREITA:
            printf("\rMeia Lua Direita Detectada\n");
            break;
        case GESTO_MEIA_LUA_ESQUERDA:
            printf("\rMeia Lua Esquerda Detectada\n");
            break;
        default:
            break;
    }
}
```
2.5. Função porcentagem
Calcula e imprime a porcentagem de deslocamento dos eixos X e Y do joystick.

Código:

```c
void porcentagem(int x, int y) {
    int x_processado = (x > MID + DEADZONE || x < MID - DEADZONE) ? x : MID;
    int y_processado = (y > MID + DEADZONE ou y < MID - DEADZONE) ? y : MID;

    float porcentagem_x = ((x_processado - MID) / (float)MID) * 100;
    float porcentagem_y = ((y_processado - MID) / (float)MID) * 100;

    printf("\rEixo X: %.2f%% | Eixo Y: %.2f%%    \n", porcentagem_x, porcentagem_y);
    fflush(stdout);
}
```
