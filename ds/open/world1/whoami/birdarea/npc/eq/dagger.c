#include <weapon.h>
#include <ansi.h>
inherit NEEDLE;

void create()
{
        set_name(HIR"���w"NOR,({"blood needle","needle"}) );
        set("long","�@�ڪ��������w�A�ݰ_�ӬO�ΤW�����������y���A�¤O
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
          init_needle(40);
          setup();        
}

