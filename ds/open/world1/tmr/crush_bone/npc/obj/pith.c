#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("碎骨精髓",({"crush-bone pith", "pith"}) );
        set_weight(80);
        set("long",@long
這是一份從碎骨皇帝身上取下來的骨髓，聽說吃了能讓人
勇氣大增，再也不會害怕毛毛蟲了。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","份");
                set("value",1);
        }
        setup();
}

void init() 
{
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
        object me;
        if(arg != "pith")
                return 0;

        me = this_player();
        if(!me) return 0;
        if(me->is_ghost()) return 0;
        if(me->is_busy() || me->is_fighting() ) return notify_fail("你正忙著，沒有空吃這個。\n");
 
        message_vision(CYN "$N將$n拿近嘴裡，唏哩呼嚕地吸起來了。\n"NOR ,me, this_object() );
        tell_object(me, HIG"你覺得非常勇敢了，覺得天塌下來也不怕。\n"NOR);
        me->start_busy(1);
        if(me->query_condition("fear") )
                me->apply_condition("fear",0);   
    destruct( this_object() );
    return 1;
}

