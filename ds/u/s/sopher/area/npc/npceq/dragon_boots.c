#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIB"���s�ֹu"NOR ,({ "dragon boots" , "boots"  }) );
        set("long","�o�O�@���`�¦�{�{�o�G���ֹu�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set_weight(100);
        set("material", "boots");
        set("unit", "��" );
        set("value",50);
set("armor_prop/armor",5);
set("armor_prop/dodge",5);
        }
        setup();
}
