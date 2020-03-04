#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", RED"七邪塔 "HIC"【水舞之陣】"NOR);
        set("long", @LONG
這裡看起來廣大的遼闊，風景讓人看起來，會覺得大自然的奧妙 
。你默默的聽到一些歌舞聲，你走了一陣子，你觀察了所有地方，還
是查不出歌曲是那來的歌曲聲音。
LONG);
       set("exits", ([ /* sizeof() == 3 */ 
   "north" : __DIR__"1f_2", 
   "southwest" : __DIR__"1f_4",    ]));
   
        set("no_recall", 1); 
        set("no_quit",1);       
        set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/water.c" : 4,
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

