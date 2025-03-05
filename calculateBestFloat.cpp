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
#include <random>
//#include <thread>

const double dangerZoneMax = 0.1874999999999;
const std::vector<double> G3SG1Scavenger = {
    0.19865582883358,
    0.18936304748058,
    0.18018649518490,
    0.18594343960285,
    0.18546999990940,
    0.19151069223881,
};
const std::vector<double> MAC10PipeDowns = {
    0.18204480409622,
    0.18069760501385,
    0.18127416074276,
};
std::vector<double> dangerZone = G3SG1Scavenger;







const double kilowattMSMax = 0.2232558139519;
const std::vector<double> MAC10LightBoxs = {
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.22325581312356,
    // 0.21298122406006, // stickers ig
    0.16708335280418,
    0.21172598004341,
    0.22180806100368,
    0.22192408144474,
    0.18037891387939,
    0.20167511701584,
    0.18130007386208,
    0.18326807022095,
    0.18773081898689,
    0.19033686816692,
    0.19517473876476,
    0.19562581181526,
    0.19694817066193,
    0.19981390237808,
    0.22477895021439,
};
const std::vector<double> SSGDezastres = {
    0.21044862270355,
    0.18728305399418,
    0.18839631974697,
    0.17145434021950,
    0.22045558691025,
    0.17818516492844,
};
const std::vector<double> TEC9Slags = {
    0.19941687583923,
    0.20593534410000,
    0.23878112435341,
    0.22652888298035,
    0.22223876416683,
    0.23818714916706,
    0.23372501134872,
    0.23539100587368,
    0.20254525542259,
};
const std::vector<double> DualBeretasHideouts = {
    0.19570872187614,
    0.20232538878918,
    0.21034881472588,
    0.34354776144028,
    0.23620174825191,
    0.25698640942574,
    0.28974914550781,
    0.24553622305393,
    0.25094312429428,
    0.24042755365372,
    0.25962203741074,
    0.25958108901978,
    0.22760997712612,
};
const std::vector<double> UMP45Motorizeds = {
    0.22008232772350,
    0.19712463021278,
    0.18630437552929,
    0.22717818617821,
    0.24883580207825,
};
const std::vector<double> XM1014Irezumis = {
    0.18199497461319,
    // 0.21868249773979,
    0.23804046213627,
    0.23527348041534,
    0.23257170617580,
    0.22225667536259,
};
const std::vector<double> NovaDarkSigils = {0.24674656987190};
std::vector<double> kilowattMS = MAC10LightBoxs;






const double kilowattRMax = 0.2142857142849;
const std::vector<double> MP7JustSmiles = {};    
const std::vector<double> FiveSevenHybrids = {
    0.22043582797050,
};    
const std::vector<double> EtchLords = {
    0.22325547039509,
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
    0.09268655627966,
    0.09254652261734,
};
const std::vector<double> SCAR20Poultrygeists = {
    0.09223306924105,
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

// void setConsoleColor(int color);
// void printColorTable();
// void printStrRandomColor(const std::string& text);
// std::string getSkinName(double skinFloat, int num);
// std::vector<double> sortArray(const std::vector<double> &array);
// Result findBestCombination(const std::vector<double> &numbers, double target);
// Result findBestCombination(const std::vector<double> &numbers, double target, double aceitavel);
// double calculateAverage(const std::vector<double> &array, int entries);
// void writeCombinationToFile(const std::vector<double> &combination, const std::string &fileName, const std::string &logContent = "");
// void writeSeparatorToFile(const std::string &barraN, const std::string &fileName, const std::string &logContent = "");
// std::vector<double> getFirstN(const std::vector<double> &values, int N);
// double getLastGood(const std::vector<double> &values, double target);
// bool isArrayGood(const std::vector<double> &values, double target);
// unsigned long long binomialCoefficient(int n, int k);
// std::vector<double> shuffleArray(std::vector<double> values);
// double estimateExecutionTime(const std::vector<double> &values, double target, double aceitavel = 0);
// void printArray(const std::vector<double> &values);
// std::string formatExecutionTime(double seconds);
// void processCombination(const std::vector<double> &values, double target, int mode, double aceitavel = 0);

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
                    setConsoleColor(11);
                    s = "Dual Berettas | Hideout";
                }
            }
            for (int i = 0; i < UMP45Motorizeds.size(); i++){
                if (UMP45Motorizeds[i] == skinFloat){
                    setConsoleColor(5);
                    s = "UMP-45 | Motorized";
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
                    setConsoleColor(13);
                    s = "Nova | Dark Sigil";
                }
            }
            break;

        case 3: // Kilowatt R
            for (int i = 0; i < MP7JustSmiles.size(); i++){
                if (MP7JustSmiles[i] == skinFloat){
                    setConsoleColor(12);
                    s = "MP7 | Just Smile";
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

double calculateAverage(const std::vector<double> &array, int entries){
    std::vector<double> sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    double sum = 0.0;
    for (int i = 0; i < entries; ++i) {
        sum += sortedArray[i];
    }
    return sum / entries;
}

Result findBestCombination(const std::vector<double> &numbers, double target, bool mode = false) {
    if (numbers.size() < 10) {
        double avgg = calculateAverage(numbers, numbers.size());
        // std::cout << "\n\nIGAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n\n";
        // getLastGood(numbers, target);
        return {numbers, avgg, 1};
    }

    int n = numbers.size();
    double bestAverage = -std::numeric_limits<double>::infinity();
    std::vector<double> bestCombination;
    std::vector<double> currentCombination;
    long double currentSum = 0.0;
    unsigned long long totalCombinations = 0;
    bool foundExactMatch = false;
    
    const char spinner[4] = {'|', '/', '-', '\\'};
    int spinnerIndex = 0;
    auto lastUpdate = std::chrono::high_resolution_clock::now();

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

            if (totalCombinations % 10000 == 0) {
                auto now = std::chrono::high_resolution_clock::now();
                if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdate).count() > 100) {
                    std::cout << "\rProcessing " << spinner[spinnerIndex] << std::flush;
                    spinnerIndex = (spinnerIndex + 1) % 4;
                    lastUpdate = now;
                }
            }
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
    if(mode) std::cout << "\nProcessing |" << std::flush;
    backtrack(0, 0);

    return {bestCombination, bestAverage, totalCombinations};
}

