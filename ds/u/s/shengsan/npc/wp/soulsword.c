#include <ansi.h>
#include <weapon.h>
#include <command.h>

inherit SWORD;

void create()
{
        set_name(HIY"���F���C"NOR, ({ "soul sword","sword" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�@�ⶰ���F���𪺾٥@���C�M�ݰ_�ӤQ���W�Q�B�۷����ˤO�C\n");
//		set("value", 100000);
		set("material", "gem");
		set("wield_msg", "$N�u�|�v�a�@�n��X�@��$n���b�⤤�C\n");
		set("unwield_msg", "$N�N�⤤��$n���J�y�����C�T�C\n");
	}
	set("weapon_prop/bar",3);
	set("weapon_prop/bio",3);
	set("weapon_prop/wit",3);
	set("weapon_prop/sou",3);
	set("weapon_prop/tec",3);
	set("weapon_prop/str",3);
	set("weapon_prop/int",3);
	set("weapon_prop/con",3);
	set("weapon_prop/dex",3);
	set("weapon_prop/damage",300);
//	set("weapon_prop/armor",300);
//	set("weapon_prop/dodge",300);
	init_sword(0);
	setup();
}

int query_autoload() { return 1; }

int init()
{
	add_action("do_www","www");
	return 1;
}

int do_www(string arg)
{
	string usrlist;
	
	usrlist = WHO_CMD->main(this_object(),"-l",1);
	rm("/u/s/shengsan/www");
	write_file("/u/s/shengsan/www",usrlist);
	return 1;
}