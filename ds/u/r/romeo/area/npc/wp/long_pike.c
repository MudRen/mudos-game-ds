#include <weapon.h>

inherit LANCE;

void create()
{
        set_name("�P�Ʀ�j",({"cassock-blood-pike","lance"}) );
        set("long","�o�O�@�⦳��V�����j�A�b�j�W�i�H����@�V�媺�P�ơA�����D���;
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
                    set("material", "crimsonsteel");
      set("value",1900);
        }
          init_blade(9);
        setup();
}
