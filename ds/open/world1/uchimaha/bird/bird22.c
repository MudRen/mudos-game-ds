#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
 set("short",HIC"天梟教"NOR"練武場");

 set("long",@LONG
你來到天梟教的練武場, 你看看四周, 發現這裡除
了一些石樁以外別無他物, 你走過去看了看石樁, 發現
原來這裡是專門練習靈翼八步訣的石樁, 你敲了敲石樁,
原本這裡的石樁硬度都不一樣, 假如一個不小心可能會
把這石樁給踩斷, 所以練起來加倍的困難。
 
LONG
    );
 
 set("exits",(["south":__DIR__"bird14",
               "north":__DIR__"bird20",
               
     ]));
 
 set("no_clean_up", 0);
 setup();
 replace_program(ROOM);
}
int do_practice(string arg)
{
        object me,weapon;       
        me=this_player();

        if(!arg) return 0;
        if(!me->query_skill("birdeight") ) return 0;
        if(arg!="bird-eight") return notify_fail("你只能練靈翼八步訣(bird-eight)。\n");

        if(me->query_skill("bird-eight")>9 )  return notify_fail("你的靈翼八步訣已有小成了，在此練步已無益了。\n");
        if(me->query("ap") <10) 
                return notify_fail("你的內勁不夠，不能練大槍訣耶。\n");

     message_vision("$N提起一口氣，踩入石樁內，開始練起靈翼八步訣裡的輕重緩急。\n");
        me->receive_damage("ap",10);
if(me->query("sk/bird-eight") )
                me->add("sk/bird-eight",random(me->query_int()) );
        else
                me->set("sk/bird-eight",random(me->query_int()) );

      if(me->query("sk/eight-bird" )>5000)
        {
                tell_object(me,HIY "經過一番苦練，你的靈翼八步訣已經架輕就熟了。\n" NOR);
        me->delete("sk/bird-eight");
          me->set_skill("bird-eight",10);
        }
        return 1;

}

           
