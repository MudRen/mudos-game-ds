#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIW"萬靈"+HIC+"解"+HIR+"毒"+HIW+"丹"NOR,({"pill"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("value", 10);
        }
}
void init()
{
     add_action("do_eat","eat");
}

int do_eat(string arg)
{ 

    object me,ob;
    me=this_player();
    ob=this_object();

    if( me->query_condition("poison") > 5){
    me->apply_condition("poison", me->query_condition("poison")-(random(5)+1) );
    tell_object(me,HIW"你感覺一陣涼爽, 看來毒性減弱不少\n"NOR);
     destruct(ob);
     } else {
    tell_object(me,HIW"你中毒的情形還不需要服食這顆丹藥\n"NOR);
    }
    return 1;

}

