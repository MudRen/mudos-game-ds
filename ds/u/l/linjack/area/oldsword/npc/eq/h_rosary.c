#include <armor.h>
#include <ansi.h>
inherit FIST;
void create()
{
	set_name("�x�W��]", ({ "hands rosary","rosary" }) );
	set_weight(300);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�ئ�]����p��, ���౾�b��l�W, ���i�H�����J����,\n"
                           "���n�ɩ|���˼Ī�����.\n");
		set("unit", "��");
		set("value",500);
		set("material","wood");
	}
	set("weapon_prop/armor",1);
	set("weapon_prop/str",1);
	init_fist(10);
	setup();
}
