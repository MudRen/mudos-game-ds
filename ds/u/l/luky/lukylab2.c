// Room: /u/l/luky/room/pearl_17.c
#include <ansi.h>
inherit ROOM;
inherit MOBROOM;	//需放在 inherit ROOM; 之後
void create()
{
	set("short", HIG"龍蝦第二實驗場"NOR);
	set("long", @LONG

[1;31m                                     ▃▃▃▃▃▃▃▃
                                   ▕[41m████████[40m▏[m
＿＿＿＿＿   你正走在熱鬧的大街上。＿[30;47m�齱搳搳搳搳搳歈�[m＿＿＿
"  .   -   許多當地的年輕人在這裡聚  [30;47m��[35m 自動販賣機[30m ��[m     "
:      -   會聊天。你看到東邊有一棟  [30;47m�齱搳搳搳搳搳歈�[m  "  :
= ."   -   大房子，人來人往的好不熱  [30;47m�齱陛娶���※○��[m     =
==-  " -   鬧。旁邊有一台自動販賣機  [30;47m�僓����嘵嘵�����[m   -==
￣￣￣￣￣ 。                      ￣[30;47m��[32mInsert coins[30m��[m￣￣￣
                                     [30;47m�遉丐丐丐丐丐片�[m


LONG
	);
set("objects",([
// __DIR__"automat":1,
]));
set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"lukylab1",
]));
set("item_desc",([
  "automat":"一台尚未啟用的自動販賣機。\n",
  "自動販賣機":"一台尚未啟用的自動販賣機。\n",
]));
	set("no_clean_up", 0);
	set("light",1);
	set("chance",50);	//則有 50% 的機率會出現怪物.
	set("mob_amount",3);	//則最多出現三個怪物.
	set("mob_object",({	//設定怪物檔名.
	"/open/world2/anfernee/start/npc/bug",
	"/u/l/luky/npc/mosquito"
	}) );
	setup();
	
	//注意, 繼承MOBROOM後 絕不可以有 replace_program(ROOM);
}

void init()
{
        ::init();	//注意, 若是有繼承MOBROOM的room要用到init(),則需加這一行!!

        add_action("d_creat","creat");
        add_action("d_stop","stop");
}

int d_stop(string arg)
{
 this_object()->set_temp("stop_creat",1);
 tell_object(this_player(),"怪物地雷已關閉!\n");
 return 1;
}

int d_creat(string arg)
{
 this_object()->set_temp("stop_creat",0);
 tell_object(this_player(),"怪物地雷已開啟!\n");
 return 1;
}