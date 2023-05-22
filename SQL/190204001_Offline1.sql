CREATE TABLE author( 
	id int primary key not null ,
	name varchaR(255),
	age int
);

CREATE TABLE student( 
	id int primary key not null ,
	name varchar(255),
	phone varchar(255),
	age int
);

CREATE TABLE book( 
	id int primary key not null,
	title varchaR(255),
	genre varchaR(255),
	authorid int ,
	CONSTRAINT fk_author
    FOREIGN KEY (authorid)
    REFERENCES author(id)
);



CREATE TABLE borrows( 
	id int,
	bookid int ,
	dateBorrowed date ,
	CONSTRAINT fk_book
    FOREIGN KEY (bookid)
    REFERENCES book(id),
    CONSTRAINT fk_stdid
    FOREIGN KEY (id)
    REFERENCES student(id)
);


Insert into student values(1,'Md. muhaiminul kabir','01783344331',23);
Insert into student values(2,'Md. hasibul kabir','01773344331',23);
Insert into student values(3,'Md. muul kabir','01763344331',27);
Insert into student values(4,'Md. haiminul kabir','01793344331',25);
Insert into student values(5,'Md. maiminul kabir','01703344331',23);
Insert into student values(6,'Md. mamul kabir','01733344331',21);
Insert into student values(7,'Md. maiminul kabir','01723344331',22);
Insert into student values(8,'Md. amul kabir','01713344331',20);
Insert into student values(9,'Md. haim kabir','01753344331',29);
Insert into student values(10,'Md. nur kabir','01763344331',19);



Insert into author values(1,'humayun kabir',78);
Insert into author values(2,'kazi nazrul islam',83);
Insert into author values(3,'ahmed chofa',90);
Insert into author values(4,'sed muztoba ali',67);
Insert into author values(5,'Rabindranath',56);
Insert into author values(6,'Jonathan Swift',56);


Insert into book values(1,'jhingeful','poem',2);
Insert into book values(2,'jhingeful','poem',2);
Insert into book values(3,'gitanjali','poem',2);
Insert into book values(4,'Gullivers Travels','Non-Fiction',6);
Insert into book values(6,'Guls','Non-Fiction',1);
Insert into book values(7,'Rivers Travels','Non-Fiction',2);
Insert into book values(8,'Gullis Crciket','Non-Fiction',3);





Insert into borrows values(1,4,'1-JAN-2023');
Insert into borrows values(6,3,'1-AUG-2023');
Insert into borrows values(6,3,'1-JAL-2023');
Insert into borrows values(2,3,'1-JUN-2023');
Insert into borrows values(2,3,'1-FEB-2023');
Insert into borrows values(2,3,'1-MAY-2023');
Insert into borrows values(5,3,'1-JAN-2023');
Insert into borrows values(5,3,'1-JAN-2023');
Insert into borrows values(5,3,'1-JAN-2023');
Insert into borrows values(10,3,'1-JAN-2023');


--solution(a)

select student.name from student 
join borrows on student.id = borrows.id
join book on borrows.bookid = book.id
where book.title = 'Gullivers Travels';

--solution(b)

select max(author.age) as oldest_author
from book join author on book.authorid = author.id
where book.genre = 'Non-Fiction';

--solution(c)

select student.phone from student 
join borrows on student.id = borrows.id
join book on borrows.bookid = book.id
where book.title = 'gitanjali' 
group by student.phone
having count(student.id) > 2;
