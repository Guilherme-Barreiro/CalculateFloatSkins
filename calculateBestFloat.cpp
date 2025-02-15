#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <limits>
#include <chrono>
#include <functional>
#include <cmath>
#include <fstream>

struct Result {
    std::vector<double> combination;
    double average;
    unsigned long long totalCombinations; // Adicionado para armazenar o total de combinações testadas
};

std::vector<double> sortArray(const std::vector<double>& array) {
    std::vector<double> sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
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
    long double currentSum = 0.0; // Para maior precisão
    unsigned long long totalCombinations = 0; // Contador para o total de combinações testadas
    bool foundExactMatch = false; // Flag to stop recursion if the exact match is found

    // Função de backtracking
    std::function<void(int, int)> backtrack = [&](int start, int depth) {
        if (foundExactMatch) return; // Stop recursion if the exact match is already found

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

    return {bestCombination, bestAverage, totalCombinations}; // Retorna também o total de combinações
}

double calculateAverage(const std::vector<double> &array, int entries) {
    std::vector<double> sortedArray = array;
    std::sort(sortedArray.begin(), sortedArray.end());
    double sum = 0.0;
    for (int i = 0; i < entries; ++i) {
        sum += sortedArray[i];
    }
    return sum / entries;
}

void writeCombinationToFile(const std::vector<double>& combination, const std::string& fileName, const std::string& logContent = "") {
    std::ofstream outFile(fileName, std::ios::app); // Open in append mode

    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open the file " << fileName << " for writing." << std::endl;
        return;
    }

    if (!logContent.empty()) {
        outFile << logContent << "\n"; // Write the log content if provided
    }

    if (!combination.empty()) {
        outFile << std::fixed << std::setprecision(13); // Set precision for 13 decimals
        for (double num : combination) {
            outFile << num << "\n";
        }
    }

    outFile.close();
}

