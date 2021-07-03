#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Position
{
private:
  double height;
  double latitude;
  double longitude;

public:
  Position(double latitude, double longitude, double height) : height(height), latitude(latitude), longitude(longitude){};
  Position(){};
  Position(const Position &other) : height(other.height), latitude(other.latitude), longitude(other.longitude){};
  double getHeight()
  {
    return height;
  };
  double getLatitude()
  {
    return latitude;
  };
  double getLongitude()
  {
    return longitude;
  };
  void setHeight(double newHeight)
  {
    height = newHeight;
  };
  void setLatitude(double newLatitude)
  {
    latitude = newLatitude;
  };
  void setLongitude(double newLongitude)
  {
    longitude = newLongitude;
  };
  void print()
  {
    cout << "Höhe: " << height << endl;
    cout << "Längengrad: " << longitude << endl;
    cout << "Breitengrad: " << latitude << endl;
    cout << "_____________________________" << endl;
  };
};

class Waypoint : public Position
{
private:
  string name;

public:
  Waypoint(double latitude, double longitude, double height, string name) : name(name), Position(latitude, longitude, height){};
  Waypoint(){};
  Waypoint(const Waypoint &other) : name(other.name), Position(other){};
  string getName()
  {
    return name;
  };
  void setName(string newName)
  {
    name = newName;
  }
  void print()
  {
    cout << "Höhe: " << getHeight() << endl;
    cout << "Längengrad: " << getLongitude() << endl;
    cout << "Breitengrad: " << getLatitude() << endl;
    cout << "Ortsbezeichnung: " << name << endl;
    cout << "_____________________________" << endl;
  };
};

class Trackpoint : public Position
{
private:
  int time;

public:
  Trackpoint(double latitude, double longitude, double height, int time) : time(time), Position(latitude, longitude, height){};
  Trackpoint(){};
  Trackpoint(const Trackpoint &other) : time(other.time), Position(other){};
  int getTime()
  {
    return time;
  };
  void setTime(int newTime)
  {
    time = newTime;
  };
  void print()
  {
    cout << "Höhe: " << getHeight() << endl;
    cout << "Längengrad: " << getLongitude() << endl;
    cout << "Breitengrad: " << getLatitude() << endl;
    cout << "Zeitstempel: " << time << endl;
    cout << "_____________________________" << endl;
  };
};

class Track
{
private:
  vector<Trackpoint> track;

public:
  Track(){};
  Track(const Track &other) : track(other.track){};
  void print()
  {
    for (int i = 0; i < track.size(); i++)
    {
      track[i].print();
    }
  };
  void add(Trackpoint point)
  {
    track.push_back(point);
  };
  void write(string filepath)
  {
    ofstream file;
    file.open(filepath);

    if (!file.is_open())
      return;

    for (int i = 0; i < track.size(); i++)
    {
      Trackpoint point = track[i];
      string line = "";

      ostringstream ss1, ss2, ss3;
      ss1.precision(7);
      ss2.precision(7);
      ss3.precision(2);

      ss1 << fixed << point.getLatitude();
      ss2 << fixed << point.getLongitude();
      ss3 << fixed << point.getHeight();

      line += ss1.str();
      line += " ";
      line += ss2.str();
      line += " ";
      line += ss3.str();
      line += " ";
      line += to_string(point.getTime());

      file << line << endl;
    }

    file.close();
  };
  void read(string filepath)
  {
    ifstream file;
    file.open(filepath);

    if (!file.is_open())
      return;

    try
    {
      while (file.good())
      {
        string temp;
        Trackpoint point = Trackpoint();

        file >> temp;
        point.setLatitude(stod(temp));

        file >> temp;
        point.setLongitude(stod(temp));

        file >> temp;
        point.setHeight(stod(temp));

        file >> temp;
        point.setTime(stoi(temp));

        add(point);
      }

      file.close();
    }
    catch (const std::exception &e)
    {
      //ignore
      file.close();
    }
  };
  double getAverageHeight()
  {
    double sum;

    for (int i = 0; i < track.size(); i++)
    {
      sum += track[i].getHeight();
    }

    return sum / track.size();
  };
};

int main(int argc, char *argv[])
{
  Track track;
  track.read("track.txt");
  track.write("compare.txt");
  track.print();
  cout << "Durschnittliche Höhe: " << track.getAverageHeight() << endl;

  return 1;
}