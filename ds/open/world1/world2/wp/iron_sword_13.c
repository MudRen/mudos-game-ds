#include <weapon.h>
inherit SWORD;
void create()
{
        set_name("�K���C",({"iron longsword","longsword","sword"}) );
	set_weight(7150);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "iron");
	set("long",@LONG
�o�O�@��ѥ��K��y�Ӧ����T�`���C�C
LONG);
	}
	init_sword(13);
	setup();
        set("value",1210);
        set("volume", 6);
}

int query_autoload() { return 1; }
