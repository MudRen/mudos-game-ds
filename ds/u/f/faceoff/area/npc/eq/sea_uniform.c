#include <armor.h>
#include <ansi.h>
inherit CLOTH;
void create()
{
        set_name("��A", ({ "uniform" }) );
        set_weight(2000);
        set("material","cloth");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@��ݰ_�ӫܫӪ���A.\n");
	set("value",400);
                set("unit", "��");
                set("material", "cloth");
                set("armor_prop/armor", 2);
        }
        setup();
}
