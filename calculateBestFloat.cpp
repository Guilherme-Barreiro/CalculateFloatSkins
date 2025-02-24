#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <chrono>
#include <functional>
#include <cmath>
#include <fstream>
#include <windows.h>
#include <cstdlib>

const double dangerZoneMax = 0.1874999999999;
const std::vector<double> G3SG1Scavenger = {
    0.19865582883358,
    0.18936304748058,
    0.18018649518490,
    0.18594343960285,
    0.18546999990940,
};
const std::vector<double> MAC10PipeDowns = {
    0.18204480409622,
    0.18069760501385,
    0.18127416074276,
};
std::vector<double> dangerZone = G3SG1Scavenger;

const double kilowattMSMax = 0.2232558139529;
const std::vector<double> MAC10LightBoxs = {
    // 0.21298122406006,
    0.17930075526237,
    0.16708335280418,
    0.22476065158844,
    0.21172598004341,
    0.22446407377720,
    0.23198553919792,
    0.22533085942268,
    0.23541513085365,
};
const std::vector<double> SSGDezastres = {
    0.21044862270355,
    0.23781546950340,
    0.22341930866241,
    0.16637663543224,
    0.17392650246620,
    0.22583504021168,
    0.23617786169052,
    0.23001581430435,
    0.22797204554081,
    0.21025262773037,
    0.17598824203014,
    0.17598824203014,
    0.22966387867928,
    0.21581986546516,
    0.21024024486542,
    0.18839631974697,
    0.20182131230831,
    0.22859668731689,
};
const std::vector<double> TEC9Slags = {
    0.22702267765999,
    0.23689585924149,
    0.22142088413239,
    0.23652729392052,
    0.23676261305809,
    0.22656439244747,
    0.23346488177776,
    0.23389655351639,
    0.22407078742981,
    0.23153664171696,
};
const std::vector<double> DualBeretasHideouts = {
    0.22760525345802,
    0.23745325207710,
    0.22508232295513,
    0.16301672160625,
    0.22196136415005,
    0.21013486385345,
    0.23987548053265,
    0.21350018680096,
    0.23210437595844,
    0.22228354215622,
    0.23633606731892,
    0.21885551512241,
    0.23826770484447,
};
const std::vector<double> UMP45Motorizeds = {
    0.23600421845913,
    0.22311396896839,
    0.23336404561996,
    0.22008232772350,
    0.23591566085815,
    0.23856626451015,
    0.22402523458004,
};
const std::vector<double> XM1014Irezumis = {
    0.23205494880676,
    0.23301656544209,
    0.22702011466026,
    0.22124402225018,
    0.23217976093292,
    0.23565153777599,
};
const std::vector<double> NovaDarkSigils = {
    0.22464281320572,
};

std::vector<double> kilowattMS = MAC10LightBoxs;

const double kilowattRMax = 0.2142857142849;
const std::vector<double> MP7JustSmiles = {
    0.22325582802296,
    0.22325579822063,
    0.22325582802296,
    0.18122749030590,
};    
const std::vector<double> FiveSevenHybrids = {
    0.22325582802296,
    0.22325582802296,
};    
const std::vector<double> EtchLords = {
    0.21562741696835,
    0.22325579822063,
    0.22325579822063,
    0.22325582802296,
    0.22325582802296,
};
std::vector<double> kilowattR = MP7JustSmiles;

const double DreamsNightmaresMSMax = 0.0921052631569;
const std::vector<double> SawedOffSpiritBoards = {
    0.09390566498041,
    0.09515551477671,
    0.09577052295208,
    0.09591663628817,
    0.09608733654022,
    0.09639929234982,
    0.09710415452719,
    0.09715437144041,
    0.09779497981071,
    0.09803152084351,
    0.10005585849285,
    0.10082382708788,
    0.10149347782135,
    0.10329607129097,
    0.10330630838871,
    0.10424643009901,
    0.10468701273203,
    0.10629476606846,
    0.10664975643158,
    0.10830996185541,
    0.11019420623779,
    0.11021392792463,
    0.11072692275047,
    0.11124511808157,
    0.11142890155315,
    0.11505038291216,
    0.11639872193336,
    0.11695097386837,
    0.11695714294910,
    0.11757521331310,
    0.14554034173489,
    0.14659325778484,
    0.09349250048399,
    0.09373930096626,
};
const std::vector<double> MP5SDNecroJrs = {
    0.09171529114246,
    0.09229476004839,
};
const std::vector<double> MAC10Ensnareds = {
    0.09040935337543,
    0.09102553129196,
};    
const std::vector<double> FiveSeveNScrawls = {
    0.09268655627966   
};
const std::vector<double> SCAR20Poultrygeists = {
    0.09223306924105  
};
const std::vector<double> MAG7Foresights = {
    0.09278006851673,
};
std::vector<double> DreamsNightmaresMS = SawedOffSpiritBoards;

