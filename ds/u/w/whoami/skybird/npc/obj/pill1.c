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

    object me,ob;
    me=this_player();
    ob=this_object();

    if( me->query_condition("poison") > 5){
    me->apply_condition("poison", me->query_condition("poison")-(random(5)+1) );
    tell_object(me,HIW"�A�Pı�@�}�D�n, �ݨӬr�ʴ�z����\n"NOR);
     destruct(ob);
     } else {
    tell_object(me,HIW"�A���r�������٤��ݭn�A���o������\n"NOR);
    }
    return 1;

}

