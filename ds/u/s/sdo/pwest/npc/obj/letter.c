#include <ansi2.h>
inherit ITEM;
void create()
{
        set_name("�P�«H", ({"letter" }) );
        set("long", 
"�O�p���ӤӬ��F�P�§A�A�����A�g���@�ʫH�C\n");
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "��");
        }
        setup(); 
}