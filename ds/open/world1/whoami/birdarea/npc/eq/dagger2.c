#include <weapon.h>
inherit NEEDLE;

void create()
{
        set_name("�u�w",({"needle"}) );
        set("long","�@�ڴ��q���u�w�A�ݱo�X�ӥu�O�M�`�K�ҥ��y�X�Ӫ��C\n");
        set_weight(800);
        if (clonep() )
        set_default_object(__FILE__);
        else {
              set("unit","��");
              set("value",100);
              set("material", "iron");
        }
        set("wield_msg","$N��W�@�̡A���_�F�@��$n��Z���C\n");
        init_needle(8);
        setup();
}

