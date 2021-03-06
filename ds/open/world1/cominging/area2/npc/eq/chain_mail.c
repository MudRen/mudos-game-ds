#include <armor.h>
inherit ARMOR;

void create()
{
        set_name("鎖子甲", ({ "chain mail","mail" }) );
        set_weight(5400);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("long",
			"用一層層鐵皮連接而成的一套裝甲，上面還有些凹洞，顯示過有些撞擊，\n"
			"這種裝具在大城市之中，可算是高級裝備，不過穿上去速度會因為重量而\n"
			"減少了些。\n");
                set("unit", "套");
                set("material", "peel");
		set("value", 8400);
                set("armor_prop/armor", 13);
                set("armor_prop/dex",-2);
        }
        set("wear_msg","$N穿上一件$n，速度好像減慢了一些。");
        set("unequip_msg","$N卸下一套$n，似乎輕鬆了許多。");
        setup();
}