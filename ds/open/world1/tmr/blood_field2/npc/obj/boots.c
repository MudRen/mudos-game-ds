#include <armor.h>

inherit BOOTS;

void create()
{
        set_name("����u", ({"field boots", "boots" }) );
        set_weight(1500);

		if ( clonep() )
  			 set_default_object(__FILE__);
		else {
                set("unit", "��");
                set("value", 1500);
                set("long",@long
�o�O�@���y�Ǧb��{��W�����u�A�`�Q�y���b���䪺���]����ۡC
long
                );
                set("armor_prop", ([
                        "armor": 5,
                ]));
        }

        setup();
}

