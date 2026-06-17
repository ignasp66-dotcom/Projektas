# Filmų katalogo valdymo sistema

## Projekto tikslas

Sukurti C++ konsolinę programą, skirtą filmų katalogo valdymui. Programa leidžia saugoti, peržiūrėti, redaguoti, šalinti ir ieškoti filmų duomenų bei juos išsaugoti tekstiniame faile.

---

## Temos aprašymas

Šis projektas yra filmų katalogo valdymo sistema, kurioje vartotojas gali tvarkyti filmų sąrašą. Kiekvienas filmas turi unikalų ID, pavadinimą, žanrą, išleidimo metus, trukmę ir įvertinimą.

Programa naudoja tekstinį failą duomenų saugojimui, todėl visi atlikti pakeitimai gali būti išsaugomi ir naudojami kitą kartą paleidus programą.

---

## Programos funkcionalumas

### CRUD operacijos

#### Create (Sukurti)

* Pridėti naują filmą į katalogą.

#### Read (Peržiūrėti)

* Peržiūrėti visų filmų sąrašą.

#### Update (Atnaujinti)

* Redaguoti esamą filmą pagal jo ID.

#### Delete (Pašalinti)

* Ištrinti filmą pagal jo ID.

---

## Papildomos funkcijos

### Paieška pagal žanrą

Vartotojas gali ieškoti filmų pagal vieną arba kelis žanrus.

Pavyzdžiai:

* Siaubo
* Trileris
* Siaubo,Trileris,Psichologinis trileris

### Paieška pagal pavadinimą

Galima ieškoti filmo pagal visą pavadinimą arba jo dalį.

Pavyzdžiai:

* Dark
* Island
* The

### Filmų rikiavimas

Filmus galima surikiuoti:

1. Pagal įvertinimą (nuo didžiausio iki mažiausio)
2. Pagal metus (nuo naujausio iki seniausio)
3. Pagal trukmę (nuo ilgiausio iki trumpiausio)

---

## Naudojami failai

### main.cpp

Pagrindinis programos kodas.

### filmai.txt

Tekstinis failas, kuriame saugomi filmų duomenys.

Duomenų formatas:

ID;Pavadinimas;Žanras;Metai;Trukmė;Įvertinimas

Pavyzdys:

1;The Shawshank Redemption;Drama;1994;142;9.3

---

## Naudotos technologijos

* C++
* Struct
* Vector
* Failų skaitymas ir rašymas
* Funkcijos
* Sąlyginiai sakiniai (if, else, switch)
* Ciklai (for, while)
* STL sort()

---

## Programos paleidimas

1. Atsisiųskite projektą iš GitHub.
2. Atidarykite projektą pasirinktoje C++ kūrimo aplinkoje.
3. Įsitikinkite, kad failas „filmai.txt“ yra tame pačiame aplanke kaip programa.
4. Sukompiliuokite programą.
5. Paleiskite programą.
6. Naudokite meniu funkcijas.

---

## Projekto autorius

Studento vardas ir pavardė: Ignas Pumputis

Studijų programa: Struktūrinis programavimas ir algoritmai

