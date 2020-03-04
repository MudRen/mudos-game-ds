#include <ansi.h>
#include <weapon.h>
#include <command.h>

inherit SWORD;

void create()
{
        set_name(HIY"天靈神劍"NOR, ({ "soul sword","sword" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "這是一把集天靈之氣的撼世神劍﹐看起來十分名貴且相當有殺傷力。\n");
//		set("value", 100000);
		set("material", "gem");
		set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
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