#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
        set_name(HIR"���s�@��"NOR ,({ "fire gloves","gloves" }) );
        set("long","�@���`�Ŧ⪺�@��\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set_weight(100);
        set("material", "steel");
        set("unit", "��" );
        set("value",50);
        set("armor_prop/armor", 40);
        }
        setup();
}
