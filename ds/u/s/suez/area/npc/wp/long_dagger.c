
#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("�ؤP",({"dagger"}) );
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("long","�@�ت����P���A���٤�����٬��@��u�C�C\n");
       set("material","copper");
              set("unit","��");
      set("value",800);
        }
              set("wield_msg","$N��W�@�̡A���_�F�@��$n��Z���C\n");
          init_dagger(10);
        setup();        
}