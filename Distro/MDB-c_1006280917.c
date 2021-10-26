/**
 *  CSC A48 - Winter 2020 - Assignment 1 starter
 *
 *  (c) 2020 Francisco Estrada & Joe Armitage 
 *  - No part of this code may be reproduced without written authorization
 *
 * This is the file where you will be doing most of your work. The
 * functionality you must provide for part 1 of the assignment is described
 * in the handout, and given in detail in the comments at the head of each
 * function below.
 *
 * Plan your work carefully, review the notes for Unit 3, and work carefully
 * to complete the functions in this file. At any point you can bring
 * questions to your TAs or instructors during office hours. But please
 * remember:
 *
 * - You should not post any assignment code on Piazza
 * - You should not share any part of your solution in any form
 * - You should definitely *help* other understand any ideas and
 *   concepts regarding linked lists that you have already mastered,
 *   but being careful not to give away parts of the solution, or
 *   descriptions of how to implement functions below.
 * - If you are not sure whether you can or can not discuss some
 *   particular aspect of the work to be done, remember it's always
 *   safe to talk with your TAs.
 * - Obtaining external 'help' including being given code by an
 *   external party, or being tutored on what to write to solve
 *   the assignment constitutes an academic offence.
 *
 * All tasks to be completed by you are clearly labeled with a
 * TODO:
 * comment block, which also gives you details about what you have to implement.
 * Look carefully and make sure you don't miss a thing!
 *
 * NOTE: This file contains no main() function! you can not compile
 * it on its own to create an executable. It's meant to be used
 * together with A1_driver.c - be sure to read that file carefully
 * to understand how to use the tests there - Any additional tests
 * you want to run on the code below should be added to A1_driver.c
 *
 * Before you even get starter implementing, please complete the
 * student identification section below, and check that you are aware
 * of the policy on academic honesty and plagiarism.
 */

/**
 * TODO: STUDENT IDENTIFICATION
 *
 * Student Name (Last name, First name): Arshad, Jawad
 * Student Number: 1006280917
 * UTORid: arshadj4
 * Your instructor's name is: Brian 
 */

/**
 * TODO:
 * Academic Integrity Statement:
 *
 * I hereby certify that the work contained in this file is my own, and
 * that I have not received any parts of my solution from other sources
 * including my fellow students, external tutoring services, the internet,
 * or algorithm implementations found online.
 *
 * Sign here with your name:
 * Jawad Arshad
 *
 */

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR_LEN 1024

/* Compound data type declarations */
/***************************************************************************/
/******                         TODO                                 *******/
/****** In the space below, complete the definitions of the compound *******/
/****** data types that will be needed to implement the movie review *******/
/****** linked list. This includes the MovieReview type, and the     *******/
/****** ReviewNode. Details about the contents of these can be       *******/
/****** found in the assignment handout. Read them carefully!        *******/
/******                                                              *******/
/***************************************************************************/

// Used to store information about the cast of a movie (Implement AFTER everything else)
typedef struct castList_struct
{
	char name[MAX_STR_LEN];
	struct castList_struct *next;
        
} CastList;

// Used to store information about a movie
typedef struct movieReview_struct
{

  // IMPLEMENT THIS FIRST - else the code won't compile
  char movie_title[MAX_STR_LEN];
  char movie_studio[MAX_STR_LEN];
  int year;
  double BO_total;
  int score;
  CastList *cast;
    
} MovieReview;

// Used to store a linked list of MovieReview nodes
typedef struct reviewNode_struct
{

  // IMPLEMENT THIS FIRST - else your code won't compile
  MovieReview review;
  struct reviewNode_struct	*next; 
    
} ReviewNode;

/**
 * Allocates a new, empty ReviewNode, and initializes its contents with the given values.
 *
 * INPUT:
 *  - title: the title of the movie
 *  - studio: the studio where the movie was produced
 *  - year: the year in which the movie was produced
 *  - BO_total: the amount of money this movie grossed at the box office
 *  - score: the average review score given to this movie
 *
 * NOTE: - The *next pointer for the new node MUST be set to NULL
 *
 * RETURN:
 *  - if something goes wrong, return NULL,
 *  - else:
 *      - the newly allocated node, initialized with:
 *          - node.next <- NULL
 *          - node.review:
 *              - movie_title <- title
 *              - movie_studio <- studio
 *              - year <- year
 *              - BO_total <- BO_total
 *              - score <- score
 *              - cast <- NULL
 */
