#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        set_name(HIG"�Q"HIW"�g�C"NOR,({"ba sword","sword"}) );
        set("long","�E�Ѷ���Q��Z���A�C���e�|�Q�����s���A�R�Q�D�`�C\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",4300);
        set("volume",5);
        set("material","iron");
        init_sword(43);
        }
        setup();
}

