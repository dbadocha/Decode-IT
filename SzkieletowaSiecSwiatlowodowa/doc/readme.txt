SZKIELETOWA SIEÆ ŒWIAT£OWODOWA
Kolejny krok za nami, ale nie przestajemy. Aby robota posz³a sprawnie i bez zak³óceñ potrzebujemy dobrej sieci, dlatego stawiamy œwiat³owodow¹ sieæ szkieletow¹.
Jeœli przesy³ odbywa siê tylko poprzez tê sieæ, to opóŸnienia komunikacyjne s¹ pomijalne. Dziêki temu sieæ rozwija siê bardzo dynamicznie.
Musisz napisaæ program, który odpowie czy dane dwa adresy IP ³¹czy sieæ czysto œwiat³owodowa. Ma byæ czyste œwiat³o, czaisz? Mamy do po³¹czenia dwa fakty:
jeden z naszych dostarczy nam numery IP pomiêdzy którymi koniecznie trzeba zbudowaæ bezpoœrednie po³¹czenie [czyli operacje typu B …]
trzeba te¿ zbadaæ które wêz³y ³¹cz¹ siê czysto œwiat³owodowo, choæ niekoniecznie bezpoœrednio [czyli operacje typu T …]

DANE WEJŒCIOWE
Wejœcie sk³ada siê z wierszy, z których ka¿dy zawiera informacjê o budowie nowego po³¹czenia lub zapytanie o istnienie po³¹czenia.

Informacja o budowie nowego ³¹cza ma postaæ:
B  IP1  IP2

gdzie IP1 i IP2 to adresy IP (w formacie czterech liczb z zakresu 1..255 oddzielonych kropkami), pomiêdzy którymi powstaje ³¹cze.
Na pocz¹tku dzia³ania programu sieæ nie zawiera ¿adnych ³¹czy.

Zapytanie o istnienie po³¹czenia œwiat³owodowego ma natomiast postaæ:
T  IP1  IP2

Dane wejœciowe koñcz¹ siê wraz z koñcem pliku.


DANE WYJŒCIOWE
Na ka¿de zapytanie nale¿y wypisaæ w osobnym wierszu T lub N w zale¿noœci, czy dane dwa adresy IP ³¹czy sieæ œwiat³owodowa, czy te¿ nie.


PRZYK£ADY
Wejœcie

B 100.100.100.1 100.100.100.2
B 100.100.100.1 100.100.100.3
B 100.100.100.10 100.100.100.11
T 100.100.100.1 100.100.100.3
T 100.100.100.10 100.100.100.2
T 100.100.100.10 100.100.100.11
B 100.100.100.11 100.100.100.2
T 100.100.100.10 100.100.100.3
T 100.100.100.100 100.100.100.103

Wyjœcie

T
N
T
T
N