#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
        set_name(HIY"邪念鎧甲"NOR ,({ "evil armor","armor" }) );
        set("long",@LONG
        
    這是邪仔為了他的護衛隊，使用強大的魔力所製造出來。由於其蘊有強大的
魔力，因此可抵禦強力的攻擊，是一件少有的防具。
LONG
);
        set_weight(100);
        if ( clonep() ) set_default_object(__FILE__);
        else
        {
        	set("material", "skin");
        	set("unit", "件");
		set("volume",6);
        	set("limit_con",8);
        	set("value",7345);
	}
	set("no_sac",1);
        setup();
        set("armor_prop/armor",100);
        set("armor_prop/shield",50);
}

