#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "�ͳ�" NOR , ({ "fish" }));
        set("long","�@�����N�����ͳ��A�A�Q�u�����T�Y�v�ܡH\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
        }
        set("heal",([
         "hp" : 15,
         "ap" : 15,
         ]));
        set("value", 150);
        setup();
}
