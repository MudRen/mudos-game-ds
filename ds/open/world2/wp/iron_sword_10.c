#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("�K�C",({"iron sword","sword"}) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
	set("long",@LONG
�o�O�@����K���K���y�Ӧ����C�C
LONG);
	}
	init_sword(10);
	setup();
        set("value",800);
        set("volume", 6);
}

int query_autoload() { return 1; }
