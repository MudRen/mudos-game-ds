#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIW"�ջȪ��@��"NOR ,({ "silver gloves","gloves" }) );
        set("long","�@���»ȦⲤ�a���𪺿��@��\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "steel");
        set("unit", "��" );
        set("value",50);
        set("armor_prop/armor", 50);
        }
        setup();
}
