#include <armor.h>
inherit CLOTH;

void create()
{
	set_name("�[�N�n",({"heart cloth","cloth"}) );
	set("long",@long
  �@�󳷥զ⪺��n�A�N�ӵ���n�ơA�O�H�R������C
long
);
	set_weight(200);
	if(clonep() )
		set_default_object(__FILE__);
	else
	{
		set("volume",3);
		set("unit", "��");
		set("value",1000);
		set("max_lv",25);
		set("limit_lv",8);
          set("armor_prop/int",2);
            set("armor_prop/dex",2);
		set("armor_prop/armor",5);
                set("armor_prop/show_damage",1);
	}
	setup();
}


