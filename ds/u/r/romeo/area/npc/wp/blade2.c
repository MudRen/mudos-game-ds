#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("�j��Y",({"bo-yeah-blade","blade"}) );
        set("long","�o�O�@���襴�y���M�A�u���M�`�W�H����¸�ۡy��Y�z��ӥj�r�C�C\n");
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
