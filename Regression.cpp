#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point
{
	float x;
	float y;

	Point(float X,float Y)
	{
		x=X;
		y=Y;
	}
	Point()
	{
		x=0;
		y=0;
	}
};
/*Function that calculate histogram estimation
Name: Hist
**********
Return value : vector<Point>
************
Params : 
******
Data - (float) Data set
NumBins - float number of the bins   
*/
vector<Point> CumSum()
{
	vector<Point> result;

	return result;
}
vector<Point> Hist(vector<float> Data,int NumBins)
{
	vector<Point> result;

	float maxD=Data.back(); 
	float minD=Data.front();
	float delta=(maxD-minD)/NumBins;

	for(int i = 0;i<=NumBins;i++)
	{
		float centerX=minD+float((i))*delta+(delta/2.0);
		Point temp(Data[i],centerX); //Create new elem width Xb and Yb
		result.push_back(temp);	
	}
	
	return result;
}
/*Normalization 
Name: Normalize
**********
Return value : vector<Point>
************
Params : 
******
Points - vector<Point> Data set
DataX_size - (float) size of DataX
DataY_size - (float) size of DataY
*/
vector<Point> Normalize(vector<Point> Points,float DataX_size,float DataY_size,float By)
{
	vector<Point> result;
	for(int i = 0;i<Points.size();i++)
	{
		Point temp(0,0);
		temp.x=Points[i].x/DataX_size;
		temp.y=((DataY_size*Points[i].y)+1.0)/(By+pow(DataY_size,2));
		result.push_back(temp);
	}
	return result; 
}
/*Printing of the data set
Name: Print
**********
Return value : (void)
************
Params : 
******
DataX - (float) Data set
maxLength - (int) max length of row  
*/
void Print(std::vector<float> Data,int maxLength)
{	
	cout<<"***********\n";

	for (int i = 0; i < Data.size();i++)
	{
		if(i>maxLength)
		{
			cout<<"\n";
		}
		cout<<Data[i]<<" ";
	}

	cout<<"\n";
}
void Print(std::vector<Point> Data,int maxLength)
{
	cout<<"***********\n";
	//cout<<"Hist:"<<endl;
	for (int i = 0; i < Data.size(); i++)
	{
		/*if(i>maxLength)
		{
			cout<<"\n";
		}*/

		cout<<"("<<Data[i].x<<","<<Data[i].y<<")"<<'\n';
	}
}
/*Array Initialization*/
void InitArray(vector<float> &Data)
{
	float input;
	cout<<"Enter data \n ";
	
	for(int i = 0;i<Data.capacity();i++)
	{
		cout<<"Elem "<<i<<":";
		cin>>input;
		Data.push_back(input);
	}
}
void InitArrayRandom(vector<float> &Data)
{
	srand(time(0));

	for(int i = 0;i<Data.capacity();i++)
	{
		Data.push_back(rand()%100);
	}
}
int main()
{
	/*Input*/

	vector<float> Dx;
	vector<float> Dy;
	vector<Point> Points;
	float R;

	Dx.reserve(50);
	Dy.reserve(50);

	//InitArray(Dx);
	InitArrayRandom(Dx);
	InitArrayRandom(Dy);

	cout<<"Capacity of Dx:"<<Dx.capacity()<<endl;
	cout<<"Size of Dx:"<<Dx.size()<<endl;
	
	/*Sorting data*/
	sort(Dx.begin(),Dx.end());
	Print(Dx,10);
	sort(Dy.begin(), Dy.end());
	Print(Dy,10);
	//Print(Dy,10);

	/*Compute Number of B bins*/
	float Bx=20*log10(Dx.size());

	float By=20*log10(Dy.size());

	cout<<"Bx = "<<Bx<<" "<<"By = "<<By<<endl;

	Print(Hist(Dx,Bx),10);
	Print(Hist(Dy,By),10);
	return 0;
}
