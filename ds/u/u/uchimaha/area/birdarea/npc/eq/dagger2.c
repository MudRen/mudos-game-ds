#include <weapon.h>
inherit DAGGER;

void create()
{
        set_name("�P��",({"dagger"}) );
        set("long","�@�ⴶ�q���P���A�ݱo�X�ӥu�O�M�`�K�ҥ��y�X�Ӫ��C\n");
        set_weight(800);
        if (clonep() )
        set_default_object(__FILE__);
        else {
              set("unit","��");
              set("value",100);
              set("material", "iron");
        }
        set("wield_msg","$N��W�@�̡A���_�F�@��$n��Z���C\n");
        init_dagger(8);
        setup();
}
