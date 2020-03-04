#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"七邪塔 "HIC"【水舞之陣】"NOR);
        set("long", @LONG
在此刻，身旁完全靜如止水，沒有任何的吵雜聲，就好像身在大
自然裡這麼的安祥寧靜，不過古人稱之為暴風雨前的寧靜，你無法預
知下一秒會發生什麼事，所以此刻內心感覺膽顫不已。
LONG);
        set("exits", ([ /* sizeof() == 3 */ 
   "northeast" : __DIR__"1f_3", 
   "southeast" : __DIR__"1f_5",    ]));
        
        set("no_recall", 1); 
        set("no_quit",1);       
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/water2.c" : 4,
        ]));
        set("world", "past");
        set("no_clean_up", 0);
        set("light",0);

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


