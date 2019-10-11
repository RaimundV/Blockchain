# Blockchain

## 1. 2 files 1 symbol each

viename faile yra raidė a, o kitame b. Gaunu tokius hash'us:

a = 1314aca1313c2d1313a141316f00131446a1313bd3131361b131344e13133911314f201312d6f1314c731314b8213136481313d001314af41313
7191314f80131333313141ac1314440

b = 13146f213134851314440131422413138641312d45131350a1313fdc13135a61315a801315d211313ed513135cf1313d801313ae01314f641314
16113148001313880131577e13141a0

## 2. 2 files 10000 symbols each

Funkcija paima du failus "10kString_1" ir "10kString_2" ir suhashuoja string'us juose.

## 3. 2 files with 1 different symbol

r0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEWrD7eOAkCxYw1A05TYbLr0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbL
r0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbLr0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbL
r0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbLr0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbL
 = 133f50e13224bc132bb2813438a01324880132f1d0131aa04131a22413243ac133acd81344e48132f43413299ce1320278131dc8013437c81322f
de1344b00131bac6133ad72131b400

r0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbLr0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbL
r0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbLr0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbL
r0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbLr0qEB0CD3SkY2VzIqWhfCeUoCkKltihR0gnb7bdEdrD7eOAkCxYw1A05TYbL
 = 134a4e81322318132d268132f3c81326e78132f1d01319b40131f5d0132344c133b11c131c9181334fa213280061323f50131dd4013437c81322e
c41339a00131c58e1334678133e200

## 4. write your own inputs

Galimybė įrašyti bet kokį tekstą iš kuriuo susidarys hash'as ir parodys kiek laiko užtruko.

## 5. Konstitucija.txt test

Konstitucija.txt failą "line by line" hash'uoja per 127681250 nanoseconds (vidurkis po 4 paleidimų).

## 6. 1000000 random pairs

Mano atveju eina patikrinimai per visus sugenerotus simbolius ir jeigu randa tokį patį hash'ą "break'ina" iš ciklo ir paduoda klaidą. Sutapimu neradau.

## 7. 100000 random pairs with 1 symbol difference

Average: 41.0173
Min: 13.6054
Max: 50.3401