#include <ansi.h>
inherit ITEM;
void delay(object me);
void create()
{
        set_name(HIY "培元金丹" NOR,({"gold pill","pill"}) );
        set("long",
"這是由泰源天國的一位奇人所練成, 據說服下後可以暫時大幅度提升能力!\n"
);
        set_weight(700);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("value",10000);
                set("unit","顆");       
        }
        setup();
}

void init()
{
        add_action("do_eat","eat");
}

int do_eat(string arg)
{
        object env;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        if(! env = environment(this_object())) return 0;
        if(env !=this_player() && !this_object()->query("no_get")) return 0;
        if( this_player()->is_busy() )
                return notify_fail("你上一個動作還沒有完成。\n");

        if(this_player()->query_temp("gold_pill") )
                return notify_fail("你已服下培元金丹了!。\n");

        message_vision("$N從懷裡拿出一顆培元金丹服下。\n",this_player() );
         tell_object(this_player(),HIY "你忽然覺得一股熱氣衝上天靈，缺盆，大椎各重穴！！\n" NOR);
        this_player()->add_temp("apply/str",3); 
        this_player()->add_temp("apply/int",3); 
        this_player()->add_temp("apply/dex",3);
        this_player()->add_temp("apply/con",3); 
        this_player()->add_temp("apply/bar",1); 
        this_player()->add_temp("apply/wit",1); 
        this_player()->add_temp("apply/tec",1); 
        this_player()->add_temp("apply/sou",1); 
        this_player()->add_temp("apply/bio",1); 
        this_player()->set_temp("gold_pill",1); 

        this_object()->set("do_eat",1);
        this_object()->set("no_drop",1);
        this_object()->set("value",50000);
        this_object()->set("no_sac",1);
        this_object()->set("no_give",1);
        call_out("delay",200,this_player() );     //附加屬性維持時間

        return 1;
}

void delay(object me)
{
        if(!me) return;
        tell_object(me,"你忽覺天靈，缺盆，大椎各重穴一陣寒氣衝上! 似乎金丹藥效已過。\n" );
        me->add_temp("apply/int",-3);
        me->add_temp("apply/dex",-3);
        me->add_temp("apply/con",-3);
        me->add_temp("apply/str",-3);
        me->add_temp("apply/bar",-1);
        me->add_temp("apply/wit",-1);
        me->add_temp("apply/bio",-1);
        me->add_temp("apply/sou",-1);
        me->add_temp("apply/tec",-1);
        me->delete_temp( "gold_pill" );
        destruct(this_object() );
}

