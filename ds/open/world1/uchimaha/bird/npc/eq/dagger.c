#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIR"�大�P��"NOR,({"blood_dagger","dagger"}) );
        set("long","�@�����⪺�P���A�ݰ_�ӬO�ΤW�����K���y���A�¤O
�ä��M�`�C\n");
          set_weight(1000);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                 set("unit","��");
                 set("material", "iron");
               }
          set("wield_msg","$N��W����@�{�A�ٮɷQ�n�����媺����C\n");
          init_dagger(20);
          setup();        
}
