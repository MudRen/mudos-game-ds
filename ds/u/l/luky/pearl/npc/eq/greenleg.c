#include <armor.h>

inherit LEGGINGS;

void create()
{
set_name("���@�L",({"green leggings","leggings"}));
set("long","�C\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "steel");
set("unit", "��");
set("value",1800);
set("armor_prop/dodge",1);
set("limit_lv",50);
//set("amount",3); //�n��n�[�o��
 }
setup();
}
