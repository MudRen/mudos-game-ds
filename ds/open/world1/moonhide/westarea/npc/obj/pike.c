#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name("��g�j",({"lin pike","pike"}) );
        set("long","�E�Ѷ�����Z���A��K�o�X�H�H����A�n���M�`�C\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",4000);
        set("volume",5);
        set("material","iron");
        init_fork(40);
        }
        setup();
}

