#include <ansi.h>
#include <weapon.h>
inherit AXE;
void create()
{
        set_name( "�}�g��" ,({"poo axe","axe"}) );
        set("long","�E�Ѷ���}��Z���A�Ѻ��ű�y�Ӧ��A��w�L��C\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",3800);
        set("volume",5);
        set("material","iron");
        init_axe(38);
        }
        setup();
}

