#include <weapon.h>

inherit STAFF;

void create()
{
        set_name("����",({"tiger-staff","staff"}) );
        set("long","�o�O�@��V�������A�����e�t����A�ӧ��Y�D�J����ΡC\n");
          set_weight(1500);
        if (clonep() )
                set_default_object(__FILE__);
        else {
              set("unit","��");
                    set("material", "blacksteel");
      set("value",1900);
        }
 init_staff(9);
        setup();
}

