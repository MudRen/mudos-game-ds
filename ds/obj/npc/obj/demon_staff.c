// demon_staff.c

#include <ansi.h>
#include <weapon.h>

inherit STAFF;

void create()
{
	set_name( RED "* �� �� �� �] �S *" NOR, ({ "demon staff", "staff" }) );
	set_weight(100000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�@��t����B��V�h�������S�C\n");
		set("material", "iron");
	}
	init_staff(100);
	setup();
}
