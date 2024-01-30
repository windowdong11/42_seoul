#include "Channel.hpp"


Channel::Channel::Channel(const Channel &other) {
    
}

Channel& Channel::operator=(const Channel &other) {
    
}

Channel::Channel::~Channel() {
    
}

void Channel::Channel::setChannelName(std::string channelName) {
    
}

void Channel::Channel::setOperator(User *user) {
    
}

void Channel::Channel::addUser(User *user) {
    
}

void Channel::Channel::removeUser(const std::string& nickname) {
    
}

void Channel::Channel::changeMode(Channel::eChannelMode mode) {
    
}

std::string Channel::Channel::getChannelName() const {
    
}

User* Channel::findUser(const std::string &nickname) const {
	for (User* user : mUsers) {
		if (user->getNickname() == nickname) {
			return user;
		}
	}
	return NULL;
}

User* Channel::getOperator() const {
    return mOperator;
}

Channel::eChannelMode Channel::getMode() const {
	return mMode;
}
