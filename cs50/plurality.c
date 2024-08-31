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
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    for (int k = 0; k < candidate_count; k++) // 0부터 유권자수 끝까지 입력과 일치하는 값 있는지 검사
    {
        if (strcmp(name, candidates[k].name) == 0)
        {
            candidates[k].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    candidate arr[1];
    for (int i = 0; i < candidate_count - 1; i++)
    {
        for (int j = 0; j < candidate_count - 1 - i; j++)
        {
            if (candidates[j].votes < candidates[j + 1].votes)
            {
                arr[0] = candidates[j + 1];
                candidates[j + 1] = candidates[j];
                candidates[j] = arr[0];
            }
        }
    }

    int c = 0; //print winner
    do
    {
        printf("%s\n", candidates[c].name);
        c++;
    }
    while (candidates[c - 1].votes == candidates[c].votes);
    return;
}
