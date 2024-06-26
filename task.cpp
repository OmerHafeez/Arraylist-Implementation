#include<iostream>
using namespace std;
const int maxsize = 100;
class Arraylist {
public:
	int Arr[maxsize];
	int size;

	Arraylist() {
		size = 0;
	}

	void InsertEnd(int vol)
	{
		if (size > maxsize)
			cout << "maximum size reached" << endl;
		else
		{
			Arr[size++] = vol;
		}
	}
	void InsertAt(int val, int pos)
	{
		if ((pos<0 && pos>size) && size == maxsize)
		{
			cout << "Invalid Position" << endl;
		}
		else
		{
			for (int i = size; i > pos; i--)
			{
				Arr[i] = Arr[i - 1];
			}
			Arr[pos] = val;
			size++;
		}
	}

	void Print()
	{
		cout << "[";
		for (int i = 0; i < size; i++)
		{
			cout << Arr[i] << ",";
		}
		cout << "]";
		cout << endl;
	}

	bool IsEmpty()
	{
		if (size == 0)
			return true;
		else
			return false;
	}

	void Replace(int val, int pos)
	{
		Arr[pos] = val;
	}

	void Sort()
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if (Arr[j] > Arr[j + 1])
				{
					// Swap arr[j] and arr[j + 1]
					int temp = Arr[j];
					Arr[j] = Arr[j + 1];
					Arr[j + 1] = temp;
				}
			}
		}
	}

	int Search(int search)
	{
		int check = -1;
		for (int i = 0; i < size; i++)
		{
			if (Arr[i] == search)
				check = 1;
		}
		return check;
	}

	void Remove(int val)
	{
		for (int i = 0; i <= size; i++)
		{
			if (Arr[i] == val)
			{
				for (int j = i; j < size; j++)
				{
					Arr[j] = Arr[j + 1];

				}
				size--;
			}
		}

	}

	void Duplicate()
	{
		if (size * 2 > 100)
			cout << "Array Size will be larger than total so invalid" << endl;
		else
		{
			for (int i = 0, j = size; i < size; i++, j++)
			{
				Arr[j] = Arr[i];
			}
			size *= 2;
		}
	}
	void Clear()
	{
		size = 0;
	}

};
int main()
{
	Arraylist list;

	// Insert elements at the end
	list.InsertEnd(10);
	list.InsertEnd(20);
	list.InsertEnd(30);

	list.Print(); // Output: 10 20 30

	// Insert an element at a given position
	list.InsertAt(15, 1);

	// Print the list
	list.Print(); // Output: 10 15 20 30

	// Check if the list is empty
	cout << "Is the list empty? " << (list.IsEmpty() ? "Yes" : "No") << endl;

	// Replace an element at a given position
	list.Replace(25, 2);

	// Print the list after replacing
	list.Print(); // Output: 10 15 25 30

	// Sort the list
	list.Sort();

	// Print the sorted list
	list.Print(); // Output: 10 15 25 30

	// Search for an element
	int searchElement = 15;
	int position = list.Search(searchElement);
	if (position != -1) {
		cout << "Element " << searchElement << " found at position " << position << endl;
	}
	else {
		cout << "Element " << searchElement << " not found in the list" << endl;
	}

	// Remove an element
	list.Remove(15);

	// Print the list after removal
	list.Print(); // Output: 10 25 30

	// Duplicate the list
	list.Duplicate();

	// Print the duplicated list
	list.Print(); // Output: 10 25 30 10 25 30
	list.Clear();
	return 0;

}