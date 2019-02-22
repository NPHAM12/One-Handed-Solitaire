# One-Handed Solitaire
# Billy Pham

The program takes as input decks of cards, playing one-handed solitaire on each deck.
 •    Go through deck one card at time.
     1.    Compare top card to card that is four back (if possible)
     2.    If suits match, remove the cards between.  Go back to step above.
     3.    If rank matches, remove the matching cards and the ones in between.
 •    You win if you remove all cards.

 Implementing dynamic data structures in C using structs and pointers
 Use a C struct to represent each card – the fields
 Use a malloc() call to create space for each card as you read it
 Put these cards into a linked list to play the game
 
 # Sample Input (3 decks):
 TS QC 8S 8D QH 2D 3H KH 9H 2H TH KS KC
 9D JH 7H JD 2S QS TD 2C 4H 5H AD 4D 5D
 6D 4S 9S 5S 7S JS 8H 3D 8C 3S 4C 6S 9C
 AS 7C AH 6H KD JC 7D AC 5C TC QD 6C 3C
 
 
 TS QC 7C AH 6H KD JC 3C
 
 ----------------------------------------------------------------------
 3C 6C 5C JC KD 6H AH 7C AS
 9C 6S 4C 3S 8C 3D 8H JS 7S 5S 9S 4S 6D
 5D 4D AD 5H 4H 2D TD QS 2S JD 7H JH 9D
 KC KS TH 2H 9H KH 3H 2D QH 8D 8S QC TS
 
 
 
 3C JC KD 6H AH 7C AS 9C 6S 4C 3S 8C 3D 8H JS 7S KS TH 2H 3H 2D TS
 ----------------------------------------------------------------------
 
 6C 8D 4D AD 8C 7C JD 5D 7H TD 7D JC 3D
 8H TS 9D KH KC 5S TC QD AC 3H 2S QC 2C
 2D 7S AH 2H 3C 6H 4H KD 4C JS 8S 5C 3S
 KS 5H QH AS 6S 9H 9C TH JH QS 4S 6D 9S

 # Output
 The output for each deck will consist of the cards left after playing.  For the 3 decks above, the correct output would be:
 Remaining cards game 1:
 3C JC KD 6H AH 7C QC TS
 Remaining cards game 2:
 TS 2D 3H 2H TH KS 7S JS 8H 3D 8C 3S 4C 6S 9C AS 7C AH 6H KD JC 3C
 You win game 3!
