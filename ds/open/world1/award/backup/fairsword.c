#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("�Ŧ���C", ({ "blue sword","sword" }) );
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "�o�O�@���a��w�S���B�W�Q�����Ŧ�u�C, �ܦn���áC\n");
		set("needaward",15);
		set("material", "silver");
	set("value",1);
	}
    set("weapon_prop/dex",1);
    set("weapon_prop/con",1);
    init_sword(35);
    setup();
}

int query_autoload() { return 1; }

