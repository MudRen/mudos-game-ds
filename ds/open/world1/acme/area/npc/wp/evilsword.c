#include <weapon.h>
inherit SWORD;

void create()
{
set_name("�@���C",({"ward off evils sword","sword"}));
set("long",
           "�o��C����C�u�ǡA�S��u�C���ǡA�~���S���A�b�C�`�B"
           "���ۤG�ӥj����L�A�B�����ۤ@�ӦN�����C",
     );
set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("unit", "��");
set("value",1000);
set("volume",3);
        }
init_sword(15);
set("weapon_prop/hit",8);
         setup();
} 
