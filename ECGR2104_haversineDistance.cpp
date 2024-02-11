#include <iostream>
#include <cmath>

using namespace std;

double haversine(double lat1, double long1, double lat2, double long2, double radius) {
    lat1 = (lat1 * M_PI) / 180;
    lat2 = (lat2 * M_PI) / 180;
    long1 = (long1 * M_PI) / 180;
    long2 = (long2 * M_PI) / 180;

    double haversineComputation = 2 * radius * asin(sqrt(pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2)));

    return haversineComputation;
}

double getFlightTime(double lat1, double long1, double lat2, double long2){
    //Time = Distance / Speed
    double totalDistance = haversine(lat1, long1, lat2, long2, 3958.8);
    double totalTime = 0.0;
    //Finding the average of the jet speed MPH from 460 to 575 instead of just picking a random point between this range
    for (int i = 460; i < 575; i++){
        double getFlightTime = totalDistance / i;
        totalTime = totalTime + getFlightTime;
    }
    totalTime = totalTime / 115;
    
    return totalTime;
}

void lineBreaker() {
    for (int i = 0; i < 115; i++) {
        std::cout << "-";
    }
    std::cout << "" << endl;
}

int main() {
    cout << "This program is intended to find the amount of time it takes an airplane to fly from one GPS location to another." << endl;
    cout << "Please look at and choose one of the following departure locations:" << endl;

    string gpsLocations_area[] = {"Peabody, MA, USA", "Northampton, MA, USA", "Newton, MA, USA", "Bowling Green, KY, USA", "Monroe, LA, USA", "Biddeford, ME, USA", "Sioux City, IA, USA", "Valparaiso, IN, USA", "Charlotte, NC, USA", "Miami, FL, USA"};
    double gpsLocations_lat[] = {42.536457, 42.328674, 42.341042, 36.976524, 32.509930, 43.489849, 42.495132, 41.483845, 35.227085, 25.761681};
    double gpsLocations_long[] = {-70.985786, -72.664658, -71.217133, -86.456017, -92.121742, -70.469711, -96.400070, -87.063965, -80.843124, -80.191788};
    
    double lat1, long1, lat2, long2;
    int userNum_1;
    
    int numLocation = 1;
    for (int i = 0; i < 10; ++i) {
        cout << numLocation << ". " << gpsLocations_area[i] << ": " << gpsLocations_lat[i] << " " << gpsLocations_long[i] << endl;
        numLocation++;
    }
    
    cin >> userNum_1;
 
    userNum_1 = userNum_1 - 1;
    for (int i = 0; i < 10; i++){
        if (userNum_1 == i){
            lat1 = gpsLocations_lat[userNum_1];
            long1 = gpsLocations_long[userNum_1];
            break;
        }
    }
    
    cout << "You Picked: " << gpsLocations_area[userNum_1] << " " << gpsLocations_lat[userNum_1] << " " << gpsLocations_long[userNum_1] << endl;
    
    lineBreaker();
    
    cout << "Now look at and choose a destination location:" << endl;
    
    numLocation = 1;
    int userNum_2;

    for (int i = 0; i < 10; i++) {
        if (userNum_1 == i) {
            continue;
        }
        cout << numLocation << ". " << gpsLocations_area[i] << " " << gpsLocations_lat[i] << " " << gpsLocations_long[i] << endl;
        numLocation++;
    }
    
    cin >> userNum_2;
    
    for (int i = 0; i < 10; i++){
        if (userNum_2 == i){
            lat2 = gpsLocations_lat[userNum_2];
            long2 = gpsLocations_long[userNum_2];
            break;
        }
    }
    
    cout << "You Picked: " << gpsLocations_area[userNum_2] << " " << gpsLocations_lat[userNum_2] << " " << gpsLocations_long[userNum_2] << endl;
    
    lineBreaker();
    
    double radius = 3958.8;
    double totalDistance = haversine(lat1, long1, lat2, long2, radius);
    cout << "Haversine Distance: " << totalDistance << " miles" << endl;
    
    double totalTime = getFlightTime(lat1, long1, lat2, long2);
    cout << "Total time from " << gpsLocations_area[userNum_1] << " to " << gpsLocations_area[userNum_2] << " is " << totalTime << " hours." << endl;

    return 0;
}
