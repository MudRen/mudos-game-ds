#include <armor.h>
#include <ansi.h>
inherit NECK;
void create()
{
        set_name(HIW"����"NOR, ({"steel necklace","necklace"}) );
        set("long", "�@���¿����y������C\n");
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��" );
                set("armor_prop/armor", 6);
        set("material","steel");
                set("value", 1020);
        }
        setup();
}

