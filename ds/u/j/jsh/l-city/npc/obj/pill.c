#include <ansi.h>
inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name(HIY"�K�G��"NOR, ({ "eight-two pill","pill" }) );
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "�}ù���������v�һs�ĤY�A�q�`�u���ӫǪ��H�~�Y����A�鶴�馳�ܤj�����U�A�O�q�j�j���ɡC\n");
                set("unit", "��");
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
    if(!arg || arg!="pill") return notify_fail("What?�A�n�Y����?[pill]\n");
    if(!objectp(z=present("eight-two pill",me) ) )
    return notify_fail("�A�S���F��i�H�Y�r?\n"); 
    {    message_vision(HIG""+me->name(1)+"�Y�U�F�@��"+this_object()->name(1)"+�C\n"NOR,me);
    destruct(z);
    }
    switch(random(10)){
                      cose 0: 
                            tell_object(me,HIR"�A���M�P��@�ѷx�y...���骬�p������n..\n"NOR);
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