ReviewNode *newMovieReviewNode(char *title, char *studio, int year, double BO_total, int score)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	
	ReviewNode *tempNode;
	tempNode = (ReviewNode *)calloc(1,sizeof(ReviewNode));	
	if (year >= 1920 && year <= 2999 && score >=1 && score <= 100)
	{
		if (tempNode == NULL)
		{
			return NULL;
		}
		else
		{
			tempNode -> next =NULL;
			strcpy(tempNode -> review.movie_title, title);
			strcpy(tempNode -> review.movie_studio, studio);
			tempNode->review.year = year;
			tempNode->review.BO_total = BO_total;
			tempNode->review.score = score;
			tempNode->review.cast = NULL;
		}
		return tempNode;
	}
	else
	{
		//printf("Invalid Inputs\n");
		return NULL;
	}
}
	
/**
 * Finds and returns a ReviewNode containing information that matches the input query:
 *      - title
 *      - studio
 *      - year
 * but if no such ReviewNode exists, returns NULL.
 *
 * INPUT:
 *  - title: the title of the movie
 *  - studio: the studio where the movie was produced
 *  - year: the year in which the movie was produced
 *
 * RETURN:
 *  - if a review matching the query is found:
 *      the node that contains that review.
 *  - else:
 *      NULL
 */
ReviewNode *findMovieReview(char *title, char *studio, int year, ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	ReviewNode *ptr = head;
	 
	while (ptr != NULL)
	{
		//printf("HERE\n\n");
		//printf("Checking :  %s, %s, %d\n", ptr -> review.movie_title, ptr -> review.movie_studio, ptr -> review.year);
		//printf("Find:       %s, %s, %d\n", title, studio, year);
		
		if(strcmp(ptr -> review.movie_title,title) == 0 && strcmp(ptr -> review.movie_studio, studio) == 0 &&  ptr -> review.year == year)
		{
			//printf("HERE2\n\n");
			return ptr;
		}
		ptr = ptr -> next;
	}
	return NULL;  // Remove this before you implement your solution!
}

/**
 * Inserts a new movie review into the linked list, if it does not exist already.
 *
 * INPUT:
 *  - title: the title of the movie
 *  - studio: the studio where the movie was produced
 *  - year: the year in which the movie was produced
 *  - BO_total: the amount of money this movie grossed at the box office
 *  - score: the average review score given to this movie
 *
 * OUTPUT: - head: the (potentially new) head of the linked list of reviews
 *
 * RETURN: - the (potentially new) head node of the linked list
 *
 * NOTE:
 *  - If head == NULL, then the list is still empty
 *  - Inserts the new movie review *at the head* of the linked list
 *  - MUST check that the movie is not already in the list before inserting (there should be no
 *      duplicate entries). If a movie with matching title, studio, and year is already in the list,
 *      nothing is inserted and the function returns the current list head.
 */
ReviewNode *insertMovieReview(char *title, char *studio, int year, double BO_total, int score,
                              ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function **********************************/
    /***************************************************************************/
	//printf("\nBoi\n");
	ReviewNode *npt = newMovieReviewNode(title, studio, year, BO_total, score);
	ReviewNode *pointer = head;
	//printf("here\n");
	
	//printf("%p %p\n", head, npt);
	if (npt != NULL)
	{
		if(head == NULL){
			head = npt;
			//printf("%p %p\n", head, npt);
			//printf("hi\n");
		}
		else
		{	
			ReviewNode *exist = findMovieReview(title, studio, year, head);
			//printf("%p %s\n" , exist, exist);
			if(exist != NULL)
			{
				//printf("%p %p %p\n", head, npt, pointer);
				printf("Sorry, that movie already exists\n");
				//return pointer;
			}
			else
			{
				while (pointer != NULL)
				{
					pointer = pointer -> next;
				}
				npt->next=head;
				head = npt;
			}
		}
	}
		
    return head;  // Remove this before you implement your solution!
}

