DZIWNE SUMOWANIE
Dobra, przysz�a pora na prawdziw� akcj�.
Pierwsza przeszkoda � znale�li�my przydatny klucz, kt�ry ma przestarza�e kodowanie, trzeba je rozszyfrowa�.
Mamy ci�g cyfr, kt�ry mo�na podzieli� na grupy po cztery cyfry ka�da. Dla ka�dej czterocyfrowej grupy stw�rz dwie dwucyfrowe liczby.
Pierwsz� liczb� tworzymy bior�c pierwsz� i trzeci� cyfr� grupy. Drug� liczb� tworzymy bior�c drug� i czwart� cyfr� grupy.
Suma otrzymanych liczb jest kodem ASCII kolejnego znaku tajnego has�a. Twoim zadaniem jest napisanie programu dekoduj�cego has�a z podanych sekwencji cyfr.

Przyk�adowo sekwencj� 24746211151814964359 dzielimy na pi�� grup 2474 6211 1518 1496 4359.
Nast�pnie dla ka�dej grupy tworzymy dwie liczby, kt�re b�dziemy dodawa�:
27+44  61+21  11+58  19+46  45+39 otrzymuj�c w ten spos�b kody znak�w ASCII 71 82 69 65 84.
W kodzie ASCII mamy has�o: GREAT.

Odszyfrujesz has�o? Wygl�da na sporo roboty, szybciej i pewniej b�dzie napisa� program, kt�ry zrobi to za Ciebie.

DANE WEJ�CIOWE
Pierwsza linia danych wej�ciowych zawiera jedn� liczb� t � liczbe przypadk�w testowych.
Dla ka�dego przypadku testowego, pierwsza linia zawiera jedn� dodatni� liczb� ca�kowit�  1 <= n <= 10.
Druga linia zawiera ci�g cyfr d�ugo�ci 4n b�d�cy zaszyfrowanym has�em.


DANE WYJ�CIOWE
Dla ka�dego przypadku testowego w osobnej linii nale�y wypisa� rozszyfrowane has�o.


PRZYK�ADY

Wej�cie
2
5
24746211151814964359
1
2244

Wyj�cie
GREAT
0