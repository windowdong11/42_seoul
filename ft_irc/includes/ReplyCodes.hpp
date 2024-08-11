#pragma once
#ifndef REPLYCODES_HPP
# define REPLYCODES_HPP

enum ReplyCodes
{
    M_RPL_WELCOME = 001,
    M_RPL_YOURHOST = 002,
    M_RPL_CREATED = 003,
    M_RPL_MYINFO = 004,
    M_RPL_BOUNCE = 005,
    M_RPL_USERHOST = 302,
    M_RPL_ISON = 303,
    M_RPL_AWAY = 301,
    M_RPL_UNAWAY = 305,
    M_RPL_NOWAWAY = 306,
    M_RPL_WHOISUSER = 311,
    M_RPL_WHOISSERVER = 312,
    M_RPL_WHOISOPERATOR = 313,
    M_RPL_WHOWASUSER = 314,
    M_RPL_ENDOFWHO = 315,
    M_RPL_WHOISIDLE = 317,
    M_RPL_ENDOFWHOIS = 318,
    M_RPL_WHOISCHANNELS = 319,
    M_RPL_LISTSTART = 321,
    M_RPL_LIST = 322,
    M_RPL_LISTEND = 323,
    M_RPL_CHANNELMODEIS = 324,
	M_RPL_CREATIONTIME = 329,
    M_RPL_NOTOPIC = 331,
    M_RPL_TOPIC = 332,
    M_RPL_TOPICWHOTIME = 333,
    M_RPL_INVITING = 341,
    M_RPL_SUMMONING = 342,
    M_RPL_VERSION = 351,
    M_RPL_WHOREPLY = 352,
    M_RPL_NAMREPLY = 353,
    M_RPL_LINKS = 364,
    M_RPL_ENDOFLINKS = 365,
    M_RPL_ENDOFNAMES = 366,
    M_RPL_BANLIST = 367,
    M_RPL_ENDOFBANLIST = 368,
    M_RPL_ENDOFWHOWAS = 369,
    M_RPL_INFO = 371,
    M_RPL_MOTD = 372,
    M_RPL_ENDOFINFO = 374,
    M_RPL_MOTDSTART = 375,
    M_RPL_ENDOFMOTD = 376,
    M_RPL_YOUREOPER = 381,
    M_RPL_REHASHING = 382,
    M_RPL_YOURESERVICE = 383,
    M_RPL_TIME = 391,
    M_RPL_USERSSTART = 392,
    M_RPL_USERS = 393,
    M_RPL_ENDOFUSERS = 394,
    M_RPL_NOUSERS = 395
};
#endif