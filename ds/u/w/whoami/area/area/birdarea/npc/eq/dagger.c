#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIR"�大�P��"NOR,({"blood dagger","dagger"}) );
        set("long","�@�����⪺�P���A�ݰ_�ӬO�ΤW�����K���y���A�¤O
�ä��M�`�C\n");
          set_weight(1300);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                 set("unit","��");
                 set("value",1200);
                 set("material", "iron");
               }
          set("wield_msg","$N��W����@�{�A�ٮɷQ�n�����媺����C\n");
          set("weapon_prop/str",3); 
          set("weapon_prop/con",1); 
          set("weapon_prop/dex",-2);
          init_dagger(40);
          setup();        
}

