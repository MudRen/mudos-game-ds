#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "湖底深處");
        set("long", @LONG
這是朝天湖最深處的地方，四周一片漆黑，你似乎感覺到四週圍的水
流非常快速，而在你面前，似乎有二點火炬在瞪視著你。
LONG
        );
        set("exits", ([ /* sizeof() == 1 */
          "up" : __DIR__"wa7.c",
        ]));

          set("objects",([
        __DIR__"npc/dragon":1,
        ]) );
        set("world", "past");
        set("light",1);
        set("no_clean_up", 0);

        setup();
}

int room_effect(object me)
{
        if(!userp(me)) return 1;
        if(random(100) < 60) return 1;
        message_vision("四週的水流忽然急速地轉了起來.......。\n",me);
        if(me->query_skill("dodge") < 50 || random(10) < 3 )
        {
                tell_object(me,HIC"你被水流轉得昏頭轉向，一時認不清方向...\n" NOR ); 
                me->add_busy(1);
        }
        return 1;
}

