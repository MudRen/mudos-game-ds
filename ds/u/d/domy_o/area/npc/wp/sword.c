#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
  set_name("�m�x�Ρn�Q�C",({"jun sword","sword"}) );
  set("long","�@��ܧQ���Q�C�A�O�x�H���Ϊ��Z���C\n");
      set_weight(4500);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
      set("value",1800);
        set("material","iron");
      init_sword(14);

   }
setup();
}

