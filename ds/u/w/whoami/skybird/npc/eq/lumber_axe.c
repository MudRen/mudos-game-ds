#include <weapon.h>
#include <ansi.h>
inherit AXE;
void create()
{
	set_name("�A���K��", ({ "lumber axe","axe" }) );
	set_weight(17500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�`�K��w�g�G������, ���L�b�������`�W�Q�C\n");
		set("value", 60000);
		set("material", "iron");
		set("limit_skill",20);
		set("limit_str",35);
	}
    set("weapon_prop/dex",-2);
    set("weapon_prop/con",2);
    set("weapon_prop/parry",3);
    set("weapon_prop/dodge",-3);
    init_axe(27);
    setup();
}
