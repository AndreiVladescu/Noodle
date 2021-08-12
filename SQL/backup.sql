--drop database Noodle

--CREATE DATABASE Noodle
--ON PRIMARY
--(
--Name = NoodleData1,
--FileName = 'D:\DB\POO\Noodle.mdf',
--size = 10MB, -- KB, Mb, GB, TB
--maxsize = unlimited,
--filegrowth = 1GB
--),
--(
--Name = NoodleData2,
--FileName = 'D:\DB\POO\Noodle.ndf',
--size = 10MB, -- KB, Mb, GB, TB
--maxsize = unlimited,
--filegrowth = 1GB
--)
--LOG ON
--(
--Name = NoodleLog1,
--FileName = 'D:\DB\POO\Noodle.ldf',
--size = 10MB, -- KB, Mb, GB, TB
--maxsize = unlimited,
--filegrowth = 1024MB
--)


---- Tabele --
--CREATE TABLE Users
--(
--	UserID int NOT NULL IDENTITY(10000, 1) PRIMARY KEY,
--	LastName nvarchar(40),
--	FirstName nvarchar(80),
--	Email varchar(40),
--	PasswordHash varchar(100),
--	JoinDate date,
--	UserRole int,
--	--
--	StudyGroup nvarchar(10),
--	StudyYear int
	
--)

--CREATE TABLE Subjects
--(
--	SubjectID int NOT NULL IDENTITY(1000, 1) PRIMARY KEY,
--	SubjectName nvarchar(80),
--	ProfessorID int,
--	FOREIGN KEY (ProfessorId) REFERENCES Users(UserID)

--)

--CREATE TABLE Grades
--(
--	StudentID int NOT NULL,
--	SubjectID int NOT NULL,
--	Grade int NOT NULL,
--	PRIMARY KEY CLUSTERED (StudentID, SubjectID),
--	FOREIGN KEY (StudentID) REFERENCES [Users] (UserID),
--	FOREIGN KEY (SubjectID) REFERENCES [Subjects] (SubjectID)
--)
----tabele test, intrebare, raspuns corect
--CREATE TABLE Tests
--(
--	TestID int NOT NULL IDENTITY(1, 1) PRIMARY KEY,
--	TestName nvarchar(40),
--	SubjectID int,
--	FOREIGN KEY (SubjectID) REFERENCES Subjects(SubjectID)
--)
--CREATE TABLE Questions
--(
--	QuestionID int NOT NULL IDENTITY(1, 1) PRIMARY KEY,
--	Question nvarchar(512),
--	TestID int,
--	FOREIGN KEY (TestID) REFERENCES Tests(TestID)
--)
--CREATE TABLE Answers
--(
--	AnswerID int NOT NULL IDENTITY(1, 1) PRIMARY KEY,
--	Answer nvarchar(128),
--	Truthness int,
--	QuestionID int,
--	FOREIGN KEY (QuestionID) REFERENCES Questions(QuestionID)
--)
--CREATE TABLE AssignedTo
--(
--	ID int NOT NULL IDENTITY(1, 1) PRIMARY KEY,
--	StudyGroup nvarchar(10),
--	StudentID int,
--	foreign key (StudentID) references Users(UserID),
--	TestID int not null,
--	FOREIGN KEY (TestID) REFERENCES Tests(TestID)
--)
--drop table AssignedTo
/*drop table Grades
drop table Subjects
drop table Users*/

--INSERT INTO Users(LastName, FirstName, Email, PasswordHash, JoinDate, UserRole, StudyGroup, StudyYear) VALUES
--('Rosu', 'Cosmin-Ioan', 'rosu.cosmin@mta.ro', 'youtube2021', GETDATE(), 1, 'C112E', 2)
--('Vladescu', 'Andrei', 'vladescu.andrei@mta.ro', 'bannerlord', GETDATE(), 1, 'C112E', 2),
--('LastNameTest','FirstNameTest','EmailTest','PasswordHashTest',GETDATE(), 1, 'A112B', 2)

Select * from Users

INSERT INTO Users(LastName, FirstName, Email, PasswordHash, JoinDate, UserRole) VALUES
('Montessori', 'Maria', 'maria.monstessori@mta.ro', 'parola', GETDATE(), 2),
('Coltan', 'Gheorghe', 'coltan_gheorghe@mta.ro', 'parola', GETDATE(), 2)

Select * from Tests

Select * from Subjects


insert into Subjects(SubjectName, ProfessorID) values
('Fizica', 10010),
('Matematica', 10011)

insert into Tests(TestName, SubjectID) values
('Test Matematica Clasa a 7-a', 1001),
('Test Fizica Clasa a 10-a', 1000)

select * from Tests
select * from Questions


--minut/ora/zi/luna/an
update Tests
set InboundDate = '0/12/6/4/2022'
where TestID = 2

