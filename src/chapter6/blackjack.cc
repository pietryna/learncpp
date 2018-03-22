#include <string>
#include <iostream>
#include <limits>
#include <utility>
#include <array>
#include <vector>

#include <ctime>
#include <cstdlib>
#include <cstring>

#include "../startStop.h"
#include "blackjack.h"

using std::cout;
using std::cin;
using std::endl;

namespace deck
{
enum CardRanks
{
   Rank_2,
   Rank_3,
   Rank_4,
   Rank_5,
   Rank_6,
   Rank_7,
   Rank_8,
   Rank_9,
   Rank_10,
   Rank_Jack,
   Rank_Queen,
   Rank_King,
   Rank_Ace,
   Rank_NumOfRanks
};

enum CardSuits
{
   Clubs,
   Diamonds,
   Hearts,
   Spades,
   NumOfSuits
};

struct Card
{
   CardRanks rank;
   CardSuits suit;
};

static const int numOfCards = Rank_NumOfRanks * NumOfSuits;

typedef std::array<Card, Rank_NumOfRanks * NumOfSuits> Deck;
Deck DeckOfCards
{ };

void initDeck(Deck &deck)
{
   int card = 0;
   for (int rank = Rank_2; rank < Rank_NumOfRanks; ++rank)
      for (int suit = Clubs; suit < NumOfSuits; ++suit)
      {
         deck[card].rank = static_cast<CardRanks>(rank);
         deck[card].suit = static_cast<CardSuits>(suit);
         ++card;
      }
}

void printCard(const Card &card)
{
   static std::string rankTranscript[Rank_NumOfRanks]
   { "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A" };
   static char suitTranscript[NumOfSuits]
   { 'C', 'D', 'H', 'S' };

   cout << rankTranscript[card.rank] << suitTranscript[card.suit];
}

void printDeck(const Deck &deck)
{
   cout << "Deck: " << endl;
   for (const auto &card : deck)
   {
      printCard(card);
      cout << ", ";
   }
   cout << endl;
}

void swapCard(Card &card1, Card &card2)
{
   std::swap(card1, card2);
}

static int pickRandomCardFromDeck(void)
{
   const int firstCard = 1;
   static const double fraction = static_cast<double>(firstCard)
         / static_cast<double>((static_cast<unsigned int>(RAND_MAX) + firstCard));
   return firstCard
         + static_cast<int>((numOfCards - firstCard + 1) * ((rand()) * fraction));
}

void shuffleDeck(Deck &deck)
{
   const int noOfShuffles = 100000;

   for (int i = 0; i < noOfShuffles; ++i)
   {
      swapCard(deck[pickRandomCardFromDeck() - 1], deck[pickRandomCardFromDeck() - 1]);
   }
}

int getCardValue(const Card &card)
{
   int value = 0;
   switch (card.rank)
   {
   case Rank_2:
      value = 2;
      break;
   case Rank_3:
      value = 3;
      break;
   case Rank_4:
      value = 4;
      break;
   case Rank_5:
      value = 5;
      break;
   case Rank_6:
      value = 6;
      break;
   case Rank_7:
      value = 7;
      break;
   case Rank_8:
      value = 8;
      break;
   case Rank_9:
      value = 9;
      break;
   case Rank_10:
   case Rank_Jack:
   case Rank_Queen:
   case Rank_King:
      value = 10;
      break;
   case Rank_Ace:
      value = 11;
      break;
   default:
      cout << "Something wrong has happened! Crash.";
      std::array<int, 1> crash
      { };
      cout << crash[2];

   }
   return value;
}
}

namespace game
{

typedef std::vector<deck::Card> usersDeck_v;
struct usersDeck
{
   usersDeck_v deck {};
   int aceCount = 0;
};

int getDecksScore(usersDeck &deck)
{
   int score = 0;
   for (unsigned int i = 0; i < deck.deck.size(); i++)
   {
      score += deck::getCardValue((deck.deck)[i]);
   }
   if(21 < score && 0 < deck.aceCount)
      score -= 10 * deck.aceCount;
   return score;
}
std::string getText(std::string prompt)
{
   std::string tmp = "\n";
   while (true)
   {
      cout << prompt;
      cin >> tmp;

      if (cin.fail())
      {
         cin.clear();
         cin.sync();
         cout << "Wrong input! Try again." << endl;
      }
      else
      {
         return tmp;
      }
   }
}

void printScore(usersDeck &dealer, usersDeck &player)
{
   cout << "Dealer's got " << getDecksScore(dealer) << " points." << endl;
   cout << "You've got " << getDecksScore(player) << " point." << endl;
}

bool checkIfBusted(usersDeck &deck)
{
   if ( 21 < getDecksScore(deck))
      return true;
   else
      return false;
}

static void dealCard(usersDeck &deck, deck::Card **topOfDeck)
{
   if ((**topOfDeck).rank == deck::Rank_Ace)
   {
      deck.aceCount++;
      cout << "Ace!";
   }
   deck::printCard(**topOfDeck);
   cout << endl;
   deck.deck.push_back(*(*topOfDeck)++);
}

static void startGame(usersDeck &dealer, usersDeck &player,
      deck::Card **topOfDeck)
{
   cout << "Dealers cards:" << endl;
   dealCard(dealer, topOfDeck);

   cout << "Your's cards:" << endl;
   dealCard(player, topOfDeck);
   dealCard(player, topOfDeck);
   cout << endl;
}

bool playBlackjack(deck::Deck &deck)
{
   deck::Card *topOfDeck = &deck[0];

   usersDeck deckOfPlayer { };
   usersDeck deckOfDealer { };

   startGame(deckOfDealer, deckOfPlayer, &topOfDeck);

   printScore(deckOfDealer, deckOfPlayer);
   std::string choice = getText("Hit/Stand: ");

   while (true)
   {
      if (choice == "Hit" || choice == "hit")
      {
         dealCard(deckOfPlayer, &topOfDeck);
         printScore(deckOfDealer, deckOfPlayer);
         if (checkIfBusted(deckOfPlayer))
            return false;
         choice = getText("Hit/Stand: ");
      }
      else if (choice == "Stand" || choice == "stand")
      {
         break;
      }
      else
      {
         choice = getText("Hit/Stand: ");
      }
   }

   cout << "Dealer's turn" << endl;
   while (17 > getDecksScore(deckOfDealer))
   {
      dealCard(deckOfDealer, &topOfDeck);
      printScore(deckOfDealer, deckOfPlayer);
      if (checkIfBusted(deckOfDealer))
         return true;
   }

   if (getDecksScore(deckOfDealer) < getDecksScore(deckOfPlayer))
      return true;
   else
      return false;
}

}


int main_blackjack()
{
   printStartBar(__FILE__);

   srand(static_cast<unsigned int>(time(0)));
   rand();

   deck::initDeck(deck::DeckOfCards);
   deck::shuffleDeck(deck::DeckOfCards);

   if ( true == game::playBlackjack(deck::DeckOfCards))
      cout << "You win!" << endl;
   else
      cout << "You lose!" << endl;

   printStopBar(__FILE__);
   return 0;
}
