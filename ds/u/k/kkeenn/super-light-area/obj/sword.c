#include <weapon.h>
inherit SWORD;
#include <ansi.h>
void create()
{
        set_name(HIY"���C"NOR, ({ "light sword","sword"} ) );
        set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("volume",2);
		set("unit", "��");
	set("material","wood");
		set("long", "�o�O�@��D�h�M���I�k�Ϊ��C�C\n");
		set("value", 10);
	}
        init_sword(15);
	setup();
}
