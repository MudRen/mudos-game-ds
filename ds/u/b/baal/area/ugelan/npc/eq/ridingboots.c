#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY"���u" NOR, ({ "riding boots", "boots" }) );
        set("long","�O�i���{�{�o�G���@�����u�C\n");
        set_weight(1500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "leather" );
                set("unit", "��" );
                set("value" , 500);
                set("volume",3);
                set("armor_prop/armor", 6);
                set("armor_prop/shield", 1);
        }
        setup();
}

