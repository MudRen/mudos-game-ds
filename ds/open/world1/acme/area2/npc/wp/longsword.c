#include <weapon.h>
inherit SWORD;
void create()
{
   set_name("���ʼC",({"ming-dung long sword","sword"}));
   set("long","�o�O�@�⯫�Z���@�k�K���N�ϥΪ��Z���C\n");
   set_weight(9000);   //�]���q
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("limit_str",10);
          set("value",1750);
		set("volume",2);
                set("material","iron");
        }
init_sword(28);
        setup();
}
