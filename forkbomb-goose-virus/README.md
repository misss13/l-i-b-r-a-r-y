# Forkbomb - goose - virus
- tylko pod windowsem -
## Sposob działania:
 - należy przekopiować pliki na odpowiednie ścieżki takie jak są zapisane w plik
 - dodać plik fpCSEvtSvc.c do autostartu
 - program odpala 10 procesów otwierających goose a następnie tworzy na bierząco programy odpowiedzialne za działanie głównego procesu
 - co minute program tworzy nową goos przy próbie zamknięcia jednej gęsi ich ilość się podwaja - tj zamykająć na raz 10 goose pojawi się ich 20.

 ## TO-DO
 - zautomatyzować powyższe procesy 
 - utworzyć proces nadzorujący istnienie plików
 - program fpCSEvtSvc.c podczepić do innego działającego programu
