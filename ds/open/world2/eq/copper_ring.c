#include <armor.h>
inherit FINGER;
void create()
{
	set_name("�ɧ٫�",({"copper ring","ring"}) );
	set("long",@LONG
�@�u���ª��٫��A�W��������F�y���B�Q�g�~�����z�X�Ӧr�C
LONG
	);
	set_weight(700);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "copper");
		set("unit", "�T");
	}
        set("armor_prop/armor",1);
        setup();
        set("value",210);
        set("volume", 1);
}
