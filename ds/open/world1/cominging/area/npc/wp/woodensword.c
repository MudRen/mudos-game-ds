#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("��C", ({ "wooden sword" , "sword" }) );
	set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("volume",2);
		set("unit", "��");
	set("material","wood");
		set("long", "�o�O�@��D�h�M���I�k�Ϊ��C�C\n");
		set("value", 10);
	}
	init_sword(1);
	setup();
}
