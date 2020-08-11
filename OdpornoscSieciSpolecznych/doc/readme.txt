ODPORNOŒÆ SIECI SPO£ECZNYCH
Trackerzy z naszej ekipy, Alice i Rob, potrzebuj¹ Twojej pomocy.
Bardzo zainteresowali siê sieciami spo³ecznymi i maj¹ kilka pomys³ów jak mo¿emy je wykorzystaæ przy naszym zleceniu.

– “Al, wierzysz w zalecenia dawane Ci przez kolesi, których nie znasz osobiœcie?” – spyta³ Robert
– “Nie.” – odpowiedzia³a Alicja
– “Ale jak twój ziomek daje Ci tipa, to raczej mu ufasz?” – dr¹¿y³ Rob
– “Dok³adnie, wtedy to co innego” – odpowiedzia³a Alice
– “W³aœnie, ja mam tak samo. A gdyby ktoœ chcia³ wp³yn¹æ na ca³¹ sieæ spo³eczn¹?” – zapyta³ Rob
– “Jeœli w danej sieci istnieje osoba, powiedzmy A, która jest w prywatnej relacji z ca³¹ reszt¹, to wystarczy kontrolowaæ
konto tej osoby, ¿eby móc wp³ywaæ na ca³¹ sieæ.” – kontynuowa³ Robert
– “Czyli odpornoœæ sieci na takie ataki zale¿y od jej struktury?” – zauwa¿y³a Alice
– “Totalnie! I dok³adnie to musimy rozgryŸæ.” – potwierdzi³ Rob

Kilka godzin póŸniej oboje zgodzili siê na nastêpuj¹cy model: dla sieci spo³ecznej o n cz³onkach i symetrycznej
relacji przyjaŸni (tzn. jeœli A jest przyjacielem B to równie¿ B jest przyjacielem A.
Dodatkowo, ka¿demu cz³onkowi A przypisujemy dodatni¹ liczbê ca³kowit¹ W(A).
Liczbê W(A) interpretujemy jako koszt przejêcia kontroli nad kontem cz³onka A.

Zadanie jakie postawili sobie nasi trackerzy polega na znalezieniu takiego zbioru cz³onków sieci spo³ecznej D, ¿e ka¿dy cz³onek
sieci spo³ecznej albo nale¿y do tego zbioru albo przyjaŸni siê z kimœ kto do tego zbioru nale¿y.
Dodatkowo Alice i Rob chcieliby znaleŸæ taki zbiór D, dla którego koszt przejêcia kont nale¿¹cych do tego zbioru jest mo¿liwie najmniejszy.

Pomó¿ im to ogarn¹æ, a bêdziemy o krok bli¿ej do udzia³u w wa¿nym dla nas konkursie!


DANE WEJŒCIOWE
W pierwszej linii danych wejœciowych znajduje siê liczba ca³kowita nbêd¹ca liczb¹ cz³onków sieci spo³ecznej.
W kolejnych n liniach znajduj¹ siê dane w nastêpuj¹cym formacie:
namei, W(namei)

To znaczy najpierw nazwa i-tego cz³onka sieci bêd¹ca ci¹giem co najwy¿ej 15 znaków.
Nastêpnie liczba ca³kowita 1 <= namei <= 205 bêd¹ca kosztem przejêcia konta tego cz³onka.
Kolejna linia danych wejœciowych zawiera liczbê ca³kowit¹ m bêd¹c¹ liczb¹ relacji przyjaŸni miêdzy cz³onkami sieci spo³ecznej.
W kolejnych m liniach znajduj¹ siê dane w nastêpuj¹cym formacie:

namex, namey

To znaczy nazwy dwóch ró¿nych cz³onków o których wiadomo, ¿e s¹ przyjació³mi.


DANE WYJŒCIOWE
W pierwszej linii danych wyjœciowych wypisz liczbê d bêd¹c¹ liczb¹ cz³onków w wyznaczonym zbiorze D.
Nastêpnie w kolejnych d liniach wypisz nazwy cz³onków zbioru D.

Na koniec, w ostatniej linii danych wejœciowych wypisz jedn¹ liczbê bêd¹c¹ sumarycznym kosztem przejêcia wszystkich kont ze zbioru D.


SPOSÓB PUNKTACJI
Liczba punktów jak¹ uzyska Twoje rozwi¹zanie zostanie obliczone jak S/Sd, gdzie S jest sumarycznym kosztem przejêcia wszystkich
kont sieci spo³ecznej a Sd jest sumarycznym kosztem przejêcia wszystkich kont ze zbioru D.

Wynik koñcowy jest czterokrotnoœci¹ sumy wyników uzyskanych przez Twój program dla wszystkich poprawnie rozwi¹zanych przypadków testowych.

Zadanie zostaje uznane za rozwi¹zane jeœli Twój program rozwi¹¿e przynajmniej jedne przypadek testowy i jako wynik koñcowy uzyska ponad 20 puntów.

PRZYK£ADY
Wejœcie

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

Wyjœcie

2
Daniel
Carol
14


LICZBA PUNKTÓW
Rozwi¹znie podane w przyk³adzie jest poprawne i uzyska³oby 50/14 = 3.57142857143 punktów.
Wk³ad tego przypadku testowego w koñcowy wynik by³by wtedy równy 4x3.57142857143 punktów.
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
t – numer przypadku testowego
n – liczba cz³onków sieci spo³ecznej
m – liczba relacji przyjaŸni
l – limit czasu