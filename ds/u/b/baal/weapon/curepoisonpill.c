#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIW"�U�F"HIC"��"HIR"�r"HIW"��"NOR,({"pill"}));
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10);
        }
}
void init()
{
     add_action("do_eat","eat");
}

int do_eat(string arg)
{ 

         object me;
        if( !this_object() ) return 0;
        if( !this_object()->id(arg) ) return 0;
        me=this_player();
    me->set("conditions/poison",0);
              return ::do_eat(arg);
}

