//SPDX-License-Identifier: UNLICENSED
pragma solidity ^0.8.0;

contract StudentData{
    struct Student{
        uint age;
        string name;
        string major;
    }

    Student[] internal students;

    function addStudents(uint _age, string memory _name, string memory _major) public{
        Student memory newStudent = Student(_age,_name,_major);
        students.push(newStudent);
    }

    function getStudentCount() public view returns (uint){
        return students.length;
    }

    function getStudent(uint index) public view returns (Student memory){
        require(index<students.length,"Student does not exist!");
        Student memory stud = students[index];
        return stud;
    }
    fallback() external payable { }
    receive() external payable { }
}