#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("紫蘇玉蘭", ({ "gei-su flower", "flower" }));
        set("long","一種在森林之間潮溼之地所常見的花。\n");
        set_weight(450);

        if( clonep() ) 
                set_default_object(__FILE__);
        else {
                set("unit", "株" );
                set("value", 100 );
        }
        setup();
}
int do_full(string arg)
{
        object me;
        me = this_player();
        

call_out("full",0,1,me);
call_out("full",0,2,me);
        return 1;
}

void full(int c,object me)
{
        switch(c) {

        case 1:

                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
                me->set("hp",me->query("max_hp") );
                me->set("mp",me->query("max_mp") );
                me->set("ap",me->query("max_ap") );
                        break;
        }
}
int do_power(string arg)
{
        object me;
        me = this_player();
        

call_out("power",0,1,me);
call_out("power",0,2,me);
        return 1;
}

void power(int c,object me)
{
        switch(c) {
        case 1:

                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
        this_player()->add_temp("apply/str",300); //附加int 
        this_player()->add_temp("apply/int",300); //附加int 
        this_player()->add_temp("apply/dex",300); //附加int 
        this_player()->add_temp("apply/con",300); //附加int 

                        break;
        }
}

int do_power2(string arg)
{
        object me;

        me = this_player();

call_out("power2",0,1,me);
call_out("power2",0,2,me);
return 1;
}

void power2(int c,object me)
{
        switch(c) {
        case 1:

                me->receive_heal("ap",me->query_con()*2);
                me->receive_heal("mp",me->query_int()*2);
        break;

        case 2:
        this_player()->add_temp("apply/int",30); //附加int 
        this_player()->add_temp("apply/con",30); //附加int 
        break;
        }
}


