#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
	set_name("�尨�j�M",({"big blade","blade"}));
	set("long","�o�O�@��j���L�b�A�O�q�n���j�~��ϥαo����C\n");
	set_weight(8000);
	if( clonep() )
	set_default_object(__FILE__);
	else {
set("volume",3);
        set("material","steel");
		set("unit", "��");
      set("value",1750);
		set("limit_str",15);
	}
	init_blade(30);
	setup();
}
