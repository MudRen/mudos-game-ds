#include <ansi.h>
inherit ITEM;
inherit F_PILL;
void create()
{
        set_name(HIR "�p��" NOR , ({ "prawn" }));
        set("long","�@�����N�����p���A�A�Q�u�ͽ��G�Y�v�ܡH\n");
        set_weight(300);
        if( clonep() ) 
                set_default_object(__FILE__);
        else {
              set("unit", "��");
        }
        set("heal",([
         "hp" : 10,
         "ap" : 10,
         ]));
        set("value", 100);
        setup();
}
