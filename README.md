# 💡 Simulador de Movimentos de Xadrez em C

Este projeto simula os movimentos das principais peças de xadrez utilizando **linguagem C** com foco em aplicar estruturas de repetição (`for`, `while`, `do-while`), **loops aninhados** e **recursividade**.

## 🎯 Objetivos

- Simular movimentos das peças de xadrez por meio de código.
- Aplicar estruturas de repetição simples e complexas.
- Praticar lógica de programação de maneira lúdica.
- Desenvolver código limpo e organizado para ensino e aprendizado.

## 🧩 Funcionalidades

| Peça      | Técnica utilizada                 |
|-----------|-----------------------------------|
| Torre     | `for` (movimentos horizontais/verticais) |
| Bispo     | `while` (movimentos diagonais)    |
| Rainha    | `do-while` (combinação torre + bispo) |
| Cavalo    | **loops aninhados** (movimento em L) |
| Rainha Avançada | **recursividade** (exploração até as bordas) |

## 📂 Estrutura

src/
└── main.c → Código principal com menu interativo

## 🖥️ Como compilar

Use um compilador C como `gcc`:

```bash
gcc src/main.c -o xadrez
./xadrez

## 🧪 Exemplo de uso
Ao rodar o programa, o usuário informa a posição da peça (linha e coluna de 0 a 7) e escolhe uma das peças. O programa exibe no terminal os movimentos válidos usando a lógica definida para cada uma.

## Autor
Felipe Dutra Musskopf
