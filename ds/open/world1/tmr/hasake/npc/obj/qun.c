// cloth: wcloth.c
// Jay 3/17/96

#include <armor.h>
inherit PANTS;

void create()
{
        set_name("���ħJ�͸�", ({ "hasake skirt", "skirt"}) );
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "�o�O�@��´�۬������͸�, ���ħJ�k�ı`�諸��ۡC\n");
                set("armor_prop/armor", 3);
                set("value", 500);
        }
        setup();
}

