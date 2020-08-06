SZKIELETOWA SIE� �WIAT�OWODOWA
Kolejny krok za nami, ale nie przestajemy. Aby robota posz�a sprawnie i bez zak��ce� potrzebujemy dobrej sieci, dlatego stawiamy �wiat�owodow� sie� szkieletow�.
Je�li przesy� odbywa si� tylko poprzez t� sie�, to op�nienia komunikacyjne s� pomijalne. Dzi�ki temu sie� rozwija si� bardzo dynamicznie.
Musisz napisa� program, kt�ry odpowie czy dane dwa adresy IP ��czy sie� czysto �wiat�owodowa. Ma by� czyste �wiat�o, czaisz? Mamy do po��czenia dwa fakty:
jeden z naszych dostarczy nam numery IP pomi�dzy kt�rymi koniecznie trzeba zbudowa� bezpo�rednie po��czenie [czyli operacje typu B �]
trzeba te� zbada� kt�re w�z�y ��cz� si� czysto �wiat�owodowo, cho� niekoniecznie bezpo�rednio [czyli operacje typu T �]

DANE WEJ�CIOWE
Wej�cie sk�ada si� z wierszy, z kt�rych ka�dy zawiera informacj� o budowie nowego po��czenia lub zapytanie o istnienie po��czenia.

Informacja o budowie nowego ��cza ma posta�:
B  IP1  IP2

gdzie IP1 i IP2 to adresy IP (w formacie czterech liczb z zakresu 1..255 oddzielonych kropkami), pomi�dzy kt�rymi powstaje ��cze.
Na pocz�tku dzia�ania programu sie� nie zawiera �adnych ��czy.

Zapytanie o istnienie po��czenia �wiat�owodowego ma natomiast posta�:
T  IP1  IP2

Dane wej�ciowe ko�cz� si� wraz z ko�cem pliku.


DANE WYJ�CIOWE
Na ka�de zapytanie nale�y wypisa� w osobnym wierszu T lub N w zale�no�ci, czy dane dwa adresy IP ��czy sie� �wiat�owodowa, czy te� nie.


PRZYK�ADY
Wej�cie

B 100.100.100.1 100.100.100.2
B 100.100.100.1 100.100.100.3
B 100.100.100.10 100.100.100.11
T 100.100.100.1 100.100.100.3
T 100.100.100.10 100.100.100.2
T 100.100.100.10 100.100.100.11
B 100.100.100.11 100.100.100.2
T 100.100.100.10 100.100.100.3
T 100.100.100.100 100.100.100.103

Wyj�cie

T
N
T
T
N