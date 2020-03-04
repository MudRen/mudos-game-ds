#include <ansi.h>

inherit ITEM;

int do_learn(string arg);

void create()
{
        set_name(HIC"夢幻百科全書"NOR,({"encyclopaedia of DS","encyclopaedia"}) );
        set_weight(800);
        set("long",@long
一本紀錄著各式各樣技能的書籍，你可以好好研究一番•
(learn <skills name> )
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
        add_action("do_learn","learn");
}

int do_learn(string arg)
{
        object me=this_player();
        if(!me->query_skill(arg)) 
                return notify_fail("這樣技能你還沒學過喔•\n");
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒空閱\讀書籍。\n");
        if(me->query_skill(arg) > 85)
                return notify_fail("你的「"+arg+"」已經到達一定火候，不用再閱\讀這本書了。\n");

        message_vision(HIC "$N細細閱\讀了"+this_object()->query("name")+"的演練方法，似乎對"+arg+"又多熟練一些了。\n" NOR,me);
        me->add_skill(arg);
        destruct(this_object());
return 1;
}
