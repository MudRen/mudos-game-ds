#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name("艮山黃金戰甲" ,({ "kop armor","armor" }) );
        set("long","這是神武教護法之一艮山將所穿著的戰甲，防禦力不錯，但卻十分沉重。\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
        set("limit_con",25);
        set("limit_str",15);
        set_weight(20000);
        set("material", "gold");
        set("unit", "件" );
        set("value",3000);
        set_temp("apply/armor",2);
        set_temp("apply/shield",7);
        set("armor_prop/armor", 20);
        set("armor_prop/dex",-2);
		set("volume",5);
        set("armor_prop/con",3);
        }
        setup();
}
