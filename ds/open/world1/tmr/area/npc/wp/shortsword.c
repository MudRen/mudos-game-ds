#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("�u�C",({"short sword","sword"}) );
          set("long","�@����W���u�C�A�q�`�Q���ӶK���O�@�Ϊ��C\n");
          set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
		set("volume",2);
      set("value",600);
        }
              set("wield_msg","$N���_�F�˳�$n�R��Z���C\n");
          init_sword(6);
        set("material","iron");
        setup();        
}
