#include <armor.h>
inherit HEAD;

void create()
{
        set_name("��A�U",({"waiter cap","cap"}) );
        set("long","�@���A�ȥͱM�Ϊ���A�U�C\n");
    set_weight(300);
        if (clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","��");
      set("value",50);           
      set("armor_prop/armor",2);
        }
        setup();
}


