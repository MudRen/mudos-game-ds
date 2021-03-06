#include <ansi.h>
#define ENTER_ROOM "/open/world1/alickyuen/match/entrance"

inherit ROOM;

int doll_check(object me);
int delete_record(object me);
int record(object me);
int check(object me);
int announce(object me);

void create()
{
	set("short", "比武場出口");
	set("long", @long
這裡是比武場的出口，所有參賽者都會由這裡出來，當然亦有大
批的比武場地監督人員在這檢查各參賽者有沒帶比武場內的物資離開。
參賽者請打"out"離去。
long);
	set("light", 1);
	set("no_fight", 1);
	set("no_kill", 1);
	set("no_cast", 1);
	set("no_recall", 1);
	set("objects", ([
		__DIR__"npc/checker" : 1,
	]));

	setup();
}

void init()
{
	object me = this_player();

	if( !me ) return;

	add_action("doll_check", "out");

	if( !me->query_temp("match_player") )
		return;

	if( !me->query_temp("match_winner") )	announce(me);

	if( me->query_temp("match_winner") )	record(me);

//	doll_check(me);
	delete_record(me);
	check(me);
}

int doll_check(object me)
{
	object doll;
	me = this_player();
        message_vision(HIW"比武場監察人員正在檢查$N身上有沒有攜有比武場的物資......\n"NOR, me);

	if( objectp(doll = present("match doll", me) ) )
	{
		message_vision(HIW"比武場監察人員把你身上的"NOR+doll->query("name")+HIW"拿走了。\n"NOR, me);
		destruct(doll);
	}
	me->move(ENTER_ROOM);

	return 1;
}

int delete_record(object me)
{
	me->remove_all_killer();

	return 1;
}

int record(object me)
{
	MATCH_D->record(me);
	return 1;
}

int check(object me)
{
	MATCH_D->check(me);
	return 1;
}

int announce(object me)
{
        message("system", HIW"【"HIG"比武通告"HIW"】"HIG""+me->query("name")+NOR HIG"("+me->query("id")+HIG")在這次比武中落敗了。\n\n"NOR, users());

	return 1;
}
