#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("���C",({"short sword","sword"}) );
          set("long","�@��ΦH�������y�����C, �j�j�i�H�ΰ�....\n");
          set_weight(2000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
                set("volume",2);
      set("value",1200);
        }
              set("wield_msg","$N���_$n���R�F��U�C\n");
          init_sword(16);
        set("material","steel");
        setup();        
}
