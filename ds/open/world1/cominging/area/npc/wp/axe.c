#include <weapon.h>
inherit AXE;
void create()
{
	set_name("���Y", ({ "middle axe", "axe" }) );
	set("long",
		"�@��M���}�s��𪺩��Y�C\n"
	);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
       set("value",700);
		set("matreial", "iron" );
		set("volume",3);
	}
	init_axe(15);
	set("wield_msg", "$N��y�������Y�Τ��|�F�_�ӡC\n");
	set("unwield_msg", "$N�N�⤤�����Y��J�y�W�C\n");
	setup();
}
