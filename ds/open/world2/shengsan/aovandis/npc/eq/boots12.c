#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("閃電靴",({"flash boots","boots"}) );
	set("long",@LONG
這雙紫色的靴子有股令人難以抗拒的魅力，並不時的閃爍出耀眼電光。
LONG
);
	set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        	set("material", "cloth");
		set("unit", "雙");
	}
	set("value",1380);
	set("armor_prop/dex",2);
	set("armor_prop/armor",12);
	set("armor_prop/dodge",10);
	setup();
}
