#include <armor.h>
#include <ansi.h>
inherit HANDS;
void create()
{
	set_name("�¥���M", ({ "gloves" }) );
	set_weight(500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�q�`���o����M, �@�w�O�`�`�������, ���F�O�@���ֿi��\n"
			   "���˦�����, ���L�ѹ�����o�بS�u�ʪ���M, ��]���ܵΪA....\n");
		set("unit", "��");
		set("value",200);
		set("material","fur");
	}
	set("armor_prop/armor",1);
	set("armor_prop/parry",5);
	setup();
}
