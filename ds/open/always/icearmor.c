#include <armor.h>
#include <ansi.h>
inherit ARMOR;
void create()
{
	set_name(HIC"�����_��"NOR, ({ "ice armor","armor" }) );
	set_weight(11000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�O�@��ѤT�d�����ͪ����l�s´�Ӧ����z���_�ҡC\n[�i�x�s�˳�]\n");
		set("unit", "��");
		set("material", "ice");
		//set("no_sell",1);
		set("no_sac",1);
		set("value",4800);
	}
	set("armor_prop/shield",15);
	set("armor_prop/dodge",5);
	set("armor_prop/armor",20);
	setup();
}

int query_autoload() { return 1; }