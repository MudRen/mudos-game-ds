#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(HIR"�i�f�i��-�C"NOR, ({ "CocaCola","sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��C�b�x�C���W�Q���C, �C���|��, �b���H���{�{,\n"
                            "�i�H�٪��W��O�@���_�C,�O�i�f�i�ֱM�ΪZ���C\n");
		set("value", 45000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "steel");
	}
    set("weapon_prop/str",1);
    set("weapon_prop/parry",9);
    set("weapon_prop/hit",5);
    set("weapon_prop/bio",1);
    set("weapon_prop/bar",1);
    set("weapon_prop/tec",1);
    set("weapon_prop/wit",1);
    set("weapon_prop/sou",1);
    init_sword(10);
    setup();
}

int query_autoload() { return 1; }