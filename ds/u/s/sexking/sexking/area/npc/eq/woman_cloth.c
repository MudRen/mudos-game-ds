#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("������",({"woman's cloth","cloth"}) );
        set("long",@long
�o�O�@�󥿦b�h�������k�Ҭ諸��A�A�C
long
);
        set_weight(800);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
           set("unit", "��"); 
          set("value",1000);
          set("armor_prop/armor",2); 
          set("volume",8); 
         
         }
setup();
}
