// dart.c

#include <weapon.h>

inherit THROWING;

void create()
{
	set_name("����", ({ "dart" }) );
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long",	"����O�@�ؤQ���`�����t���C\n");
		set("unit", "��");
		set("base_unit", "�K");
		set("base_weight", 40);
		set("base_value", 5);
	}
	set_amount(1);
	init_throwing(20);
	setup();
}
