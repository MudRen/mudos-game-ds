#include <ansi.h>
inherit ITEM;
void create() 
{
          set_name(HIC"車票"NOR,({"ticket"}) );
           set("long","一張浮刻著[地下城->主城]的車票(use ticket)\n");
               set("value",300);
               set_weight(2000);
            if(clonep() ) 
       set_default_object(__FILE__);
            else {
               set("unit","張");
                  }
      setup();
}

void init()
{
        add_action("do_use","use");
}

int do_use(string arg)
{ 
        object me,ob;
        if( !this_object() ) return 0;        
        if( !this_object()->id(arg) ) 
   return notify_fail("你想要在這裡使用啥 ﹖\n");
        ob=this_object();
        me=this_player(); 
                message_vision(HIY+me->query("name")+"拿出手上的車票一晃, 一台電車立刻飛奔而來把"+me->query("name")+"載走了。\n" NOR ,me);
   me->move("/open/world3/tmr/basic/train_station1.c");
                message_vision(HIY"電車突然出現在你面前, "+me->query("name")+"從車上緩步走出。\n" NOR ,me);
        destruct(ob);
  return 1;
}

