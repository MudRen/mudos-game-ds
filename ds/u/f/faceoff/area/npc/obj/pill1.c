#include <ansi.h>
inherit ITEM;
inherit F_PILL;

void create()
{
        set_name(HIW"�U�F"+HIC+"��"+HIR+"�r"+HIW+"��"NOR,({"pill"}));
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
         int x;
        me=this_player();
        x = me->query_condition("poison");
    if ( x > 0)
    {
    tell_object(me,HIW"�A�Pı�@�}�D�n, �ݨӬr�ʴ�z����\n"NOR);
    x = x - 1;
    }
    else
    {
     tell_object(me,HIW"�A���ݭn�A���o������\n"NOR);
    }
    return 1;

}
