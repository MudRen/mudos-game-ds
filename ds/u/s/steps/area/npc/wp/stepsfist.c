#include <weapon.h>
#include <ansi.h>
inherit FIST;
void create()
{
set_name(HIR"�ۤ�"NOR,({"steps fist","fist"}) );
    set("long",HIB"�ۥ���\n"NOR);
   set_weight(20000);
     if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
         set("value",10000);
        set("material","gold");
      init_fist(80);
         set("weapon_prop/hit", 30);
   set("armor_prop/str", 6);
   set("armor_prop/con", 6);
}
setup();
}
