#include <armor.h>
inherit CLOTH;
void create()
{
        set_name( "蛇鱗", ({ "snake cloth","cloth","snake" }) );
	set("long","這是一件從蛇身上取下來的皮，可供穿著，看起來似乎很沉重。\n");
        set_weight(2900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("material", "cloth");
		set("value", 100);
		set("volume",3);
	set("material","fur");
                set("armor_prop/armor", 2);
        }
        setup();
}
