inherit ITEM;
void create()
{
    set_name("����",({ "chicken soup","soup" }));
    if( clonep() )
    set_default_object(__FILE__);
    else
    {
       set("no_give",1);
       set("no_put",1);
       set("no_sell",1);
       set("unit","�J");
    }
    set_temp("invis",3);
    setup();
}

void init()
{
    add_action("do_full", "full");
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
