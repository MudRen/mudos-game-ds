#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
        set_name(HIY"�s�����C"NOR, ({ "luky sword","sword" }) );
	set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@����s���~�ߩҥ��y�����@��C�M�ݰ_�ӤQ���a�ܮz�C\n");
//		set("value", 100000);
		set("material", "steel");
		set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
//	set("weapon_prop/bar",3);
//	set("weapon_prop/bio",3);
//	set("weapon_prop/wit",3);
//	set("weapon_prop/sou",3);
//	set("weapon_prop/tec",3);
//	set("weapon_prop/str",3);
//	set("weapon_prop/int",3);
//	set("weapon_prop/con",3);
//	set("weapon_prop/dex",3);
//	set("weapon_prop/armor",300);
//	set("weapon_prop/dodge",300);
	init_sword(0);
	setup();
}

int query_autoload() { return 1; }
