/*
 * File    : gfinger_a.c
 * Creator : Pinkfish@Discworld
 *         : Grendel@Tmi-2
 * When    : 93-08-15
 *
 * This file is part of the tmi mudlib.  Please keep this header intact.
 *
 * This protocol contains the answer to a gfinger request.
 */

// Ported to ES2 mudlib by Annihilator@ES2 (06/15/95)

#include <net/dns.h>
#include <net/macros.h>
#include <net/gchannel.h>
inherit F_CLEAN_UP;
inherit F_DBASE;
int debug;
string *gb_mud_list=GB_MUD_IP;
void start_debug()
{
	debug=1;
	write("Gfinger_a Debug start!!\n");
	return;
}

void stop_debug()
{
	debug=0;
	write("Gfinger_a Debug stop!!\n");
	return;
}

// They answered our finger request.  Nice of them.
void incoming_request(mapping info)
{
	object ob;
	string text="",*key,asker,target,target_id,target_name,verb,channel;
	mapping minfo;
	int loop;
	if(!ACCESS_CHECK(previous_object())) return;

	if(debug)
	{
		set("channel_id", "�����W�D���F");
		CHANNEL_D->do_channel(this_object(), "sys",
		sprintf("gfinger_a have incoming_request from %s.", (string)info["NAME"]));
		key=keys(info);
		for(loop=0; loop<sizeof(key); loop++)
		{
       			if(strlen(key[loop]) > 7)  text += key[loop] + "\t: ";
       			else text += key[loop] + "\t\t: ";
		        text +=sprintf("%O [0m\n",info[ key[loop] ]);
     		}
    		text+="============================\n";
		log_file("gfinger_a",text);
	}
	if (info["PORTUDP"] && info["NAME"])
	{
		// dont want to finger ourselves
		if (info["NAME"] == Mud_name()) return ;

		// if we haven't got an entry for the mud, get one.
		if (!DNS_MASTER->dns_mudp(info["NAME"]))
			PING_Q->send_ping_q(info["HOSTADDRESS"], info["PORTUDP"]);

		//Remote Emote?
		if(sscanf(info["ASKWIZ"],"<!!%s!!><!!%s!!>%s",asker,channel,verb)==3) {
			ob = find_player(asker);
			if(!ob) return;
			minfo = DNS_MASTER->query_mud_info(info["NAME"]);
			if( (!undefinedp(minfo["ENCODING"]) && lower_case(minfo["ENCODING"])=="gb")
			   || (!undefinedp(info["ENCODING"]) && lower_case(info["ENCODING"])=="gb")
			   || member_array(info["HOSTADDRESS"],gb_mud_list)!=-1
			) {
				info["MSG"]=LANGUAGE_D->toBig5(info["MSG"]);
			}
			//���RMSG
			if(sscanf(info["MSG"],"%*s�^��N���R\t%s\n�m    �W�R\t%s\n%*s",target_id,target_name)==4)
			{
				target=sprintf("%s(%s@%s)",target_name,capitalize(target_id),info["NAME"]);
				set("channel_asker",ob);
				set("channel_target",target);
				set("channel_id", "GFINGER");
				set("channel_verb", verb);
//				CHANNEL_D->do_channel(this_object(), "sys",
//					sprintf("gfinger_a :  %s %s %s", lower_case(channel),verb,target));
				CHANNEL_D->do_channel(this_object(), lower_case(channel), verb, 1);
				
			}
			else if(ob) tell_object(ob,info["MSG"]);
			else return;
			
			return;
		}
		// send the info to the player
		ob = find_player(info["ASKWIZ"]);
		if (ob)
		{
			//message("finger", "Finger from "+info["NAME"]+":\n"+info["MSG"],ob);
			tell_object(ob,"Finger from "+info["NAME"]+":\n"+info["MSG"]);
		}
	}
}
