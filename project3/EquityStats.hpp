/*BY::Cebastian Santiago
* EquityStats header file
* SSU CS315 DSA Project 3
*/
#pragma once
#ifndef EquityStats_HPP
#define EquityStats_HPP
#include<fstream>
#include<vector>
#include<string>
#include"EntitySet.hpp"
#include"EntityInstance.hpp"
class EquityStats{
public:
	/// <summary>
	/// takes a EntitySet and sets equal to EntitySet vector
	/// </summary>
	/// <param name="instanceOfEntitySet"></param>
	EquityStats(EntitySet& instanceOfEntitySet);

	/// <summary>
	/// PreCondition::Execepts Close value not to 
	/// be zeros
	/// Calculates the EMA for 12 and 26 days
	/// </summary>
	/// <param name="tweleve"></param>
	void calculateExponentialMovingAverage(int tweleve);
	
	/// <summary>
	/// Precondition calculates MACD base on difference being 
	/// 26 days and days of EMA 
	/// </summary>
	void calculateMACD();
	
	/// <summary>
	/// Calcuates Signal based on 9 days 
	/// </summary>
	/// <param name="days"></param>
	void calculateSignal(int days);
	void print(std::vector<std::string> keys);
	double firstaverage(int days);
private:
	std::vector<EntityInstance> startinstance();
	std::vector<EntitySet> entityset;
	std::vector<EntityInstance> instance;
};
#endif // !EquityStats_HPP
