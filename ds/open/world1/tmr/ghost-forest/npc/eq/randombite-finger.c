#include <armor.h>
inherit FINGER;
void create()
{
        set_name("荒咬戒" ,({ "random-bite finger","finger" }) );
        set("long","這是一只用鬼獸荒咬的骸骨所製的戒，隱隱地發出一陣黑氣。\n");
       	set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       		set("unit","只");
        	set("material", "jade");
	}
        set("armor_prop/armor", 2);
        set("armor_prop/str",2);
        set("value",1000);
    	set("limit_lv",10);
        setup();
}
