#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIW"�K�K"HIC"�P��"NOR,({"blood_dagger","dagger"}) );
        set("long","�@��g���K�K���P���C\n");
          set_weight(5000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
      set("value",800);
        }
              set("wield_msg",HIC"$N�p���l�l������W���K�K�����~���W�C\n"NOR);
          init_dagger(10000);
        setup();        
}
