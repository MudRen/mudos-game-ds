#include <armor.h>
#include <ansi.h>
inherit BOOTS;
void create()
{
        set_name("�]�N�c",({"magic boots","boots"}) );
        set("long","�@��o�N���]�N�c�A�|�۰��ܰʤj�p�ӾA�X�ϥΪ̪��}���C\n");
        set_weight(1000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","��");
  set("value",800);
set("material","cloth");
set("armor_prop/armor", 2);
set("armor_prop/dodge",1);
        }

        setup();
}
int query_autoload() { return 1; }
