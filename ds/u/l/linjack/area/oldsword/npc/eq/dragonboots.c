#include <armor.h>
#include <ansi.h>
inherit BOOTS;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"���s�Թu"NOR, ({ "dragon boots","boots" }) );
	set_weight(2000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���c�W���k�ⰼ���U�äF���s, �A���ݴNı�o���I\n"
                           "�˶��r�����Pı�F, �����D�o���c������S�O���\��??\n");
		set("unit", "��");
		set("value",10000);
		set("material","cloth");
		set("limit_dex",35);
		set("limit_int",25);
		set("replica_ob",__DIR__"boots.c");
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",8);
	set("armor_prop/shield",4);
	setup();
}
