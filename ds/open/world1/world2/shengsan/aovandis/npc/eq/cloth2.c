
#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("花襯衫",({"color shirts","shirts"}) );
	set("long","這是一件很俗氣的花襯衫，最上面的釦子還被拆掉了。\n");
	set_weight(870);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("value",370);
        set("armor_prop/armor",4);
        setup();
}

