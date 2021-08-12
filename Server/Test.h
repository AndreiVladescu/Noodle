#pragma once
#include "ITest.h"
#include "IQuestion.h"
#include "IUser.h"

class Test :
    public ITest
{
private:
    vector <IQuestion*> questions;
    vector <IUser*> students;
    IUser* ProfessorOwner;
    float maxPoints;
    float suppPoints;
    string name;
    string time; //formated time: minutes/hours/days/months/years
    int id;
    string subject;
    int numberOfQuestions;
    int timeToComplete;

    vector<string> assignedStudyGroups;
    vector<int> assignedStudents;

public:
    Test(string testName, IUser* owner, vector<IUser*> toStudents, string testTime);
    Test(string testName, IUser* owner, string testTime);
    Test(string testName, string subjectName, string testTime);
    void printTest() {}; //Why? Why would you?
    
    inline void addQuestion(IQuestion* q) override { questions.push_back(q); }
    float calculateMaxPoints() override;
    bool isStudentPartOf(IUser* student) override;

    inline void setID(int newID) override { id = newID; }
    inline void setSuppPoints(float x) override { suppPoints = x; }
    inline void setTime(string testTime) override { time = testTime; }
    inline void setSubject(string newSubject) override { subject = newSubject; }
    inline void setNumberOfQuestions(int number) override { numberOfQuestions = number; }
    inline void assignTo(string studyGroup) override { assignedStudyGroups.push_back(studyGroup); }
    inline void assignTo(int userID) override { assignedStudents.push_back(userID); }
    void assignTo(vector<string> studyGroups) override;
    void assignTo(vector<int> studentIDs) override;
    inline void setTimeToComplete(int time) override { timeToComplete = time; }

    inline int getTimeToComplete() { return timeToComplete; };
    inline vector<int> getAssignedStudents() override { return assignedStudents; }
    inline vector<string> getAssignedStudyGroups() override { return assignedStudyGroups; }
    inline int getNumberOfStudents() override{ return assignedStudents.size(); }
    inline int getNumberOfStudyGroups() override{ return assignedStudyGroups.size(); }
    inline int getNumberOfQuestions() override { return numberOfQuestions; }
    inline int getID() override { return id; }
    inline string getTime() override { return time; }
    inline vector <IQuestion*> getQuestions() override { return questions; }
    inline float getSuppPoints() override { return suppPoints; };
    inline float getMaxPoints() override { return maxPoints; };
    inline string getSubject() override { return subject; }
    inline string getName() override { return name; }

    virtual ~Test() {};
};

