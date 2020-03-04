#include <ansi.h>
#define SOPHER "/u/s/sopher/"
inherit ROOM;
void create()
{
        set ("short", HIC"HANS集團時空裂縫閘門"NOR);
        set ("long", @LONG
這裡就是時空裂縫了！你懷著侃刻不安的心踏上了第一步
，朝著改變歷史的目標踏出一大步！(step)
LONG);  
        
        set("exits", ([
        "south" : __DIR__"time",
        "step" : __DIR__"road1",
        ]) );
        set("no_clean_up", 0);
        set("light",1);
        setup();
        
        }
void init()
{ 
       add_action("do_step","step");
}
int do_step()
{
  object me;
  me=this_player();
  tell_object(me, HIW "你伸長了右腳，小心翼翼的踏出了第一步.\n\n"NOR);
  tell_object(me, HIR "突然！！你被這到閘門吸住了！\n\n" NOR );
  tell_object(me, HIC "你四周的環境漸漸起了變化！\n\n\n" NOR );
  tell_object(me, HIB "你雙眼一閉，昏了過去\n" NOR );
  tell_object(me, HIW "你睜開了眼睛，你發現你到了古代？...\n" NOR );
 return 0;
}          
