
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("�p�M",({"knife"}) );
          set_weight(500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("long","�@��`�����p�M�A�ä��W�Q���ˤl�C\n");
       set("material","iron");
              set("unit","��");
      set("value",100);
        }
              set("wield_msg","$N��W�@�̡A���_�F�@��$n��Z���C\n");
          init_dagger(1);
        setup();        
}