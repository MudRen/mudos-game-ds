#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("�K����", ({ "eight angle staff","staff" }) );
	set_weight(9100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o���K�������ءA��ݦU���@�ӤK�����K���C
LONG
);
		set("material", "iron");
	}
    init_staff(16);
    setup();
    set("value", 2350);
    set("volume", 6);
}

int query_autoload() { return 1; }
