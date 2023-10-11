EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Module:Arduino_Nano_v3.x A?
U 1 1 6526171F
P 1900 2400
F 0 "A?" H 1900 1311 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 1900 1220 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 2050 1450 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 1900 1400 50  0001 C CNN
	1    1900 2400
	1    0    0    -1  
$EndComp
$Comp
L Driver_FET:IR2113S U?
U 1 1 65265C2A
P 4700 1900
F 0 "U?" H 4700 2581 50  0000 C CNN
F 1 "IR2113S" H 4700 2490 50  0000 C CNN
F 2 "Package_SO:SOIC-16W_7.5x10.3mm_P1.27mm" H 4700 1900 50  0001 C CIN
F 3 "https://www.infineon.com/dgdl/ir2110.pdf?fileId=5546d462533600a4015355c80333167e" H 4700 1900 50  0001 C CNN
	1    4700 1900
	1    0    0    -1  
$EndComp
$Comp
L Driver_FET:IR2113S U?
U 1 1 65267901
P 4700 3400
F 0 "U?" H 4700 4081 50  0000 C CNN
F 1 "IR2113S" H 4700 3990 50  0000 C CNN
F 2 "Package_SO:SOIC-16W_7.5x10.3mm_P1.27mm" H 4700 3400 50  0001 C CIN
F 3 "https://www.infineon.com/dgdl/ir2110.pdf?fileId=5546d462533600a4015355c80333167e" H 4700 3400 50  0001 C CNN
	1    4700 3400
	1    0    0    -1  
$EndComp
$Comp
L Diode:1N4148 D?
U 1 1 6526989B
P 6550 1500
F 0 "D?" H 6550 1284 50  0000 C CNN
F 1 "1N4148" H 6550 1375 50  0000 C CNN
F 2 "Diode_THT:D_DO-35_SOD27_P7.62mm_Horizontal" H 6550 1325 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/1N4148_1N4448.pdf" H 6550 1500 50  0001 C CNN
	1    6550 1500
	-1   0    0    1   
$EndComp
$EndSCHEMATC
