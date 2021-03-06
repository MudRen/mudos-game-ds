#include <ansi2.h>
inherit ROOM;

void create()
{
	set("short", "渾沌大廳");
	set("long", @LONG
這裡是擁有奇異力量的大廳，而奇異力量的來源就是正中央的時
空門。這個門擁有十分特殊的能力，可以穿梭在各區域裡，可以說是
十分好用的魔法道具。
LONG
	);
	set("item_desc",([
        "時空門":"這是一扇神秘的石門，上面雕刻著張牙舞爪的五色巨龍，栩栩如生\n"
        	 "的樣子讓人有點害怕，使用方法請乞求門 (help door)的幫忙吧！\n",
        ]));
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  		"north" : __DIR__"workroom",
	]));

	setup();
}
void init()
{
	add_action("do_help","help");
}
int do_help(string str)
{
	if(str != "door") return 0;
	write(HIW"你想要穿越(pass)到哪裡？\n"NOR);
	add_action("do_pass","pass");
	return 1;
}
int do_pass(string str1)
{
	if(!str1)
	{
	message_vision(
	HIW"現在能去的地方有：\n\n"NOR
	HIW"1.無名英雄之墓\n\n"NOR
	HIW"2.迷霧森林\n\n"NOR
	HIW"3.無相法環\n\n"NOR
	HIW"請用『pass 數字』穿越時空\n"NOR,this_player()
	);
	return 1;
	}
	if(str1 =="1")
	{
	message_vision(
	HIW"$N用力的踢著石門，大喊著：還不帶我去無名英雄之墓！\n"NOR
	HIW"忽然門產生一股很大的吸引力，將$N拉扯進去。\n"NOR,this_player()
	);
	
	this_player()->move(__DIR__"nonhero/h_d.c");
	return 1;
	}
	if(str1 == "2")
	{
	message_vision(
	HIW"$N哀求著石門說：讓我去迷霧森林啦！\n"NOR
	HIW"忽然門產生一股很大的吸引力，將$N拉扯進去。\n"NOR,this_player()
	);
	
	this_player()->move(__DIR__"pwest/path1.c");
	return 1;
	}
	if(str1 == "3")
	{
	message_vision(
        HIW"$N對著石門說：我要去無相法環...\n"NOR
	HIW"忽然門產生一股很大的吸引力，將$N拉扯進去。\n"NOR,this_player()
	);
	
	this_player()->move(__DIR__"nonhero/cir12.c");
	return 1;
	}
	else
	{
	write(HIW"你想去"+str1+HIW"阿？麻煩自己走路吧！\n"NOR);
	}
	return 1;
}
