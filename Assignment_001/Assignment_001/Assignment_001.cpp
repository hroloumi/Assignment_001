// Assignment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;
bool gameIsRunning = true;

void PlayerChoos();
void ShowInventory();
void ShowShop();
void ExitGame();
void InventoryMenu();
void ShopMenu();
void TotalXp();

int TotalXpSum = 0;


string EmptyInv = "Empty    ";
vector<string> NpcInvent = { "1.Sword     ", "2.Shild     ",  "3.Armor     ", };
vector<int> NpcInvXp = { 500, 500, 500 };
const int SwordXp = 500;
const int ArmorXp = 500;
const int ShildXp = 500;


vector<string> ShopItems = { "1.Battle Axe     ", "2.Backbag        ", "3.Heal Potion    " };
vector<int> ShopXps = { 1000, 1000, 1000 };
const int BattAxeXp = 1000;
const int BackbagXp = 1000;
const int HealXp = 1000;
string ShopItemBattleAxe = "1.Battle Axe    ";
string ShopItemBackBag = "2.Backbag    ";
string ShopItemHeal = "3.Heal Potion    ";





int main()
{
	do {
		PlayerChoos();
	} while (gameIsRunning);

    return 0;
}


void PlayerChoos() {
	system("Color 1F");
	int PlayerInput;
	cout << "******* WLCOME TO MAIN MENUE ****** \n\n";
	cout << "[1] show your inventory - [2] show items shop - [3] Exit!\n\n";
	cin >> PlayerInput;
	switch (PlayerInput) {
	case 1:
		ShowInventory();

	case 2:
		ShowShop();

	case 3:
		gameIsRunning = false;
		ExitGame();

	default:

		PlayerChoos();
	}
}

void ShowInventory()
{
	int PlayerInput = 1;
	if (PlayerInput == 1)
	{

		cout << "You Have " << NpcInvent.size() <<  " items in your inventory : \n";
		for (int i = 0; i < NpcInvent.size(); ++i) {
			cout << NpcInvent[i] << NpcInvXp[i] << endl;
		}

		TotalXp();

		cout << "==================== \n";

		InventoryMenu();
	}
	else {
		cout << "Worng Input! \n\n";
	}
}

void ShowShop()
{
	int PlayerInput = 2;
	if (PlayerInput == 2)
	{



		cout << "There are " << ShopItems.size() << " items in shop : \n";
		for (int i = 0; i < ShopItems.size(); ++i) {
			cout << ShopItems[i] << ShopXps[i] << endl;
		}

		cout << "==================== \n";

		ShopMenu();

	}

}

void ExitGame()
{
	gameIsRunning = false;
	int PlayerInput = 3;
	if (PlayerInput == 3)
	{
		system("CLS");
		cout << "**Thanks for visiting us today!** \n\n";
		exit(0);
	}

}

void InventoryMenu()
{
	cout << "[S] Sell - [B] Back to main menu\n\n";
	char InvMenue;
	cin >> InvMenue;
	switch (InvMenue)
	{
	case 's':
	case 'S':
		cout << "Chose the item you want to sell! \n\n";
		int ItemForSell;
		cin >> ItemForSell;
		cout << "Item Number " << ItemForSell << " solde! \n";
		switch (ItemForSell)
		{
		case 1:
			if (ItemForSell == 1) {
				NpcInvent[0] = EmptyInv;
				NpcInvXp[0] = SwordXp;
				for (int i = 0; i < 3; i++) {
					cout << NpcInvent[i] << NpcInvXp[i] << endl;

				}
				TotalXp();
				cout << "==================== \n";
				InventoryMenu();
				break;
			}
			


		case 2:
			if (ItemForSell == 2) {
				NpcInvent[1] = EmptyInv;
				NpcInvXp[1] = ArmorXp;
				for (int i = 0; i < 3; i++) {
					cout << NpcInvent[i] << NpcInvXp[i] << endl;

				}
				TotalXp();
				cout << "==================== \n";
				InventoryMenu();
				break;
			}


		case 3:
			if (ItemForSell == 3) {
				NpcInvent[2] = EmptyInv;
				NpcInvXp[2] = ShildXp;
				for (int i = 0; i < 3; i++) {
					cout << NpcInvent[i] << NpcInvXp[i] << endl;

				}
				TotalXp();
				cout << "==================== \n";
				InventoryMenu();
				break;
			}


		}


	case 'B':
	case 'b':
		cout << "You are at the main menu! \n\n";
		PlayerChoos();

	}
}

void ShopMenu()
{
	cout << "[B] Buy - [C] Back to main menu\n\n";
	char InvShop;
	cin >> InvShop;

	switch (InvShop)
	{
	case 'b':
		cout << "Chose the item you want to buy! \n\n";
		int ItemToBuy;
		cin >> ItemToBuy;

		switch (ItemToBuy)
		{
		case 1:
			if (ItemToBuy == 1) {
				if (NpcInvent[0] == EmptyInv && TotalXpSum >= 1000)
				{
					cout << "Item Number " << ItemToBuy << " Bought! \n";
					NpcInvent[0] = ShopItemBattleAxe;
					NpcInvXp[0] = BattAxeXp;
					TotalXpSum -= 1500;
					for (int i = 0; i < 3; i++) {
						cout << NpcInvent[i] << NpcInvXp[i] << endl;

					}
					cout << "==================== \n";
					TotalXp();
					ShopMenu();
					break;
				}
				else
				{
					cout << "You have not enogh space in your inventory! \n";
					cout << "==================== \n";
					ShopMenu();
					break;
				}

			}

			
		case 2:
			if (ItemToBuy == 2) {
				if (NpcInvent[1] == EmptyInv && TotalXpSum >= 1000)
				{
					cout << "Item Number " << ItemToBuy << " Bought! \n";
					NpcInvent[1] = ShopItemBackBag;
					NpcInvXp[1] = BackbagXp;
					TotalXpSum -= 1000;
					for (int i = 0; i < 3; i++) {
						cout << NpcInvent[i] << NpcInvXp[i] << endl;

					}
					cout << "==================== \n";

					ShopMenu();
					break;
				}
				else
				{
					cout << "You have not enogh space in your inventory! \n";
					cout << "==================== \n";
					ShopMenu();
					break;
				}

			}

				
		case 3:
			if (ItemToBuy == 3) {
				if (NpcInvent[2] == EmptyInv && TotalXpSum >= 1000)
				{
					cout << "Item Number " << ItemToBuy << " Bought! \n";
					NpcInvent[2] = ShopItemHeal;
					NpcInvXp[2] = HealXp;
					TotalXpSum -= 1000;
					for (int i = 0; i < 3; i++) {
						cout << NpcInvent[i] << NpcInvXp[i] << endl;

					}
					cout << "==================== \n";
					ShopMenu();
					break;
				}
				else
				{
					cout << "You have not enogh space in your inventory! \n";
					cout << "==================== \n";
					ShopMenu();
					break;
				}

			}


			

		}
	case 'c':
		cout << "You are at the main menu! \n\n";
		PlayerChoos();


	}


}

void TotalXp() {

	TotalXpSum = NpcInvXp[0]+NpcInvXp[1]+NpcInvXp[2];
	cout << "You have : " << TotalXpSum << " XP. \n\n";
		
}