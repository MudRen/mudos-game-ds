#include <armor.h>
inherit FINGER;
void create()
{
	set_name("�C�ɫ���", ({ "bronze ring", "ring" }) );
	set("long", "�@�L�W���g�����C�`���٫��C\n");
	set_weight(1600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "�u" );
		set("armor_prop/armor", 2);
	set("material","copper");
		set("value", 200);
	}
	setup();
}
