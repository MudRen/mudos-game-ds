#include <weapon.h>

inherit DAGGER;

void create()
{
        set_name("�p�M",({"dagger"}) );
        set("long","�@�ⴶ�q���p�M�A���u�O�@��P���Ӥw�C\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
      set("value",800);
        }
              set("wield_msg","$N��W�@�̡A���_�F�@��$n��Z���C\n");
          init_dagger(8);
        setup();        
}


