#include <weapon.h>
inherit FORK;
void create()
{
        set_name("���j",({"funeral pike","pike"}) );
        set("long","�@��ݰ_�Ӧ~�N�ܻ����j�A���G�O�H�e�Z�L�H�h�������Z���C\n");
          set_weight(6200);
        if (clonep() )
             set_default_object(__FILE__);
        else {
        set("unit","��");
        set("value",3500);
        set("volume",3);
        set("material","iron");
             }
  set("weapon_prop/int",2);
  set("weapon_prop/hit",6);
  init_fork(38);
  setup();
}


