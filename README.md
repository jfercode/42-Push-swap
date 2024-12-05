# 42-Push-Swap 🚀
Push_swap es un proyecto que te enseña sobre algoritmos de ordenación y cómo optimizarlos. El proyecto consiste en ordenar un **`stack`** de enteros utilizando un conjunto limitado de operaciones (push, swap y rotate) y minimizando el número de movimientos.

Un **`stack`** (o pila) es una estructura de datos en la que los elementos se agregan y se eliminan siguiendo el principio LIFO (Last In, First Out, por sus siglas en inglés), es decir, el último elemento que se agrega es el primero en ser eliminado. Piensa en un **`stack`** como una pila de platos: el último plato que pongas en la parte superior será el primero que retires.

<div align="center">
  <img src="https://github.com/jfercode/42-Push-swap/blob/main/assets/Stack.png" alt="stack.png" width="200">
</div>

Al inicio, tendrás un **`stack`**, llamado **`stack a`**, con todos tus números colocados uno al lado del otro. Con la ayuda de las operaciones que se describen a continuación, al final todos los números del **stack** **a** deberán estar ordenados.

Para ello, puedes usar un segundo **`stack`** vacío, llamado **`stack b`**, en el que puedes enviar temporalmente elementos. Aquí están las operaciones que puedes usar (y que deberás programar):

- **`sa (swap a):`** 🔄 Intercambia los dos primeros elementos en la parte superior del **`stack a`**. No hace nada si hay uno o ninguno.
  
- **`sb (swap b):`** 🔄 Intercambia los dos primeros elementos en la parte superior del **`stack b`**. No hace nada si hay uno o ninguno.
  
- **`ss:`** Realiza **`sa`** y **`sb`** al mismo tiempo.
  
- **`pa (push a):`** ⬆️ Toma el primer elemento de la parte superior de **`stack b`** y lo pone en **`stack a`**. No hace nada si **`stack b`** está vacío.
  
- **`pb (push b):`** ⬇️ Toma el primer elemento de la parte superior de **`stack a`** y lo pone en **`stack b`**. No hace nada si **`stack a`** está vacío.
  
- **`ra (rotate a):`** 🔁 Desplaza todos los elementos del **`stack a`** una posición hacia arriba. El primer elemento pasa a ser el último.
  
- **`rb (rotate b):`** 🔁 Desplaza todos los elementos del **`stack b`** una posición hacia arriba. El primer elemento pasa a ser el último.
  
- **`rr:`** Realiza **`ra`** y **`rb`** al mismo tiempo.
  
- **`rra (reverse rotate a):`** 🔄 Desplaza todos los elementos del **`stack a`** una posición hacia abajo. El último elemento pasa a ser el primero.
  
- **`rrb (reverse rotate b):`** 🔄 Desplaza todos los elementos del **`stack b`** una posición hacia abajo. El último elemento pasa a ser el primero.
  
- **`rrr:`** Realiza **`rra`** y **`rrb`** al mismo tiempo.

## Cómo ejecutar 🖥️

Los siguientes comandos deben ser ejecutados en la terminal, dentro del directorio de tu proyecto:

- **`make all`**: Compila el proyecto y genera la biblioteca estática `push_swap.a`.

- **`make test`**: Una vez compilado, genera un ejecutable llamado `push_swap`.

- **`make clean`**: Elimina los archivos objeto (`.o`) generados durante la compilación.
  
- **`make fclean`**: Ejecuta el comando `clean` y, además, elimina el archivo `push_swap.a` y cualquier ejecutable generado.

- **`make re`**: Ejecuta los comandos `fclean` y `all`, recompilando todo el proyecto desde cero.

## Uso del programa 🏃

Una vez generado el archivo `push_swap` podremos ejecutarlo por teminal pasandole una lista de números como argumentos. Algunos posibles ejemplos para su ejecución serían:


A continuación el programa mostrará por la terminal la serie de instrucciones que utiliza para ordenar el stack, no como tal el stack ordenado.

### Casos de error ⚠️
Ten en cuenta que el programa devolverá Error si se topa con uno de los siguientes casos:
- Si se encuentra con caracteres no numéricos: `./push_swap 1 3 dog 35 80 -3`
- Si se manda como argumentos números repetidos: `./push_swap 1 3 58 9 3`
- Si alguno de los valores enviados se encuentran fuera de los rangos de **INT_MIN** y **INT_MAX**: `./push_swap "214748364748385 28 47 29"`

## Configuración ⚙️

Puedes ajustar las opciones de compilación en el Makefile según tus necesidades específicas. 

## Autor 👨‍💻

<div align="center">
  <img src="https://avatars.githubusercontent.com/u/102600920?v=4" alt="Logo" width="200"/>
  <br/> 
  <a href="https://github.com/jfercode">Javier Fernández Correa</a>
</div>
<div align="center">
  <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcTVInHuUPtp3uiEuvF0aYAkFBUzpnr65b2CDA&s" alt="Logo"/>
</div>
