#include <armor.h>
#include <ansi.h>
inherit NECKLACE;
void create()
{
        set_name("�ѱ��@����", ({ "sky amult","amult" }) );
        set_weight(1000);
        set("material","wood");
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@�Ӥѱ����@����.\n");
                set("unit", "��");
                set("material", "wood");
                set("armor_prop/armor", 2);
		set("armor_prop/shield",2);
        }
        setup();
}
