# FT_PRINTF #

## <a name="introduction-en">📖 Introduction ##

Own implementation of printf() function from libc (stdio.h).

The prototype of ft_printf() is:
`int ft_printf(const char *, ...);`

Here are the requirements:

* Don’t implement the buffer management of the original printf().
* Your function has to handle the following conversions: `cspdiuxX%`
* Your function will be compared against the original printf().
* Use Variadic arguments (unknown number of arguments)

The first requirements is to not use any sort of buffering so this ft_printf is executing each argument one by one, and writing on the file descriptor (1, for stdout).

## 📋 Table of Contents ##

* [📖 Introduction](#introduction-en)
* [✨ Compatible Flags](#compatible-flags-en)
* [🚀 Usage](#usage-en)
* [⚙️ Compilation](#compilation-en)
* [📝 Additionnal Notes](#notes-en)

## <a name="compatible-flags-en">✨ Compatible flags ##

`cspdiuxX%` means that you need to handle the following letters as 'flags' :
`c`,`s`,`p`,`d`,`i`,`u`,`x`,`X`,`%`.

* `c` is for characters
* `s` is for NULL-Terminated (`\0`) Strings
* `p` is for `void *` adresses in hex format
* `d` is for base 10 decimal number
* `i` is for base 10 integers
* `u` is for base 10 unsigned decimal number
* `x` is for base 16 hex format (lowercase)
* `X` is for base 16 hex format (UPPERcase)
* `%` is for printing a single '%' sign.

The flags are used as following :
`"A normal string and here a flag %d", 15478`

%d is the flag and 15478 is the number that we want to print.

### Notes ###

Any other flag will result as an undefined behavior so please don't.

## <a name="usage-en">🚀 Usage ##

`int ft_printf(const char *str, ...);`

`str` is the string to print

`...` are the variadic arguments.

Using variadic arguments is usefull when you don't know at advance the number of arguments that the function will receive, to handle the type of the argument, you need to know it's type. The type is known with the flag that you use. You can print an integer with a string flag but it will not work as intended.

## <a name="compilation-en">⚙️ Compilation ##

Use ``make`` for compiling the library

```sh
make
```

To use it in your program, you should add `-lftprintf` to your compilation lines.

## <a name="notes-en">📝 Additionnal Notes ##

Can't leak as there is no memory allocation in the library.

---

# FT_PRINTF #

## <a name="introduction-fr">📖 Introduction ##

Implémentation de la fonction 'printf()' de la bibliothèque libc (stdio.h).

Le prototype de ft_printf est :
`int ft_printf(const char *, ...);`

Voici les prérequis :

* Ne pas implémenter de gestion de la mémoire comme sur la fonction originale printf()
* Votre fonction doit gérer les conversions suivantes : `cspdiuxX%`
* Votre fonction sera comparée à l'originale (printf())
* Utiliser des arguments Variadic (nombres d'argument inconnu à l'avance)

Le premier prérequis est de ne pas utiliser de système de gestion de la mémoire car notre ft_printf exécute chaque argument un par un, et écrit directement sur le descripteur de fichier (1, pour stdout).

## 📋 Table des matières ##

* [📖 Introduction](#introduction-fr)
* [✨ Compatible Flags](#compatible-flags-fr)
* [🚀 Usage](#usage-fr)
* [⚙️ Compilation](#compilation-fr)
* [📝 Notes supplémentaires](#notes-fr)

## <a name="compatible-flags-fr">Compatible flags ##

`cspdiuxX%` veut dire qu'il faut être compatible avec les flags suivants :
`c`,`s`,`p`,`d`,`i`,`u`,`x`,`X`,`%`.

* `c` pour les caractères
* `s` pour les chaînes de caractères terminées par un `\0`.
* `p` pour les adresses en `void *`  dans le format hexadécimal
* `d` pour les nombres décimaux en base 10
* `i` pour les nombres entiers en base 10
* `u` pour les nombres entiers signés en base 10
* `x` pour les nombres en base 16 au format hexadécimal (casse basse)
* `X` pour les nombres en base 16 au format hexadécimal (casse HAUTE)
* `%` pour écrire uniquement le symbole '%'.

Les flags sont utilisés comme ça :
`"A normal string and here a flag %d", 15478`

%d est le flag et 15478 est le nombre que l'on veut afficher.

### Notes ###

N'importe quel autre flag non défini précédemment résultera n'une manière indéterminée donc s'il vous plait, évitez.

## <a name="usage-fr">Utilisation ##

`int ft_printf(const char *str, ...);`

`str` est la chaîne de caractère à afficher

`...` représente les arguments variadics.

Utiliser des arguments variadics est pratique quand on ne connait pas à l'avance le nombre d'argument que contiendra la fonction, et sans connaitre leur type. Pour déterminer le type, on utilise le flag. On peut par exemple afficher un entier avec le flag d'une chaîne mais ça ne marchera pas comme prévu.

## <a name="compilation-fr">Compilation ##

Utiliser ``make`` pour compiler la bibliothèque

```sh
make
```

Pour l'utiliser dans un programme, vous devriez ajouter `-lftprintf` à vos lignes de compilation.

## <a name="notes-fr">Notes Supplémentaires ##

La bibliothèque ne peut pas leak car il n'y a pas d'allocation mémoire.
