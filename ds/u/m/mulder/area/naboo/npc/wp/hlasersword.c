#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
	set_name(HIB"���ſE���C"NOR,({"laser sword","sword"}));
	set_weight(15000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�����W�y�檺���ſE���C\n");
		set("value", 9000);
		set("material", "iron");
	}
     init_sword(30);
	setup();
}