#include <armor.h>
inherit LEGGING;

void create()
{
        set_name("���@��",({"rattan leggings","leggings"}) );
        set("long",@LONG
�o�O�@���Φ��îͰ��������@���A�i�����C
LONG
);
        set_weight(2500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("unit", "��");
        }
        set("armor_prop/armor",4);
        setup();
        set("value",650);
        set("volume", 2);
}

