#include <iostream>

#include <ctime>

#include <cstdlib>

using namespace std;

struct BowlerClass
{
    int bowlerIndex;
    string bowlerName;
    int TotalRunsGave;
    int TotalWicketstaken;
    float totalBallsBowled;
    struct BowlerClass * next;
};
typedef struct BowlerClass * Bowler;
Bowler firstBowler = new BowlerClass;
Bowler firstBowlerr = new BowlerClass;

class Cricket_team
{
public:
    string team_name;
    bool isBatting;
    bool isBowling;
    int total_runs;
    int total_wickets;
    string playerName[11];

public:
    void get_teamName(string firstOrSecond)
    {
        cout << "What is the name of " << firstOrSecond << " team : ";
        cin >> this -> team_name;
    }
    int get_totalRuns(int runs)
    {
        this -> total_runs = runs;
        return runs;
    }
    int get_totalWickets(int wickets)
    {
        this -> total_wickets = wickets;
        return wickets;
    }

};

class Cricket_match
{
public:
    int number_of_overs;
    Cricket_team t1;
    Cricket_team t2;
    int target;
public:
    void get_numberOfOvers()
    {
        cout << "How many overs this cricket match contains : ";
        cin >> this -> number_of_overs;
    }
    int returnNoOfOvers()
    {
        return this -> number_of_overs;
    }
};

int show_overs(int number_of_overs, Cricket_team t3, Cricket_team t4, Cricket_match match);
int show_overs_2(int number_of_overs, Cricket_team t3, Cricket_team t4, Cricket_match match, int target_runs);
void target_reveal(int number_of_overs, int target, Cricket_team t3, Cricket_team t4);
void show_batter_details();
void show_bowler_details();

int main()
{
    Cricket_match match;
    Cricket_team t1, t2;

    cout << endl;
    match.get_numberOfOvers();
    t1.get_teamName("first");
    t2.get_teamName("second");

    for (int i = 0; i < 11; i++)
    {
        t1.playerName[i] = t1.team_name + " player " + to_string(i + 1);
    }

    for (int i = 0; i < 11; i++)
    {
        t2.playerName[i] = t2.team_name + " player " + to_string(i + 1);
    }

    system("cls");
    srand(time(0));
    int k = (rand() % 60) + 1;
    if (k <= 30)
    {
        cout << t1.team_name << " won the toss and chose batting.";
        // battingNow.team_name=t1.team_name;
        cout << endl << endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;
        t1.isBatting = true;
        t2.isBatting = false;
        t1.isBowling = false;
        t2.isBowling = true;
    }
    else
    {
        cout << t2.team_name << " won the toss and chose batting.";
        cout << endl << endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;
        t2.isBatting = true;
        t1.isBatting = false;
        t2.isBowling = false;
        t1.isBowling = true;

    }

    cout << endl;
    int target_match1, target_match2;
    if (t1.isBatting == true && t2.isBatting == false)
    {
        target_match1 = show_overs(match.returnNoOfOvers(), t1, t2, match);
        target_reveal(match.returnNoOfOvers(), target_match1, t1, t2);
        match.target = target_match1;
        t1.isBatting = false;
        t2.isBatting = true;
        t1.isBowling = true;
        t2.isBowling = false;
    }
    else if (t2.isBatting == true && t1.isBatting == false)
    {
        target_match1 = show_overs(match.returnNoOfOvers(), t2, t1, match);
        target_reveal(match.returnNoOfOvers(), target_match1, t2, t1);
        match.target = target_match1;
        t2.isBatting = false;
        t1.isBatting = true;
        t2.isBowling = true;
        t1.isBowling = false;
    }

    if (t1.isBatting == true && t2.isBatting == false)
    {
        cout << endl << t1.team_name << " is batting." << endl;
        cout << endl << endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;
        target_match2 = show_overs_2(match.returnNoOfOvers(), t1, t2, match, target_match1);
        if (target_match1 > target_match2)
        {
            cout << t2.team_name << " won the match" << endl;
        }
        else if (target_match1 == target_match2)
        {
            cout << "The match become draw." << endl;
        }
        else
        {
            cout << t1.team_name << " won the match" << endl;
        }
    }
    else if (t2.isBatting == true && t1.isBatting == false)
    {
        cout << endl << t2.team_name << " is batting." << endl;
        cout << endl << endl << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -" << endl << endl;
        target_match2 = show_overs_2(match.returnNoOfOvers(), t2, t1, match, target_match1);
        if (target_match1 > target_match2)
        {
            cout << t1.team_name << " won the match" << endl;
        }
        else if (target_match1 == target_match2)
        {
            cout << "The match become draw." << endl;
        }
        else
        {
            cout << t2.team_name << " won the match" << endl;
        }
    }

    return 0;
}

