
#include <armor.h>

inherit FINGER;

void create()
{
	set_name("���[���٫�",({"red glazed ring","ring","red","glazed"}) );
	set("long",@LONG
�o�ӧ٫����۬��⪺�����A�A�ݥX���R������[���O�o�u�٫����F��Ҧb�C
LONG
	);
	set_weight(1500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("material", "gem");
		set("unit", "�T");
		set("value",1650);
	}
	setup();
}
