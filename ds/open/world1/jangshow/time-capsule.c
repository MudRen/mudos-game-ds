#include <ansi.h> 
inherit ITEM ; 
void create()
{
        set_name(HIC"時空膠囊"NOR,({"time capsule","capsule"})); 
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","顆");
        set("value",1);
        set("long","一顆透明狀的東西，裡面閃爍著點點光芒，不知道是做什麼用的\n"); 
             }
        setup();
}

void init()
{
     add_action("do_eat","eat");
     return;
}
int do_eat(string arg)
{
 object me,it,z;
 me=this_player(); 
    if(!objectp(z=present("time capsule",me) ) )
                          return notify_fail("你沒有東西可以吃啊 ? \n");
   if(!arg || arg=="") return notify_fail("你想要吃什麼？\n");
   {
    if(arg=="capsule")
    { 
     message_vision(""+me->name()+"一口氣將膠囊吞了下去，似乎面有難色。\n",me); 
     me->add_temp("capsule",1);
     call_out("do_move_room",5,me); 
    }
   }
   return 1;
}

int do_move_room()
{
    object me=this_player(),room;   
    if(me->query_temp("capsule")==1)  
    {    message_vision(HIW""+me->name()+"化做一道光束直衝雲宵！消失在地平線之上了！\n"NOR,me); 
room = load_object("/open/world1/jangshow/mage_room/room1"); 
    me->move(room); 
    me->delete_temp("capsule");  
    destruct(this_object()); 
    return 1;
    } 
    else {return 0;}
}


