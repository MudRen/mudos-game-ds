#include <armor.h>
#include <ansi.h>
inherit FINGER;
inherit F_UNIQUE;
void create()
{
	set_name(HIC"���s����"NOR, ({ "dragon ring","ring" }) );
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o�٫����j, ���A���M��ݥX�b�z�����٫��W����ۤ@���ݮݦp��\n"
			   "���s, ��b�t�B�ɧA�hı�o���٦��z�o�H�H�����~, ���G���ǯ������O�q.\n");
		set("unit", "��");
		set("value",15000);
		set("material","gold");
	}
	set("armor_prop/armor",1);
	set("armor_prop/str",2);
	set("armor_prop/dex",2);
	set("armor_prop/int",2);
	set("armor_prop/con",2);
	setup();
}
