#include <ctime>
#include <iostream>
#include <fstream>
#include <random>
#include <cstdlib>
#include <sstream>
using namespace std;

string to_string(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int main()
{
default_random_engine * gptr;
gptr = new default_random_engine(time(NULL));

///______________________________________
fstream fout1;
fstream fout2;
fstream fout3;
///_____________________________________
string pngfile;
string target2;
string target3;
string index;


///______________________________________making the command file
fout1.open("command.txt",ios::out);

fout1<<"set xlabel \"stuff\""<<endl;
fout1<<"set ylabel \"other stuff\""<<endl;
fout1<<"set xrange [-5:30]"<<endl;
fout1<<"set yrange [-5:30]"<<endl;
fout1<<"set terminal png"<<endl;


///_____________________________________________________only 10 moves
for(int i = 0; i<10; i++)
{
    index = to_string(i);

    target2 = "outputE"+index+".dat";   ///like the name of elk data files these files numbered output20+
    fout2.open(target2.c_str(),ios::out);
    fout2<<i<<" "<<i<<" "<<".25"<<endl;        ///i only have one, you have 10
    fout2.close();

    target3="outputW"+index+".dat";      ///this is like the name of wolf files, these files numbered output300+
    fout3.open(target3.c_str(),ios::out);
    normal_distribution<double> ndist(i, i+.25);
    fout3<<ndist(*gptr)<<" "<<ndist(*gptr)<<" "<<".25"<<endl; ///this is the random drunk wolf
    fout3.close();


    pngfile="output"+index+".png";  /// png files numbered output0 to...
    fout1<<"set output \'"<<pngfile<<"\'"<<endl;
    fout1<<"plot \'"<<target2<<"\' with circles linecolor rgb \"#9ACD32\" fill solid noborder, \'"<<target3<<"\' with circles linecolor rgb \"#9E6014\" fill solid noborder"<<endl;
}

fout1<<"pause -1"<<endl;

fout1.close();
///_______________________

system("gnuplot command.txt");
return 0;}
