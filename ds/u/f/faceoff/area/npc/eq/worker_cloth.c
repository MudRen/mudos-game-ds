#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�u�@�A", ({ "cloth" }) );
        set_weight(2000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@��ż����, �o�������u�@�A.\n");
                set("unit", "��");
	set("value",100);
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}
