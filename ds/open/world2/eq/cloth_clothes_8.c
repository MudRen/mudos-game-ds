#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("ＮＥＴ純棉上衣",({"net clothes","clothes"}) );
	set("long",@LONG
這是一件名牌上衣，時下年輕人的最愛。
LONG);
	set_weight(1470);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "cloth");
                set("unit", "件");
        }
        set("armor_prop/armor",8);
        setup();
        set("value",1210);
        set("volume", 4);
}
int query_autoload() { return 1; }
