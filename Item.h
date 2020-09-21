#ifndef ITEM_H

#define ITEM_H



// TODO: your code goes here
#include <iostream> 
#include <string> 
#include <sstream>
#include <cmath>
using std::string;
using std::cout;
using std::ostream;
using std::endl;
using std::ostringstream;

class Item {

private:


	long double latitude; //Their latitude (a number in degrees, e.g. 51.75087595155126) 

	long double longitude; //Their longitude (a number in degrees, e.g. -0.33483137537806396)

	string id; // A string ID

	int time; //The time at which they become available: an integral number of seconds past the hour



public:
  
	/**
	* The following constructor takes 4 parameters and assigns the values for the four private fields above
	*/

	Item(const long double theLatitude, const long double theLongitude, const string theId, const int theTime)
	: latitude(theLatitude), longitude(theLongitude),  id(theId), time(theTime){    }
	
	/**
	 * The following method returns the value for latitude
	 */
	double getLatitude() const {
	
		return latitude;
	
	}

	/**
	 * The following method returns the value for longitude
	 */
	double getLongitude() const {
	
		return longitude;
	
	}
	
	/**
	 * The following method returns the value for id
	 */
	string getId() const {

		return id;
  
	}
	
	/**
	 * The following method returns the value for time
	 */
	int getTime() const {

		return time;

	}

	/**
	 * The following method takes a parameter of an Item and works out the distance between the item this method was called from and the given item using the Haversine formula 
	 */
	double distanceTo (Item &other) {
	  
		long double pi = 3.14159265359; //pi represents the irrational number pi to 12 significant figures

		long double  longitude1=(longitude * pi)/180; //longitude1 is the longitude in radians instead of degrees
		long double  longitude2=((other.getLongitude()) * pi)/180; //longitude2 is other's longitude in radians instead of degrees
		
		long double  latitude1=(latitude * pi)/180; //latitude1 is the latitude in radians instead of degrees
		long double  latitude2=((other.getLatitude()) * pi)/180; //latitude2 is other's latitude in radians instead of degrees

		long double dLon = longitude2 - longitude1; //dLon represents the difference in longitudes (difference between longitude2 and longitude1)
		long double dLat = latitude2 - latitude1; //dLat represents the difference in latitudes (difference between latitude2 and latitude1)
		
		long double a = //a is assigned the value of the result of the formula below
		pow ((sin(dLat/2)), 2) //dLat is divided by two and the sine of that result is squared
		+ //then add
		cos(latitude1) * cos(latitude2)  //the cosine of latitude1 multiplied by the cosine of latitude2
		* pow((sin(dLon/2)), 2); //multiplied by the result of dividing dLon by two, applying sine and squaring the sine result
		
		long double c = 2 * atan2(sqrt(a), sqrt(1-a));  //c is assigned as twice the value of the result of atan2 with the two parameters (square root of a and the square root of (1-a))
		
		int R = 6373000; //represents the radius of the earth in metres
		
		long double distance = R * c; //distance is assigned as the product of R and c
		
		return distance; //distance is returned 
	}
	
	/**
	 * The following method is used in conjunction with operator<< to write to a ostream and return a string in the format {latitude, longitude, "ID", time}
	 * 
	 */
	void write(ostream & os) const {
	  
		os << "{" << getLatitude() <<", "<< getLongitude() <<", "<< "\""<<getId() <<"\""<<", " << getTime() << "}";
	
	}

};

	/**
	 * The operator << is overloaded. This method takes an ostream and an Item as a parameter and calls write from the item using the ostream.
	 */
	ostream& operator<< (ostream & os, const Item & item){

		item.write(os); //write is called from item using the parameter os

		return os ; //os is returned

	}


// don't write any code below this line



#endif

