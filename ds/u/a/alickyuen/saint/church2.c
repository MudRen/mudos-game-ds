// updated 26.12
#include <ansi.h>
inherit ROOM;
void create()
{
	set("short", HIC"ST．Church＠St.Rolence"NOR);
	set("long", @LONG
金光盡散後，你來到了一間新的房間。但不知為何你有一種不安的感覺
另你不寒而慄，而你又聽到一些叫聲從南面傳來，另你更加害怕。這樣中間
有一尊月影神像，但有一樣東西十分奇怪，那就是月影神像的右手伸了出來
。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"church4",
"out" : __DIR__"church",
]));
set("light",1);
	set("item_desc", ([ /* sizeof() == 2 */
  "月影神像" : "你看到月影神像的手伸了出來,你可以嘗試捉摸它的手。\n",
]));
	set("world", "future");
	set("no_clean_up", 0);
	setup();
}
void init()
{
add_action("do_touch","touch");
}
int do_touch(string arg)
{
        object me;
        me=this_player();
        if (arg != "月影神像的手") 
                   return 0;
        else {
                   message_vision("突然地上穿了個大洞，$N掉了進去。\n\n" ,me);
                   me->move(__DIR__"church3");
                   tell_room(environment(me),me->query("name")+"突然出現在你眼前。\n",me);
           return 1;
                 }
}
