#include <armor.h>
inherit BOOTS;
void create()
{
	set_name("強化型四國鐵鞋",({"s-fc iron boots","boots"}) );
	set("long",@LONG
這一雙四國產業製造的鐵皮鞋經過了渡錫處理，以防止氧化。
LONG
);
	set_weight(5500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "leather");
		set("unit", "雙");
	}
	set("value",1840);
	set("armor_prop/armor", 10);
	setup();
	set("volume", 4);
}

//int query_autoload() { return 1; }
