#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"秘道"NOR);
        set("long", @LONG
這條陰暗的秘道在山腹中曲折延伸，不知通往何處。前面的道路越來
越暗，你快要看不見東西了。這裡空氣污濁，還夾雜著一股刺鼻的味道，
你一走過來便覺得頭腦發暈，像是中毒了。
LONG);                
        set("exits", ([
              "west" : __DIR__"lane04",
              "east" : __FILE__,
              "north" : __FILE__,
              "south" : __DIR__"lane02",
        ]));
        setup(); 
}

void init()
{    
  	object me = this_player();
     	if (random(me->query_skill("anti_poison")) <50 && me->query_con() < 50){ 
        	tell_object(me, HIB "你忽然感到呼吸一緊，原來是這裡的空氣污濁、流通不暢。\n" NOR );      
             	tell_room(environment(me), me->name()+"突然臉色變得極為難看，並深深地吸了口氣。\n" NOR,({ me }));
             	me->receive_damage("hp", 60);
             	me->receive_damage("mp", 50);
             	me->receive_damage("ap", 20);
             	}               
}
