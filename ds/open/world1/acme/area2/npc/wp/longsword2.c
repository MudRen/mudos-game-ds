#include <weapon.h>
inherit SWORD;
void create()
{
   set_name("�h���C",({"lau yip sword","sword"}));
   set("long","�o�O�@��Ϊ��p�h����ӲӪ������C�C\n");
   set_weight(3000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("volume",2);
              set("value",1500);
                set("material","iron");
        }
init_sword(23);
        setup();
}
