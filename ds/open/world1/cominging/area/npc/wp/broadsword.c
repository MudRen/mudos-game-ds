#include <weapon.h>
inherit SWORD;
void create()
{
	set_name("��C", ({ "broad sword" , "sword" }) );
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("material","steel");
		set("volume",3);
		set("unit", "��");
		set("long", "�o�O�@��ݰ_�۷��q����C�M���q�j�����G�Q�Ӥ祪�k�C\n");
      set("value",1000);
	}
	init_sword(25,TWO_HANDED);
	setup();
}
