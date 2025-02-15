<?php

set_time_limit(500);

function findBestCombination($numbers, $target) {
    if (count($numbers) < 10) {
        throw new Exception("O array deve conter pelo menos 10 números.");
    }

    $n = count($numbers);
    $bestCombination = null;
    $bestAverage = -INF;

    $combination = [];
    $currentSum = 0;

    $backtrack = function($start, $depth) use (&$numbers, &$bestCombination, &$bestAverage, &$combination, &$currentSum, $target, $n, &$backtrack) {
        if ($depth == 10) {
            $average = $currentSum / 10;
            // if(round($average, 10) == 0.2000000000) echo "0.2000000000";
            // if(round($average, 10) == 0.2121212121) echo "0.2121212121";
            // if(round($average, 10) == 0.2222222222) echo "0.2222222222";
            if ($average < $target && $average > $bestAverage) {
                $bestCombination = $combination;
                $bestAverage = $average;
            }
            return;
        }

        for ($i = $start; $i < $n; $i++) {
            $combination[] = $numbers[$i];
            $currentSum += $numbers[$i];

            $backtrack($i + 1, $depth + 1);

            $currentSum -= array_pop($combination);
        }
    };

    $backtrack(0, 0);
    
    return [
        'combination' => $bestCombination,
        'average' => $bestAverage
    ];
}

function CalcAvg($array, $entries){
    sort($array);
    for($i = 0, $avg = 0; $i < $entries; $i++) $avg += $array[$i];
    return $avg / $entries;
}

$G3SG1Scavenger = 0.18749999999;
$G3SG1Scavenger = [
    0.19865582883358,
];

$MAG7MonsterCallMax = 0.199999999999;
$MAG7MonsterCalls = [
    0.19039992988110,
    0.21039286255836,
    0.21223406493664,
];

$MP7JustSmileMax = 0.214285714284;
$MP7JustSmiles = [
    0.21948476135731,
    0.21711011230946,
    0.22325579822063,
];

$SawedOffSpiritBoardMax = 0.092105263156;
$SawedOffSpiritBoards = [
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
];

$MAC10LightBoxMax = 0.2222222222222;
$MAC10LightBoxMax = 0.223255813952;
$MAC10LightBoxs = [
    0.11830624938011,
    0.17638036608696,
    0.16825272142887,
    0.21138545870781,
    0.16708335280418,
    0.18908819556236,
    0.19509527087212,
    0.16613449156284,
    0.18874476850033,
    0.17930075526237,
    0.20214964449406,
    0.21601539850235,
    0.21081492304802,
    0.21618142724037,
    0.16462661325932,
    0.19966270029545,
    0.21646547317505,
    0.22862643003464,
    0.22718563675880,
    0.21543163061142,
    0.20731912553310,
    0.22959379851818,
    0.18212370574474,
    0.18519701063633,
    0.20168852806091,
    0.18575841188431,
    0.19023495912552,
    0.22614651918411,
    0.18110595643520,
    0.18464408814907,
    0.21750548481941,
    0.16841973364353,
    0.18795239925385,
    0.20126208662987,
    0.34500795602798,
    0.32848018407822,
    0.37935221195221,
    0.21583628654480,
];

function printFilteredCombinations($numbers) {
    if (count($numbers) < 10) {
        throw new Exception("O array deve conter pelo menos 10 números.");
    }

    $n = count($numbers);
    $combination = [];
    $currentSum = 0;

    $backtrack = function($start, $depth) use (&$numbers, &$combination, &$currentSum, $n, &$backtrack) {
        if ($depth == 10) {
            $average = $currentSum / 10;
            $averageRounded = round($average, 12);

            if ($averageRounded == floor($averageRounded * 1e12) / 1e12) {
                echo "Combination: [" . implode(", ", $combination) . "] - Average: " . number_format($averageRounded, 12, '.', '') . "<br>";
            }
            return;
        }

        for ($i = $start; $i < $n; $i++) {
            $combination[] = $numbers[$i];
            $currentSum += $numbers[$i];

            $backtrack($i + 1, $depth + 1);

            $currentSum -= array_pop($combination);
        }
    };

    $backtrack(0, 0);
}


$skin = $MAC10LightBoxMax;
$floats = $MAC10LightBoxs;
// printFilteredCombinations($floats);
try {
    echo "<pre>";
    print_r($floats);
    echo "</pre>";

    $result = findBestCombination($floats, $skin);

    if ($result === null || !is_array($result['combination'])) {
        $avg = CalcAvg($floats, 10);
        echo "Não há combinações possíveis para estes floats.<br>";
        echo "Average dos 10 mais baixos: " . $avg ."<br>";
        echo "Valor " . abs($skin - $avg) . " acima";
    } else {

        sort($result['combination']);

        echo "Melhor Combinação:";
        echo "  [<br>" . implode("<br>", $result['combination']) . "<br>]<br>";
        echo "  Média: " . number_format($result['average'], 10) . "<br>";
        echo "  Ideal: " . $skin;

        echo "<br><br>";

        echo number_format($result['average'], 10) . "<br>" . $skin;
    }
} catch (Exception $e) {
    echo "Erro: " . $e->getMessage();
}

?>

