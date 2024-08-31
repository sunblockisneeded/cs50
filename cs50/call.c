#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// preferences[i][j] is number of voters who prefer i over j
int preferences[MAX][MAX];

// locked[i][j] means i is locked in over j
bool locked[MAX][MAX];

// Each pair has a winner, loser
typedef struct
{
    int winner;
    int loser;
} pair;

// Array of candidates
string candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, string name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
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
        candidates[i] = argv[i + 1];
    }

    // Clear graph of locked in pairs
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    int voter_count = get_int("Number of voters: ");

    // Query for votes
    for (int i = 0; i < voter_count; i++)
    {
        // ranks[i] is voter's ith preference
        int ranks[candidate_count];

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);

        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

// Update ranks given a new vote
bool vote(int rank, string name, int ranks[])
{
    for (int k = 0; k <candidate_count; k++)
    {
        if (strcmp(name, candidates[k]) == 0 )
        {
            ranks[rank] = k;
            for (int a =0; a< rank ; a++)
            {
                if (ranks[rank] == ranks[a])
                {
                    return false;
                }
            }
            return true;
        }
        else
        {
            return false;
        }
    }

    return;
}

// Update preferences given one voter's ranks
void record_preferences(int ranks[])
{
    for (int a =0; a <candidate_count; a++)
    {
        for (int b = a+1 ; b < candidate_count; b++)
        {
            preferences[ranks[a]][ranks[b]]++;
        }
    }
    return;
}

// Record pairs of candidates where one is preferred over the other
void add_pairs(void)
{
    for(int i = 0; i< candidate_count; i++)
    {
        for(int j = 0; j< candidate_count; j++)
        {
            if(preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].loser = i;
                pairs[pair_count].winner = j;
                pair_count ++;
            }
        }
    }
}

// Sort pairs in decreasing order by strength of victory
void sort_pairs(void)
{
    pair pair1[1];
    for (int i = 0 ; i < n-1 ; i++)
    {
        for(int j = 0; j < n-1-i ;j++)
        {if (preference[pair[j].winner][pair[j].loser] < preference[pair[j+1].winner][pair[j+1].loser] )}
        {
            pair1[0] = pairs[j+1];
            pairs[j+1] = pairs[j];
            pairs[j] = pair1[0];
        }}

    return;
}

bool cycle (int winner, int loser)
{
    if (locked[loser][winner] = true)
    {
        return true;
    }
    for (int i = 0; i< candidate_count; i++)
    {
        if(locked[loser][i] ==true && cycle(winner. i))
        return true;
    }
    return false;
}
// Lock pairs into the candidate graph in order, without creating cycles
void lock_pairs(void)
{
    for (int i = 0 ; i < pair_count ; i++)
    {
        if(!cycle)
        {
            int winner = pairs[i].winner
            int loser = pairs[i].loser
            locked[pairs[i].winner][pairs[i].loser] = ture
        }
    }
    return;
}


// Print the winner of the election
void print_winner(void)
{
    for(int i =0; i< candidate_count; i++)
    {
        for(int j =0; j< candidate_count ; j++)
        {
            if(locked[j][i] == true)

            break;

            if (j == candidate_count -1)
            {
                printf("%s",candidates{i});
            }
        }
    }
    return;
}
