#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
	set_name(CYN"�C���C"NOR, ({ "green stone sword","sword" }) );
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@��C�b�x�C���W�Q���C, �C���|��, �b���H���{�{,\n"
                            "�ӥB���ɵo�X��䪺�n��, �C�������D�äF����_�Ǫ��F��C\n");
		set("needaward",35);
	set("value",1);
		set("material","blacksteel");
	}
    set("weapon_prop/con",2);
    set("weapon_prop/int",2);
    set("weapon_prop/hit",25);
    set("weapon_prop/bar",1);
    set("weapon_prop/wit",-1);
    init_sword(60);
    setup();
}

int query_autoload() { return 1; }
