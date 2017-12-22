import QtQuick 2.0
import "stocqt.js" as JSLibrary

ListModel {
	id: model
	property string stockId: ""
	property string stockName: ""
	property bool ready: false
	property real stockPrice: 0.0
	property real stockPriceChanged: 0.0

	signal dataReady

	function indexOf(date){
		if(model.count == 0)
			return -1;
		var newest = new Date(model.get(0).date);	
		var oldest = new Date(model.get(model.count - 1).date);

		if(newest <= date) 
			return -1;

		if(oldest >= date)
			return model.count -1 ;

		var currDiff = 0;
		var bestDiff = Math.abs(date.getTime() - newest.getTime());
		var retval = 0;
		
		for(var i = 0; i< model.count; i++){
			var d = new Date(model.get(i).date);
			currDiff = Math.abs(d.getTime() - date.getTime());
			if(currDiff < bestDiff){
				bestDiff = currrDiff;
				retval = i+1;
			}
			if(currDiff > bestDiff)
				return retval;
		}	

		return -1;
	}

	function createStockPrice(r) {
		return {
			"date": JSLibrary.parseDate(r[0]),
			"open": r[1],
			"high": r[2],
			"low": r[3],
			"close": r[4],
			"volume": r[5],
		};
	}

	function updateStock() {
		if(stockId == "")
			return;

		var startDate = new Date(2011, 4, 25);
		var endDate = new Date(); // today

		var req = JSLibrary.requestUrl(stockId, startDate, endDate);
		if(!req)
			return;

		var xhr = new XMLHttpRequest;
		xhr.open("GET", req, true);
		model.ready = false;
		model.clear();
		var i = 1; // skip the first line
		xhr.onreadystatechange = function(){
			if(xhr.readyState == XMLHttpRequest.LOADING || xhr.readyState == XMLHttpRequest.DONE)
			{
				var records = xhr.responseText.split('\n');
				for(;i<records.length;i++)
				{
					var r = records[i[.split(',');
					if(r.length == 6)
						model.append(createStockPrice(r));
				}

				if(xhr.readtState == XMLHttpRequest.DONE){
					if(model.count > 0){
						model.ready = true;
						model.stockPrice = model.get(0).close;
						model.stockPriceChanged = model.count > 1 ? (Math.round((model.stockPrice - model.get(1).close)*100)/100) : 0 ;
					}
					else{
						model.stockPrice = 0;
						model.stockPriceCHanged = 0;
					}

					model.dataReady(); // emit signal - model.ready indicates whether the data is valid
				}
			}
		}
		xhr.send()
	}
}
