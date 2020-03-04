/*
 * File    : rwho_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol is used to send a reply to a remote who request.
 */

#include <net/dns.h>
#include <net/macros.h>

inherit F_CLEAN_UP;

// They have answered our remote who question.

void incoming_request(mapping info)
{
	object ob;
	string output;
	mapping minfo;
	if( !ACCESS_CHECK(previous_object())) return;

	if (stringp(info["PORTUDP"]) && stringp(info["HOSTADDRESS"]))
	{
		if (info["NAME"] == Mud_name())	return ;
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);
		if (!(ob = find_player(lower_case(info["ASKWIZ"])))) return ;
		output=info["RWHO"];
		if(!undefinedp(info["ENCODING"]) && lower_case(info["ENCODING"])=="gb" )
		{
			output=LANGUAGE_D->GB2Big5(output);
		} else {
			minfo = DNS_MASTER->query_mud_info(lower_case(info["NAME"]));
			if(!undefinedp(minfo["ENCODING"]) && lower_case(minfo["ENCODING"])=="gb")
			output=LANGUAGE_D->GB2Big5(output);
		}
		tell_object(ob, output);
	}
}

void create()
{
	seteuid(ROOT_UID);
}
