#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name("�Ȧ�u�C", ({ "silver short sword","sword" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@���a��w�S���B�W�Q���¥ջȵu�C, �ܦn���áC\n");
		set("value", 30000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "silver");
	}
    set("weapon_prop/int",1);
    set("weapon_prop/wit",1);
    init_sword(12);
    setup();
}

int query_autoload() { return 1; }
