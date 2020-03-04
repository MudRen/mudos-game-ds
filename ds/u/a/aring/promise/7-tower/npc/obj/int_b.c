#include <ansi.h>

inherit ITEM;

void create()
{
        set_name("智慧之書",({"int of book","book"}) );
        set_weight(80);
        set("long",@long
增加經驗的書籍，請打(read book)來增加力量。
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","本");
                set("value",0);
        }
        setup();
}
 
void init()
{
        add_action("do_read","read");
}

int do_read(string arg)
{
        object me=this_player();
        if(arg!="book") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒空閱\讀書籍。\n");
        message_vision(HIG "$N專心的閱\讀智慧之書，增加了不少智慧。\n" NOR,me);
               me->add("int",1);
        destruct(this_object());
return 1;
}
