#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name("�K����", ({ "iron fist","fist" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o���K���Q���W�Q, �b�{��@�Ԯɥi�H�W�[���֪�\n"
                            "�������O�C\n");
		set("needaward",15);
		set("material", "silver");
	set("value",1);
	}
    set("weapon_prop/con",1);
    set("weapon_prop/str",2);
    init_fist(30);
    setup();
}

int query_autoload() { return 1; }
