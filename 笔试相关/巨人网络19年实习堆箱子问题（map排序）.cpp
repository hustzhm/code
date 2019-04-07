
#include <iostream>
#include <vector>
#include <map>
using namespace std;
/*堆箱子问题。每个箱子都是一个长方体，将这些箱子堆起来，要满足下面的箱子长和宽都小于上面的长和宽，求模型的最大高度。*/
typedef struct Bin
{
	Bin(){}
	Bin(int w, int d, int h) :_w(w), _d(d), _h(h){}
	bool canBeAbove(Bin& bottom)
	{
		if (_w < bottom._w && _d < bottom._d && _h < bottom._h)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (const Bin& bin) const

	{
		if (_w != bin._w)
		{
			return _w < bin._w;
		}
		else
		{
			if (_d != bin._d)
			{
				return _d < bin._d;
			}
			else
			{
				return _h < bin._h;
			}
		}
	}
	int _w;
	int _d;
	int _h;
}Bin;

int getHeight(vector<Bin>& bins)

{
	if (bins.empty())
	{
		return 0;
	}
	int size = bins.size();
	int height = 0;
	for (int i = 0; i < size; i++)
	{
		height += bins.at(i)._h;
	}
	return height;
}


vector<Bin> createBins(vector<Bin>& bins, Bin& bottom, map<Bin, vector<Bin> >& binToList)

{
	vector<Bin> vecBin;
	if (bins.empty())
	{
		return vecBin;
	}
	if (binToList.find(bottom) != binToList.end())

	{
		return binToList.find(bottom)->second;
	}
	int maxHeight = 0;
	vector<Bin> maxBins;
	int n = bins.size();
	for (int i = 0; i < n; i++)
	{
		if (bins.at(i).canBeAbove(bottom))
		{
			vector<Bin> newBins = createBins(bins, bins.at(i), binToList);
			int newHeight = getHeight(newBins);
			if (newHeight > maxHeight)
			{
				maxHeight = newHeight;
				maxBins = newBins;
			}
		}
	}
	maxBins.insert(maxBins.begin(), bottom);
	binToList.insert(pair<Bin, vector<Bin> >(bottom, maxBins));
	return maxBins;
}
void process()

{
	int n;
	vector<Bin> bins;
	map<Bin, vector<Bin> > binToList;
	vector<Bin> results;
	vector<Bin> maxResults;
	int w, d, h;
	while (cin >> n)
	{
		bins.clear();
		binToList.clear();
		for (int i = 0; i < n; i++)
		{
			cin >> h >> w >> d;
			Bin bin(w, d, h);
			bins.push_back(bin);
		}
		int maxHeight = 0;
		for (int i = 0; i < n; i++)
		{
			Bin bottom = bins.at(i);
			results = createBins(bins, bottom, binToList);
			int height = getHeight(results);
			if (height > maxHeight)
			{
				maxHeight = height;
				maxResults = results;
			}
		}
		cout << maxHeight << endl;
	}
}

int main()

{
	process();
	//system("pause");
	return 0;
}
