#include <weapon.h>
inherit SWORD;
void create()
{
   set_name("���ʼC",({"fau min sword","sword"}));
   set("long","�o�O�@�⦳�۷����J�����٦��ʤ媺�C�C\n");
   set_weight(3000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("volume",2);
              set("value",3500);
                set("material","iron");
        }
init_sword(25);
        setup();
}

