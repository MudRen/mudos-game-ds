#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("�e�y�j����", ({ "cloth" }) );
        set_weight(3000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@��`�����x�A.\n");
	set("value",245);
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 3);
        }
        setup();
}
