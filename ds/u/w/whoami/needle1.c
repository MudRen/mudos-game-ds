#include <weapon.h>
inherit NEEDLE;
void create()
{
        set_name("�Ȱw", ({"silver needle" ,"needle"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("base_unit", "��");
                set("unit", "��");
                set("base_volume",1);
                set("base_weight",300);
                set("material", "iron");
        set("long",@LONG
�@�ڻȰw�E
LONG);
        }
        init_needle(15);
        setup();
        set("value",300);
        set("volume", 5);
        set_amount(15);
}

