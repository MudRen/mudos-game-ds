#include <armor.h>
#include <ansi.h>
inherit FINGER;
void create(){
      set_name(HIC"�p�ۧ٫�"NOR,({"gem ring","ring"}) );
      set("long","�o�٫��^�F�@���p�ۡA�ݰ_�Ӫ���ģ�����A�⤣���C\n");
      set_weight(250);
     if (clonep() )
         set_default_object(__FILE__);
     else {
          set("unit","�T");                            
       }
       set("armor_prop/armor",4);
       set("armor_prop/int",2);
       set("value",50);
       setup();
}


