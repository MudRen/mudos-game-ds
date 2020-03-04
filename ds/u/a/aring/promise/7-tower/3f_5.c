#include <ansi.h>
inherit __DIR__"desert";

string *exitss = ({
__DIR__"3f_1", __DIR__"3f_2", __DIR__"3f_3", __DIR__"3f_4", __DIR__"3f_5", __DIR__"3f_6",
__DIR__"3f_7", __DIR__"3f_8", __DIR__"3f_9",__DIR__"3f_10", __DIR__"3f_11",__DIR__"3f_12", __DIR__"3f_13",});

void create()
{
        set("short", RED"七邪塔 "YEL"【土輪之陣】"NOR);
        set("long", (: ROOM_LONG :),);
        set("objects", ([
        __DIR__"npc/rock" : random(2)+1,
]));
        set("exits", ([ 
        "west" : exitss[random(sizeof(exitss))],
        "east" : exitss[random(sizeof(exitss))],
        "north" : exitss[random(sizeof(exitss))],
        "south" : exitss[random(sizeof(exitss))],
]));
        setup();
}
 int room_effect(object me)
{
        switch(random(2))
        {


         case 0:
         write(HIY"滾滾沙塵侵襲你而來....\n"NOR);
         tell_object(me, HIW"你怠慢了些..。\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIY"酷熱的陽光吸乾了你的體力... \n"NOR);
         tell_object(me, HIB "你似乎有些脫水...。\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;

        }
}


