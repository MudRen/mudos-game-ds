#include <armor.h>
inherit FINGER;
void create()
{
        set_name("��r��" ,({ "random-bite finger","finger" }) );
        set("long","�o�O�@�u�ΰ��~��r���e���һs���١A�����a�o�X�@�}�®�C\n");
        if ( clonep() )
                set_default_object(__FILE__);
        else {
       set("value",1000);
        set("unit","�u");
        set_weight(500);
        set("material", "jade");
        set("armor_prop/armor", 2);
        set("armor_prop/str",2);
    set("limit_lv",10);
        }
        setup();
}
