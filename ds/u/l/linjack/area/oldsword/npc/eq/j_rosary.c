#include <armor.h>
#include <ansi.h>
inherit NECK;
inherit F_UNIQUE;
void create()
{
	set_name("�ɦ�]", ({ "jade rosary","rosary" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o��]�ٯu�O�Q��������, �������_�ɩҦꦨ, �i�O\n"
                           "�A���T�Q�Q, �J�w�|�j�Ҫ�, �n�o�ثU�𪺦�]���?\n");
		set("unit", "��");
		set("value",8000);
		set("replica_ob",__DIR__"rosary");
		set("material","jade");
	}
	set("armor_prop/armor",2);
	set("armor_prop/int",3);
	set("armor_prop/wit",1);
	set("armor_prop/tec",-1);
	set("armor_prop/show_damage",1);
	setup();
}
