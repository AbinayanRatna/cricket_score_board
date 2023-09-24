#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class BowlerClass
{
public:
    int bowlerIndex;
    string bowlerName;
    int TotalRunsGave;
    int TotalWicketstaken;
    float totalBallsBowled;
    class BowlerClass * next;
};

typedef class BowlerClass * Bowler;
Bowler firstBowler = new BowlerClass;
Bowler firstBowlerr = new BowlerClass;

class BatsmenClass
{
public:
    int batsmenIndex;
    string batsmenName;
    int totalRunsGot;
    float totalBallsFaced;
    class BatsmenClass*next;
    bool isPlaying=false;
    bool isOut=false;
};

typedef class BatsmenClass * Batsmen;

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

int main()
{
    Cricket_match match;
    Cricket_team t1, t2;

    cout << endl;
    match.get_numberOfOvers();
    t1.get_teamName("first");
    t2.get_teamName("second");

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
    Batsmen firstBatsmen = new BatsmenClass;
    Batsmen firstBatsmen2 = new BatsmenClass;

    cout << "enter number of bowlers in team 1: " << endl;
    cin >> noOfBowlers;
    int total_runs = 0;
    int total_wickets = 0;
    firstBatsmen->next=firstBatsmen2;


    firstBatsmen = NULL;
    Batsmen currentBatsmen_1 = new BatsmenClass;
    Batsmen currentBatsmen_2 = new BatsmenClass;
    Batsmen battingPtr = new BatsmenClass;

    Bowler ccheckPtr = new BowlerClass;
    ccheckPtr = NULL;
    Batsmen newBatsmen1 = new BatsmenClass;
    Batsmen newBatsmen2 = new BatsmenClass;
    if(firstBatsmen==NULL)
    {

        newBatsmen1->batsmenIndex=1;
        newBatsmen2->batsmenIndex=2;
        newBatsmen1->batsmenName="1-Batsman ( " + t4.team_name + " team )";
        newBatsmen2->batsmenName="2-Batsman ( " + t4.team_name + " team )";
        firstBatsmen=newBatsmen1;
        firstBatsmen2=newBatsmen2;
        newBatsmen1->isPlaying=true;
    }


    for (int i = 1; i <= number_of_overs; i++)
    {

        int sum_runs_per_over;
        Bowler newBowler = new BowlerClass;
        newBowler -> bowlerIndex = NULL;

        if (firstBowler == NULL)
        {
            
            newBowler -> bowlerIndex = 1;
            newBowler -> bowlerName = "1-Bowler ( " + t4.team_name + " team )";
            firstBowler = newBowler;
        }
        else
        {
        	//cout<<"test 1"<<endl;
			Bowler ptr = new BowlerClass;
            //cout<<"test 2"<<endl;
            //ptr=NULL;
            //cout<<"test 3"<<endl;
            ptr->next = NULL;
            //cout<<"test 4"<<endl;
            ptr = firstBowler;
			//cout<<"test 6"<<endl;
			ptr=firstBowler;
            while (ptr -> next != NULL)
            {
                ptr = ptr -> next;
            }

            if (ptr -> bowlerIndex < noOfBowlers)
            {
                ptr -> next = newBowler;
                newBowler -> bowlerIndex = ptr -> bowlerIndex + 1;
                int index = newBowler -> bowlerIndex;
                newBowler -> bowlerName = to_string(index) + "-Bowler ( " + t4.team_name + " team )";
                delete ptr;
            }
            else
            {
                if (ccheckPtr == NULL)
                {
                    ccheckPtr = firstBowler;
                }

            }

        }


        cout <<endl<< i << " over : " << endl<<endl;
        sum_runs_per_over = 0;
        int sum_wickets_per_over = 0;
        newBatsmen1->isOut=false;
        newBatsmen2->isOut=false;

        for (int j = 1; j <= 6; j++)
        {
            // cout<<"test5"<<endl;
            cout<<endl;
            if (total_wickets >= 10)
            {
                break;
            }
            int k = (rand() % 100) + 1;
            int sum_runs_per_ball = 0;

            int sum_wickets_per_ball = 0;
            if (k <= 35)
            {
                cout << "Run taken this ball : 1 "<<endl;
                // cout<<"test 1 run"<<endl;
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if(newBatsmen1->isPlaying==true)
                {
                    newBatsmen1->totalRunsGot+=1;
                    newBatsmen1->totalBallsFaced+=1;
                    newBatsmen1->isPlaying=false;
                    newBatsmen2->isPlaying=true;
                    newBatsmen1->isOut=false;
                    newBatsmen2->isOut=false;


                }
                else if(newBatsmen2->isPlaying==true)
                {
                    newBatsmen2->totalRunsGot+=1;
                    newBatsmen2->totalBallsFaced+=1;
                    newBatsmen2->isPlaying=false;
                    newBatsmen1->isPlaying=true;
                    newBatsmen2->isOut=false;
                    newBatsmen1->isOut=false;
                }
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
            }
            else if (k > 35 && k <= 55)
            {
                cout << "Run taken this ball : 0 "<<endl;
                //cout<<"test 0 run"<<endl;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
            }
            else if (k > 55 && k <= 70)
            {
                cout << "this ball is a wide. Run taken this ball : 1 "<<endl;
                //cout<<"test wde run"<<endl;
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                j--;
                newBatsmen1->isOut=false;
                newBatsmen2->isOut=false;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
            }

            else if (k > 70 && k <= 80)
            {

                cout << "Run taken this ball : 6 "<<endl;
                sum_runs_per_ball += 6;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if(newBatsmen1->isPlaying==true)
                {
                    newBatsmen1->totalRunsGot+=6;
                    newBatsmen1->totalBallsFaced+=1;
                }
                else if(newBatsmen2->isPlaying==true)
                {
                    newBatsmen2->totalRunsGot+=6;
                    newBatsmen2->totalBallsFaced+=1;
                }
                newBatsmen1->isOut=false;
                newBatsmen2->isOut=false;
                //cout<<"test 6 run"<<endl;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
            }
            else if (k > 80 && k <= 90)
            {
                cout << "Run taken this ball : 4 "<<endl;
                sum_runs_per_ball += 4;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if(newBatsmen1->isPlaying==true)
                {
                    newBatsmen1->totalRunsGot+=4;
                    newBatsmen1->totalBallsFaced+=1;
                }
                else if(newBatsmen2->isPlaying==true)
                {
                    newBatsmen2->totalRunsGot+=4;
                    newBatsmen2->totalBallsFaced+=1;
                }
                newBatsmen1->isOut=false;
                newBatsmen2->isOut=false;
                //cout<<"test 4 run"<<endl;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
            }
            else
            {
                cout << "This ball is a wicket ."<<endl;
                sum_wickets_per_ball++;
                total_wickets += sum_wickets_per_ball;
                sum_wickets_per_over++;

                //cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                if(newBatsmen1->isPlaying==true )
                {

                    cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                    cout<< "last wicket : "<<newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                    newBatsmen1->totalBallsFaced+=1;
                    newBatsmen1->isOut=true;
                    newBatsmen2->isOut=false;
                    Batsmen battingIn = new BatsmenClass;
                    battingIn->batsmenIndex=0;
                    battingIn->batsmenName="";
                    battingIn->isOut=false;
                    battingIn->totalBallsFaced=0;
                    battingIn->totalRunsGot=0;
                    battingIn->isPlaying=false;
                    newBatsmen2->next=battingIn;

                    int index;
                    if(newBatsmen2->batsmenIndex > newBatsmen1->batsmenIndex)
                    {
                        index=newBatsmen2->batsmenIndex;
                    }
                    else
                    {
                        index=newBatsmen1->batsmenIndex;
                    }

                    battingIn->batsmenIndex=index + 1;
                    newBatsmen1=battingIn;
                    newBatsmen2->batsmenName=to_string(newBatsmen2->batsmenIndex) +" - Batsman ( " + t4.team_name + " team )";
                    newBatsmen1->batsmenName=to_string(newBatsmen1->batsmenIndex) +" - Batsman ( " + t4.team_name + " team )";
                    newBatsmen1->isPlaying=true;
                    newBatsmen2->isPlaying=false;
                    newBatsmen1->isOut=false;
                    newBatsmen2->isOut=false;
                    // cout<<"test10"<<endl;

                }
                else if(newBatsmen2->isPlaying==true )
                {

                    cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                    newBatsmen2->totalBallsFaced+=1;
                    cout<< "last wicket : "<<newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;

                    newBatsmen2->isOut=true;
                    newBatsmen1->isOut=false;
                    Batsmen battingIn = new BatsmenClass;
                    battingIn->batsmenIndex=0;
                    battingIn->batsmenName="";
                    battingIn->isOut=false;
                    battingIn->totalBallsFaced=0;
                    battingIn->totalRunsGot=0;
                    battingIn->isPlaying=false;
                    newBatsmen2->next=battingIn;

                    int index;
                    if(newBatsmen2->batsmenIndex > newBatsmen1->batsmenIndex)
                    {
                        index=newBatsmen2->batsmenIndex;
                    }
                    else
                    {
                        index=newBatsmen1->batsmenIndex;
                    }

                    newBatsmen2=battingIn;
                    newBatsmen2->batsmenIndex=index+1;
                    //cout<<" newBatsmen2->batsmenIndex"<<newBatsmen2->batsmenIndex<<endl;
                    newBatsmen2->batsmenName=to_string(newBatsmen2->batsmenIndex)+ " - Batsman ( " + t4.team_name + " team )";
                    //cout<<"test74"<<endl;
                    newBatsmen1->isPlaying=false;
                    newBatsmen2->isPlaying=true;
                    newBatsmen1->isOut=false;
                    newBatsmen2->isOut=false;


                }


            }



        }


        if(newBatsmen1->isPlaying==true )
        {
            newBatsmen1->isPlaying=false;
            newBatsmen2->isPlaying=true;
        }
        else if(newBatsmen2->isPlaying==true )
        {
            newBatsmen2->isPlaying=false;
            newBatsmen1->isPlaying=true;
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
        if (total_wickets >= 10)
        {
            break;
        }

    }

    firstBowler = NULL;
    newBatsmen1=NULL;
    newBatsmen2=NULL;
    firstBatsmen2=NULL;
    firstBatsmen=NULL;
    return t3.total_runs + 1;
}


int show_overs_2(int number_of_overs, Cricket_team t3, Cricket_team t4, Cricket_match match,int target_runs)
{
    int noOfBowlers;
    firstBowler = NULL;
    Batsmen firstBatsmen = new BatsmenClass;
    Batsmen firstBatsmen2 = new BatsmenClass;

    cout << "enter number of bowlers in team 1: " << endl;
    cin >> noOfBowlers;
    int total_runs = 0;
    int total_wickets = 0;
    firstBatsmen->next=firstBatsmen2;


    firstBatsmen = NULL;

    Batsmen currentBatsmen_1 = new BatsmenClass;
    Batsmen currentBatsmen_2 = new BatsmenClass;
    Batsmen battingPtr = new BatsmenClass;
    //Batsmen battingIn = new BatsmenClass;

    // battingIn=NULL;
    //battingIn->batsmenIndex=0;

    Bowler ccheckPtr = new BowlerClass;
    Bowler ptr = new BowlerClass;
    ptr = NULL;
    ccheckPtr = NULL;
    Batsmen newBatsmen1 = new BatsmenClass;
    Batsmen newBatsmen2 = new BatsmenClass;
    if(firstBatsmen==NULL)
    {

        newBatsmen1->batsmenIndex=1;
        newBatsmen2->batsmenIndex=2;
        newBatsmen1->batsmenName="1-Batsman ( " + t4.team_name + " team )";
        newBatsmen2->batsmenName="2-Batsman ( " + t4.team_name + " team )";
        firstBatsmen=newBatsmen1;
        firstBatsmen2=newBatsmen2;
        // newBatsmen2->next=battingIn;
        newBatsmen1->isPlaying=true;
    }


    for (int i = 1; i <= number_of_overs; i++)
    {

        int sum_runs_per_over;
        Bowler newBowler = new BowlerClass;
        newBowler -> bowlerIndex = NULL;

        if (firstBowler == NULL)
        {
            firstBowler = newBowler;
            newBowler -> bowlerIndex = 1;
            newBowler -> bowlerName = "1-Bowler ( " + t4.team_name + " team )";
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
                newBowler -> bowlerName = to_string(index) + "-Bowler ( " + t4.team_name + " team )";
            }
            else
            {
                if (ccheckPtr == NULL)
                {
                    ccheckPtr = firstBowler;
                }

            }

        }


        cout <<endl<< i << " over : " << endl<<endl;
        sum_runs_per_over = 0;
        int sum_wickets_per_over = 0;
        newBatsmen1->isOut=false;
        newBatsmen2->isOut=false;

        for (int j = 1; j <= 6; j++)
        {
            // cout<<"test5"<<endl;
            cout<<endl;
            if (total_wickets >= 10)
            {
                break;
            }
            int k = (rand() % 100) + 1;
            int sum_runs_per_ball = 0;

            int sum_wickets_per_ball = 0;
            if (k <= 35)
            {
                cout << "Run taken this ball : 1 "<<endl;
                // cout<<"test 1 run"<<endl;
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if(newBatsmen1->isPlaying==true)
                {
                    newBatsmen1->totalRunsGot+=1;
                    newBatsmen1->totalBallsFaced+=1;
                    newBatsmen1->isPlaying=false;
                    newBatsmen2->isPlaying=true;
                    newBatsmen1->isOut=false;
                    newBatsmen2->isOut=false;


                }
                else if(newBatsmen2->isPlaying==true)
                {
                    newBatsmen2->totalRunsGot+=1;
                    newBatsmen2->totalBallsFaced+=1;
                    newBatsmen2->isPlaying=false;
                    newBatsmen1->isPlaying=true;
                    newBatsmen2->isOut=false;
                    newBatsmen1->isOut=false;
                }
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else if (k > 35 && k <= 55)
            {
                cout << "Run taken this ball : 0 "<<endl;
                //cout<<"test 0 run"<<endl;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else if (k > 55 && k <= 70)
            {
                cout << "this ball is a wide. Run taken this ball : 1 "<<endl;
                //cout<<"test wde run"<<endl;
                sum_runs_per_ball += 1;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                j--;
                newBatsmen1->isOut=false;
                newBatsmen2->isOut=false;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                if (total_runs > target_runs)
                {
                    break;
                }
            }

            else if (k > 70 && k <= 80)
            {

                cout << "Run taken this ball : 6 "<<endl;
                sum_runs_per_ball += 6;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if(newBatsmen1->isPlaying==true)
                {
                    newBatsmen1->totalRunsGot+=6;
                    newBatsmen1->totalBallsFaced+=1;
                }
                else if(newBatsmen2->isPlaying==true)
                {
                    newBatsmen2->totalRunsGot+=6;
                    newBatsmen2->totalBallsFaced+=1;
                }
                newBatsmen1->isOut=false;
                newBatsmen2->isOut=false;
                //cout<<"test 6 run"<<endl;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else if (k > 80 && k <= 90)
            {
                cout << "Run taken this ball : 4 "<<endl;
                sum_runs_per_ball += 4;
                sum_runs_per_over += sum_runs_per_ball;
                total_runs += sum_runs_per_ball;
                if(newBatsmen1->isPlaying==true)
                {
                    newBatsmen1->totalRunsGot+=4;
                    newBatsmen1->totalBallsFaced+=1;
                }
                else if(newBatsmen2->isPlaying==true)
                {
                    newBatsmen2->totalRunsGot+=4;
                    newBatsmen2->totalBallsFaced+=1;
                }
                newBatsmen1->isOut=false;
                newBatsmen2->isOut=false;
                //cout<<"test 4 run"<<endl;
                cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                if (total_runs > target_runs)
                {
                    break;
                }
            }
            else
            {
                cout << "This ball is a wicket ."<<endl;
                sum_wickets_per_ball++;
                total_wickets += sum_wickets_per_ball;
                sum_wickets_per_over++;

                //cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                if(newBatsmen1->isPlaying==true )
                {

                    cout<< newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;
                    cout<< "last wicket : "<<newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                    newBatsmen1->totalBallsFaced+=1;
                    newBatsmen1->isOut=true;
                    newBatsmen2->isOut=false;
                    Batsmen battingIn = new BatsmenClass;
                    battingIn->batsmenIndex=0;
                    battingIn->batsmenName="";
                    battingIn->isOut=false;
                    battingIn->totalBallsFaced=0;
                    battingIn->totalRunsGot=0;
                    battingIn->isPlaying=false;
                    newBatsmen2->next=battingIn;

                    int index;
                    if(newBatsmen2->batsmenIndex > newBatsmen1->batsmenIndex)
                    {
                        index=newBatsmen2->batsmenIndex;
                    }
                    else
                    {
                        index=newBatsmen1->batsmenIndex;
                    }

                    battingIn->batsmenIndex=index + 1;
                    newBatsmen1=battingIn;
                    newBatsmen2->batsmenName=to_string(newBatsmen2->batsmenIndex) +" - Batsman ( " + t4.team_name + " team )";
                    newBatsmen1->batsmenName=to_string(newBatsmen1->batsmenIndex) +" - Batsman ( " + t4.team_name + " team )";
                    newBatsmen1->isPlaying=true;
                    newBatsmen2->isPlaying=false;
                    newBatsmen1->isOut=false;
                    newBatsmen2->isOut=false;
                    // cout<<"test10"<<endl;

                }
                else if(newBatsmen2->isPlaying==true )
                {

                    cout<< newBatsmen1->batsmenName<<" : "<<newBatsmen1->totalRunsGot<<" in "<<newBatsmen1->totalBallsFaced<<" ."<<endl;
                    newBatsmen2->totalBallsFaced+=1;
                    cout<< "last wicket : "<<newBatsmen2->batsmenName<<" : "<<newBatsmen2->totalRunsGot<<" in "<<newBatsmen2->totalBallsFaced<<" ."<<endl;

                    newBatsmen2->isOut=true;
                    newBatsmen1->isOut=false;
                    Batsmen battingIn = new BatsmenClass;
                    battingIn->batsmenIndex=0;
                    battingIn->batsmenName="";
                    battingIn->isOut=false;
                    battingIn->totalBallsFaced=0;
                    battingIn->totalRunsGot=0;
                    battingIn->isPlaying=false;
                    newBatsmen2->next=battingIn;

                    int index;
                    if(newBatsmen2->batsmenIndex > newBatsmen1->batsmenIndex)
                    {
                        index=newBatsmen2->batsmenIndex;
                    }
                    else
                    {
                        index=newBatsmen1->batsmenIndex;
                    }

                    newBatsmen2=battingIn;
                    newBatsmen2->batsmenIndex=index+1;
                    //cout<<" newBatsmen2->batsmenIndex"<<newBatsmen2->batsmenIndex<<endl;
                    newBatsmen2->batsmenName=to_string(newBatsmen2->batsmenIndex)+ " - Batsman ( " + t4.team_name + " team )";
                    //cout<<"test74"<<endl;
                    newBatsmen1->isPlaying=false;
                    newBatsmen2->isPlaying=true;
                    newBatsmen1->isOut=false;
                    newBatsmen2->isOut=false;


                }


            }



        }


        if(newBatsmen1->isPlaying==true )
        {
            newBatsmen1->isPlaying=false;
            newBatsmen2->isPlaying=true;
        }
        else if(newBatsmen2->isPlaying==true )
        {
            newBatsmen2->isPlaying=false;
            newBatsmen1->isPlaying=true;
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

        if (total_wickets >= 10)
        {
            break;
        }

    }

    firstBowler = NULL;
    newBatsmen1=NULL;
    newBatsmen2=NULL;
    firstBatsmen2=NULL;
    firstBatsmen=NULL;
    return t3.total_runs + 1;
}

void target_reveal(int number_of_overs, int target, Cricket_team t3, Cricket_team t4)
{
    cout << endl << "Target : " << t4.team_name << " needs " << target << " in " << number_of_overs << " overs to win." << endl;

}
