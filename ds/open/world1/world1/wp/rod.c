#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("����",({"fish rod","rod"}) );
	set("long","�@�K�����Ϊ����q����A�ݨӺ���T�@�ΡA�����Ψӥ��H�|�p��C\n");
      set_weight(2000);
	if (clonep() )
	 	set_default_object(__FILE__);
	else {
		set("unit","�K");
		set("volume",2);
       set("value",400);
	}
		set("wield_msg","$N���_�F�@�K$n�R��Z���C\n");
init_whip(8);
	setup();	
}	
