#include <armor.h>

inherit WAIST;

void create()
{
        set_name("��y�a", ({ "field belt", "belt"}) );
        set_weight(300);

		if ( clonep() )
  			 set_default_object(__FILE__);
  		else {
                set("unit", "��");
                set("value", 1000);
                set("long", "�o�O�@���y�Ǧb��{��W���y�a�A�`�Q�y���b���䪺���]����ۡC\n");
                set("armor_prop", ([
                        "armor": 5,
                ]));
        }
        setup();
}

