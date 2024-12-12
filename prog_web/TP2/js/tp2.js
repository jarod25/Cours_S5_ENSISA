$(document).ready(function() {
    const $acButton = $('#btn-AC');
    const $cButton = $('#btn-C');
    const $pmButton = $('#btn-pm');
    const $percentButton = $('#btn-percent');
    const $addButton = $('#btn-add');
    const $subButton = $('#btn-sub');
    const $multButton = $('#btn-mult');
    const $pointButton = $('#btn-point');
    const $eqButton = $('#btn-eq');
    const $divButton = $('#btn-div');
    const $result = $('#display');
    let initialSituation = true;
    let currentNumber = null;
    let currentOperator = null;

    const buttons = {
        '0': 'btn-0',
        '1': 'btn-1',
        '2': 'btn-2',
        '3': 'btn-3',
        '4': 'btn-4',
        '5': 'btn-5',
        '6': 'btn-6',
        '7': 'btn-7',
        '8': 'btn-8',
        '9': 'btn-9',
    };

    function handleNumberClick(number) {
        if (initialSituation) {
            $result.text(number);
            initialSituation = false;
        } else {
            $result.text($result.text() + number);
        }
    }

    $.each(buttons, function(number, id) {
        $('#' + id).click(function() {
            handleNumberClick(number);
        });
    });

    $pointButton.click(function() {
        if ($result.text().indexOf('.') == -1) {
            $result.text($result.text() + '.');
            if (initialSituation) {
                $result.text('0.');
                initialSituation = false;
            }
        }
    });

    $cButton.click(clearDisplay);

    function clearDisplay() {
        $result.text('0');
        initialSituation = true;
    }

    function manageOperator(operator) {
        if (initialSituation) return;
        if (currentNumber === null) {
            currentNumber = parseFloat($result.text());
        } else if (!initialSituation) {
            compute();
        }
        currentOperator = operator;
        initialSituation = true;
    }

    function compute(operator) {
        if (currentOperator && currentNumber !== null) {
            const secondNumber = parseFloat($result.text());
            let computationResult;

            switch (currentOperator) {
                case '+':
                    computationResult = currentNumber + secondNumber;
                    break;
                case '-':
                    computationResult = currentNumber - secondNumber;
                    break;
                case '*':
                    computationResult = currentNumber * secondNumber;
                    break;
                case '/':
                    computationResult = secondNumber !== 0 ? currentNumber / secondNumber : "Error, can't devide by 0";
                    break;
                default:
                    computationResult = secondNumber;
            }

            $result.html(`<span class="text-muted small-text fade-in">${currentNumber} ${currentOperator} ${secondNumber}</span><br>${computationResult}`);

            currentNumber = computationResult;
            currentOperator = null;
            initialSituation = true;
        }
        if (operator == '=') {
            currentNumber = null;
        }
    }

    $addButton.click(function() { manageOperator('+'); });
    $subButton.click(function() { manageOperator('-'); });
    $multButton.click(function() { manageOperator('*'); });
    $divButton.click(function() { manageOperator('/'); });

    $eqButton.click(function() { compute('='); });

    $acButton.click(function() {
        currentNumber = null;
        currentOperator = null;
        clearDisplay();
    });

    $(document).keydown(function(event) {
        const key = event.key;

        if (buttons.hasOwnProperty(key)) {
            handleNumberClick(key);
        }

        if (key === '.') {
            $pointButton.click();
        }

        if (key === '+') {
            manageOperator('+');
        } else if (key === '-') {
            manageOperator('-');
        } else if (key === '*') {
            manageOperator('*');
        } else if (key === '/') {
            manageOperator('/');
        }

        if (key === 'Enter' || key === '=') {
            compute('=');
        } else if (key === 'Backspace') {
            if ($result.text().length > 1) {
                $result.text($result.text().slice(0, -1));
            } else {
                clearDisplay();
            }
        } else if (key === 'Escape') {
            $acButton.click();
        }
    });
});
