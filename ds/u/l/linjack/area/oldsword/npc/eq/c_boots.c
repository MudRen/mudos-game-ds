#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
	set_name("�涳�c", ({ "cloud boots","boots" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","�o���c�l�D�`�����ӥB����, ť����F�i�H�涳�y��\n"
                           "�몺�b�Ť��樫, �ӥB��u�륩, �����O����W�a�Ұ�.\n");
		set("unit", "��");
		set("value",8000);
		set("material","cloth");
		set("limit_dex",10);
		set("limit_int",5);
	}
	set("armor_prop/dex",1);
	set("armor_prop/armor",4);
	set("armor_prop/shield",2);
	setup();
}
