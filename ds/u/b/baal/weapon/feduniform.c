#include <armor.h>

inherit CLOTH;
 
void create()
{
set_name("�P���p����A-������",({"federation uniform","uniform"}) );
set("long","�o�O�@��P���p�����¬۶������h�����H����A�C\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "��");
set("value",10000);

set("limit_con",3);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor    ���z���@
//  armor_prop/shield   �D���z���@
//  armor_prop/hit      �R���v
set("armor_prop/armor", 500);
set("armor_prop/shield", 300);
        }
        setup();
}