int show_overs(int number_of_overs, Cricket_team t3, Cricket_team t4, Cricket_match match)
{
    int noOfBowlers;
    firstBowler = NULL;
    cout << "enter number of bowlers in team 1: " << endl;
    cin >> noOfBowlers;
    int total_runs = 0;
    int total_wickets = 0;
    Bowler ccheckPtr = new BowlerClass;
    Bowler ptr = new BowlerClass;
    ptr = NULL;
    ccheckPtr = NULL;
    for (int i = 1; i <= number_of_overs; i++)
    {
        int sum_runs_per_over;
        Bowler newBowler = new BowlerClass;
        newBowler -> bowlerIndex = NULL;
        if (firstBowler == NULL)
        {
            firstBowler = newBowler;
            newBowler -> bowlerIndex = 1;
            newBowler -> bowlerName = "1-Bowler ( " + t4.team_name + "team )";
        }
        else
        {

            ptr = firstBowler;
            while (ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }

            if (ptr -> bowlerIndex < noOfBowlers)
            {
                ptr -> next = newBowler;
                newBowler -> bowlerIndex = ptr -> bowlerIndex + 1;
                int index = newBowler -> bowlerIndex;
                newBowler -> bowlerName = to_string(index) + "-Bowler ( " + t4.team_name + "team )";
            }
            else
            {
                if (ccheckPtr == NULL)
                {
                    ccheckPtr = firstBowler;
                }

            }

        }
        cout << i << " over : " << endl;
        sum_runs_per_over = 0;
        int sum_wickets_per_over = 0;

        for (int j = 1; j <= 6; j++)
        {
            int k = (rand() % 100) + 1;
            int sum_runs_per_ball = 0;

            int sum_wickets_per_ball = 0;
            if (k <= 35)
            {
                cout << "1 ";
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
            }
            else if (k > 35 && k <= 55)
            {
                cout << "0 ";
            }
            else if (k > 55 && k <= 70)
            {
                cout << "wde ";
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                j--;
            }
            else if (k > 70 && k <= 80)
            {
                cout << "6 ";
                sum_runs_per_ball += 6;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
            }
            else if (k > 80 && k <= 90)
            {
                cout << "4 ";
                sum_runs_per_ball += 4;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
            }
            else
            {
                cout << "wkt ";
                sum_wickets_per_ball++;
                total_wickets += sum_wickets_per_ball;
                sum_wickets_per_over++;
                if (total_wickets == 10)
                {
                    break;
                }

            }

        }
        if (ccheckPtr == NULL)
        {
            newBowler -> TotalRunsGave = sum_runs_per_over;
            newBowler -> totalBallsBowled = 1;
            newBowler -> TotalWicketstaken = sum_wickets_per_over;
            cout << endl << "now bowling : " << newBowler -> bowlerName << endl;
            cout << "total runs gave by this bowler : " << newBowler -> TotalRunsGave << endl;
            cout << "total overs by this bowler : " << newBowler -> totalBallsBowled << endl;
            cout << "total wickets taken by this bowler : " << newBowler -> TotalWicketstaken << endl << endl;

        }
        else
        {
            ccheckPtr -> TotalRunsGave = ccheckPtr -> TotalRunsGave + sum_runs_per_over;
            ccheckPtr -> totalBallsBowled += 1;
            ccheckPtr -> TotalWicketstaken += sum_wickets_per_over;
            cout << endl << "now bowling : " << ccheckPtr -> bowlerName << endl;
            cout << "total runs gave by this bowler : " << ccheckPtr -> TotalRunsGave << endl;
            cout << "total overs by this bowler : " << ccheckPtr -> totalBallsBowled << endl;
            cout << "total wickets taken by this bowler : " << ccheckPtr -> TotalWicketstaken << endl << endl;
            if (ccheckPtr -> bowlerIndex >= noOfBowlers)
            {
                ccheckPtr = firstBowler;
            }
            else
            {
                ccheckPtr = ccheckPtr -> next;
            }
        }

        t3.total_runs = total_runs;
        t4.total_wickets = total_wickets;
        cout << endl << "total runs taken by " << t3.team_name << " at the end of " << i << " over : " << t3.total_runs << endl;
        cout << "total wickets taken by " << t4.team_name << " at the end of " << i << " over : " << t4.total_wickets << endl << endl;

    }

    firstBowler = NULL;
    return t3.total_runs + 1;
}

