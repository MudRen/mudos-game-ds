#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create(){
      set_name(HIC"鑽石戒指"NOR,({"gem ring","ring"}) );
      set("long","這戒指鑲了一顆鑽石，看起來金光耀眼的，嗯不錯。\n");
      set_weight(250);
     if (clonep() )
         set_default_object(__FILE__);
     else {
          set("unit","枚");                            
       }
       set("armor_prop/armor",4);
       set("armor_prop/int",2);
       set("value",50);
       setup();
}


