#include <weapon.h>
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("�C��O", ({ "wood plate","plate" }) );
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 0);
                set("long", "�@�ӭ]�a�����ڪ��O�P");
                }
        setup();
}
