#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIY"�����G�ּi"NOR, ({ "gold fur boots","boots" }) );
        set_weight(3000);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","�@���Q���H���Ҭ諸�c.\n");
                set("unit", "��");
	set("value",3000);
                set("material","fur");
                set("weapon_prop/dex",-1);
                set("armor_prop/shield",1);
                set("armor_prop/armor", 5);
        }
        setup();
}
