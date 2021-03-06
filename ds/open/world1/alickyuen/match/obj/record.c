/*	File : /obj/board/record.c		*
 *	write by -alickyuen@ds-		*
 *	每月一次比武大會記錄板		*/

#include <ansi2.h>

inherit ITEM;

void create()
{
	set_name(HIC"『夢幻七域比武大會』報告板"NOR, ({ "notice board", "notice", "board" }) );
	set("no_get", 1);
	set("no_sac", 1);
	set("value", 0);
	set("long", " ");

	setup();
}

void init()
{
	object me = this_player();

	if( !me ) return;
	if( !userp(me) ) return; // 若沒 me 又判斷userp的話會出bug -alickyuen@ds-
	
	add_action("do_look", "look");
	add_action("sign_list", "sign");
	add_action("reset_record", "reset");
}

int sign_list(string arg)
{
        return MATCH_D->sign_list(arg);
}

int reset_record()
{
	if( !wizardp(this_player()) ) return 1;
	return MATCH_D->reset_record();
}

int do_look(string arg)
{
	string msg;

	if ( arg == "board" || arg == "notice" )
	{
		if( wizardp(this_player()) ) msg = "請用 reset 指令清除參賽名單。\n";
			else msg = "";
		msg += MATCH_D->do_list();
		return this_player()->start_more(msg);
	}
}
