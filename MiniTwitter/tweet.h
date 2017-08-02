#ifndef TWEET_H
#define TWEET_H

#include <iostream>
#include <string>
using namespace std;

class Tweet
{
	private:
		int cronologia;
		string usuNombre;
		string mensaje;
		bool null;
		
	public:
		Tweet();
		Tweet(int, string);
		Tweet(int, string, string);
		int getCrono();
		string getUsuNombre();
		string getMensaje();
		void setCrono(int);
		void setUsuNombre(string);
		bool compare(Tweet);
		bool esNull();
		
};

#endif
