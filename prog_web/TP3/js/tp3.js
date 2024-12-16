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
    if (val === "C") return "Cherbourg";
    if (val === "Q") return "Queenstown";
    if (val === "S") return "Southampton";
}

function updateSex(val) {
    return val === "male" ? '<i class="fa-solid fa-mars"></i>' : '<i class="fa-solid fa-venus"></i>';
}

function updateSurvived(val) {
    return val === 1 ? "Yes" : "No";
}

function sortTable(columnIndex, order) {
    let rows = $('#titanic_data tr').get();
    rows.sort(function(a, b) {
        let valA = $(a).children('td').eq(columnIndex).text().toUpperCase();
        let valB = $(b).children('td').eq(columnIndex).text().toUpperCase();
        if ($.isNumeric(valA) && $.isNumeric(valB)) {
            valA = parseFloat(valA);
            valB = parseFloat(valB);
        }
        return (valA < valB ? -1 : valA > valB ? 1 : 0) * (order === 'asc' ? 1 : -1);
    });
    $.each(rows, function(index, row) {
        $('#titanic_data').append(row);
    });
}

$("th").on("click", function() {
    let columnIndex = $(this).index();
    let isAscending = $(this).hasClass('asc');
    $("th").removeClass('asc desc');
    $(this).addClass(isAscending ? 'desc' : 'asc');
    sortTable(columnIndex, isAscending ? 'desc' : 'asc');
});

function filterTable() {
    let input = document.getElementById("filter");
    let filter = input.value.toUpperCase();
    let table = document.getElementById("titanic_data");
    let tr = table.getElementsByTagName("tr");
    for (let i = 0; i < tr.length; i++) {
        let td = tr[i].getElementsByTagName("td")[1];
        if (td) {
            let txtValue = td.textContent || td.innerText;
            tr[i].style.display = txtValue.toUpperCase().indexOf(filter) > -1 ? "" : "none";
        } 
    }
}

document.getElementById("filter").addEventListener("keyup", filterTable);
