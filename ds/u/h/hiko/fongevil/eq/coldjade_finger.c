#include <armor.h>
inherit FINGER;
void create()
{
        set_name("�H�ɧ�" ,({ "cold-jade finger","finger" }) );
        set("long","�o�O�@�u�δH�ɪ��һs���١A�O�Ψӳ��������~�C\n");
        set_weight(500);
        if ( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","�u");
                set("material", "jade");
        }
        set("armor_prop/armor", 2);
        set("armor_prop/dex",2);
        set("value",3000);
        set("limit_lv",10);
        setup();
}


