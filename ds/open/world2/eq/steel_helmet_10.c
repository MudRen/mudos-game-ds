#include <armor.h>
inherit HEAD;

void create()
{
	set_name("鋼盔",({"steel helmet","helmet"}) );
	set("long",@LONG
這頂鋼盔上面有著密密麻麻的刮痕，看起來已經用了一段時間了。
LONG);
	set_weight(2970);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material","cloth");
		set("unit", "頂");
	}
        set("armor_prop/armor",10);
        setup();
        set("value",1800);
        set("volume", 4);
}
//int query_autoload() { return 1; }