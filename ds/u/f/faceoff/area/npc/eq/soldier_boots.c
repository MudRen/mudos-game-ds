#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIC"水師軍靴"NOR, ({ "boots" }) );
        set_weight(3600);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","一雙水師穿著作戰的靴子, 相當厚實!.\n");
                set("unit", "雙");
                set("material","fur");
	set("value",145);
                set("weapon_prop/dex",-1);
	set("weapon_prop/con",1);
                set("armor_prop/armor", 8);
        }
        setup();
}
