#include <iostream>

using namespace std;

class UnsortedList
{
	private:
    	int listOfItems[5];
    	int subListPart1[3] = {1, 2, 7};
    	int subListPart2[2] = {4, 5};
	public:
    	int findSpot(int &spotFound);
    	void mergeList(int &spotFound);
    	void printFullArray() const;
    	void printSubListPart1() const;
    	void printSubListPart2() const;
    	//int spotFound;
};

int UnsortedList::findSpot(int &spotFound)
{
	//flag to identify if the item has been found
	bool spotFlag = false;

	int smallerList = 0;

	//counter used when searching for the item
	int step = 0;

	//find which list has the smaller item in the first spot
	if (subListPart1[0] < subListPart2[0])
	{
    	smallerList = 1;
	}

	if (subListPart2[0] < subListPart1[0])
	{
    	smallerList = 2;
	}

	if (smallerList == 1)
	{
    	while (step < 3)
    	{
        	if (subListPart2[0] <= subListPart1[step])
        	{
            	spotFlag = true;
            	cout << "The spot is: " << step << endl;
            	break;
        	}
        	step++;  //increase the step until the item is found
    	}
	}

	spotFound = step;

	return spotFound;
}

void UnsortedList::mergeList (int &spotFound)
{
	//counter for first while loop
	int step = 0;
	int lengthOfList2 = 2;

	while (step < spotFound)
	{
    	listOfItems[step] = subListPart1[step];
    	step++;
	}

	//second while counter
	int step2 = 0;

	while (step2 < lengthOfList2)
	{
    	listOfItems[step] = subListPart2[step2];
    	step++;
    	step2++;
	}

	while (step < 5)
	{
    	listOfItems[step] = subListPart1[step2];
    	step++;
	}

}



void UnsortedList::printFullArray() const
{
	int step = 0;
	while (step < 5)
	{
    	cout << listOfItems[step] << endl;
    	step++;
	}
}

void UnsortedList::printSubListPart1() const
{
	cout << "Part 1 of the split list is: " << endl;

	int step = 0;
	while (step < 3)
	{
    	cout << subListPart1[step] << endl;
    	step++;
	}
}

void UnsortedList::printSubListPart2() const
{
	cout << "Part 2 of the split list is: " << endl;

	int step = 0;
	while (step < 2)
	{
    	cout << subListPart2[step] << endl;
    	step++;
	}
}

int main()
{
	int spotFound;
	UnsortedList list1;
	list1.findSpot(spotFound);
	list1.mergeList(spotFound);
	list1.printFullArray();

	return 0;
}


