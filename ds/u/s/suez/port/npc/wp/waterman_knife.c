#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("����p�M",({"waterman knife","knife"}) );
        set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
         set("long","����b��W�`�Ϊ��u��A�]�i�H���Ө����C\n");
         set("material","iron");
         set("unit","��");
         set("value",300);
        }
        set("wield_msg","$N��W�@�̡A���_�F�@��$n��Z���C\n");
        init_dagger(5);
        setup();        
}

