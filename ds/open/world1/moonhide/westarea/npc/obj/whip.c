#include <ansi.h>
#include <weapon.h>
inherit WHIP;
void create()
{
        set_name("�y�g�X��",({"liu whip","whip"}) );
        set("long","�E�Ѷ���y��Z���A�Ӧp���A�X�G�ݤ���A���ˤO��ΡC\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",3400);
        set("volume",5);
        set("material","iron");
        init_whip(34);
        }
        setup();
}