const double MAG7MonsterCallMax = 0.1999999999999;
const std::vector<double> MAG7MonsterCalls = {
    0.19039992988110,
    0.21039286255836,
    0.21223406493664,
    0.18544407188892,
    0.20020510256290,
    0.20667530596256,
};



void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

void printColorTable() {
    std::cout << "Available Colors:\n";
    setConsoleColor(0);  std::cout << "0: Black\n";
    setConsoleColor(1);  std::cout << "1: Blue\n";
    setConsoleColor(2);  std::cout << "2: Green\n";
    setConsoleColor(3);  std::cout << "3: Aqua (Cyan)\n";
    setConsoleColor(4);  std::cout << "4: Red\n";
    setConsoleColor(5);  std::cout << "5: Purple\n";
    setConsoleColor(6);  std::cout << "6: Yellow (Dark)\n";
    setConsoleColor(7);  std::cout << "7: White (Default)\n";
    setConsoleColor(8);  std::cout << "8: Gray\n";
    setConsoleColor(9);  std::cout << "9: Light Blue\n";
    setConsoleColor(10); std::cout << "10: Light Green\n";
    setConsoleColor(11); std::cout << "11: Light Aqua (Cyan)\n";
    setConsoleColor(12); std::cout << "12: Light Red\n";
    setConsoleColor(13); std::cout << "13: Light Purple\n";
    setConsoleColor(14); std::cout << "14: Light Yellow\n";
    setConsoleColor(15); std::cout << "15: Bright White\n";

    setConsoleColor(7);
    std::cout << std::endl;
}

void printStrRandomColor(const std::string& text) {
    srand(static_cast<unsigned>(time(0)));
    int randomColor = -1;
    for (size_t i = 0; i < text.length(); i++) {
        char c = text[i];
        if(i % 4 == 1) randomColor = 1 + rand() % 15;
        setConsoleColor(randomColor);
        std::cout << c;
    }
    
    setConsoleColor(7);
    std::cout << std::endl;
}

std::string getSkinName(double skinFloat, int num) {
    std::string s = "Skin not found!";    
    switch (num) {
        case 1: // Danger Zone MS
            for (int i = 0; i < G3SG1Scavenger.size(); i++){
                if (G3SG1Scavenger[i] == skinFloat){
                    setConsoleColor(12);
                    s = "G3SG1 | Scavenger";
                }
            }
            for (int i = 0; i < MAC10PipeDowns.size(); i++){
                if (MAC10PipeDowns[i] == skinFloat){
                    setConsoleColor(1);
                    s = "MAC-10 | Pipe Down";
                }
            }
            break;

        case 2: // Kilowatt MS
            for (int i = 0; i < MAC10LightBoxs.size(); i++){
                if (MAC10LightBoxs[i] == skinFloat){
                    setConsoleColor(12);
                    s = "MAC-10 | Light Box";
                }
            }
            for (int i = 0; i < SSGDezastres.size(); i++){
                if (SSGDezastres[i] == skinFloat){
                    setConsoleColor(1);
                    s = "SSG 08 | Dezastre";
                }
            }
            for (int i = 0; i < TEC9Slags.size(); i++){
                if (TEC9Slags[i] == skinFloat){
                    setConsoleColor(6);
                    s = "Tec-9 | Slag";
                }
            }
            for (int i = 0; i < DualBeretasHideouts.size(); i++){
                if (DualBeretasHideouts[i] == skinFloat){
                    setConsoleColor(13);
                    s = "Dual Berettas | Hideout";
                }
            }
            for (int i = 0; i < UMP45Motorizeds.size(); i++){
                if (UMP45Motorizeds[i] == skinFloat){
                    setConsoleColor(5);
                    s = "UMP-45 | Motor Pool";
                }
            }
            for (int i = 0; i < XM1014Irezumis.size(); i++){
                if (XM1014Irezumis[i] == skinFloat){
                    setConsoleColor(2);
                    s = "XM1014 | Irezumi";
                }
            }
            for (int i = 0; i < NovaDarkSigils.size(); i++){
                if (NovaDarkSigils[i] == skinFloat){
                    setConsoleColor(11);
                    s = "Nova | Dark Sigil";
                }
            }
            break;

        case 3: // Kilowatt R
            for (int i = 0; i < MP7JustSmiles.size(); i++){
                if (MP7JustSmiles[i] == skinFloat){
                    setConsoleColor(12);
                    s = "MP7 | Just My Style";
                }
            }
            for (int i = 0; i < FiveSevenHybrids.size(); i++){
                if (FiveSevenHybrids[i] == skinFloat){
                    setConsoleColor(1);
                    s = "Five-SeveN | Hybrid";
                }
            }
            for (int i = 0; i < EtchLords.size(); i++){
                if (EtchLords[i] == skinFloat){
                    setConsoleColor(6);
                    s = "M4A4 | Etch Lord";
                }
            }
            break;

        case 4: // Dreams & Nightmares MS
            for (int i = 0; i < SawedOffSpiritBoards.size(); i++){
                if (SawedOffSpiritBoards[i] == skinFloat){
                    setConsoleColor(12);
                    s = "Sawed-Off | Spirit Board";
                }
            }        
            for (int i = 0; i < MP5SDNecroJrs.size(); i++){
                if (MP5SDNecroJrs[i] == skinFloat){
                    setConsoleColor(1);
                    s = "MP5-SD | Necro Jnr";
                }
            }        
            for (int i = 0; i < MAC10Ensnareds.size(); i++){
                if (MAC10Ensnareds[i] == skinFloat){
                    setConsoleColor(6);
                    s = "MAC-10 | Ensnared";
                }
            }        
            for (int i = 0; i < FiveSeveNScrawls.size(); i++){
                if (FiveSeveNScrawls[i] == skinFloat){
                    setConsoleColor(13);
                    s = "Five-SeveN | Scrawl";
                }
            }      
            for (int i = 0; i < SCAR20Poultrygeists.size(); i++){
                if (SCAR20Poultrygeists[i] == skinFloat){
                    setConsoleColor(5);
                    s = "SCAR-20 | Poultrygeist";
                }
            }            
            for (int i = 0; i < MAG7Foresights.size(); i++){
                if (MAG7Foresights[i] == skinFloat){
                    setConsoleColor(2);
                    s = "SCAR-20 | Poultrygeist";
                }
            }
            break;

        default:
            break;
    }
    return s;
    
}

