/*
 * File    : gfinger_q.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is a request for information about a user at another mud.
 */
 

// Ported to ES2 mudlib by Annihilator@ES2 (06/15/95)

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;
inherit F_DBASE;
int debug;
void create() { seteuid(ROOT_UID); }
void start_debug()
{
	debug=1;
	write("Gfinger_q Debug start!!\n");
	return;
}

void stop_debug()
{
	debug=0;
	write("Gfinger_q Debug stop!!\n");
	return;
}

// Finger a wiz on another mud.
void send_gfinger_q(string mud, string wiz, object them)
{
	mapping minfo;

	if(!ACCESS_CHECK(previous_object())) return;

	if (!them) them = this_player(1);
	mud = htonn( mud );
	if(debug)
	{
		set("channel_id", "�����W�D���F");
		CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("gfinger_q : [htonn== %s ][mud_nname()== %s]\n",mud,mud_nname()));
	}
	if (mud == mud_nname()) return ;

	// make sure we have an entry for the recipient
	minfo = DNS_MASTER->query_mud_info(mud);
	if (!minfo) 
	{
		if(debug)
		{
			set("channel_id", "�����W�D���F");
			CHANNEL_D->do_channel(this_object(), "sys",
			sprintf("gfinger_q : DNS_MASTER->query_mud_info(mud) Fail..\n",mud,mud_nname()));
		}
		return ;
	}

	// send the finger
	DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		sprintf("@@@%s||NAME:%s||PORTUDP:%d||PLAYER:%s||ASKWIZ:%s@@@\n",
		DNS_GFINGER_Q, Mud_name(), udp_port(),
		wiz, (string)them->query("id")));
}
// Finger a wiz on another mud.
varargs void send_finger_q(string mud, string wiz, object them,string verb)
{
	mapping minfo;
	string channel;
	if(!ACCESS_CHECK(previous_object())) return;

	if (!them) them = this_player(1);
	mud = htonn( mud );
	if(debug)
	{
		set("channel_id", "�����W�D���F");
		CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("gfinger_q : [htonn== %s ][mud_nname()== %s]\n",mud,mud_nname()));
	}
	if (mud == mud_nname()) return ;

	// make sure we have an entry for the recipient
	minfo = DNS_MASTER->query_mud_info(mud);
	if (!minfo) 
	{
		if(debug)
		{
			set("channel_id", "�����W�D���F");
			CHANNEL_D->do_channel(this_object(), "sys",
			sprintf("gfinger_q : DNS_MASTER->query_mud_info(mud) Fail..\n",mud,mud_nname()));
		}
		return ;
	}
	
	if(verb)
	{
		if(sscanf(verb,"%s#%s",channel,verb)!=2) return;
		DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		sprintf("@@@%s||NAME:%s||PORTUDP:%d||PLAYER:%s||ASKWIZ:%s@@@\n",
		DNS_GFINGER_Q, Mud_name(), udp_port(),
		wiz, sprintf("<!!%s!!><!!%s!!>%s",them->query("id"),channel,verb)));
	}
	else
	// send the finger
	DNS_MASTER->send_udp(minfo["HOSTADDRESS"], minfo["PORTUDP"],
		sprintf("@@@%s||NAME:%s||PORTUDP:%d||PLAYER:%s||ASKWIZ:%s@@@\n",
		DNS_GFINGER_Q, Mud_name(), udp_port(),
		wiz, (string)them->query("id")));
}

void incoming_request(mapping info)
{
	string *key,text="",reply;
	int loop;
	if(debug)
	{
		set("channel_id", "�����W�D���F");
		CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("gfinger_q have incoming_request from %s.", (string)info["NAME"]));
	}
	if (info["NAME"] && info["PORTUDP"] && info["PLAYER"]) {
		if (info["NAME"] == mud_nname()) return ;

		// if we don't have a record of the mud get it
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

		// send the finger reply
		reply = (string)FINGER_D->finger_user(lower_case(info["PLAYER"]));
	if(debug)
	{
		key=keys(info);
		for(loop=0; loop<sizeof(key); loop++)
		{
       			if(strlen(key[loop]) > 7)  text += key[loop] + "\t: ";
       			else text += key[loop] + "\t\t: ";
		        text +=sprintf("%O [0m\n",info[ key[loop] ]);
     		}
    		text+="============================\n";
		log_file("gfinger_q",text);
	}
		DNS_MASTER->send_udp(info["HOSTADDRESS"], info["PORTUDP"],
			sprintf("@@@%s||NAME:%s||PORTUDP:%d||ASKWIZ:%s||MSG:%s@@@\n",
			DNS_GFINGER_A, mud_nname(), udp_port(),
			info["ASKWIZ"], reply));
	}
}