/**
 * Returns the length of the linked list that begins at head.
 *
 * INPUT: - head: the start of a linked list
 *
 * RETURN: - the number of elements in this linked list
 */
int countReviews(ReviewNode *head)
{
    /***************************************************************************/
    /****************** TODO: Complete this function ***************************/
    /***************************************************************************/
	ReviewNode *ptr = head;
	
	int count = 0;
	while (ptr != NULL)
	{
		ptr = ptr -> next;
		count++;
	}

    return count;  // Remove this before you implement your solution
}

/**
 * Updates the review matching the input query:
 *  - title
 *  - studio
 *  - year
 * with new BO_total and score.
 *
 * If no such review is found, the function prints out: "Sorry, no such movie exists at this point"
 *
 * INPUT:
 *  - title: the title of the movie
 *  - studio: the studio where the movie was produced
 *  - year: the year in which the movie was produced
 *  - BO_total: the amount of money this movie grossed at the box office
 *  - score: the average review score given to this movie
 *
 * OUTPUT:
 *  - head: the (potentially new) head of the linked list of reviews
 *  - error message to the terminal, if no node is found matching given [title, studio, year] query
 */
void updateMovieReview(char *title, char *studio, int year, double BO_total, int score,
                       ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	ReviewNode *pointer = findMovieReview(title, studio, year, head);
	
	if(pointer == NULL){
		printf("Sorry, no such movie exists at this point \n");
	}
	else
	{
		pointer -> review.BO_total = BO_total;
		pointer -> review.score = score;
		
	}

}

/**
 * Removes a review matching the input query from the linked list, if such review can be found.
 *
 * INPUT:
 *  - title: the title of the movie
 *  - studio: the studio where the movie was produced
 *  - year: the year in which the movie was produced
 *
 * OUTPUT: - head: the (potentially new) head node of the linked list
 * RETURN: - the (potentially new) head node of the linked list
 */
ReviewNode *deleteMovieReview(char *title, char *studio, int year, ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	
	ReviewNode *pointer = head;
	ReviewNode *follower = NULL;
	
	ReviewNode *want = findMovieReview(title, studio, year, head);
	if(want != NULL){
		while (pointer != want)
		{
			follower = pointer;
			pointer = pointer -> next;
		}
		if (follower == NULL)
		{
			follower = pointer -> next;
			head = follower;
		}
		else
		{
			follower -> next = pointer -> next;
		}
		free(pointer);
	}
	else 
	{
		//printf("That moive review does not exist\n");
	}
	
    return head;  // Remove this before implementing your solution
}

/**
 * Prints out all the reviews in the linked list and returns the sum of all the box office totals
 * for all stored movie reviews.
 *
 * INPUT: - the head node of the linked list
 *
 * RETURN: - the BOX OFFICE TOTAL, for all movies
 *
 * NOTE:
 *  - Each field in the review is printed in a separate line, with *no additional text*
 *  - The only thing printed is the value of the corresponding field
 *  - Reviews are separated from each other by a line of "*******************"
 *    whose length is irrelevant, as long as it is >= 2
 *  - See the Assignment handout for a sample of the output that should be produced by this function
 */
double printMovieReviews(ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	double total = 0;
	ReviewNode *pointer = head;
	
	if(head != NULL)
	{
		while(pointer != NULL)
		{
			printf("%s\n", pointer ->review.movie_title);
			printf("%s\n", pointer ->review.movie_studio);
			printf("%d\n", pointer ->review.year);
			printf("%f\n", pointer ->review.BO_total);
			printf("%d\n", pointer ->review.score);
			printf("***********************\n");
			total = total + pointer ->review.BO_total;
			
			pointer = pointer -> next;
		}
	}
	else
	{
		//printf("There are no movies in the database\n");
	}
	
    return total;  // Remove this before you implement your solution
}

