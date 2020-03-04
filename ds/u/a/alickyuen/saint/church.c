//updated 26/12
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short", HIC"ST．Church＠St.Rolence"NOR);
	set("long", @LONG
這裡就是Saint內唯一一間中古式的大教堂，雖然這裡己經破爛殘缺，
但是在聖母像後射出了一道自然光。看到聖母慈祥的面容，令你的心平靜
了許多。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"dst2",
]));
set("objects", ([
__DIR__"npc/father.c" :1,
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "聖母像" : "一尊聖母像，你可以向它祈禱。\n",
]));
set("light",1);
	set("no_clean_up", 0);
	setup();
}
void init()
{
 add_action("do_pray","pray");
}
int do_pray(string arg)
{
        object me;
        me=this_player();
if( me->query_temp("readdi") )
{
        if (arg != "聖母像") 
                   return 0;
        else {
                   message_vision(HIW"$N跪在地上，誠心地向著聖母像祈禱，突然$N頭上泛起一片金光，眼睛一閃就去到另一地方了。\n\n"NOR ,me);
                   me->move(__DIR__"church2");
                   tell_room(environment(me),me->query("name")+"突然出現在你眼前。\n",me);
me->delete_temp("readdi");
me->set_temp("readdia");
           return 1;
                 }
}
}

