# QuantumCrypt

Acest proiect reprezintă un joc bazat pe criptarea cuvintelor, implementată în limbajul de programare `C++`. Scopul principal al acestei aplicații este realizarea unui scor cât mai mare, oferind funcționalități precum "Achievements", vizualizarea statisticilor și interacționarea cu diverse meniuri.

## Utilizare

Se recomandă utilizarea `C++23` pentru a asigura rularea corectă a programului. Este posibil ca versiunile anterioare de `C++` să corespundă standardelor `C++23` utilizate însă nu sunt recomandate.

Pentru rularea codului este obligatorie instalarea bibliotecii open-source `ncurses` care a fost necesară pentru realizarea reîmprospătării datelor pe ecran fără conflicte cu introducerea datelor.

## Funcționalități

- generarea de cuvinte și criptarea lor
- creșterea treptată a dificultății jocului
- stocarea și vizualizarea statisticilor
- opțiuni
- realizări ("achievements")

## Cum funcționează jocul

Jocul începe cu un cuvânt decriptat, iar jucătorul trebuie să îl cripteze astfel încât pentru fiecare literă se va scrie următoarea literă din alfabet, după modelului de criptare Caesar. Excepție de la regulă face litera 'z' care va fi transformată în litera 'a'.

Punctele sunt acordate în funcție de complexitatea cuvântului.

După terminarea timpului, scorul jocului se compară cu scorul maxim obținut de jucător în toate celelalte jocuri ale sale și se înlocuiește dacă se realizează depășirea sa.

## Concepte de programare folosite

- programare orientată pe obiecte
- timer
- multithreading
- frame generation, frame refresh
- word generation
- global stats
