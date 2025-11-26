# Juego de Preguntas Tipo Quiz en C++ para Consola

Este proyecto implementa un juego de preguntas tipo quiz desarrollado en C++ para ejecutarse en consola (Windows). El jugador debe responder preguntas en tiempo real, con un límite temporal y un sistema de puntuaciones. El juego incluye un menú interactivo, selección de número de jugadores, carga aleatoria de preguntas desde archivos externos y representación visual mediante ASCII art.

## Características principales

### Sistema de Jugadores
- Permite entre 2 y 6 jugadores.
- Cada jugador responde por turnos.
- Las puntuaciones se actualizan automáticamente.
- Al final de la ronda se muestra la tabla de resultados.

### Gestión de Preguntas y Respuestas
- Las preguntas se leen desde archivos externos:
  - `PREGUNTAS`
  - `RESPUESTAS`
  - `RESPUESTAS1`
- Cada ejecución selecciona una línea aleatoria para generar la pregunta.
- Las respuestas correctas se comparan con la respuesta del jugador.

### Controles en Tiempo Real
- El jugador responde con las teclas:
  - `a` → Opción A
  - `b` → Opción B
  - `c` → Opción C
  - `d` → Opción D
- El juego detecta entrada de teclado sin necesidad de pulsar Enter.
- Si pasa el tiempo sin responder, se marca como incorrecta.

### Menú Interactivo
- Título animado con ASCII art.
- Opción para iniciar partida con Enter.
- Opción para salir con Esc.
- Acceso oculto con tecla `a` para un modo de administración simple.

### Elementos Técnicos Destacados
- Uso de `kbhit()` y `getch()` para lectura instantánea de teclas.
- Uso de `gotoxy()` para posicionar elementos en pantalla.
- Uso de `Sleep()` y temporizadores.
- Gestión de cursor oculto para mejorar la presentación visual.
- Uso de múltiples clases:
  - `PLAY` para la lógica principal de juego.
  - `MENU` para la interfaz inicial.
- Lectura y escritura de archivos con `fstream`.

## Requisitos

- Sistema operativo: Windows.
- Compilador compatible con:
  - `<windows.h>`
  - `<conio.h>`
  - `<fstream>`
  - `<ctime>`

Recomendado: MinGW, Dev-C++, Visual Studio o CodeBlocks.

## Estructura esperada de archivos

El programa requiere que existan estos archivos en el mismo directorio que el ejecutable:

```
PREGUNTAS
RESPUESTAS
RESPUESTAS1
```

Cada archivo debe contener una línea por pregunta.

Ejemplo:

Archivo `PREGUNTAS`:
```
Capital de Francia
Capital de España
```

Archivo `RESPUESTAS`:
```
A) Paris B) Roma C) Berlin D) Lisboa
A) Madrid B) Paris C) Lisboa D) Roma
```

Archivo `RESPUESTAS1` (respuesta correcta):
```
A
A
```

## Ejecución

1. Compilar el archivo `.cpp`.
2. Colocar los archivos de preguntas junto al ejecutable.
3. Ejecutar el programa.
4. Seleccionar número de jugadores.
5. Responder preguntas usando las teclas indicadas.

## Posibles mejoras futuras

- Añadir preguntas en formato JSON o CSV.
- Implementar un sistema de puntuación persistente.
- Añadir niveles de dificultad.
- Añadir soporte multiplataforma.
- Implementar interfaz gráfica con SDL o SFML.

## Autor

Proyecto desarrollado como práctica académica de programación en C++.