int show_overs_2(int number_of_overs, Cricket_team t3, Cricket_team t4, Cricket_match match, int target_runs)
{

    int noOfBowlers;
    firstBowlerr = NULL;
    cout << "enter number of bowlers in team 1: " << endl;
    cin >> noOfBowlers;
    int total_runs = 0;
    int total_wickets = 0;

    Bowler checkPtr = new BowlerClass;
    Bowler ptrr = new BowlerClass;
    ptrr = NULL;
    checkPtr = NULL;
    for (int i = 1; i <= number_of_overs; i++)
    {
        int sum_runs_per_over;
        Bowler newwBowler = new BowlerClass;
        newwBowler -> bowlerIndex = NULL;
        if (firstBowlerr == NULL)
        {
            firstBowlerr = newwBowler;
            newwBowler -> bowlerIndex = 1;
            newwBowler -> bowlerName = "1-Bowler ( " + t4.team_name + "team )";
            firstBowlerr -> next = NULL;
        }
        else
        {
            ptrr = firstBowlerr;
            while (ptrr -> next != NULL)
            {
                ptrr = ptrr -> next;
            }

            if (ptrr -> bowlerIndex < noOfBowlers)
            {
                ptrr -> next = newwBowler;
                newwBowler -> bowlerIndex = ptrr -> bowlerIndex + 1;
                int index = newwBowler -> bowlerIndex;
                newwBowler -> bowlerName = to_string(index) + "-Bowler ( " + t4.team_name + "team )";

            }
            else
            {
                if (checkPtr == NULL)
                {
                    checkPtr = firstBowlerr;
                }

            }

        }
        cout << i << " over : " << endl;
        sum_runs_per_over = 0;

        int sum_wickets_per_over = 0;

        for (int j = 1; j <= 6; j++)
        {
            int k = (rand() % 100) + 1;
            int sum_runs_per_ball = 0;
            int sum_wickets_per_ball = 0;
            if (k <= 35)
            {
                cout << "1 ";
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else if (k > 35 && k <= 55)
            {
                cout << "0 ";
            }
            else if (k > 55 && k <= 70)
            {
                cout << "wde ";
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                j--;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else if (k > 70 && k <= 80)
            {
                cout << "6 ";
                sum_runs_per_ball += 6;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else if (k > 80 && k <= 90)
            {
                cout << "4 ";
                sum_runs_per_ball += 4;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else
            {
                cout << "wkt ";
                sum_wickets_per_ball++;
                total_wickets += sum_wickets_per_ball;
                sum_wickets_per_over++;
                if (total_wickets == 10)
                {
                    break;
                }

            }

        }
        if (checkPtr == NULL)
        {
            newwBowler -> TotalRunsGave = sum_runs_per_over;
            newwBowler -> totalBallsBowled = 1;
            newwBowler -> TotalWicketstaken = sum_wickets_per_over;
            cout << endl << "now bowling : " << newwBowler -> bowlerName << endl;
            cout << "total runs gave by this bowler : " << newwBowler -> TotalRunsGave << endl;
            cout << "total overs by this bowler : " << newwBowler -> totalBallsBowled <<  endl;
            cout << "total wickets taken by this bowler : " << newwBowler -> TotalWicketstaken  << endl;

        }
        else
        {
            checkPtr -> TotalRunsGave = checkPtr -> TotalRunsGave + sum_runs_per_over;
            checkPtr -> totalBallsBowled += 1;
            checkPtr -> TotalWicketstaken += sum_wickets_per_over;
            cout << endl << "now bowling : " << checkPtr -> bowlerName << endl;
            cout << "total runs gave by this bowler : " << checkPtr -> TotalRunsGave << endl;
            cout << "total overs by this bowler : " << checkPtr -> totalBallsBowled << endl << endl;
            cout << "total wickets taken by this bowler : " << checkPtr -> TotalWicketstaken << endl << endl;
            if (checkPtr -> bowlerIndex >= noOfBowlers)
            {
                checkPtr = firstBowlerr;
            }
            else
            {
                checkPtr = checkPtr -> next;
            }
        }

        t3.total_runs = total_runs;
        t4.total_wickets = total_wickets;
        if (target_runs > total_runs)
        {

            cout << endl << "total runs taken by " << t3.team_name << " at the end of " << i << " over : " << t3.total_runs << endl;
            cout << "total wickets taken by " << t4.team_name << " at the end of " << i << " over : " << t4.total_wickets << endl << endl;
        }
        else
        {
            cout << endl << "total runs taken by " << t3.team_name << " at the end of match : " << t3.total_runs << endl;
            cout << "total wickets taken by " << t4.team_name << " at the end of match : " << t4.total_wickets << endl << endl;

        }

    }

    return t3.total_runs + 1;
}

void target_reveal(int number_of_overs, int target, Cricket_team t3, Cricket_team t4)
{
    cout << endl << "Target : " << t4.team_name << " needs " << target << " in " << number_of_overs << " overs to win." << endl;

}
