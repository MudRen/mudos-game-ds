#include <weapon.h>
inherit FIST;

void create()
{
  set_name("�U�F�ۤ�",({"stone fist","fist"}) );
  set("long",
"�o�O���]���H�Ҹ˳ƪ��Z���A�ѥۤl��F�զ��A���m����ˤO\n"
"�A�����i�����C\n"
);
        set_weight(12000);
        if (clonep() )
             set_default_object(__FILE__);      
        else {
                set("material","iron");
                set("volume",2);
                set("unit","��");
               set("value",3000);
                set("limit_str",32);
        }
                set("weapon_prop/parry",12); 
                set("weapon_prop/dodge",-5);               set("weapon_prop/con",1);
                set("weapon_prop/str",2);
                set("weapon_prop/dex",-1);
init_fist(45);
        setup();
}

