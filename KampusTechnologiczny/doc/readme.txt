KAMPUS TECHNOLOGICZNY
Potrzebujemy kontrolowa� miejsce, w kt�rym ma powsta� kampus technologiczny.
Og�osili konkurs i musimy go wygra�, �eby nasz projekt zosta� wdro�ony.
U�atwi to du�o rzeczy i musisz nam w tym pom�c.

Zdecydowano, �e w fazie wst�pnej projekty zostan� poddane ocenie parametrycznej, w kt�rej jednym z element�w
jest koszt stworzenia i utrzymania Kampusu, a to z kolei zale�y od d�ugo�ci ogrodzenia, jakie trzeba b�dzie wok� niego wybudowa�.
Obiekty, kt�re b�d� umieszczone w Kampusie maj� nieregularne kszta�ty, ponadto konieczne jest zagwarantowanie
wolnej przestrzeni parku wok� ka�dego obiektu, dlatego ustalono, �e dobrym przybli�eniem b�dzie plan, na kt�rym obiekty
wraz z woln� przestrzeni� wok� b�d� zaznaczone jako okr�gi.
Twoim zadaniem jest dla ka�dego planu oszacowanie najmniejszej mo�liwej d�ugo�ci ogrodzenia budowanego w taki spos�b, aby Kampus stanowi� jeden sp�jny obszar.

DANE WEJ�CIOWE
W pierwszej linii liczba test�w t. Dla ka�dego testu w pierwszej linii liczba okr�g�w n i w kolejnych liniach
dla ka�dego okr�gu trzy liczby ca�kowite -1000 <= x,y, x <= 1000, wsp�rz�dne �rodka i promie� okr�gu odpowiednio.
NIE NALE�Y zak�ada�, �e okr�gi si� nie przecinaj� lub, �e nie s� po�o�one jeden wewn�trz drugiego.

DANE WYJ�CIOWE
Dla ka�dego testu w oddzielnej linii jedna liczba b�d�ca minimaln� d�ugo�ci� ogrodzenia wok� kampusu.

SPOS�B PUNKTACJI
Niech li oznacza wzorcow� d�ugo�� ogrodzenia, a l'i d�ugo�� obliczon� przez program dla planu o numerze i

Niech Ei = |(li - l'i/li)| oraz xi = 1.1 + 0.14log Ei, gdzie log oznacza logarytm dziesi�tny. Warto�ci wzorcowe podawane s� z dok�adno�ci� do 10^-10.

Punktacja za ocen� planu o numerze i wynosi pi = 1 - min(1, max(0, xi)).

Ostatecznie liczba punkt�w za zadanie sk�adaj�ce si� z t test�w jest normalizowana tak, �eby finalna punktacja zawiera�a si� w przedziale od 0 do 100 

score = 100(p1 + p2 + ... + pi) / t

Aby zadanie zosta�o uznane za rozwi�zane nale�y zdoby� ponad 20 punkt�w.


PRZYK�ADY
Wej�cie

1
2
100 100 100
500 100 100
Wyj�cie

-
KOMENTARZ
Wzorcowa odpowied� w tym przypadku, to 1428,3185307180. Dla odpowiedzi 1429,215 punktacja w zaokr�gleniu do 10^-2 wynosi 0,35.
Ostateczna liczba punkt�w by�aby wtedy r�wna 35.

Dodatkowe dane testowe dost�pne do pobrania.
https://decode-it.pracuj.pl/wp-content/uploads/2020/07/GS_PARKS-kampus_dane-2.zip