#include <weapon.h>

inherit FIST;

void create()
{
        set_name("��ù��x",({"bolood-fist","fist"}) );
        set("long","�۶ǳo�O�@���Ѫ���ù�a���Ӫ���x�A�M�����z�g�ۦ���⪺���A�C\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
                    set("material", "skin");
      set("value",1900);
        }
          init_fist(9);
        setup();
}
