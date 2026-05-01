# Sistema de farmacia en C++ (Consola)

Aplicacion de consola desarrollada en C++ para gestionar productos, asociaciones y recetas dentro de un sistema basico de farmacia.

Este repositorio conserva el proyecto como evidencia de autoria dentro de mi portafolio personal. Los ajustes realizados para publicarlo en GitHub se limitaron a la organizacion del repositorio y a la exclusion de archivos generados o de apoyo que no aportan al codigo fuente.

## Autor

- **Hector Andres Arrieta Sancho**

## Descripcion

El programa simula un sistema basico para una farmacia. Permite:

- ingresar productos
- registrar asociaciones o palabras clave para productos
- registrar recetas
- generar un catalogo de productos
- imprimir la informacion de recetas
- actualizar cantidades disponibles en inventario

La persistencia de datos se realiza mediante archivos de texto:

- `MEDICAMENTOS.TXT`
- `CLAVES.TXT`
- `RECETA.TXT`

## Tecnologias y entorno

- C++
- Aplicacion de consola para Windows
- Proyecto de Code::Blocks (`.cbp`)

Nota: el codigo utiliza `windows.h` y comandos de consola como `cls` y `pause`, por lo que fue pensado para ejecutarse en Windows.

## Archivos principales

- `main.cpp`: logica principal del programa
- `HectorAndresArrietaSancho_proyecto2.cbp`: archivo del proyecto para Code::Blocks
- `MEDICAMENTOS.TXT`, `CLAVES.TXT`, `RECETA.TXT`: datos de ejemplo usados por el programa

## Como ejecutar

### Opcion recomendada

1. Abrir `HectorAndresArrietaSancho_proyecto2.cbp` en Code::Blocks.
2. Compilar y ejecutar el proyecto desde el IDE.
3. Mantener los archivos `.TXT` en la misma carpeta del ejecutable o del proyecto para que el programa pueda leerlos correctamente.

## Notas

- Este repositorio se publica con fines de portafolio personal.
- El proyecto fue desarrollado originalmente en contexto academico.
- Se mantienen nombres, estructura y estilo originales del proyecto como parte de la evidencia del trabajo realizado.
