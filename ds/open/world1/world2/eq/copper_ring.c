#include <armor.h>
inherit FINGER;
void create()
{
	set_name("銅戒指",({"copper ring","ring"}) );
	set("long",@LONG
一只老舊的戒指，上面隱約刻了『結婚十週年紀念』幾個字。
LONG
	);
	set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "copper");
		set("unit", "枚");
	}
        set("armor_prop/armor",1);
        setup();
        set("value",210);
        set("volume", 1);
}
