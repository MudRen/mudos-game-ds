#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"秘道"NOR);
        set("long", @LONG
這條陰暗的秘道在山腹中曲折延伸，不知通往何處。這裡的石壁非常
潮濕，看來附近有水源。
LONG);
        set("objects", ([
                    __DIR__"npc/boa" : 1,
        ]));
        set("exits", ([
              "westdown" : __DIR__"lane03",
              "east" : __DIR__"lane01",
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query_skill("anti_poison")) <50 && me->query_con() < 50){ 
        	tell_object(me, HIB "你忽然感到呼吸一緊，原來是這裡的空氣污濁、流通不暢。\n" NOR );      
             	tell_room(environment(me), me->name()+"突然臉色變得極為難看，並深深地吸了口氣。\n" NOR,({ me }));
             	me->receive_damage("hp", 50);
             	me->receive_damage("mp", 50);
             	me->receive_damage("ap", 50);
             	}           
}