void writeSeparatorToFile(const std::string& barraN, const std::string& fileName, const std::string& logContent = "") {
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

void processCombination(const std::vector<double> &values, double target) {
    auto start = std::chrono::high_resolution_clock::now();

    try {
        // Find the best combination
        Result result = findBestCombination(values, target);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;

        std::ostringstream logStream;
        if (result.combination.empty()) {
            double avg = calculateAverage(values, 10);

            // Console Output
            std::cout << "No possible combinations for these floats.\n";
            std::cout << "Average of the lowest 10: " << avg << "\n";
            std::cout << "Value " << (target - avg) << " above target.\n";

            // Log Content
            logStream << "No possible combinations for these floats.\n";
            logStream << "Average of the lowest 10: " << avg << "\n";
            logStream << "Value " << (target - avg) << " above target.\n";
        } else {
            // Sort the combination for output consistency
            std::sort(result.combination.begin(), result.combination.end());
            std::cout << std::fixed << std::setprecision(13);
            logStream << std::fixed << std::setprecision(13);

            // Add the header first
            logStream << "Best Combination:\n";

            // Console Output and Log Content
            std::cout << "Best Combination:\n";
            for (double value : result.combination) {
                std::cout << value << "\n";
                logStream << value << "\n";
            }
            std::cout << "Average: " << result.average << "\n";
            std::cout << "Target : " << target << "\n";

            logStream << "\nAverage: " << result.average << "\n";
            logStream << "Target : " << target << "\n";

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

    const std::vector<double> G3SG1Scavenger = {
        0.19865582883358,
        0.18936304748058,
        0.18018649518490,
        0.18594343960285,
    };
    const std::vector<double> MAC10PipeDowns = {
        0.18204480409622,
    };
    const double dangerZoneMax = 0.1874999999999;;
    std::vector<double> dangerZone = G3SG1Scavenger;
    dangerZone.insert(dangerZone.end(), MAC10PipeDowns.begin(), MAC10PipeDowns.end());


    const double kilowattMSMax = 0.2232558139529;
    const std::vector<double> MAC10LightBoxs = {
        0.20178636908531,
        0.20817500352859,
        0.16570964455605,
        0.16032433509827,
        0.21347983181477,
        0.23522691428661,
        0.17515532672405,
        0.17087467014790,
        0.22778210043907,
        0.27762398123741,
        0.17429776489735,
        0.23533487319946,
        0.29931730031967,
        0.23929674923420,
        0.23022133111954,
        0.21298122406006,
        0.21347321569920,
        0.16039046645164,
        0.26372575759888,
        0.17791439592838,
        0.22541609406471,
        0.19915968179703,
        0.18887348473072,
        0.19163368642330,
        0.20180258154869,
        0.21347795426846,
        0.24343460798264,
        0.22197084128857,
        0.21840749680996,
        0.22470217943192,
        0.20070546865463,
        0.16516806185246,
        0.27231746912003,
        0.21748292446136,
        0.22033570706844,
        0.16841973364353,
        0.18575841188431,
        0.20168852806091,
        0.18212370574474,
        0.21543163061142,
        0.21646547317505,
        0.21081492304802,
        0.17930075526237,
        0.16708335280418,
        0.23494851589203,
    };
    const std::vector<double> SSGDezastres = {
        0.22584071755409,
        0.23766255378723,
        0.23517481982708,
        0.23154202103615,
    };
    const std::vector<double> TEC9Slags = {
        0.23586140573025,
        0.22419106960297,
        0.23238793015480,
        0.23075944185257,
    };
    const std::vector<double> DualBeretasHideouts = {
        0.23895758390427,
    };
    const std::vector<double> UMP45Motorized = {
        0.23030893504620,
    };
    const std::vector<double> XM1014Irezumis = {
        0.22794359922409,
    };
    std::vector<double> kilowattMS = MAC10LightBoxs;
    kilowattMS.insert(kilowattMS.end(), SSGDezastres.begin(), SSGDezastres.end());
    kilowattMS.insert(kilowattMS.end(), TEC9Slags.begin(), TEC9Slags.end());
    kilowattMS.insert(kilowattMS.end(), DualBeretasHideouts.begin(), DualBeretasHideouts.end()); 
    kilowattMS.insert(kilowattMS.end(), XM1014Irezumis.begin(), XM1014Irezumis.end()); 

    const double kilowattRMax = 0.2142857142849;
    const std::vector<double> MP7JustSmiles = {
        0.0,
    };    
    const std::vector<double> FiveSevenHybrids = {
        0.0,
    };    
    const std::vector<double> EtchLords = {
        0.0,
    };
    std::vector<double> kilowattR = MP7JustSmiles;
    kilowattR.insert(kilowattR.end(), FiveSevenHybrids.begin(), FiveSevenHybrids.end());
    kilowattR.insert(kilowattR.end(), EtchLords.begin(), EtchLords.end());

    const double MAG7MonsterCallMax = 0.1999999999999;
    const std::vector<double> MAG7MonsterCalls = {
        0.19039992988110,
        0.21039286255836,
        0.21223406493664,
        0.18544407188892,
        0.20020510256290,
    };


    const double SawedOffSpiritBoardMax = 0.0921052631569;
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
    

    // printArray(kilowattMS);

    processCombination(kilowattMS, kilowattMSMax);
    std::cout << "\n\n\n";    
    // std::cout << "\n\n\n";    
    // processCombination(MAC10LightBoxs, 0.2000000000009);
    // std::cout << "\n\n\n";    
    // processCombination(MAC10LightBoxs, 0.2121212121219);
    std::cout << "\nfimmmm!";
    return 0;
}

/*   COMANDOS CMD
cd C:\xampp\htdocs\cs
g++ -std=c++17 -o calculateBestFloat calculateBestFloat.cpp
calculateBestFloat.exe

cd C:\Users\Utilizador\Desktop\CalcularFloat
*/


/*   SORT ARRAY AND PRINT IT
    const std::vector<double> arrray = sortArray(MAC10LightBoxs);
    std::cout << std::fixed << std::setprecision(13);

    for (double num : arrray) {
        std::cout << num << "\n";
    }
*/
