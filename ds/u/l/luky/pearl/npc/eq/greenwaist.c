#include <armor.h>
inherit WAIST;

void create()
{
set_name("�񴹧��y",({"green waist","waist"}));
set("long","�@���X�n�������y�C�ΨӫO�@�����θy�������ˮ`�C\n");
set_weight(1800);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit","��");
//set("wear_msg","$N�N�񴹧��y�j�b�y���C\n");
set("material","cloth");
//set("armor_prop/armor",7);
//set("armor_prop/dex",7);
set("value",1800);
set("limit_lv",50);
 }
setup();
}
