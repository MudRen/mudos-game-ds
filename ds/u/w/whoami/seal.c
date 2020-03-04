#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("封印符",({"sealed seal","seal"}) );
        set("long",@LONG
LONG
        );
        set_weight(50);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","張");
                set("value",500);
        }
        setup();
}

void init()
{
        add_action("do_charm","charm");
}

int do_charm(string str)
{
        object me,ob,ob1;

        me=this_player();

        if( !str ) return notify_fail("charm <目標>\n");
        if( !objectp(ob = present(str, environment(me))) )
           return notify_fail("這裡沒有這樣東西。\n");
        if(!ob->is_character() || ob->is_corpse()) 
           return notify_fail("你看清楚一點，那並不是活物。\n"); 

        tell_object(me,"嘟嘟、"+ob->query("name")+"被封招了！\n");
        ob1=new(__DIR__"noexert");
        ob1->move(ob);
        destruct(this_object());
        return 1;
}

