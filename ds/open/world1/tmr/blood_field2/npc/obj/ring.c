#include <armor.h>

inherit FINGER;

void create()
{
	set_name("��٫�", ({ "field ring" }) );
	set_weight(100);
	set("unit", "�T");
	set("value", 1500);
	set("long",@long
�o�O�@�T�y�Ǧb��{��W���٫��A�`�Q�y���b���䪺���]����ۡA�q
�`�֦��_�S���]�O�C                
long
                );
		if ( clonep() )
  			 set_default_object(__FILE__);
		else {
                set("armor_prop", ([
                        "armor": 5,
                    	"int": 1,
                ]));
        }
        setup();
}

