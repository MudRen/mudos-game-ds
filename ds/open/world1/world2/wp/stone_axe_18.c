#include <weapon.h>
inherit AXE;

void create()
{
        set_name("�۩�",({"stone axe","axe"}) );
	set_weight(8400);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("long",@LONG
�o����Y���򨭬O�Ѫ�^���i���A��`�h�O�ĥΧܿi�����C
LONG);
		set("material", "stone");
		set("limit_lv",1);
		set("limit_str",1);
		set("limit_int",1);
		set("limit_dex",1);
		set("limit_con",1);
		set("limit_skill",0);
		
	}
	init_axe(18);
	setup();
	set("value",1280);
}