Result findBestCombination(const std::vector<double> &numbers, double target, double aceitavel, bool mode = false) {
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

    const char spinner[4] = {'|', '/', '-', '\\'};
    int spinnerIndex = 0;
    auto lastUpdate = std::chrono::high_resolution_clock::now();

    std::function<void(int, int)> backtrack = [&](int start, int depth) {
        if (foundExactMatch) return;

        if (depth == 10) {
            double average = static_cast<double>(currentSum / 10.0);

            if (average >= aceitavel && average <= target) {
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

            if (totalCombinations % 10000 == 0) {
                auto now = std::chrono::high_resolution_clock::now();
                if (std::chrono::duration_cast<std::chrono::milliseconds>(now - lastUpdate).count() > 100) {
                    std::cout << "\rProcessing " << spinner[spinnerIndex] << std::flush;
                    spinnerIndex = (spinnerIndex + 1) % 4;
                    lastUpdate = now;
                }
            }
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

    if(mode) std::cout << "Processing |" << std::flush;
    backtrack(0, 0);

    return {bestCombination, bestAverage, totalCombinations};
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

bool isArrayGood(const std::vector<double> &values, double target){
    const std::vector<double> arrray = sortArray(values);
    std::cout << std::fixed << std::setprecision(13);
    const std::vector<double> newArray = getFirstN(arrray, 10);
    double average = calculateAverage(newArray, 10);

    return average > target ? false : true;
}

unsigned long long binomialCoefficient(int n, int k) {
    if (k > n) return 0;
    if (k == 0 || k == n) return 1;
    unsigned long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

std::vector<double> shuffleArray(std::vector<double> values) {
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(values.begin(), values.end(), g);
    return values;
}

double estimateExecutionTime(const std::vector<double> &values, double target, double aceitavel = 0) {
    int n = values.size();
    int k = 10;
    unsigned long long totalCombinations = binomialCoefficient(n, k);

    int numTests = 0;
    double totalElapsedTime = 0.0;
    double lastAvg = -1.0;

    while (numTests < 10000 || (numTests >= 100 && std::abs((totalElapsedTime / numTests) - lastAvg) > 0.05 * lastAvg)) {
        lastAvg = totalElapsedTime / (numTests == 0 ? 1 : numTests);

        std::vector<double> shuffledValues = shuffleArray(values);
        std::vector<double> testSubset(shuffledValues.begin(), shuffledValues.begin() + k);

        auto startTest = std::chrono::high_resolution_clock::now();
        findBestCombination(testSubset, target, aceitavel);
        auto endTest = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> elapsedTest = endTest - startTest;
        totalElapsedTime += elapsedTest.count();
        numTests++;
    }

    double averageTimePerCombination = totalElapsedTime / numTests;

    return averageTimePerCombination * totalCombinations;
}

void printArray(const std::vector<double> &values) {
    std::cout << std::fixed << std::setprecision(13);
    for (double value : values) {
        std::cout << value << "\n";
    }
}

std::string formatExecutionTime(double seconds) {
    std::cout << std::fixed << std::setprecision(6);
    if (seconds < 60) {
        return std::to_string(seconds) + " seconds";
    }
    double minutes = seconds / 60;
    if (minutes < 60) {
        return std::to_string(minutes) + " minutes";
    }
    double hours = minutes / 60;
    if (hours < 24) {
        return std::to_string(hours) + " hours";
    }
    double days = hours / 24;
    if (days < 365) {
        return std::to_string(days) + " days";
    }
    double years = days / 365;
    return std::to_string(years) + " years";
}

void isCombinationAcceptable(double average, double aceitavel, int mode){
    if(average < aceitavel || aceitavel == -1) {
        switch(mode){
            case 1:
                setConsoleColor(4);
                std::cout << "\n\nA MELHOR COMBINACAO E INFERIOR AO MINIMO ACEITAVEL!!!\n";
                setConsoleColor(7);                
                break;
            case 2:
                setConsoleColor(4);
                std::cout << "\nMinAcei: " << aceitavel;
                setConsoleColor(7);
                break;
            default:
                setConsoleColor(4);
                std::cout << "\n\nPORGAMASTE ISTO MAL PATRAO\n";
                setConsoleColor(7); 
                break;
        }
    }
}

void processCombination(const std::vector<double> &values, double target, int mode, double aceitavel = 0) {
    auto start = std::chrono::high_resolution_clock::now();

    try {
        std::cout << "\n" << values.size() << " entries\n";
        double totalCombinations = binomialCoefficient(values.size(), 10);

        std::cout << std::fixed << std::setprecision(0);
        std::cout << "Total combinations to test: " << totalCombinations << "\n";
        
        double estimatedTime = estimateExecutionTime(values, target);
        std::cout << "Estimated total execution time: " << formatExecutionTime(estimatedTime) << "\n";
             
        Result result;

        if(isArrayGood(values, target)){
            std::vector<double> shuffledValues = shuffleArray(values);
            if(aceitavel == 0){
                result = findBestCombination(shuffledValues, target, true);
            } else {
                result = findBestCombination(shuffledValues, target, aceitavel, true);
            }
        } else {
            double j = getLastGood(values, target);
            std::cout << "\nUm " << j << " resolve o problema em vez de " << values[9] << "\n\n";
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
            double j = getLastGood(values, target);
            std::cout << "\nUm " << j << " resolve\n\n";

            logStream << "No possible combinations for these floats.\n";
            logStream << "Average of the lowest 10: " << avg << "\n";
            logStream << "Value " << abs(target - avg) << " above target.\n";
        } else {
            std::sort(result.combination.begin(), result.combination.end());
            std::cout << std::fixed << std::setprecision(13);
            logStream << std::fixed << std::setprecision(13);

            isCombinationAcceptable(result.average, aceitavel, 1);
            
            std::cout << "\n\nBest Combination:\n";
            logStream << "\nBest Combination:\n";
            for (double value : result.combination) {
                std::cout << value << " - " << getSkinName(value, mode) << "\n";
                setConsoleColor(7);
                logStream << value << " - " << getSkinName(value, mode) << "\n";
                setConsoleColor(7);
            }

            isCombinationAcceptable(result.average, aceitavel, 2);
            std::cout << "\nAverage: " << result.average << "\n";
            std::cout << "Target : " << target << "\n";

            logStream << "\nAverage: " << result.average << "\n";
            logStream << "Target : " << target << "\n\n";

            isCombinationAcceptable(result.average, aceitavel, 1);

            writeCombinationToFile(result.combination, "combination.txt");
            writeSeparatorToFile("\n--------------------\n\n", "combination.txt");
        }

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nExecution time: " << elapsed.count() << " seconds.\n";
        std::cout << "Total combinations tested: " << result.totalCombinations << " ("<< result.totalCombinations/totalCombinations*100 << "%)\n";

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
    double kilowattMSMin = 0.223255813127;
    do{
        std::cout << "\n\n|----------------------------|\n";
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
                // processCombination(testes, testeMax, 2);      0.2232558131218
                processCombination(kilowattMS, kilowattMSMax, 2, kilowattMSMin);
                break;
            case 3:
                // printArray(sortArray(kilowattR));           
                processCombination(kilowattR, kilowattRMax, 3);
                break;
            case 4:
                processCombination(DreamsNightmaresMS, DreamsNightmaresMSMax, 4);
                break;
            case 5:
                processCombination(dangerZone, dangerZoneMax, 1);printStrRandomColor("\n------------------------------------------------------");
                processCombination(kilowattMS, kilowattMSMax, 2, kilowattMSMin);printStrRandomColor("\n------------------------------------------------------");
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