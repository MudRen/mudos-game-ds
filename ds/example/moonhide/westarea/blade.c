#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        set_name(HIG"��"HIW"�g�M"NOR,({"mon blade","blade"}) );
        set("long","�E�Ѷ���ڻ�Z���A�M�Y�ٴ��ۤ@��p�M�A�y�ɥ[���F���o�C\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",3700);
        set("volume",5);
        set("material","iron");
        init_blade(37);
        }
        setup();
}

