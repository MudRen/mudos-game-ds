#include <armor.h>

inherit SURCOAT;

void create()
{
set_name("�¥֧��J",({"black jacket","jacket"}) );
set("long","�o�O�@��ϥֻs�����¦�֧��J�C�~�h�٤W�F�@�h�G�o�C\n");
set_weight(1275);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("material", "cloth");
set("unit", "��");
set("value",1275);
//set("armor_prop/armor",12);
set("limit_lv",25);
        }
        setup();
}
