#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIR"���s�ֹu"NOR ,({ "fire boots" , "boots"  }) );
        set("long","�o�O�@���`����x�ۤ������ֹu�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(100);
        set("material", "boots");
        set("unit", "��" );
        set("value",50);
        set("armor_prop/armor", 80);
        set("armor_prop/dodge", 80);
        }
        setup();
}
