#include <armor.h>

inherit BOOTS;

void create()
{
	set_name("���q����u",({"straw boots","boots"}) );
	set("long","�@����B���R�o�쪺��u�C\n");
	set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("value",480);
	}
	setup();
}