/**
 * Prints out all the reviews in the linked list which share the production studio given by studio
 * and then returns the sum of all the box office totals for these such stored movie reviews.
 *
 * INPUT: - the head node of the linked list
 *
 * RETURN:
 *  - the BOX OFFICE TOTAL, for all the movies that match the query
 *  - the studio attribute of the query: only print and count nodes matching this studio
 *
 * NOTE:
 *  - Each field in the review is printed in a separate line, with *no additional text*
 *  - The only thing printed is the value of the corresponding field
 *  - Reviews are separated from each other by a line of "*******************"
 *    whose length is irrelevant, as long as it is >= 2
 *  - See the Assignment handout for a sample of the output that should be produced by this function
 */
double queryReviewsByStudio(char *studio, ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	double total = 0;
	ReviewNode *pointer = head;
	bool found = false;
	
	
	while(pointer != NULL && strcmp(pointer -> review.movie_studio, studio) == 0)
	{
		found = true;
		printf("%s\n", pointer ->review.movie_title);
		printf("%s\n", pointer ->review.movie_studio);
		printf("%d\n", pointer ->review.year);
		printf("%f\n", pointer ->review.BO_total);
		printf("%d\n", pointer ->review.score);
		printf("***********************\n");
		total = total + pointer ->review.BO_total;
		
		pointer = pointer -> next;
	}
	if(found == false)
	{
		//printf("There are no movies in the database form that studio\n");
	}
	

    return total;   // Remove this before you implement your solution
}

/**
 * Prints out the contents of all reviews whose score is greater than, or equal to min_score.
 *
 * INPUT: - the head node of the linked list
 *
 * RETURN:
 *  - the BOX OFFICE TOTAL, for all the movies that match the query
 *  - the minimum score attribute of the query: only print and count nodes above this score
 *
 * NOTE:
 *  - Each field in the review is printed in a separate line, with *no additional text*
 *  - The only thing printed is the value of the corresponding field
 *  - Reviews are separated from each other by a line of "*******************"
 *    whose length is irrelevant, as long as it is >= 2
 *  - See the Assignment handout for a sample of the output that should be produced by this function
 */
double queryReviewsByScore(int min_score, ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	double total = 0;
	ReviewNode *pointer = head;
	bool found = false;
	
	while(pointer != NULL && pointer -> review.score >= min_score)
	{
		found = true;
		printf("%s\n", pointer ->review.movie_title);
		printf("%s\n", pointer ->review.movie_studio);
		printf("%d\n", pointer ->review.year);
		printf("%f\n", pointer ->review.BO_total);
		printf("%d\n", pointer ->review.score);
		printf("***********************\n");
		total = total + pointer ->review.BO_total;
		
		pointer = pointer -> next;
	}
	if(found == false)
	{
		//printf("There are no movies in the database with a score higher that %d\n", min_score);
	}
	
	

    return total;  // Remove this before you implement your solution
}

/**
 * Deletes the linked list of movie reviews, releasing the memory allocated to each node.
 *
 * INPUT: - the head node of the linked list
 *
 * RETURN: - a NULL pointer (so that the head of the list can be set to NULL after deletion)
 */
ReviewNode *deleteReviewList(ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	ReviewNode *pointer = head;

	while(head != NULL)
	{
		head = head -> next;
		free(pointer);
		pointer = head;
	}

    return head;  // Remove this before you implement your solution
}

/////////////////////////////////////////////////////////////////////////////////////////////
// CRUNCHY SECTION!
// Do not work on the functions below until your A1 is working properly and is fully tested!
/////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Sorts the list of movie reviews in ascending order of movie title.
 * If duplicate movie titles exist, the order is arbitrary (i.e. you choose which one goes first).
 *
 * INPUT: - the head of the unsorted list.
 * OUTPUT: - the head of the sorted list.
 * RETURN: - the head of the sorted list.
 */
