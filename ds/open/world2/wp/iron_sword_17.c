#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("���K���C",({"whiteiron longsword","longsword","sword"}) );
	set_weight(9150);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
	set("long",@LONG
�o�O�@��ѥ��K��y�Ӧ����T�`���C�C
LONG);
	}
	init_sword(17);
	setup();
        set("value",2210);
        set("volume", 6);
}

int query_autoload() { return 1; }
