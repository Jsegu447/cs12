#ifndef __BBOARD_H__
#define __BBOARD_H__

#include <string>
#include <vector>
using namespace std;

#include "Message.h"
#include "User.h"
#include "Topic.h"
#include "Reply.h"

class BBoard {
 private:
   string title;
	vector<User> user_list;
	const User * current_user;
	vector<Message *> message_list;
    void menuDisplay();
    void newTopic();
 public:
	BBoard();
	BBoard(const string &);
	~BBoard();
	bool loadUsers(const string &);
	bool loadMessages(const string &);
	bool saveMessages(const string &);
	void login();
	void run();
};

#endif