ReviewNode *sortReviewsByTitle(ReviewNode *head)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	//printf("h1\n");
	int len = countReviews(head);
	int count = 0;

	 while (count != len)
	{
		ReviewNode *pointer_a = head;
		ReviewNode *pointer_b = NULL; 
		
		//printf("count %d\n", count);
		while(pointer_a != NULL)
		{
			
		
			//printf("h5\n");
			//printf("%s --- %s\n\n" , pointer_a -> review.movie_title, pointer_b -> review.movie_title);
			
			if (pointer_b != NULL && (strcmp(pointer_a -> review.movie_title, pointer_b -> review.movie_title) < 0))
			{
				
				char temp_movie_title[MAX_STR_LEN];
				char temp_movie_studio[MAX_STR_LEN];
				int temp_year;
				double temp_BO_total;
				int temp_score;
				CastList *temp_cast;
				
				/* printf("%s\n", temp_movie_title);
				printf("%s\n", temp_movie_studio);
				printf("%d\n", temp_year);
				printf("%f\n", temp_BO_total);
				printf("%d\n", temp_score);
				printf("%p\n", temp_cast);
				printf("\n");
				
				printf("%s\n", pointer_a -> review.movie_title);
				printf("%s\n", pointer_a -> review.movie_studio);
				printf("%d\n", pointer_a -> review.year);
				printf("%f\n", pointer_a -> review.BO_total);
				printf("%d\n", pointer_a -> review.score);
				printf("%p\n", pointer_a -> review.cast);
				printf("\n");
				
				printf("%s\n", pointer_b -> review.movie_title);
				printf("%s\n", pointer_b -> review.movie_studio);
				printf("%d\n", pointer_b -> review.year);
				printf("%f\n", pointer_b -> review.BO_total);
				printf("%d\n", pointer_b -> review.score);
				printf("%p\n", pointer_b -> review.cast);
				printf("\n"); */
				
				
				
				strcpy(temp_movie_title, pointer_a -> review.movie_title);
				strcpy(temp_movie_studio, pointer_a -> review.movie_studio);
				temp_year = pointer_a -> review.year;
				temp_BO_total = pointer_a -> review.BO_total;
				temp_score = pointer_a -> review.score;
				temp_cast = pointer_a -> review.cast;
			
				
				strcpy(pointer_a -> review.movie_title, pointer_b -> review.movie_title);
				strcpy(pointer_a -> review.movie_studio, pointer_b -> review.movie_studio);
				pointer_a -> review.year = pointer_b -> review.year;
				pointer_a -> review.BO_total = pointer_b -> review.BO_total;
				pointer_a -> review.score = pointer_b -> review.score;
				pointer_a -> review.cast = pointer_b -> review.cast;
				
				
				strcpy(pointer_b -> review.movie_title, temp_movie_title);
				strcpy(pointer_b -> review.movie_studio, temp_movie_studio);
				pointer_b -> review.year = temp_year;
				pointer_b -> review.BO_total = temp_BO_total;
				pointer_b -> review.score = temp_score;
				pointer_b -> review.cast = temp_cast;
				
				/* printf("*******\n");
				
				printf("%s\n", temp_movie_title);
				printf("%s\n", temp_movie_studio);
				printf("%d\n", temp_year);
				printf("%f\n", temp_BO_total);
				printf("%d\n", temp_score);
				printf("%p\n", temp_cast);
				printf("\n");
				
				printf("%s\n", pointer_a -> review.movie_title);
				printf("%s\n", pointer_a -> review.movie_studio);
				printf("%d\n", pointer_a -> review.year);
				printf("%f\n", pointer_a -> review.BO_total);
				printf("%d\n", pointer_a -> review.score);
				printf("%p\n", pointer_a -> review.cast);
				printf("\n");
				
				printf("%s\n", pointer_b -> review.movie_title);
				printf("%s\n", pointer_b -> review.movie_studio);
				printf("%d\n", pointer_b -> review.year);
				printf("%f\n", pointer_b -> review.BO_total);
				printf("%d\n", pointer_b -> review.score);
				printf("%p\n", pointer_b -> review.cast);
				printf("\n"); */
							
			}
			
			
			pointer_b = pointer_a;
			pointer_a = pointer_a -> next;
			//printf("1");
		
		}
		
	 	//printf("2");
		
		count++;
		
	} 
	
	

    return head;  // Remove this before you implement your solution
}

