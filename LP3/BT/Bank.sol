// SPDX-License-Identifier: Unlicensed
pragma solidity ^0.8.0;

contract Bank {
    address public customer;
    uint private balance;

    constructor() {
        customer = msg.sender;
    }

    function depositMoney() public payable {
        require(customer == msg.sender, "Unauthorized access!!");
        require(msg.value > 0, "Amount must be greater than 0");
        balance += msg.value;
    }

    //0x5B38Da6a701c568545dCfcB03FcB875f56beddC4

    function withdraw(uint amount) public {
        require(customer == msg.sender, "Unauthorized access!!");
        require(amount > 0, "Amount must be greater than 0");
        require(amount <= balance, "Insufficient balance");

        balance -= amount;
        payable(customer).transfer(amount);
    }

    function getBalance() public view returns (uint) {
        require(customer == msg.sender, "Unauthorized access!!");
        return balance;
    }
}
