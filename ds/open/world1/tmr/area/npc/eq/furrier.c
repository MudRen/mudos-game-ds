#include <armor.h>

inherit CLOTH;

void create()
{
	set_name("�֦�",({"furrier"}) );
	set("long","�@����֩��_�s�Ӧ����֦�A�ݨӺ��@�諸�C\n");
        set_weight(1200);
	if (clonep() )
		set_default_object(__FILE__);
	else {
		set("volume",3);
		set("unit","��");
		set("value",200);
          set("armor_prop/armor",3);
	}
	setup();
}

