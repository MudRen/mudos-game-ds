#include <armor.h>

inherit CLOTH;
 
void create()
{
set_name("�ָ�",({"furred robe","robe"}) );
set("long","�o�O�@��p�����ָ�, ���}�n���m�H�ĪG�C�~���ФW�@�h�����C\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "��");
set("value",215);

set("limit_con",3);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor    ���z���@
//  armor_prop/shield   �D���z���@
//  armor_prop/hit      �R���v
set("armor_prop/armor", 20);
set("armor_prop/shield", 15);
        }
        setup();
}