struct Result {
    std::vector<double> combination;
    double average;
    unsigned long long totalCombinations;
};

std::vector<double> sortArray(const std::vector<double> &array) {
    std::vector<double> sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    std::cout << std::fixed << std::setprecision(13);

    // for (double num : sortedArray) {
    //     std::cout << num << "\n";
    // }

    return sortedArray;
}

Result findBestCombination(const std::vector<double> &numbers, double target) {
    if (numbers.size() < 10) {
        throw std::invalid_argument("The array must contain at least 10 numbers.");
    }

    int n = numbers.size();
    double bestAverage = -std::numeric_limits<double>::infinity();
    std::vector<double> bestCombination;
    std::vector<double> currentCombination;
    long double currentSum = 0.0;
    unsigned long long totalCombinations = 0;
    bool foundExactMatch = false;

    std::function<void(int, int)> backtrack = [&](int start, int depth) {
        if (foundExactMatch) return;

        if (depth == 10) {
            double average = static_cast<double>(currentSum / 10.0);

            double truncatedAverage = std::floor(average * 1e12) / 1e12;
            double truncatedTarget = std::floor(target * 1e12) / 1e12;

            if (truncatedAverage == truncatedTarget) {
                bestCombination = currentCombination;
                bestAverage = average;
                foundExactMatch = true;
                return;
            }

            if (average < target && average > bestAverage) {
                bestCombination = currentCombination;
                bestAverage = average;
            }

            totalCombinations++;
            return;
        }

        for (int i = start; i < n; ++i) {
            currentCombination.push_back(numbers[i]);
            currentSum += numbers[i];

            backtrack(i + 1, depth + 1);

            currentSum -= currentCombination.back();
            currentCombination.pop_back();
        }
    };

    backtrack(0, 0);

    return {bestCombination, bestAverage, totalCombinations};
}

double calculateAverage(const std::vector<double> &array, int entries){
    std::vector<double> sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    double sum = 0.0;
    for (int i = 0; i < entries; ++i) {
        sum += sortedArray[i];
    }
    return sum / entries;
}

void writeCombinationToFile(const std::vector<double> &combination, const std::string &fileName, const std::string &logContent = ""){
    std::ofstream outFile(fileName, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file " << fileName << " for writing." << std::endl;
        return;
    }

    if (!logContent.empty()) {
        outFile << logContent << "\n";
    }

    if (!combination.empty()) {
        outFile << std::fixed << std::setprecision(13);
        for (double num : combination) {
            outFile << num << "\n";
        }
    }

    outFile.close();
}

