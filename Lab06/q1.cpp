/*Create a Message class
o It should have a private instance variable text of type string to store the message content.
o Implement a method toString() that returns the message text.
o Provide a setter method to modify the text value.*/

#include <iostream>
#include <string>
using namespace std;

class Message {
    private:
    string messageContent;

    public:
    Message() {
        messageContent = "";
    }

    Message(string messageContent) : messageContent(messageContent) {}

    void setMessageContent(string content) {
        messageContent = content;
    }

    virtual string toString() {
        return messageContent;
    }
};

/*2. Create an SMS class that inherits from Message
o It should have an additional instance variable recipientContactNo to store the recipient’s phone number.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing the recipient’s contact number and the message text.*/

class SMS : public Message {
    private: 
    string recipientContactNo;

    public:
    SMS(string messageContent, string recipientContactNo) : recipientContactNo(recipientContactNo), Message(messageContent) {}

    void setRecipientContactNo (string recipientContactNo){
        this->recipientContactNo = recipientContactNo;
    }

    string getRecipientContactNo() const {
        return recipientContactNo;
    }

    string toString() override {
        string newStr = recipientContactNo + " " + Message::toString();
        return newStr;
    }
};

/*Create an Email class that inherits from Message
o It should have additional instance variables: sender, receiver, and subject.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing sender, receiver, subject, and the message text.*/

class Email : public Message {
    private:
    string sender;
    string receiver;
    string subject;

    public:
    Email(string messageContent, string sender, string receiver, string subject) : Message(messageContent), sender(sender), receiver(receiver), subject(subject) {}

    string getSender() const {
        return sender;
    }
    string getSubject() const {
        return subject;
    }
    string getReceiver() const {
        return receiver;
    }


    void setSender(string sender) {
        this->sender = sender;
    }
    void setReceiver(string receiver) {
        this->receiver = receiver;
    }
    void setSubject(string subject) {
        this->subject = subject;
    }

    string toString() override {
        string newStr = sender + " " + receiver + " " + subject + " " + Message::toString();
        return newStr;
    }

};

/*4. Implement Keyword Search Function
o Define a function:
o bool ContainsKeyword(const Message& messageObject, const string& keyword);
o This function should return true if the text of the Message object contains the given keyword, otherwise return false.*/

bool ContainsKeyword(Message& messageObject, const string& keyword) {
    int found = messageObject.toString().find(keyword);
    return (found != string::npos);
}

/*Implement Message Encoding
o Define a function to encode a given message using the following scheme:
 Each character should be replaced by the next character in the alphabet (e.g., ‘A’ → ‘B’, ‘b’ → ‘c’, ‘Z’ → ‘A’, ‘z’ → ‘a’).
 Example: If the message is "This is Java", the encoded message should be "Uijt jt Kbwb".*/

string encode (Message& messageObject) {
    string msg = messageObject.toString();
    for (int i=0; i<msg.length(); i++){
        if (msg.at(i) >= 65 && msg.at(i) <= 89){
            msg.at(i)++;
        }
        if (msg.at(i) >= 97 && msg.at(i) <= 121){
            msg.at(i)++;
        }
        if (msg.at(i) == 122){
            msg.at(i) = 97;
        }
        if (msg.at(i) == 90){
            msg.at(i) = 65;
        }
    }
    return msg;
}

int main() {
    string encoded;

    Message msg("hello world");
    cout << "Message Class: " << endl;
    cout << "Original Message: " << msg.toString() << endl;

    cout << "find 'hello'" << endl;
    if (ContainsKeyword(msg, "hello")) {
        cout << "contains hello" << endl;
    } else {
        cout << "does not contain hello" << endl;
    }

    cout << "find 'universe'" << endl;
    if (ContainsKeyword(msg, "Universe")) {
        cout << "Contains universe" << endl;
    } else {
        cout << "does not contain universe" << endl;
    }

    encoded = encode(msg);
    cout << "Encoded Message: " << encoded << endl << endl;

    SMS sms("Hello, this is an SMS", "03300764399");
    cout << "SMS Class: " << endl;
    cout << "Original SMS: " << sms.toString() << endl;

    cout << "find 'SMS'" << endl;
    if (ContainsKeyword(sms, "SMS")) {
        cout << "contains 'SMS'" << endl;
    } else {
        cout << "does not contain'SMS'" << endl;
    }

    cout << "find 'email'" << endl;   
    if (ContainsKeyword(sms, "email")) {
        cout << "Contains 'Email'? Yes" << endl;
    } else {
        cout << "does not caontain email" << endl;
    }

    encoded = encode(sms);
    cout << "Encoded SMS: " << encoded << endl << endl;

    Email email("email object: ", "fatima@nu.edu.pk", "abc@nu.edu.pk", "Subject");
    cout << "Email Class: " << endl;
    cout << "Original Email: " << email.toString() << endl;

    cout << "find 'email' " << endl;
    if (ContainsKeyword(email, "email")) {
        cout << "contains 'email'" << endl;
    } else {
        cout << "Contains 'email'? No" << endl;
    }

    encoded = encode(email);
    cout << "Encoded Email: " << encoded << endl;
}
