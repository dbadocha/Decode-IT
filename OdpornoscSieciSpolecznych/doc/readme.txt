ODPORNO�� SIECI SPO�ECZNYCH
Trackerzy z naszej ekipy, Alice i Rob, potrzebuj� Twojej pomocy.
Bardzo zainteresowali si� sieciami spo�ecznymi i maj� kilka pomys��w jak mo�emy je wykorzysta� przy naszym zleceniu.

� �Al, wierzysz w zalecenia dawane Ci przez kolesi, kt�rych nie znasz osobi�cie?� � spyta� Robert
� �Nie.� � odpowiedzia�a Alicja
� �Ale jak tw�j ziomek daje Ci tipa, to raczej mu ufasz?� � dr��y� Rob
� �Dok�adnie, wtedy to co innego� � odpowiedzia�a Alice
� �W�a�nie, ja mam tak samo. A gdyby kto� chcia� wp�yn�� na ca�� sie� spo�eczn�?� � zapyta� Rob
� �Je�li w danej sieci istnieje osoba, powiedzmy A, kt�ra jest w prywatnej relacji z ca�� reszt�, to wystarczy kontrolowa�
konto tej osoby, �eby m�c wp�ywa� na ca�� sie�.� � kontynuowa� Robert
� �Czyli odporno�� sieci na takie ataki zale�y od jej struktury?� � zauwa�y�a Alice
� �Totalnie! I dok�adnie to musimy rozgry��.� � potwierdzi� Rob

Kilka godzin p�niej oboje zgodzili si� na nast�puj�cy model: dla sieci spo�ecznej o n cz�onkach i symetrycznej
relacji przyja�ni (tzn. je�li A jest przyjacielem B to r�wnie� B jest przyjacielem A.
Dodatkowo, ka�demu cz�onkowi A przypisujemy dodatni� liczb� ca�kowit� W(A).
Liczb� W(A) interpretujemy jako koszt przej�cia kontroli nad kontem cz�onka A.

Zadanie jakie postawili sobie nasi trackerzy polega na znalezieniu takiego zbioru cz�onk�w sieci spo�ecznej D, �e ka�dy cz�onek
sieci spo�ecznej albo nale�y do tego zbioru albo przyja�ni si� z kim� kto do tego zbioru nale�y.
Dodatkowo Alice i Rob chcieliby znale�� taki zbi�r D, dla kt�rego koszt przej�cia kont nale��cych do tego zbioru jest mo�liwie najmniejszy.

Pom� im to ogarn��, a b�dziemy o krok bli�ej do udzia�u w wa�nym dla nas konkursie!


DANE WEJ�CIOWE
W pierwszej linii danych wej�ciowych znajduje si� liczba ca�kowita nb�d�ca liczb� cz�onk�w sieci spo�ecznej.
W kolejnych n liniach znajduj� si� dane w nast�puj�cym formacie:
namei, W(namei)

To znaczy najpierw nazwa i-tego cz�onka sieci b�d�ca ci�giem co najwy�ej 15 znak�w.
Nast�pnie liczba ca�kowita 1 <= namei <= 205 b�d�ca kosztem przej�cia konta tego cz�onka.
Kolejna linia danych wej�ciowych zawiera liczb� ca�kowit� m b�d�c� liczb� relacji przyja�ni mi�dzy cz�onkami sieci spo�ecznej.
W kolejnych m liniach znajduj� si� dane w nast�puj�cym formacie:

namex, namey

To znaczy nazwy dw�ch r�nych cz�onk�w o kt�rych wiadomo, �e s� przyjaci�mi.


DANE WYJ�CIOWE
W pierwszej linii danych wyj�ciowych wypisz liczb� d b�d�c� liczb� cz�onk�w w wyznaczonym zbiorze D.
Nast�pnie w kolejnych d liniach wypisz nazwy cz�onk�w zbioru D.

Na koniec, w ostatniej linii danych wej�ciowych wypisz jedn� liczb� b�d�c� sumarycznym kosztem przej�cia wszystkich kont ze zbioru D.


SPOS�B PUNKTACJI
Liczba punkt�w jak� uzyska Twoje rozwi�zanie zostanie obliczone jak S/Sd, gdzie S jest sumarycznym kosztem przej�cia wszystkich
kont sieci spo�ecznej a Sd jest sumarycznym kosztem przej�cia wszystkich kont ze zbioru D.

Wynik ko�cowy jest czterokrotno�ci� sumy wynik�w uzyskanych przez Tw�j program dla wszystkich poprawnie rozwi�zanych przypadk�w testowych.

Zadanie zostaje uznane za rozwi�zane je�li Tw�j program rozwi��e przynajmniej jedne przypadek testowy i jako wynik ko�cowy uzyska ponad 20 punt�w.

PRZYK�ADY
Wej�cie

5
Robert 12
Julia 23
Adam 1
Carol 10
Daniel 4
5
Robert Julia
Robert Carol
Adam Robert
Daniel Adam
Daniel Julia

Wyj�cie

2
Daniel
Carol
14


LICZBA PUNKT�W
Rozwi�znie podane w przyk�adzie jest poprawne i uzyska�oby 50/14 = 3.57142857143 punkt�w.
Wk�ad tego przypadku testowego w ko�cowy wynik by�by wtedy r�wny 4x3.57142857143 punkt�w.
PRZYPADKI TESTOWE
t	n	m	l
1	100	99	2s
2	100	101	2s
3	100	105	2s
4	100	114	2s
5	100	130	2s
6	300	299	5s
7	300	302	5s
8	300	311	5s
9	300	339	5s
10	300	404	5s

Gdzie:
t � numer przypadku testowego
n � liczba cz�onk�w sieci spo�ecznej
m � liczba relacji przyja�ni
l � limit czasu