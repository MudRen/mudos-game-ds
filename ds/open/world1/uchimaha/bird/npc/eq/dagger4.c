#include <weapon.h>
#include <ansi.h>
inherit DAGGER;

void create()
{
        set_name(HIC"�뤧�P��"NOR,({"uya_dagger","dagger"}) );
        set("long","�@���Ŧ⪺�P���A�ݰ_�ӬO�ΤW�����K���y���A�¤O
�ä��M�`�C\n");
          set_weight(1200);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                set("unit","��");
          set("material", "iron");
               }
          set("wield_msg","$N��W�N���@�{�A�ٮ�$N�Pı��I�l�x���C\n");
          init_dagger(14);
          setup();        
}
