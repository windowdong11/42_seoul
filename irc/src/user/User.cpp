#include "User.hpp"


User::User() : mRole(ROLE_NORMAL) {
}

User::User(const User &other)
	: mUsername(other.mUsername), mNickname(other.mNickname), mPassword(other.mPassword), mRole(other.mRole) {
}

User& User::operator=(const User &other) {
    if (this != &other) {
		mUsername = other.mUsername;
		mNickname = other.mNickname;
		mPassword = other.mPassword;
		mRole = other.mRole;
	}
	return *this;
}

User::~User() {
}

std::string User::getNickname() const {
    return mNickname;
}

std::string User::getPassword() const {
    return mPassword;
}

User::eRole User::getRole() const {
	return mRole;
}

void User::setUsername(std::string username) {
	mUsername = username;
}

void User::setNickname(std::string nickname) {
	mNickname = nickname;
}

void User::setPassword(std::string password) {
	mPassword = password;
}

void User::setRole(User::eRole role) {
	mRole = role;
}
