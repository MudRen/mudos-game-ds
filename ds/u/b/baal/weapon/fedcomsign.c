#include <armor.h>

inherit CLOTH;
 
void create()
{
set_name("�P���p���q�T����",({"federation communication sign","sign"}) );
set("long","�o�O�@�ӬP��ĥ���лx�Ÿ����Pĥ�x�x�Ϊ��q�T�����A�i�H�O�b�ݫe�C\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "necklace");
set("unit", "��");
set("value",5000);

set("limit_int",20);

//  armor_prop/dex
//  armor_prop/str
//  armor_prop/int
//  armor_prop/con
//  armor_prop/armor    ���z���@
//  armor_prop/shield   �D���z���@
//  armor_prop/hit      �R���v
set("armor_prop/armor", 322);
set("armor_prop/shield", 124);
        }
        setup();
}
