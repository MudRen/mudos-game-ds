#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�u�C",({"short sword","sword"}) );
        set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
         set("long","�u�C�O�ܮe���W�⪺�Z���A�A�X����_�I�̨ϥΡC\n");
         set("material","iron");
         set("unit","��");
         set("value",500);
        }
        set("wield_msg","$N�q�C�T�����X�@��$n��Z���C\n");
        init_sword(10);
        setup();        
}
