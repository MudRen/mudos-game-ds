#include <armor.h>
inherit FINGER;
void create(){
      set_name("�h��",({"willow ring","ring"}) );
      set("long","�@�T�����h�K���٫��A�ݨӥj��L�ءC\n");
      set_weight(250);
     if (clonep() )
         set_default_object(__FILE__);
     else {
          set("unit","�T");                            
       }
       set("armor_prop/armor",2);
       set("armor_prop/int",1);
       set("value",50);
       setup();
}

