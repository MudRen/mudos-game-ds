#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("��c" ,({ "wood boots","boots" }) );
        set("long","�o�O�@���¤�u�A�åѤ��Y�s�����c�l�A�ݰ_�Ӭ۷�@��C\n");
        set_weight(1000);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("material", "boots");
        set("unit", "��" );
        set("value",120);
        }
set("armor_prop/armor", 2);
        setup();
}
