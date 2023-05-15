set DYMOSIMGUI=1
if exist dsin.txt goto startProgram
msg meagh "Input file dsin.txt is missing, default with 0 simulation length generated."
dymosim.exe -i
:startProgram
dymosim.exe
