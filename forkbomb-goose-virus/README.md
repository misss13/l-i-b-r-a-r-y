# Forkbomb - goose - virus
 tylko pod windowsem 
## Sposob działania:
 - należy przekopiować skompilowany pliki na odpowiednie ścieżki takie jak są zapisane w pliku
 - dodać plik fpCSEvtSvc.exe do autostartu
 - program odpala 10 procesów otwierających goose a następnie tworzy na bierząco programy odpowiedzialne za działanie głównego procesu
 - co minute program tworzy nową goose przy próbie zamknięcia jednej gęsi ich ilość się podwaja - tj zamykająć na raz 10 goose pojawi się ich 20.

 ## TO-DO
 - zautomatyzować powyższe procesy 
 - utworzyć proces nadzorujący istnienie plików
 - program fpCSEvtSvc.exe podczepić do innego działającego programu