/**
 * Inserts the name of a cast member into the linked list of cast members, matching the input query:
 *  - title
 *  - studio
 *  - year
 * if a match is found; else, does nothing.
 *
 * INPUT:
 *  - title: the title of the movie
 *  - studio: the studio where the movie was produced
 *  - year: the year in which the movie was produced
 *  - head: the head node of the linked list
 *  - name: the name of the cast member being inserted
 *
 * OUTPUT: - the (internally modified) linked list of ReviewNodes, starting at head
 *
 * NOTE:
 *  - Duplicate names are allowed - this time!
 */
void insertCastMember(char *title, char *studio, int year, ReviewNode *head, char *name)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	
	ReviewNode *pointer_moive = findMovieReview(title, studio, year, head);
	//printf("%p\n", pointer_moive);
	if (pointer_moive != NULL)
	{
		//printf("\n\n\n\n\n\n");
		CastList *cast_head = pointer_moive -> review.cast;
		CastList *pointer = NULL;
		pointer = (CastList *) calloc(1, sizeof(CastList));
		//printf("%p --- %p --- %p\n", cast_head, pointer, pointer ->next);
		
		if (cast_head ==NULL)
		{
			
		}
		
		strcpy(pointer -> name, name);
		
		pointer -> next = cast_head;
		//printf("%p --- %p --- %p\n", cast_head, pointer, pointer ->next);
		cast_head = pointer;	
		//printf("%p --- %p --- %p\n", cast_head, pointer, pointer ->next);
		pointer_moive -> review.cast = cast_head;
	}
	else if (pointer_moive == NULL)
	{
		//printf("That Moive does't exist, try again.\n");
		
	}

}

/**
 * Counts how many actors have names containing the input parameter "name".
 *
 * INPUT:
 *  - movie: the movie from which the cast is to be searched
 *  - name: the name to be searched for in the cast list of this movie
 *
 * RETURN: - number of cast members of this movie that contain the substring "name".
 *
 * EXAMPLE:
 * If the input name is "Joe", and the cast list contains
 * - Joe Cool
 * - Notajoe Jones
 * - OneJoe Smith
 * - Last Name Joe
 * then the function will return 3 (actor names 1, 3, and 4 contain 'Joe').
 *
 * NOTE: The case of each character MUST match (the J must be a capital letter in the above example
 * for the match to count)
 */
int countNames(MovieReview *movie, char *name)
{
    /***************************************************************************/
    /**********  TODO: Complete this function *********************************/
    /***************************************************************************/
	
	int count_names = 0;
	int len = strlen(name);
	CastList *pointer = movie -> cast; 
	
	while (pointer != NULL)
	{
		int i = 0;
		bool found = false;
		//printf("%s -- %s\n",pointer -> name, name);
		while(pointer -> name[i] != '\0' && i <= strlen(pointer -> name) - len && found == false)
		{
			int count = 0;
			for(int j = i; j < i + len; j++)
			{
				//printf("%c -- %c\n",pointer -> name[j], name [j-i]);
				if(pointer -> name[j] == name [j-i])
				{
					count++;
				}
				if (count == len)
				{
					found = true;
				}
			}
			//printf("\n\n");
			i++;
		}
		if(found == true)
		{
			count_names++;
		}
		pointer = pointer -> next;
	}

				/* for(int k = 0; k < len; k++)
				{
					printf("%c -- %c\n",pointer -> name[j], name [k]);
					if(pointer -> name[j] == name [k])
					{
						count++;
					}
					if (count == len)
					{
						found = true;
					}
				} */
    return count_names;  // Remove this when you start working on your solution
}

// Prints out names of cast members for this movie - use it to help you debug
// UN-COMMENT this function AFTER you've implemented the cast list CDT, or
// you will get compiler errors!

void printNames(ReviewNode *head)
{
    if (NULL == head || NULL == head->review.cast) return;
    printf("The cast for this movie are:\n");
    for (CastList *p = head->review.cast; NULL != p; p = p->next) printf("%s\n", p->name);
}
