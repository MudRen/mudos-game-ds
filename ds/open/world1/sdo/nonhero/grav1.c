#include <ansi2.h>
inherit ROOM;
void create()
{
        set("short","墓室之內");
        set("long",@LONG
這裡就是傳說中的無名英雄之墓了。牆上佈滿了讚頌無名英雄的
詩、辭以及歌曲，可以看出當時戰爭的慘烈以及無名英雄保家衛國的
高尚情操。前方不遠處有一個橫躺的棺木，那個棺木似乎勾引出你的
好奇心，讓你不自覺的想前往一探究竟。不過兩旁的牆壁似乎有點不
太對勁。
LONG
        );
	set("item_desc",([
	"牆壁":"左右兩邊的牆壁，感覺有點單薄，好像一踢就會破的樣子。\n",
	]));
        set("exits",([
        "north":__DIR__"gravgate.c",
	"south":__DIR__"fere.c",
        ]));
        set("light", 0);
        setup();
}

void init()
{
	add_action("kick_well","kick");
}

int kick_well(string str)
{
	if(this_object()->query_temp("opened") != 0) return 0;
	
	if(str=="牆" || str=="牆壁")
	{
	object me;
	me=this_player();

	message_vision(
	HIG"\n$N華麗的使出一招二連踢，兩邊的牆應聲而破。\n"NOR
	HIG"\n轟的一聲，牆倒了。\n"NOR,me);

        set("long",@LONG
這裡就是傳說中的無名英雄之墓了。牆上佈滿了讚頌無名英雄的
詩、辭以及歌曲，可以看出當時戰爭的慘烈以及無名英雄保家衛國的
高尚情操。前方不遠處有一個橫躺的棺木，那個棺木似乎勾引出你的
好奇心，讓你不自覺的想前往一探究竟。兩旁的牆壁出現了破洞。
LONG
        );
        set("item_desc",([
        "牆壁":"左右兩邊的牆壁上都出現的一個大破洞。\n",
        ]));

	set("exits",([
	"east":__DIR__"grav3.c",
	"west":__DIR__"grav2.c",
        "north":__DIR__"gravgate.c",
	"south":__DIR__"fere.c",
	]));
	
	set_temp("opened",1);
	return 1;
	}
}

void reset()
{
        set("long",@LONG
這裡就是傳說中的無名英雄之墓了。牆上佈滿了讚頌無名英雄的
詩、辭以及歌曲，可以看出當時戰爭的慘烈以及無名英雄保家衛國的
高尚情操。前方不遠處有一個橫躺的棺木，那個棺木似乎勾引出你的
好奇心，讓你不自覺的想前往一探究竟。不過兩旁的牆壁似乎有點不
太對勁。
LONG
        );
	set("item_desc",([
	"牆壁":"左右兩邊的牆壁，感覺有點單薄，好像一踢就會破的樣子。\n",
	]));

	set("exits", ([
        "north":__DIR__"gravgate.c",
	"south":__DIR__"fere.c",
        ]));
	delete_temp("opened");
	::reset();
}