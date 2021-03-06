#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIR"秘道"NOR);
        set("long", @LONG
這條陰暗的秘道在山腹中曲折延伸，不知通往何處。前面的道路越來
越暗，你快要看不見東西了。地上散落著幾個火折，似乎還可以使用
(use fire)。這裡空氣污濁，還夾雜著一股刺鼻的味道，你一走過來
便覺得頭腦發暈，像是中毒了。
LONG);                
        set("exits", ([
              "west" : __FILE__,
              "east" : __DIR__"lane03",
              "north" : __DIR__"lane04",
              "south" : __FILE__,    
        ]));
   set("objects", ([
       __DIR__"obj/fire" : 1,
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
        add_action("do_use", "use");
        add_action("do_push", "push");
}


int do_use(string arg)
{
        object me;
        me = this_player();
        if( !arg || arg=="" ) return 0;
        if (!present("fire", me))  return 0;
        if( arg=="fire" ) {
             write("你點燃了火折，發現前面石壁上有一洞口，但被巨石堵住了，不知能不能推(push)開它。\n");
             this_player()->set_temp("marks/推", 1);
             return 1;
       }
}

int do_push(string arg)
{
        object me = this_player();
        
        if( (int)me->is_busy() || me->is_fighting()) 
        	return notify_fail("你正忙著呢。\n");
        	
        if (arg == "stone"){    
        	if (me->query_temp("marks/推") ) {
          		if(me->query("class1") != "天梟派" ){
               			me->add("hp", -(1+random(100)));
               			me->add("ap", -(1+random(100)));
               			me->add("mp", -(1+random(100)));
               			message_vision(HIR "$N運氣猛力向巨石一擊，結果不但沒推開它，反而震傷了自己。\n" NOR, me);
               			me->unconcious();
               			return 1;
               			}
           		else{
            			message_vision("$N出掌抵住巨石，猛地一推將巨石推開一條縫鑽了出去。\n", me);  
            			me->move(__DIR__"laneout");
            			message("vision", me->name() + "從亂石堆裡鑽了出來。\n",environment(me), ({me}) );
            			this_player()->delete_temp("marks/推");
            			return 1;
          			}
        		}
       		}
        else {
            	write("你想推什麼？\n");
            	return 1;
        	}
}
