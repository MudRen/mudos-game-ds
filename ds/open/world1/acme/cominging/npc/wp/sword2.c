#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("���C",({"long sword","sword"}));

	set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("long","�o�O�@��Z�L���`�������C�C\n");
		set("unit", "��");
        set("value",1000);
		set("material","iron");
	}
	init_sword(15);
        setup();
}
