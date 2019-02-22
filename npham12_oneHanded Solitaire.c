/*One-Handed Solitaire*/
/*Nguyen Pham*/

/*The program takes as input decks of cards, playing one-handed solitaire on each deck.
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
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 52
typedef struct Node{
	char *data;
	struct Node *next, *pre;}Node_rec, *Node_ptr;

struct Node *dummy();
void print_list(Node_ptr list);
Node_ptr add_to_head(Node_ptr curs, char *val);

/*Create a dummy node in front of 1st node to mark the head point*/
struct Node *dummy(){
	Node_ptr newNode = (Node_ptr)malloc(sizeof(Node_rec)); /* create a new node*/
	newNode -> data = malloc(2*sizeof(char *) + 1);
        newNode->next=NULL;
        newNode->pre=NULL;
        return newNode;}
  
/* add new node to head*/
Node_ptr add_to_head(Node_ptr curs, char *val){
	Node_ptr newNode = dummy();
	strcpy((newNode -> data), val);	/*copy data from val to newNode*/
	newNode -> next = curs;
	if(curs != NULL)	// If newNode is not the first node.
		curs -> pre = newNode;
	return newNode;}

/*delete nodes*/
void freeNodes(Node_ptr start, Node_ptr end){
	while(1){
	/*delete nodes until from 2 set node*/
             if(start -> next != end){
		start = start -> next;
		free(start -> pre -> data);
		free(start -> pre);}
	     else{
		free(start->data);
		free(start);
                break;}}
   	if(end!=NULL){/*free itself if it is NULL-> no more nodes*/
    		free(end->data);
		free(end);}}

/*display the deck*/
void print_list(Node_ptr list){
	while (list != 0){
		printf("%s ", list -> data);
		list = list -> next;}
	printf("\n\n");}

/*MATCH CASE*/
void match (Node_ptr list){
 Node_ptr curs1, curs2, start, end;
  curs1 = list;
  curs2 = list;
  /*move curs2 to 4th node from 1st node*/
  int i;
  for(i = 0; i < 3; i++)
  	curs2 = curs2->next;
  int distance=4; /*4 nodes from curs1 to curs2*/	

  while(curs2!=NULL){                         
  /*RANK MATCH*/
   if(distance==4 &&(*(curs1->data)) == (*(curs2->data)))/*xx0000x*/
   {
  	/*Move curs1 and curs2 out of the 4 nodes will be deleted*/
  	curs1->pre->next = curs2->next;
        if(curs2->next!=NULL)
             curs2->next->pre = curs1->pre;
        /*create a end pointer a position of curs2 in rank case*/
     	end = curs2;
        curs2 = curs2 -> next;
        freeNodes(curs1,end); /*delete 4 nodes between curs1 and end*/ 
        curs1 = curs2; 		
  	distance = 1;/*curs1 and curs2 are in the same node*/	
  	/*free all pointers when it in the end of the list*/
  	if(curs2 == NULL){
        free(curs1);
        free(curs2);}}
     
     /*SUIT MATCH*/
     else if (distance==4 && (*(curs1->data + 1)) == (*(curs2->data + 1))){
	/*create 2 pointers point to 2 nodes will be deleted*/
        start = curs1-> next;
        end = curs2 -> pre;
        /*link nodes at curs1 and 2*/
	curs1->next = curs2;         
	curs2->pre = curs1;
	/*delete 2 middle nodes*/
        freeNodes(start,end);
        distance=2;/*2 nodes from curs1 to curs2*/}

    /*NO MATCH*/
     else{
    	    if(distance == 4){ 
    	    	    if(curs2 -> next!=NULL)
    	    	    	    curs1 = curs1 -> next; /*move curs1 to next node*/
    	    	    if(curs2 != NULL)
    	    	    	    curs2 = curs2 -> next; /*move curs2 to next node, may be NULL*/
    	    	    else/*finish a game when curs2 is NULL*/
      	     		 break;}
      	    else{
      	    	    while(distance < 4){
      	    	    	    /*2 nodes in front of curs1 -> move curs1 back 2 nodes*/
      	    	    	    if(curs1 != NULL && curs1 -> pre -> pre != NULL)
      	    	    	    	    curs1= curs1->pre;
      	    	    	    else 
      	    	    	    	    break;
      	    	    	    distance++;/*precondition for curs2 move forward some nodes*/
      	    	    }
      	    	    while(distance < 4){
      	    	    	    /*move curs2 to some nodes to maintain 4 nodes with curs1*/
      	    	    	    if(curs2 != NULL) 
      	    	    	    	    curs2= curs2->next;
      	    	    	    else
      	    	    	    	    break;
      	    	    	    distance++;}
      	    	   if(curs2 == NULL) /*no more nodes*/
      	    	   	   break;}}}}
      	    	   
main(int argc, char **argv){
  /*Read data from file deck*/
 FILE *input_file;
 char filename[32], val[3];
 
  if (argc<=1) {printf("Usage: %s <filename>\n",argv[0]); exit(2);}
  int j = 1;
  if ((input_file = fopen(argv[j],"r")) == NULL){
     printf("Unknown file: %s\n",argv[j]); exit(3);}  
     
  /*Game*/
  int i, game = 0;
  while(!0){
  	  Node_ptr list = NULL;
  	  /*get value from a file and put it in value of a node*/
  	  for(i = 0; i < N; i++){ 
  	  	  if(fscanf(input_file, "%s", val) == 1)
  	  	  	  list = add_to_head(list ,val);
  	  	  /*Not enough 52 cards on a deck*/
  	  	   else{
  	  	  	  if(i > 0)
  	  	  	  	  printf("Can't play the game\n");
  	  	  	  /*free cards on the error game*/
  	  	  	  if(list != NULL)
  	  	  	  	  freeNodes(list,NULL);
  	  	  	  fclose(input_file);      
  	  	  	  return 1;}}
  	  game++;
  	  printf("Deck of Game %d:\n", game);
  	  print_list(list);
  	  Node_ptr dum = dummy();
  	  /*define dum Node in front of the 1st node of the list*/
  	  dum -> next = list;
  	  list->pre = dum;
  	  /*check match*/
  	  match(list);
  	  /*output remaining cards on a game*/
  	  if(dum -> next != NULL){
  	  	printf("Remaining cards on game %d:\n", game);   
  	  	print_list(list);}
  	  else
  	  	  printf("You win the game\n");  
  		  freeNodes(dum,NULL);}

 return 0;}