SELECT CONVERT(datetime, '21-04-2022 10:30', 105); 

alter table Tests
add InboundDate varchar(30)


select * from Questions

insert into Questions(Question, TestID) values
('In ce se masoara intensitatea curentului electric?', 1),
('In ce se masoara tensiunea curentului electric?', 1),
('In ce se masoara rezistenta electrica?', 1)

select * from Answers

insert into Answers(Answer, QuestionID) values
('amperi', 2),
('volti', 3),
('ohmi', 4)

insert into Questions(Question, TestID) values
('Cat fac 2 + 2?', 2),
('Cat este 2 * 3?', 2),
('Cat este suma tuturor numerelor naturale?', 2)

insert into Answers(Answer, QuestionID, Truthness) values
('4', 5, 1),
('5', 5, 0),
('-2', 5, 0)

insert into Answers(Answer, QuestionID, Truthness) values
('5', 6, 0),
('6', 6, 1),
('23', 6, 0)

insert into Answers(Answer, QuestionID, Truthness) values
('infinit', 7, 0),
('nu stiu', 7, 0),
('-1/12', 7, 1)

select Answer +' ' + CAST(QuestionID as varchar) from Answers

update Questions set Points = 3

select * from Users

select * from Tests

select * from Answers

select * from Subjects

select * from Questions

insert into Subjects(SubjectName) values
('Filosofie')

update Subjects set ProfessorID = 10008
where SubjectName = 'Filosofie'

select SubjectID from Subjects where SubjectName = 'Filosofie'

select top(1) TestID from Tests where SubjectID = 1004 order by TestID desc

select * from Questions

select top(1) QuestionID from Questions order by QuestionID desc


select * from Users
select * from Subjects
select * from Grades

insert into Grades(StudentID, SubjectID, Grade) values
(10000, 1001, 9)

select S.SubjectName, G.Grade
from Grades as G
inner join Subjects as S
on S.SubjectID = G.SubjectID
inner join Users as U
on U.UserID = G.StudentID
where U.FirstName + ' ' + U.LastName = 'Andrei Vladescu'

insert into Grades(StudentID, SubjectID, Grade) values
(10001, 1001, 10)

update Grades
set Grades.Grade = 7 
from Grades as G
inner join Subjects as S
on G.SubjectID = S.SubjectID
where S.SubjectName = 'Filosofie' and G.StudentID = 10001

select U.FirstName + ' ' + U.LastName as [Full Name], G.Grade, S.SubjectName
from Users as U
inner join Grades as G
on G.StudentID = U.UserID
inner join Subjects as S
on S.SubjectID = G.SubjectID
where U.StudyGroup = 'C112E' and S.SubjectName = 'Matematica';

select * from Tests

select * from Users

insert into AssignedTo(TestID, StudyGroup)
values (26, 'C112E')

Insert into AssignedTo(TestID, StudentID) values (26, 10002)

select * from AssignedTo

select * from Questions

select * from Answers

select CONVERT(nvarchar(15),TestID) + '$' + TestName + '$' + CONVERT(nvarchar(15),SubjectID) + '$' + InboundDate from Tests

select CONVERT(nvarchar(15),QuestionID) + '$' + Question + '$' + CONVERT(nvarchar(15),TestID) + '$' + CONVERT(nvarchar(15),Points) from Questions where TestID = 26

select count(*) from Answers where QuestionID = 17

select  * from Answers where Answers.QuestionID = 17

select SubjectName from Subjects where SubjectID = 1004

select * from Subjects 

select * from Tests

select * from Questions where TestID = 2
select * from Answers where QuestionID = 5

update Answers 
set Truthness = -1
where Truthness is null

select CONVERT(nvarchar(15),AnswerID) + '$' + Answer + '$' + CONVERT(nvarchar(15),QuestionID) + '$' + CONVERT(nvarchar(15),Truthness) from Answers where QuestionID = 4

--make trigger to not have null answers

select StudyGroup
from AssignedTo
where StudyGroup is not null
and TestID = 26

select StudentID
from AssignedTo
where StudentID is not null

select * from Users

insert into Subjects(SubjectName, ProfessorID)
values ('Romana', 10013)

select * from AssignedTo

select Email + PasswordHash from Users
where Email = 'vladescu.andrei@mta.ro' and PasswordHash = 'lalala'

select * from Answers


if OBJECT_ID('answerCorrectness', 'TR') IS NOT NULL
drop trigger answerCorrectness;
go
create trigger answerCorrectness
on Answers
after insert
as
begin
	if @@ROWCOUNT = 0 return;
	set nocount on;
	update Answers
	set Truthness = -1
	where Truthness is null
end;

select * from Tests

update Tests
set TimeToComplete = 10