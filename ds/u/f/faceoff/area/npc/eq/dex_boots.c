#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name(HIW"玲瓏靴"NOR, ({ "boots" }) );
        set_weight(3500);
        if( clonep() )
        set_default_object(__FILE__);
        else {
                set("long","這是一雙由步六狐所製成的靴子, 看來相當珍貴!\n");
                set("unit", "雙");
	set("value",10000);
                set("material","fur");
	 set("armor_prop/dex",2);
	set("armor_prop/con",1);
                set("armor_prop/shield",2);
                set("armor_prop/armor", 16);
        }
        setup();
}
