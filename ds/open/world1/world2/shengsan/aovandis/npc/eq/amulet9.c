#include <armor.h>
inherit NECK;

void create()
{
	set_name("�@����",({"amulet"}));
	set("long",@LONG
�o�@������@���Ū������L��[�n�Ѯc]�T�Ӫ���p�r�C
LONG
	);
	set_weight(900);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "��");
	}
	set("armor_prop/shield",3);
	set("auto_set",2);
	setup();
}

// int query_autoload() { return 1; }
