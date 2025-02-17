#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Train {
	int number;
	string departure_time;
	string destination;
};

void addTrain(vector<Train>& trains) {
	Train train;
	cout << "Enter train number: ";
	cin >> train.number;
	cin.ignore();
	cout << "Enter departure time: ";
	getline(cin, train.departure_time);
	cout << "Enter destination: ";
	getline(cin, train.destination);
	trains.push_back(train);
}

void showAllTrains(const vector<Train>& trains) {
	for (const auto& train : trains) {
		cout << "Number: " << train.number
			<< ",Time: " << train.departure_time
			<< ",Destination: " << train.destination << '\n';
	}
}

void searchTrain(const vector<Train>& trains, int number) {
	for (const auto& train : trains) {
		if (train.number == number) {
			cout << "Number: " << train.number
				<< ",Time: " << train.departure_time
				<< ",Destination: " << train.destination << '\n';
			return;
		}
	}
	cout << "Train with number " << number << " not found\n";	
}

int main() {
	vector<Train> trains;
	int choice;
	do {
		cout << "1.Add Train\n2.Show All Trains\n3.Search Train\n4.Exit\n";
		cout << "Choose an option: ";
		cin >> choice;
		switch (choice) {
		case 1:
			addTrain(trains);
			break;
		case 2:
			showAllTrains(trains);
			break;
		case 3:
			int number;
			cout << "Enter train number: ";
			cin >> number;
			searchTrain(trains, number);
			break;
		case 4:
			cout << "Exiting program.\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
			break;
		}
	} while (choice != 4);
	return 0;
}