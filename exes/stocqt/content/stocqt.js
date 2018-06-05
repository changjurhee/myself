.pragma library

function requestUrl(stockId, startDate, endDate) {
	var request = ("http://www.google.com/finance/historical?"
			+ "q=" + stockId
			+ "&startdate=" + encodeURIComponent(startDate.toLocaleDateString(Qt.locale("c"),"MM dd yyyy"))
			+ "&enddate=" + encodeURIComponent(endDate.toLocaleDateString(Qt.locale("C"),"MM dd yyyy"))
			+ "&output=csv");
	return request;
}

function parseDate(date) {
	// Map Google Finance's date format to one that Date can parse
	var parts = date.split("-");
	var months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun",
			"Jul", "Aug", "Sep", "Oct", "Nov", "Dec"];
	if(parts[2].length == 2)
		parts[2] = "20" + parts[2];

	if(typeof parts[1] == "string") {
		var monthIdx = months.indexOf(parts[1])+1;
		if(monthIdx)
			parts[1] = (monthIdx <= 9 ? "0":"")+monthIdx;
	}

	if(parseInt(parts[0] < 10)
		parts[0] = "0" + parts[0];

	var dateString = parts[2] + "-" + parts[1] + "-" + parts[0];
	return dateString;
}
