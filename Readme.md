Przy pomocy potokow nienazwanych systemu UNIX zaimplementowac problem Pro-
ducenta i konsumenta”. Dla zademonstrowania, ze nie doszlo do utraty ani zwielokrot-
nienia towaru, niech Producent pobiera ,,surowiec” (np. porcje bajtow) z pliku tekstowego
i wstawia go jako towar do potoku, a Konsument niech umieszcza pobrany z potoku
towar w innym pliku tekstowym (porcje danych Producenta i Konsumenta nie musza byc
rowne). Po zakonczeniu dzialania programow (wyczerpaniu zasobow ,surowca”) oba pliki
tekstowe powinny byc identyczne (mozna to sprawdzic poleceniem di↵ -s, kt´ore najlepiej
umiescic w pliku Makefile po poleceniu uruchomienia programu). Oba procesy niech
drukuj ,a odpowiednie komunikaty na ekranie, w tym towar, ktory przesylaj ,a. Do zasymu-
lowania roznych szybkosci dzialania programow uzyc funkcji sleep, np. z losowym czasem
usypiania. Do czytania/pisania danych z/do pliku tekstowego, jak rowniez wypisywania
ich na ekran uzyc funkcji read i write.#include <stdio.h>
