#include <armor.h>
#include <ansi2.h>
inherit HEAD;
void create()
{
        set_name("奈斯的頭巾", ({"nice's hood","hood" }) );
        set("long", 
"一條頗髒的頭巾，頭巾內側寫著『奈斯』，上面有一塊乾掉的血跡。\n");
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "條");
        set("value",100);
        set("material","cloth");
	}
	set("armor_prop/armor",2);
	set("volume",1);
        setup(); 
}