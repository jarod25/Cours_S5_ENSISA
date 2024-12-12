jQuery.getJSON("../data/titanic.json", function(data) {
    let tbody = $("#titanic_data");
    $.each(data, function(i, item) {
        $.each(item, function(j, val) {
            let $row = $("<tr></tr>");
            $row.append('<td>' + val.PassengerId + '</td>');
            $row.append('<td>' + val.Name + '</td>');
            $row.append('<td>' + updateSex(val.Sex) + '</td>');
            $row.append('<td>' + val.Age + '</td>');
            $row.append('<td>' + val.Pclass + '</td>');
            $row.append('<td>' + updateCityname(val.Embarked) + '</td>');
            $row.append('<td>' + updateSurvived(val.Survived) + '</td>');
            val.Survived ? $row.addClass("table-success") : $row.addClass("table-danger");
            tbody.append($row);
        });
    });
});

function updateCityname(val) {
    if (val == "C") {
        return "Cherbourg";
    }
    if (val == "Q") {
        return "Queenstown";
    }
    if (val == "S") {
        return "Southampton";
    }
}

function updateSex(val) {
    if (val == "male") {
        return '<i class="fa-solid fa-mars"></i>';
    } else {
        return '<i class="fa-solid fa-venus"></i>';
    }
}

function updateSurvived(val) {
    if (val == 1) {
        return "Yes";
    } else {
        return "No";
    }
}

function sortTable() {
    let table, rows, switching, i, x, y, shouldSwitch;
    table = document.getElementById("titanic_data");
    switching = true;
    while (switching) {
        switching = false;
        rows = table.rows;
        for (i = 1; i < (rows.length - 1); i++) {
            shouldSwitch = false;
            x = rows[i].getElementsByTagName("td")[0];
            y = rows[i + 1].getElementsByTagName("td")[0];
            if (parseInt(x.innerHTML) > parseInt(y.innerHTML)) {
                shouldSwitch = true;
                break;
            }
        }
        if (shouldSwitch) {
            rows[i].parentNode.insertBefore(rows[i + 1], rows[i]);
            switching = true;
        }
    }
}