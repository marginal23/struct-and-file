/*******************************
* Автор:   Сатин Владимир      *
* Задание: Работа с файлами    *
* Вариант: 10                  *
*******************************/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
  constexpr int maxCarCount = 100;
  string brandList[maxCarCount];
  int yearList[maxCarCount];
  string surnameList[maxCarCount];
  string numberList[maxCarCount];
  ifstream infoCars;
  string fileName;
  string targetBrand;
  int currentYear;
  int carCount = 0;
  int matchedCarCount = 0;
  int oldestIndex = 0;
  double ageSum = 0.0;
  double averageAge = 0.0;

  cout << "Enter file name (for example cars.txt): ";
  cin >> fileName;
  cout << "Enter car brand: ";
  cin >> targetBrand;
  cout << "Enter current year: ";
  cin >> currentYear;

  infoCars.open(fileName);
  if (!infoCars.is_open()) {
    cout << "Error: file " << fileName << " not found";
    return 1;
  }

  while (carCount < maxCarCount
         && infoCars >> brandList[carCount] >> yearList[carCount]
                     >> surnameList[carCount] >> numberList[carCount]) {
    ++carCount;
  }
  infoCars.close();

  if (carCount == 0) {
    cout << "Error: file " << fileName << " is empty";
    return 1;
  }

  for (int carIndex = 0; carIndex < carCount; ++carIndex) {
    if (brandList[carIndex] == targetBrand) {
      ageSum += currentYear - yearList[carIndex];
      ++matchedCarCount;
    }
    if (yearList[carIndex] < yearList[oldestIndex]) {
      oldestIndex = carIndex;
    }
  }

  if (matchedCarCount > 0) {
    averageAge = ageSum / matchedCarCount;
  }

  if (matchedCarCount == 0) {
    cout << "No cars of brand " << targetBrand << " found" << endl;
  } else {
    cout << "Cars of brand " << targetBrand << ":" << endl;
    for (int carIndex = 0; carIndex < carCount; ++carIndex) {
      if (brandList[carIndex] == targetBrand) {
        cout << brandList[carIndex] << " " << yearList[carIndex] << " "
             << surnameList[carIndex] << " " << numberList[carIndex] << endl;
      }
    }
    cout << "Average age: " << averageAge << endl;
  }

  cout << "Oldest car: " << brandList[oldestIndex] << " "
       << yearList[oldestIndex] << " " << surnameList[oldestIndex] << " "
       << numberList[oldestIndex];

  return 0;
}
