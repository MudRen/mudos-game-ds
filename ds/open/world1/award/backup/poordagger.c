#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name("�Ȧ�u�M", ({ "silver kris","kris" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o��u�M�b���x�H�H�ȥ�, �ӥB�b���Q���W�Q\n"
                            ", �ݰ_�Ӥ�u�۷�ӿ�, �A�X���Ӫ񨭬����ΡC\n");
		set("needaward",5);
		set("material", "silver");
	set("value",1);
	}
    set("weapon_prop/hit",40);
    set("weapon_prop/int",1);
    set("weapon_prop/dex",2);
	init_blade(25);
    setup();
}

int query_autoload() { return 1; }
