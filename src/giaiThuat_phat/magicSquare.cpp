/*https://scontent.fdad3-1.fna.fbcdn.net/v/t1.15752-9/229394265_149513760649236_7340660106556981235_n.png?_nc_cat=106&ccb=1-4&_nc_sid=ae9488&_nc_ohc=orUiXwfn8BUAX-62Wb6&tn=c-Lvvcr9_LyGospK&_nc_ht=scontent.fdad3-1.fna&oh=8270df787526359f6f40fa950b888b2c&oe=613641AA
https://scontent.fdad3-1.fna.fbcdn.net/v/t1.15752-9/224012700_388708382610905_772489386370048767_n.png?_nc_cat=110&ccb=1-4&_nc_sid=ae9488&_nc_ohc=FSN6gQtsIdIAX-iMp6P&_nc_ht=scontent.fdad3-1.fna&oh=d4ec6fa000f6376b3bac67ac99a305c5&oe=61345C57*/
#include<bits/stdc++.h>
#define faster() ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main(){
    faster()
    const valarray<int> magicSquares[] = {
        { 8, 1, 6, 3, 5, 7, 4, 9, 2 },
        { 6, 1, 8, 7, 5, 3, 2, 9, 4 },
        { 8, 3, 4, 1, 5, 9, 6, 7, 2 },
        { 4, 3, 8, 9, 5, 1, 2, 7, 6 },
        { 6, 7, 2, 1, 5, 9, 8, 3, 4 },
        { 2, 7, 6, 9, 5, 1, 4, 3, 8 },
        { 4, 9, 2, 3, 5, 7, 8, 1, 6 },
        { 2, 9, 4, 7, 5, 3, 6, 1, 8 }};
    valarray<int> a(9);
    for (auto & i : a) cin >> i;
    int temp;
    for (auto && magicSquare : magicSquares)
        temp = min(temp, abs(magicSquare - a).sum());
    cout << temp <<endl;
    return 0;
}