//updated 2000/2/20

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
          "聖母像" : "一尊大理石雕刻而成的聖母像，常被人們用來祈禱求福。\n",
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
        if (arg != "聖母像")  return 0;
        if(!objectp(present("electric note book",me) ) )
                        return 0;
        message_vision("$N跪在地上，誠心地向著聖母像祈禱。\n",me);
        tell_room(environment(me),me->query("name")+"忽然消失不見了。\n",me);
        tell_object(me,"你的眼前忽然出現一道金光，似乎你到了另一個地方。\n");
        me->move(__DIR__"church2");
        tell_room(environment(me),me->query("name")+"突然出現在你眼前。\n",me);
        return 1;
}


