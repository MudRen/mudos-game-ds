#include <weapon.h>
#include <ansi.h>
inherit FORK;
void create()
{
    set_name(MAG"�i�̫�L��"NOR, ({ "Vicch","pike" }) );
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
        set("long", "�o�����ꪺ�F��, �ݨӲ@���_��, �o�S�o�X�O�H���i���������~�C");
		set("value", 20000);
        set("no_drop",1);
		set("no_sac",1);
		set("material", "gold");
	}
      set("weapon_prop/str",100);
      set("weapon_prop/con",100);
      set("weapon_prop/bar",100);
      set("weapon_prop/hit",100);
      set("weapon_prop/dex",100);
    init_fork(100); 
    setup();
}

int query_autoload() { return 1; }
