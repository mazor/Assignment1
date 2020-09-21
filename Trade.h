#ifndef TRADE_H
#define TRADE_H


#include "vector.h"
using pep::vector;


class Trade {
protected:
    int buyTime;
    int sellTime;

public:
    Trade(const int buyTimeIn, const int sellTimeIn)
        : buyTime(buyTimeIn), sellTime(sellTimeIn) {
    }

    int getBuyTime() const {
        return buyTime;
    }

    int getSellTime() const {
        return sellTime;
    }

};

#include <iostream>
using std::cout;
using std::endl; 

    
	
/**
 * bestBuySellTime takes a vector of prices and returns a Trade object with the buy and sell time that maximises profit. 
 */
Trade bestBuySellTime (vector<int> prices){
  
	long tempBuyIndex = 0; //represents the temporary index for when the buying should take place. Initialised as 0.
	long tempSellIndex = 0; //represents the temporary index for when the selling should take place. Initialised as 0.
	long tempProfit = 0; //represents the profit made if you buy at tempBuyIndex and sell at tempSellIndex. Initialised as 0.
	
	long mpBuy = 0; //represents the best index found so far for buying to maximise profit. Initialised as 0.
	long mpSell = 0; //represents the best index found so far for selling to maximise profit. Initialised as 0.
	long maximumProfit = 0; //represents the best profit found so far (profit made if you buy at mpBuy and sell at mpSell). Initialised as 0.

	long bestBuy = -1; //represents the buy index that will be used when creating the Trade to return.
	long bestSell = -1; //represents the sell index that will be used when creating the Trade to return.

	//for the entire length of the vector prices do
	for (long i = 0; i < prices.size(); ++i){
  
		//if the price at tempBuyIndex is greater than the price at i then
		if ((prices[tempBuyIndex])>(prices[i])){

			tempBuyIndex = i; //tempBuyIndex is assigned as i

		}

		tempSellIndex=tempBuyIndex; //tempSellIndex is assigned as tempBuyIndex since you can only buy in the same hour as you buy or later. Therefore, tempSellIndex should never be greater than tempBuyIndex.

		//from the tempBuyIndex to the end of prices do
		for (long k = tempBuyIndex; k < prices.size(); ++k){

			//if the price at tempSellIndex is less than the price at k then
			if ((prices[tempSellIndex])<(prices[k])){

				tempSellIndex = k; //tempSellIndex is assigned as k

			}
	
		}

		tempProfit = ((prices[tempSellIndex])- (prices[tempBuyIndex])); //tempProfit is assigned as the price at tempSellIndex minus the price at tempBuyIndex. This is because profit is the difference between the amount earned and the amount spent in buying something.
		
			//if maximumProfit is less than tempProfit then
			if (maximumProfit < tempProfit){

				maximumProfit = tempProfit; //maximumProfit is assigned as tempProfit
				mpBuy = tempBuyIndex; //mpBuy is assigned as tempBuyIndex as it is currently the buy index that gives the maximum profit.
				mpSell = tempSellIndex; //mpSell is assigned as tempSellIndex as it is currently the sell index that gives the maximum profit.
	
			}

	}

	bestBuy = mpBuy; //bestBuy is assigned as mpBuy as it is the best index to buy at to maximise the profit
	bestSell = mpSell; //bestSell is assigned as mpSell as it is the best index to buy at to maximise the profit

	Trade bestTrade (bestBuy, bestSell); //a new Trade called bestTrade is created with the parameters bestBuy and bestSell. It represents the trade needed to maximise profit.
    
	return bestTrade; //bestTrade is returned

}




// Don't write any code below this line

#endif
