// Task: Write a book management system.
// Each book is a certain identification number. Numbers cannot be repeated.
// All communication with the user must take place through the menu.
// At the beginning, the user sets the initial number of books, but later he can expand this number.
// Books are entered manually, the user enters a book, after which there is a check whether
// such a book does not exist yetand only then it is added to the system.
//

#include <iostream>
using namespace std;

int main()
{
	int size, menu;
	cout << "\n\n\tEnter the library size: ";	cin >> size;
	int* library = new int[size];	// Creating a custom size array

	int size_ = -1;
	int in_index = 0;
	int new_size;
	int search;
	int hi;
	int lo;
	int mid;

	for (int i = 0; i < size; i++)	// Filling empty array cells with the maximum number
	{
		library[i] = INT_MAX;
	}
	do
	{
	start:
		if (size_ >= 0)
		{
			cout << "\n\n\tLibrary: ";
			for (int i = 0; i < size; i++)	// Array Output
			{
				if (library[i] == INT_MAX) // Replacing empty cells with a dash
				{
					cout << "_";
				}
				else
				{
					cout << library[i];
				}
				cout << " ";
			}
			cout << "\n\n\n";
		}
		cout << "\n\t1 -- Add new book\n\t2 -- Resize library\n\t3 -- Sort\n\t4 -- Search\n\t5 -- Randomize\n\t";	cin >> menu;

		switch (menu)
		{
		case 1:	// Add new book
		Add_new_book:

			cout << "\n\t0 --Back\n\t1 -- Add to the end\n\t2 -- Add to given position\n\t";
			cin >> menu;

			if (menu == 0)
			{
				goto start;
			}
			switch (menu)
			{
			case 1:	// Add to the end
			add_end:

				cout << "\n\t0 --Back\n\tEnter the index of new book: "; cin >> in_index;
				if (in_index == 0)
				{
					goto Add_new_book;
				}
				for (int i = 0; i < size; i++) // Checking if a book exists in an array
				{
					if (library[i] == in_index)
					{
						cout << "\n\tBook is alredy added";
						goto add_end;
					}
				}
				size_++;
				library[size_] = in_index;
				break;

			case 2:	// Add to given position
			add_pos:

				cout << "\n\t0 --Back\n\tEnter the index of new book: "; cin >> in_index;

				if (in_index == 0)
				{
					goto Add_new_book;
				}
				for (int i = 0; i < size; i++) // Checking if a book exists in an array
				{
					if (library[i] == in_index)
					{
						cout << "\n\tBook is alredy added";
						goto add_pos;
					}
				}
				int pos;
				cout << "\n\tEnter book position: ";	cin >> pos;

				if (pos <= size)	// Swap and insert into position
				{
					int temp;
					temp = library[pos];
					library[pos] = in_index;
					size_++;
					library[size_] = temp;
				}
				else // Error
				{
					cout << "\n\tOut of size";
					goto add_pos;
				}
				break;
			default:
				break;
			}
			break;

		case 2:	// Resize library
			cout << "\n\t0 -- Back\n\tCurent library size is " << size << " books";
			cout << "\n\tEnter the new size: "; cin >> new_size;

			if (new_size == 0)
			{
				goto start;
			}
			int temp;
			temp = size;
			size = new_size;

			for (int i = temp; i < new_size; i++)	// Filling empty array cells with the maximum number
			{
				library[i] = INT_MAX;
			}
			break;

		case 3:	// Sort
		sort:
			cout << "\n\t0 -- Back\n\t1 -- Bubble sort\n\t2 -- Selection sort\n\t3 -- Insertion sort\n\t4 -- Merge Sort -- NOT AVAILABLE\n\t5 -- Shell Sort\n\t";
			cin >> menu;

			if (menu == 0)
			{
				goto start;
			}
			switch (menu)
			{
			case 1:	// Bubble sort
				cout << "\n\t0 -- Back\n\t1 -- From lower to bigger\n\t2 -- From bigger to lower\n\t"; cin >> menu;

				if (menu == 0)
				{
					goto sort;
				}
				bool swapped;

				switch (menu)
				{
				case 1:	// From lower to bigger
					// Last i elements are already
					// in place
					for (int i = 0; i < size - 1; i++)
					{
						swapped = false;
						for (int j = 0; j < size - i - 1; j++)
						{
							if (library[j] > library[j + 1])
							{
								swap(library[j], library[j + 1]);
								swapped = true;
							}
						}
						if (swapped == false)
						{
							break;
						}
					}
					break;

				case 2:	// From bigger to lower
					
					for (int i = 0; i < size - 1; i++)
					{
						swapped = false;
						for (int j = 0; j < size - i - 1; j++)
						{
							if (library[j] < library[j + 1])
							{
								swap(library[j], library[j + 1]);
								swapped = true;
							}
						}
						if (swapped == false)
						{
							break;
						}
					}
					break;
				default:
					break;
				}
				
				break;
			case 2:	// Selection Sort
				cout << "\n\t0 -- Back\n\t1 -- From lower to bigger\n\t2 -- From bigger to lower\n\t"; cin >> menu;

				if (menu == 0)
				{
					goto sort;
				}
				int min_idx;
				switch (menu)
				{
				case 1:	// From lower to bigger

					for (int i = 0; i < size - 1; i++)
					{
						// Find the minimum element in
						// unsorted array
						min_idx = i;
						for (int j = i + 1; j < size; j++)
						{
							if (library[j] < library[min_idx])
								min_idx = j;
						}
						// Swap the found minimum element
						// with the first element
						if (min_idx != i)
						{
							swap(library[min_idx], library[i]);
						}
					}
					break;
				case 2:	// From bigger to lower

					for (int i = 0; i < size - 1; i++)
					{
						// Find the minimum element in
						// unsorted array
						min_idx = i;
						for (int j = i + 1; j < size; j++)
						{
							if (library[j] > library[min_idx])
								min_idx = j;
						}
						// Swap the found minimum element
						// with the first element
						if (min_idx != i)
						{
							swap(library[min_idx], library[i]);
						}
					}
					break;
				default:
					break;
				}
				break;
			case 3:	// Insertion sort
				cout << "\n\t0 -- Back\n\t1 -- From lower to bigger\n\t2 -- From bigger to lower\n\t"; cin >> menu;

				if (menu == 0)
				{
					goto sort;
				}
				int key, j;

				switch (menu)
				{
				case 1:	// From lower to bigger
					for (int i = 1; i < size; i++)
					{
						key = library[i];
						j = i - 1;
						// Move elements of arr[0..i-1], 
						// that are greater than key, to one
						// position ahead of their
						// current position
						while (j >= 0 && library[j] > key)
						{
							library[j + 1] = library[j];
							j = j - 1;
						}
						library[j + 1] = key;
					}
					break;
				case 2:	// From bigger to lower
					for (int i = 1; i < size; i++)
					{
						key = library[i];
						j = i - 1;
						// Move elements of arr[0..i-1], 
						// that are greater than key, to one
						// position ahead of their
						// current position
						while (j >= 0 && library[j] < key)
						{
							library[j + 1] = library[j];
							j = j - 1;
						}
						library[j + 1] = key;
					}
					break;
				default:
					break;
				}
				break;
			case 4:	// Merge Sort

				break;
			case 5:	// Shell Sort
				cout << "\n\t0 -- Back\n\t1 -- From lower to bigger\n\t2 -- From bigger to lower\n\t"; cin >> menu;

				if (menu == 0)
				{
					goto sort;
				}
				switch (menu)
				{
				case 1:	// From lower to bigger
					// Start with a big gap, then reduce the gap
					for (int gap = size / 2; gap > 0; gap /= 2)
					{
						// Do a gapped insertion sort for this gap size.
						// The first gap elements a[0..gap-1] are already in gapped order
						// keep adding one more element until the entire array is
						// gap sorted 
						for (int i = gap; i < size; i += 1)
						{
							// add a[i] to the elements that have been gap sorted
							// save a[i] in temp and make a hole at position i
							int temp = library[i];

							// shift earlier gap-sorted elements up until the correct 
							// location for a[i] is found
							int j;
							for (j = i; j >= gap && library[j - gap] > temp; j -= gap)
								library[j] = library[j - gap];

							//  put temp (the original a[i]) in its correct location
							library[j] = temp;
						}
					}
					break;
				case 2:	// From bigger to lower
					// Start with a big gap, then reduce the gap
					for (int gap = size / 2; gap > 0; gap /= 2)
					{
						// Do a gapped insertion sort for this gap size.
						// The first gap elements a[0..gap-1] are already in gapped order
						// keep adding one more element until the entire array is
						// gap sorted 
						for (int i = gap; i < size; i += 1)
						{
							// add a[i] to the elements that have been gap sorted
							// save a[i] in temp and make a hole at position i
							int temp = library[i];

							// shift earlier gap-sorted elements up until the correct 
							// location for a[i] is found
							int j;
							for (j = i; j >= gap && library[j - gap] < temp; j -= gap)
								library[j] = library[j - gap];

							//  put temp (the original a[i]) in its correct location
							library[j] = temp;
						}
					}
					break;
				default:
					break;
				}
				break;
			default:
				break;
			}
			break;
		case 4:	// Search
		search:
			cout << "\n\t0 --Back\n\t1 -- Linear search\n\t2 -- Binary search\n\t"; cin >> menu;

			if (menu == 0)
			{
				goto start;
			}
			switch (menu)
			{
			case 1:	// Linear search
				cout << "\n\t0 -- Back\n\tEnter a book index: "; cin >> search;

				if (search == 0)
				{
					goto search;
				}
				for (int i = 0; i < size; i++)
				{
					if (library[i] == search)
					{
						cout << "\n\tThe book " << search << " in position " << i;
					}
				}
				break;
			case 2:	// Binary search
				cout << "\n\t0 -- Back\n\tEnter a book index: "; cin >> search;

				if (search == 0)
				{
					goto search;
				}
				lo = 0;
				hi = size - 1;
				
				while ((hi - lo) > 1)
				{
					mid = (hi + lo) / 2;
					if (library[mid] < search)
					{
						lo = mid + 1;
					}
					else
					{
						hi = mid;
					}
				}
				if (library[lo] == search)
				{
					cout << "\n\tThe book " << search << " in position " << lo;
				}
				else if (library[hi] == search)
				{
					cout << "\n\tThe book " << search << " in position " << hi;
				}
				else
				{
					cout << "\n\tThe book " << search << " not found\n";
				}
				break;
			default:
				break;
			}
			break;
		case 5:	// Randomize
			srand(time(NULL));

			for (int i = 0; i < size; i++)
			{
				int s = size - 1;
				int r = rand() % s + 0;
				swap(library[i], library[r]);
			}
			break;
		default:
			break;
		}
	} while (true);
}