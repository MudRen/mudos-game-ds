#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�]���", ({ "black suit","suit" }) );
        set_weight(2500);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@��b�]�߬諸��A.\n");
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}
