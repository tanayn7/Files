// SPDX-License-Identifier: MIT
pragma solidity ^0.8.11;

contract Student_Management{

    struct Student{
        int stud_id;
        string stud_Name;
        string department;
    }

    Student[] Students;

    function add_student_details(int stud_id, string memory stud_Name, string memory department) public{
        Student memory stud_data = Student(stud_id, stud_Name, department);
        Students.push(stud_data);
    }

    function get_student_data(int stud_id) public view returns(string memory, string memory){
        for(uint i=0; i<Students.length; i++){
            Student memory stud = Students[i];
            if(stud.stud_id == stud_id){
                return (stud.stud_Name, stud.department);
            }
        }
        return("Not found","Not found");
    }
}