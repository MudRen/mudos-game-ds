#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", "舊世界地下鐵");
	set("long", @LONG
這裡是一間十分老舊的車站，火車雖然還在行進著卻已經沒有多少人
在搭承，你粉難想像這裡曾經是一個人潮洶湧的地方，你仔細一看牆上塗
滿著塗鴉，牆角還有一張火車時刻表。
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "火車時刻表" : "這是一張火車的時刻表，不過已經有些破爛，你可以試著讀(read)看看。
",
]));
	set("world", "future");
	set("light", 1);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"2.c",
  "out" : __DIR__"3.c",
  "up" : __DIR__"8.c",
]));
	set("no_clean_up", 0);

	setup();
}
void init()
{
 add_action("do_read","read");
}

int do_read(string arg)
{
        object me,to;
        me = this_player();
        if( !arg ) return 0;
if(arg != "火車時刻表" ) return 0;
        message_vision("$N看了看火車時刻表。\n",me);
tell_object(me, HIW"暫時每幾分鐘有一班車，若有更改再另行通知。    \n"NOR );
        return 1;

}