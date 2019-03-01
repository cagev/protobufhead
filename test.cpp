
#include <iostream>
#include <fstream>
#include <string>
#include "addressbook.pb.h"
using namespace std;
using namespace tutorial ;


int main(int argc, char* argv[]) {
    GOOGLE_PROTOBUF_VERIFY_VERSION;
    Person  person; 
    person.mutable_head()->set_type( "person"); 
    person.set_name("arthur"); 
    person.set_email("fatih@qq.com"); 


    string data;  
    person.SerializeToString(&data);

    MessageHead msgHead; 
    msgHead.ParseFromString(data);
    std::cout << msgHead.type() << std::endl ; 

    std::cout << "data is " << data << std::endl; 

    Person person2; 
    person2.ParseFromString(data); 

    std::cout << "person name is " << person2.name() << std::endl; 
    std::cout << "person email is " << person2.email() << std::endl; 

    // Optional:  Delete all global objects allocated by libprotobuf.
    google::protobuf::ShutdownProtobufLibrary();

    return 0;
}
