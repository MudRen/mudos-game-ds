#include <ansi.h>
#include <weapon.h>
inherit FIST;
void create()
{
        set_name(HIG"��"HIW"�g��"NOR,({"sha fist","fist"}) );
        set("long","�E�Ѷ������Z���A�Ѥ��������X�֬��@���A����]�]�����C\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",3900);
        set("volume",5);
        set("material","iron");
        init_fist(39);
        }
        setup();
}

