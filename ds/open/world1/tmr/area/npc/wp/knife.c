#include <weapon.h>

inherit BLADE;

void create()
{
	set_name("�p�M",({"knife"}) );
	set("long","�@����ȤG�o���p�M�A�h�b�O�����@���Ϊ��C\n");
      set_weight(200);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("unit","��");
      set("value",500);
		set("material","iron");
	}
		set("wield_msg","$N��W�@�̡A�����q�󮳰_�F�@��U�Q��$n\n");
		init_blade(5);
		setup();
}
