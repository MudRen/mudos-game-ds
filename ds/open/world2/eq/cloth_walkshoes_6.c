#include <armor.h>
inherit BOOTS;

void create()
{
	set_name("�𶢾c",({"walking shoes","shoes"}) );
	set("long",@LONG
�o�O�@���Ȫ��Ͳ����@�ئ�𶢾c�C
LONG
);
	set_weight(2700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "cloth");
		set("unit", "��");
	}
	set("value",1370);
	set("armor_prop/armor", 6);
	setup();
	set("volume", 4);
}

int query_autoload() { return 1; }
