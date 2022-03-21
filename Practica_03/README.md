# El juego de la vida

```
 * AUTHOR: XueMei Lin
 * DATE: 08/03/2022
 * EMAIL: alu0101225845@ull.edu.es
 * GITHUB: XueMei-L
 * UNIVERSITY: Universidad de La Laguna
 * SUBJECT: Algoritmos y estructruas de datos avanzadas
 * PRACTICENUM: 1
 * VERSION: 1.0
 * TITLE: El juego de la vida
 * LENGUAJE: C++
 * TOOLS: Visual Studio Code && iaaS
 * MAKEFILE: make (compile files) 
 *           make clean (Delete files other than the source code)
 * DESCRIPTION: https://es.m.wikipedia.org/wiki/Juego_de_la_vida
```

requisitos:
    - Frontera periodica:
        ejemplo 5 * 7
        [4][6] corresponde con la esquina inferior derecha [4][6]
        [4][0] corresponde a [4][0]
        跟对角相似

    - Frontera reflectora:
        跟右边或者下面的位置一样

    - sin fronteras:
        crecer dinamicamente para aumentar el tamaño de la regilla.
    
Implementacion:
    State - clases abstracta
        StateAlive - subclase de State{}
        StateDead - subclase de State{}
    