void writeSeparatorToFile(const std::string &barraN, const std::string &fileName, const std::string &logContent = ""){
    std::ofstream outFile(fileName, std::ios::app);

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file " << fileName << " for writing." << std::endl;
        return;
    }

    if (!logContent.empty()) {
        outFile << logContent << "\n";
    }

    outFile << barraN;
    outFile.close();
}

std::vector<double> getFirstN(const std::vector<double> &values, int N){
    std::vector<double> newArray = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i = 0; i < 10; i++)
        newArray[i] = values[i];

    return newArray;
}

double getLastGood(const std::vector<double> &values, double target){
    std::vector<double> newArray = getFirstN(values, 9);
    double j = target * 10 - (newArray[0] + newArray[1] + newArray[2] + newArray[3] + newArray[4] + newArray[5] + newArray[6] + newArray[7] + newArray[8]);
    return j;
}

boolean isArrayGood(const std::vector<double> &values, double target){
    const std::vector<double> arrray = sortArray(values);
    std::cout << std::fixed << std::setprecision(13);
    const std::vector<double> newArray = getFirstN(arrray, 10);
    double average = calculateAverage(newArray, 10);

    return average > target ? false : true;
}

void processCombination(const std::vector<double> &values, double target, int mode) {
    auto start = std::chrono::high_resolution_clock::now();

    try {
        std::cout << "\n" << values.size() << " entries\n";
        Result result;

        if(isArrayGood(values, target)){
            Result result = findBestCombination(values, target);
        } else {
            double j = getLastGood(values, target);
            std::cout << "\nUm " << j << " resolve o problema em vez de " << values[8] << "\n\n";
        }

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::ostringstream logStream;
        if (result.combination.empty()) {
            double avg = calculateAverage(values, 10);
            std::cout << std::fixed << std::setprecision(13);
            logStream << std::fixed << std::setprecision(13);
            std::cout << "No possible combinations for these floats.\n";
            std::cout << "Average of the lowest 10: " << avg << "\n";
            std::cout << "Value " << abs(target - avg) << " above target.\n";

            logStream << "No possible combinations for these floats.\n";
            logStream << "Average of the lowest 10: " << avg << "\n";
            logStream << "Value " << abs(target - avg) << " above target.\n";
        } else {
            std::sort(result.combination.begin(), result.combination.end());
            std::cout << std::fixed << std::setprecision(13);
            logStream << std::fixed << std::setprecision(13);

            logStream << "Best Combination:\n";

            std::cout << "Best Combination:\n";
            for (double value : result.combination) {
                std::cout << value << " - " << getSkinName(value, mode) << "\n";
                setConsoleColor(7);
                logStream << value << " - " << getSkinName(value, mode) << "\n";
                setConsoleColor(7);
            }
            std::cout << "\nAverage: " << result.average << "\n";
            std::cout << "Target : " << target << "\n\n";

            logStream << "\nAverage: " << result.average << "\n";
            logStream << "Target : " << target << "\n\n";

            writeCombinationToFile(result.combination, "combination.txt");
            writeSeparatorToFile("\n--------------------\n\n", "combination.txt");
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Execution time: " << elapsed.count() << " seconds.\n";
        std::cout << "Total combinations tested: " << result.totalCombinations << "\n";

        logStream << std::fixed << std::setprecision(2);
        logStream << "\nExecution time: " << elapsed.count() << " seconds.\n";
        logStream << "Total combinations tested: " << result.totalCombinations;

        writeCombinationToFile({}, "combination_log.txt", logStream.str());
        writeSeparatorToFile("\n---------------------------------------\n\n", "combination_log.txt");

        std::cout << "Combination e log guardados.\n";
    } catch (const std::exception &e) {
        std::cerr << "Erro: " << e.what() << "\n";
        writeCombinationToFile({}, "combination_log.txt", std::string("Erro: ") + e.what());
    }
}

void printArray(const std::vector<double> &values) {
    std::cout << std::fixed << std::setprecision(13);
    for (double value : values) {
        std::cout << value << "\n";
    }
}


int main(){

    dangerZone.insert(dangerZone.end(), MAC10PipeDowns.begin(), MAC10PipeDowns.end());

    kilowattMS.insert(kilowattMS.end(), SSGDezastres.begin(), SSGDezastres.end());
    kilowattMS.insert(kilowattMS.end(), TEC9Slags.begin(), TEC9Slags.end());
    kilowattMS.insert(kilowattMS.end(), DualBeretasHideouts.begin(), DualBeretasHideouts.end());
    kilowattMS.insert(kilowattMS.end(), UMP45Motorizeds.begin(), UMP45Motorizeds.end());
    kilowattMS.insert(kilowattMS.end(), XM1014Irezumis.begin(), XM1014Irezumis.end());
    kilowattMS.insert(kilowattMS.end(), NovaDarkSigils.begin(), NovaDarkSigils.end());

    kilowattR.insert(kilowattR.end(), FiveSevenHybrids.begin(), FiveSevenHybrids.end());
    kilowattR.insert(kilowattR.end(), EtchLords.begin(), EtchLords.end());

    DreamsNightmaresMS.insert(DreamsNightmaresMS.end(), MP5SDNecroJrs.begin(), MP5SDNecroJrs.end());
    DreamsNightmaresMS.insert(DreamsNightmaresMS.end(), MAC10Ensnareds.begin(), MAC10Ensnareds.end());
    DreamsNightmaresMS.insert(DreamsNightmaresMS.end(), FiveSeveNScrawls.begin(), FiveSeveNScrawls.end());
    DreamsNightmaresMS.insert(DreamsNightmaresMS.end(), SCAR20Poultrygeists.begin(), SCAR20Poultrygeists.end());
    DreamsNightmaresMS.insert(DreamsNightmaresMS.end(), MAG7Foresights.begin(), MAG7Foresights.end());
    
    int op = -1;
    do{
        std::cout << "\n\n\n\n|----------------------------|\n";
        std::cout << "| Escolha uma opcao:         |\n";
        std::cout << "| 1 - Danger Zone MS         |\n";
        std::cout << "| 2 - Kilowatt MS            |\n";
        std::cout << "| 3 - Kilowatt R             |\n";
        std::cout << "| 4 - Dreams & Nightmares MS |\n";
        std::cout << "| 5 - Todas as anteriores    |\n";
        std::cout << "| 0 - Sair                   |\n";
        std::cout << "|----------------------------|\n";
        scanf("%d", &op);
        setConsoleColor(10); std::cout << "\n---------------------------------------------------------------------"; setConsoleColor(7);
        switch(op){
            case 1:
                processCombination(dangerZone, dangerZoneMax, 1);
                break;
            case 2:
                // processCombination(testes, testeMax, 2);
                processCombination(kilowattMS, kilowattMSMax, 2);
                break;
            case 3:
                processCombination(kilowattR, kilowattRMax, 3);
                break;
            case 4:
                processCombination(DreamsNightmaresMS, DreamsNightmaresMSMax, 4);
                break;
            case 5:
                processCombination(dangerZone, dangerZoneMax, 1);printStrRandomColor("\n------------------------------------------------------");
                processCombination(kilowattMS, kilowattMSMax, 2);printStrRandomColor("\n------------------------------------------------------");
                processCombination(kilowattR, kilowattRMax, 3);printStrRandomColor("\n------------------------------------------------------");
                processCombination(DreamsNightmaresMS, DreamsNightmaresMSMax, 4);
                break;
            case 0:
                break;
            default:
                std::cout << "Opcao invalida!\n";
                break;
        }
        printStrRandomColor("------------------------------------------------------");
    }while(op != 0);

    std::cout << "\nfimmmm!";
    return 0;
}
/*
case 1: Danger Zone MS
            
case 2: Kilowatt MS
            
case 3: Kilowatt R
            
case 4: Dreams & Nightmares MS
*/

/*   COMANDOS CMD
cd C:\xampp\htdocs\cs\CalculateBestFloat\CalculateFloatSkins
cd C:\xampp\htdocs\cs\CalculateFloatSkins
g++ -std=c++17 -o calculateBestFloat calculateBestFloat.cpp
calculateBestFloat.exe
*/

/*   SORT ARRAY AND PRINT IT
    const std::vector<double> arrray = sortArray(MAC10LightBoxs);
    std::cout << std::fixed << std::setprecision(13);

    for (double num : arrray) {
        std::cout << num << "\n";
    }
*/


/*

 - assumindo que cada letra é um numero e estao ordenados por ordem crescente
quero que media seje inferior a 0.2 (exemplo)
(a + b + c + d + e + f + g + h + i + j) / 10 = media

se a media for > 0.2 (digamos que seja 0.21)
qual seria o valor que tenho de substituir j para que a media seje 0.2

*/

/*
    const double testeMax = 5;
    const std::vector<double> testes = {
        1,
        2,
        3,
        4,
        5,
        6,
        7,
        8,
        9,
        10,
    };
*/