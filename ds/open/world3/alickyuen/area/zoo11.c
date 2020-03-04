//update by alickyuen 30/12
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIC"ST。Park＠CyberZoo"NOR);
	set("long", @LONG
這裡是動物園內的一個小公園，遊客累了可在這裡休息一會兒，你也
可看到很多人在坐著，四處的環境很好。但你發現身後有些和人一般高的
草叢，你不禁懷疑裡面隱藏著什麼。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"zoo5",
]));
set("outdoors","land");
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}
void init()
{
	add_action("do_pass","pass");
}
int do_pass(string arg)
{
 	object me;
	me=this_player();
	if (arg != "草叢") 
                   return 0;
	else {
                   message_vision("$N在草叢堆中找了找，突然找到了一條路。\n\n" ,me);
                   me->move(__DIR__"zoo12");
                   tell_room(environment(me),me->query("name")+"走了過來。\n",me);
	   return 1;
                 }
}
