#include <ansi.h>
inherit ITEM;
int do_load(string arg);
void create()
{
        set_name("技巧晶片-喚風術技巧",({"summon_wind ic","ic"}) );
        set_weight(80);
        set("long",@long
這是一片晶片，上頭記載著「喚風術」的用法。(load ic)
long
);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","片");
                set("value",0);
        }
        setup();
}
void init()
{
        add_action("do_load","load");
}

int do_load(string arg)
{
        object me=this_player();
        if(arg!="ic") return 0;
        if(me->is_fighting() || me->is_busy() )
                return notify_fail("你正忙著，沒空載入晶片。\n");
        if( query("do_load") )
                return notify_fail("這晶片已經被使用了，你無法再次讀取。\n");
        if(me->query_spell("summon_wind") > 60)
                return notify_fail("你的「喚風術」已經熟練多了，晶片已經對你沒用了。\n");
        message_vision(HIC "$N載入了晶片上的技巧，似乎領悟到一種技巧。\n" NOR,me);
        me->add_spell("summon_wind");
        set("do_load",1);
return 1;
}

