#include <ansi.h>
inherit __DIR__"water";

string *exitss = ({
__DIR__"w1",__DIR__"w2",__DIR__"w3",__DIR__"w4",__DIR__"w5",__DIR__"w6",__DIR__"w7",__DIR__"w8",
__DIR__"w9",__DIR__"w10",__DIR__"w11",__DIR__"w12",__DIR__"w13",__DIR__"w14",__DIR__"w15"
});

void create()
{
        set("short", HIC"水舞之陣"NOR);
        set("long", (: ROOM_LONG :),);
        set("objects", ([
//        __DIR__"npc/oyster" : random(2)+1,
//	comment by alickyuen , no this file
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
         write(HIC"陣陣海浪襲擊你全身....\n"NOR);
         tell_object(me, HIC"你感覺身體遲鈍了些..。\n" NOR ); 
         me->add_busy(2);
         return 1;

         case 1:
         write(HIB"海浪滔滔襲擊你... \n"NOR);
         tell_object(me, HIB "你被海浪刺了些...。\n" NOR ); 
         me->receive_damage("hp",30);
         me->receive_damage("mp",30);
         me->receive_damage("ap",30);
         return 1;


         default:       
         return 1;
        }
}

