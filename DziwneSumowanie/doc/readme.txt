DZIWNE SUMOWANIE
Dobra, przysz³a pora na prawdziw¹ akcjê.
Pierwsza przeszkoda – znaleŸliœmy przydatny klucz, który ma przestarza³e kodowanie, trzeba je rozszyfrowaæ.
Mamy ci¹g cyfr, który mo¿na podzieliæ na grupy po cztery cyfry ka¿da. Dla ka¿dej czterocyfrowej grupy stwórz dwie dwucyfrowe liczby.
Pierwsz¹ liczbê tworzymy bior¹c pierwsz¹ i trzeci¹ cyfrê grupy. Drug¹ liczbê tworzymy bior¹c drug¹ i czwart¹ cyfrê grupy.
Suma otrzymanych liczb jest kodem ASCII kolejnego znaku tajnego has³a. Twoim zadaniem jest napisanie programu dekoduj¹cego has³a z podanych sekwencji cyfr.

Przyk³adowo sekwencjê 24746211151814964359 dzielimy na piêæ grup 2474 6211 1518 1496 4359.
Nastêpnie dla ka¿dej grupy tworzymy dwie liczby, które bêdziemy dodawaæ:
27+44  61+21  11+58  19+46  45+39 otrzymuj¹c w ten sposób kody znaków ASCII 71 82 69 65 84.
W kodzie ASCII mamy has³o: GREAT.

Odszyfrujesz has³o? Wygl¹da na sporo roboty, szybciej i pewniej bêdzie napisaæ program, który zrobi to za Ciebie.

DANE WEJŒCIOWE
Pierwsza linia danych wejœciowych zawiera jedn¹ liczbê t – liczbe przypadków testowych.
Dla ka¿dego przypadku testowego, pierwsza linia zawiera jedn¹ dodatni¹ liczbê ca³kowit¹  1 <= n <= 10.
Druga linia zawiera ci¹g cyfr d³ugoœci 4n bêd¹cy zaszyfrowanym has³em.


DANE WYJŒCIOWE
Dla ka¿dego przypadku testowego w osobnej linii nale¿y wypisaæ rozszyfrowane has³o.


PRZYK£ADY

Wejœcie
2
5
24746211151814964359
1
2244

Wyjœcie
GREAT
0