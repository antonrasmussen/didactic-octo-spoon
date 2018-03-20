
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>  ///this has system in it.
#include <sstream> ///this has the stringstream conversion in it
using namespace std;

///this little code of mine converts a number into a sentence
string to_string(int i)
{
    stringstream ss;
    ss<<i;
    return ss.str();
}

int main()
{
    fstream fout;
    fstream comout;
///comout  is a connection to the file command.txt
///that gnuplot will use
    comout.open("command.txt",ios::out);
    comout<<"set yrange [-10:30]"<<endl;
    comout<<"set xrange [-10:30]"<<endl;
    comout<<"set xlabel \"X Axis\""<<endl;
    comout<<"set ylabel \"Y Axis\""<<endl;
    comout<<"set terminal png"<<endl;



    string pngfile;
    string target;

    int num;
    cout<<"how many images?"<<endl;
    cin>>num;
    for(int i=0; i<num; i++)
    {   ///target is the name of the file where data goes
        target = "output"+to_string(i)+".dat";
        fout.open(target.c_str(), ios::out);
        fout<<i<<" "<<i<<" 1 "<<endl;
        fout.close();

        ///pngfile is the name of the image that gnuplot makes
        pngfile="output"+to_string(i)+".png";
        comout<<"set output \'"<<pngfile<<"\'"<<endl;
        comout<<"plot \'"<<target<<"\' with circles linecolor rgb \"#9ACD32\" fill solid noborder"<<endl;

    }
    comout.close();
    ///the command file is ready, close it..and use it.
    ///system needs the <cstdlib> library

    system("gnuplot command.txt");

    return 0;
}
