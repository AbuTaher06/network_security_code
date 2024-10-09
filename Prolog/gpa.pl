grade(english,3).
grade(math,3).
grade(science,2).

gpa() :-
    findall(Grade,grade(_,Grade),Grades),
    sumlist(Grades,Sum),
    length(Grades,Length),
    Gpa is Sum / Length,
    format('GPA = ~2f~n',[Gpa])