// user.c

#include <origin.h>
#include <user.h>

inherit CHARACTER;
inherit F_ALIAS;
inherit F_EDIT;
inherit F_MORE;
inherit F_MESSAGE;
inherit F_AUTOLOAD;
inherit F_SAVE;
inherit F_QUEST;

nosave int last_age_set;

void create()
{
	::create();
	set_name("�ϥΪ̪���", ({ "user object", "user", "object" }) );
}

void terminal_type(string term_type)
{
	set_temp("terminal_type", term_type);
	message("system", "�׺ݾ����A�]�w�� " + term_type + "�C\n", this_object());
}

void reset()
{
	if( (int)query("thief") > 0 ) this_object()->delete("thief");
}

// This is used by F_SAVE to determine the filename to save our data.
string query_save_file()
{
	string id;

	id = geteuid();
	if( !id ) id = getuid();
	if( !stringp(id) ) return 0;
	return sprintf(DATA_DIR "user/%c/%s", id[0], id);
}

int save()
{
	int res;

	save_autoload();
	res = ::save();
	clean_up_autoload();		// To save memory
	return res;
}

// This function updates player's age, called by heart_beat()
void update_age()
{
	// Update the time we spend on mudding, using method from TMI-2 mudlib.
	if( !last_age_set ) last_age_set = time();
	if(!this_object()->is_inactive()) add("mud_age", time() - last_age_set);
	last_age_set = time();
	set("age", 14 + (int)query("age_modify") + ((int)query("mud_age") / 86400));
}

void setup()
{
	// We want set age first before new player got initialized with
	// random age.
	update_age();

	::setup();
	restore_autoload();
}

void user_dump(int type)
{
	switch(type) {
		case DUMP_NET_DEAD:
			tell_room( environment(), query("name") + "�_�u�W�L "
				+ NET_DEAD_TIMEOUT/60 + " �����M�۰ʰh�X�o�ӥ@�ɡC\n");
			command("quit");
			break;
		case DUMP_IDLE:
                        if(!wizardp(this_object()) && !this_object()->is_inactive() )
                        {
			  tell_object( this_object(), "�藍�_�M�z�w�g�o�b�W�L " 
				+ IDLE_TIMEOUT/60 + " �����F�M�ФU���A�ӡC\n");
			  tell_room( environment(), "�@�Ӷ¬}�w�w���U, �N�o�b����" + query("name")
				+ "�]��M�M�ấ���Y�p..�C�C�����F�C\n", ({this_object()}));
			  command("quit");
			} else return;
			break;
		default: return;
	}
}

// net_dead: called by the gamedriver when an interactive player loses
// hir network connection to the mud.
void net_dead()
{
	object link_ob;

	set_heart_beat(0);
	if( objectp(link_ob = query_temp("link_ob")) )
		destruct(link_ob);

	// Stop fighting, we'll be back soon.
	remove_all_enemy();
	this_object()->clear_map_skill(1);
	this_object()->dismiss_team();
	set_temp("netdead", 1);
	if( userp(this_object()) )
	{
		call_out("user_dump", NET_DEAD_TIMEOUT, DUMP_NET_DEAD);
	    tell_room(environment(), query("name") + "�_�u�F�C\n", this_object());
	    CHANNEL_D->do_channel(this_object(), "sys", "�_�u�F�C");
	} else {
		command("quit");
	}
}

// reconnect: called by the LOGIN_D when a netdead player reconnects.
void reconnect()
{
	set_heart_beat(1);
	set_temp("netdead",0);
	remove_call_out("user_dump");
	tell_object(this_object(), "���s�s�u�����C\n");
}

