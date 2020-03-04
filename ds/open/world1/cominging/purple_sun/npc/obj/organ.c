#include <ansi.h>
        
inherit ITEM;

void create()
{
        set_name("獸王內臟",({"king organ", "organ"}) );
        set_weight(80);
        set("long",@long
這是一團漆黑血淋淋的內臟，散發著噁心的臭味。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","團");
                set("value",0);
        }
        setup();
}

void init() 
{
        add_action("summon_book", "eat");
}

int summon_book(string arg)
{
        object me;
        if(arg != "organ")
                return 0;

        me = this_player();
    if(!me) return 0;
    if(me->is_ghost()) return 0;
         if(me->query("int") < 5) return notify_fail("你已經夠笨了，不需要再吃這個。\n");
 
    message_vision(CYN "$N忍淚\咬牙將$n吞下肚裡。\n"NOR ,me, this_object() );
        tell_object(me, HIG"你覺得腦袋漲痛的非常厲害，好像變笨不少了。\n"NOR);
        me->set("int", me->query("int")-1);
    me->start_busy(1);
        me->save();
   
    destruct( this_object() );
    return 1;
}

