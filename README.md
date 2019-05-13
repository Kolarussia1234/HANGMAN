#C++ HANGMAN GAME

Minu lõputöö on programm ( täpsemalt mäng ) HANGMAN ehk Poomine.

Reegild on lihtsad:

On üks sõna mis on saladuses, teie ülesanne on seda ära arvata.

Kordi, et proovida on 5 ->  ehk kui te vastate valesti ühe korra,
siis saate veel 4 korda proovida jne. Kui korduste arv saab otsa,
siis mäng on läbi ja te kaotasite.
Muidugi te võite proovida uuesti või siis mängu kinni panna.
Kui te sisestate tähe õigesti, siis kordused maha ei lähe ning programm
näitab mitu tähte on veel jäänud.

NB! -> Kui sõnas on mitu sama tähte - näiteks sõna jäätis vms ning te sisestate 
tähe 'ä' siis avanevad kohe mõlemad tähed ( see peaks olema loogiline :) ).
Programm loeb täpitähed nagu tavalised tähed ( ilma täppideta ), ehk tegelikult
sõna oleks jaatis, mitte jäätis. Kuid kui te arvate, et sõnas on mingi täpitäht, siis
võite seda sisestada, programm täppe lihtsalt ei arvesta.

Mängus kasutatav sõna on non case sensitive, ehk suva kas te sisestate suure või väikese
tähe programm loeb mõlemad õigeks.

Sisestamine toimub koheselt - ENTERit vajutama ei pea.


Version: v1.0.5
Platform: Windows
Author: Nikolai Ovtsinnikov  / Estonia / 2019 / nikolai.ovtsinnikov@gmail.com

v1.0.0: Game made
v1.0.1: Code made more readable, added some new features, bugfixes
v1.0.2: Added check for same letter input
v1.0.3: Added main loop reset after lose
v1.0.4: Grouped some code into different functions
v1.0.4: Fixed main loop reset, some other minor changes
