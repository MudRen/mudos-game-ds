#include <weapon.h>
inherit STAFF;
void create()
{
	set_name("�K��", ({ "iron staff","staff" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o�O�@��Ѽ��K���y�Ӧ����K���C
LONG
);
		set("material", "iron");
	}
    init_staff(10);
    setup();
    set("value", 800);
    set("volume", 6);
}

int query_autoload() { return 1; }
