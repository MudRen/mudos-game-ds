#include <weapon.h>
#include <ansi.h>
inherit DAGGER;
void create()
{
	set_name(HIR"�i�f�i��-�P��"NOR, ({ "CocaCola","dagger" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�u�O�@��ʻs�ݳy���u�M.......���L�����p�ʪ��i�H�j�j�ΡC\n");
		set("value", 1000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "iron");
	}
    set("weapon_prop/hit",10);
    init_dagger(5);
    setup();
}

int query_autoload() { return 1; }