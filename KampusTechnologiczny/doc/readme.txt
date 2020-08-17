KAMPUS TECHNOLOGICZNY
Potrzebujemy kontrolowaæ miejsce, w którym ma powstaæ kampus technologiczny.
Og³osili konkurs i musimy go wygraæ, ¿eby nasz projekt zosta³ wdro¿ony.
U³atwi to du¿o rzeczy i musisz nam w tym pomóc.

Zdecydowano, ¿e w fazie wstêpnej projekty zostan¹ poddane ocenie parametrycznej, w której jednym z elementów
jest koszt stworzenia i utrzymania Kampusu, a to z kolei zale¿y od d³ugoœci ogrodzenia, jakie trzeba bêdzie wokó³ niego wybudowaæ.
Obiekty, które bêd¹ umieszczone w Kampusie maj¹ nieregularne kszta³ty, ponadto konieczne jest zagwarantowanie
wolnej przestrzeni parku wokó³ ka¿dego obiektu, dlatego ustalono, ¿e dobrym przybli¿eniem bêdzie plan, na którym obiekty
wraz z woln¹ przestrzeni¹ wokó³ bêd¹ zaznaczone jako okrêgi.
Twoim zadaniem jest dla ka¿dego planu oszacowanie najmniejszej mo¿liwej d³ugoœci ogrodzenia budowanego w taki sposób, aby Kampus stanowi³ jeden spójny obszar.

DANE WEJŒCIOWE
W pierwszej linii liczba testów t. Dla ka¿dego testu w pierwszej linii liczba okrêgów n i w kolejnych liniach
dla ka¿dego okrêgu trzy liczby ca³kowite -1000 <= x,y, x <= 1000, wspó³rzêdne œrodka i promieñ okrêgu odpowiednio.
NIE NALE¯Y zak³adaæ, ¿e okrêgi siê nie przecinaj¹ lub, ¿e nie s¹ po³o¿one jeden wewn¹trz drugiego.

DANE WYJŒCIOWE
Dla ka¿dego testu w oddzielnej linii jedna liczba bêd¹ca minimaln¹ d³ugoœci¹ ogrodzenia wokó³ kampusu.

SPOSÓB PUNKTACJI
Niech li oznacza wzorcow¹ d³ugoœæ ogrodzenia, a l'i d³ugoœæ obliczon¹ przez program dla planu o numerze i

Niech Ei = |(li - l'i/li)| oraz xi = 1.1 + 0.14log Ei, gdzie log oznacza logarytm dziesiêtny. Wartoœci wzorcowe podawane s¹ z dok³adnoœci¹ do 10^-10.

Punktacja za ocenê planu o numerze i wynosi pi = 1 - min(1, max(0, xi)).

Ostatecznie liczba punktów za zadanie sk³adaj¹ce siê z t testów jest normalizowana tak, ¿eby finalna punktacja zawiera³a siê w przedziale od 0 do 100 

score = 100(p1 + p2 + ... + pi) / t

Aby zadanie zosta³o uznane za rozwi¹zane nale¿y zdobyæ ponad 20 punktów.


PRZYK£ADY
Wejœcie

1
2
100 100 100
500 100 100
Wyjœcie

-
KOMENTARZ
Wzorcowa odpowiedŸ w tym przypadku, to 1428,3185307180. Dla odpowiedzi 1429,215 punktacja w zaokr¹gleniu do 10^-2 wynosi 0,35.
Ostateczna liczba punktów by³aby wtedy równa 35.

Dodatkowe dane testowe dostêpne do pobrania.
https://decode-it.pracuj.pl/wp-content/uploads/2020/07/GS_PARKS-kampus_dane-2.zip