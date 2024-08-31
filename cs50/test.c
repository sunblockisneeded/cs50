#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;
int voter_count;
// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name)) // ! : 논리 부정 연산자
        {
            printf("Invalid vote.\n");
        }
        if (vote(name))
        {
        candidates[i].votes++;
        }

    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int i = 0 ; i < voter_count ; i++)
    {
    if (strcmp(name, candidates[i].name ) == 0 )
    {
        return true;
    }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int arr1[1] = {0}; //bubble 정렬
    for (int i = 0 ; i < candidate_count-1 ; i++)
    {
        for(int j = 0; j < candidate_count-1-i ;j++)
        {
            if (candidates[j].votes < candidates[j+1].votes)
        {
            arr1[0] = candidates[j+1].votes;
            candidates[j+1].votes = candidates[j].votes;
            candidates[j].votes = arr1[0];
        }}
    }
    for (int i = 0 ; i < candidate_count ; i++)
    {
        for(int j = i+1 ; j < candidate_count ; j++)
        {
            if (candidates[i].votes == candidates[j].votes)
            {
                printf("%s\n",candidates[i].name);
            }
        }
    }
    printf("%s\n",candidates[0].name);
    return;
}

