#include <weapon.h>
inherit THROWING;
void create()
{
        set_name("���ؼC",({"hand sword","hand","sword"}) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "�T");
                set("base_volume",1);
                set("base_weight",350);
              set("long",@LONG
�o�O�Ԫ̭̾԰��ɺD�Ϊ��t���C
LONG);
        }
        init_throwing(20);
        setup();
        set("value",50);
        set("volume", 1);
        set_amount(1);
}
