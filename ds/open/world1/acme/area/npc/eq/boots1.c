#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("���c" ,({ "boots" }) );
        set("long","�o�O�@�����q�����c�C\n");
set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "boots");
        set("unit", "��" );
        set("value",50);
	set("volume",2);
        }
        set("armor_prop/armor", 1);
        setup();
}

