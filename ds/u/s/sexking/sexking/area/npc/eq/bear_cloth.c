#include <armor.h>
inherit CLOTH;

void create()
{
        set_name("�ԧ���",({"bear cloth","cloth"}) );
        set("long",@long
�o���A�Q�����B�ܷt�A�j���O�Ԫ̭̦�ʮɬ諸��A�C
long
);
        set_weight(600);
        if(clonep() )
                set_default_object(__FILE__);
        else
        {
           set("unit", "��"); 
          set("value",1000);
          set("armor_prop/int",1);         
          set("armor_prop/armor",6); 
          set("volume",4); 
         
         }
setup();
}
