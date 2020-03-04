#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"八二丹"NOR, ({ "eight-two pill","pill" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "開羅長城之祭師所製藥丸，通常只有皇室的人才吃的到，對身體有很大的幫助，力量大大提升。\n");
                set("unit", "片");
                set("value", 10000);  
                set("food_remaining",1);
        } 
                }

void init()
{
     add_action("do_eat","eat");
}
int do_eat(string arg)
{ 
    object me,x;
    me=this_player();
    if(!arg || arg!="pill") return notify_fail("What?你要吃什麼?[pill]\n");
    if(!objectp(z=present("eight-two pill",me) ) )
    return notify_fail("你沒有東西可以吃呀?\n"); 
    {    message_vision(HIG""+me->name(1)+"吃下了一顆"+this_object()->name(1)"+。\n"NOR,me);
    destruct(z);
    }
    switch(random(10)){
                      cose 0: 
                            tell_object(me,HIR"你忽然感到一股暖流...身體狀況漸漸轉好..\n"NOR);
                            set("heal_hp",600);   
                            set("heal_ap",500);
                            set("heal_mp",400); 
                            break;
                      case 1:
                            me->set_temp("apply/bar",1);
                            me->set_temp("apply/bio",1);
                            me->set_temp("apply/wit",1);
                            me->set_temp("apply/str",3);
                            me->set_temp("apply/con",3);
                            me->set_temp("apply/int",3);
                            me->set_temp("apply/dex",3);
                            call_out("delay",300,this_object());
                            break;  
                       }
}void delay(string arg)
{
     if(!me)return;
     tell_object(me,"\n");
     me->set_temp("apply/bar",-1);
     me->set_temp("apply/bio",-1);
     me->set_temp("apply/wit",-1);
     me->set_temp("apply/str",-3);     me->set_temp("apply/dex",-3);     
     me->set_temp("apply/int",-3);
     me->set_temp("apply/dex",-3);
}
