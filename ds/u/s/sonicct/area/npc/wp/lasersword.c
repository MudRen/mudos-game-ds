#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
      set_name(HIR"�E���C"NOR,({"laser sword","sword"}));
	set_weight(6000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long", "�o�O�����W�y�檺�E���C\n");
		set("value", 5000);
		set("material", "iron");
}
     init_sword(20);
	setup();
}
