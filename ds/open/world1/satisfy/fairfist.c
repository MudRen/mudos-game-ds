#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name("�K���M", ({ "iron fist","fist" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "�u");
		set("long", "�o���K���M�˦b��W���I���ӵξA, ���L�����[�{��������¤O�C\n");
		set("value", 30000);
//		set("no_drop",1);
		set("no_sac",1);
		set("material", "silver");
	}
    set("weapon_prop/con",1);
    set("weapon_prop/str",1);
    set("weapon_prop/hit",3);
    set("weapon_prop/unarmed",10);
    init_fist(15);
    setup();
}

int query_autoload() { return 1; }