#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
        set_name( "���g��" ,({"ean staff","staff"}) );
        set("long","�E�Ѷ������Z���A���Y����A���Ʀ��u�ʡC\n");
          set_weight(8000);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",3300);
        set("volume",5);
        set("material","iron");
        init_staff(33);
        }
        setup();
}

