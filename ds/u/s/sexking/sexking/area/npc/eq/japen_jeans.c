#include <armor.h>
inherit PANTS;

void create()
{
        set_name("�B�r��",({ "japen jeans","jeans" }) );
        set("long",@LONG
�o�O�饻���B�Ұʮɬ��F��K�Ҭ諸���ǡA�Q�������C
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "cloth");
                set("unit", "��");
        set("value",200);
        set("volume", 1);
        set("max_lv",50);
        set("limit_lv",1);
   set("armor_prop/armor",2);
  }
      setup();
}
