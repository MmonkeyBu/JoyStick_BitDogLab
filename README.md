# 🕹️ JoyStick BitDogLab

Este repositório contém o código-fonte e a documentação da biblioteca para o joystick usando o Raspberry Pi Pico W.

## 🌟 Visão Geral
O projeto implementa várias funcionalidades para o joystick:
- 🎮 **Leitura de Estado dos Botões**: Funções para ler o estado de cada botão do joystick.
- 🕹️ **Leitura dos Eixos Analógicos**: Funções para ler as posições dos eixos analógicos (X e Y) do joystick.
- 🔧 **Debouncing de Botões**: Algoritmo para eliminar o efeito de "rebote" nos botões.
- 📏 **Detecção de Gestos**: Identificação de gestos baseados no movimento do joystick.
- 📊 **Porcentagem dos Eixos**: Função para calcular e exibir a porcentagem de deslocamento nos eixos.

---

### 📂 Conteúdo
- **`src/`**: Código-fonte do projeto (arquivos `.c` e `.h`). Inclui a implementação dos periféricos e a função main.
  - Os arquivos `.h` contêm as definições de funções e constantes usadas em seus respectivos módulos.
- **`docs/`**: Imagens e documentação sobre a configuração e uso da biblioteca.

---

## 📜 Módulos
1. 🕹️ [**Direção (`direcao.c`)**](src/direcao.c) - Funções para ler a direção baseada nas coordenadas x e y do joystick.
2. 📏 [**Botão Joystick (`botao_joystick.c`)**](src/botao_joystick.c) - Leitura e debouncing dos botões do joystick.
3. 📊 [**Porcentagem (`porcentagem.c`)**](src/porcentagem.c) - Cálculo da porcentagem de deslocamento nos eixos.
4. 🧠 [**Principal (`joystick.c`)**](src/Joystick.c) - Integração dos módulos e controle principal do joystick.

---

## 📜 Licença
Este projeto é licenciado sob a [MIT License](https://opensource.org/licenses/MIT).
