#include <weapon.h>
inherit SWORD;
void create()
{
  set_name("�z���l�C",({"light sword","sword"}) );
  set("long","�@�ⴶ�q���z���l�C�A�ΨӨ����ˤ]�����C\n");
      set_weight(3000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
        set("value",800);
        set("volume",2);
        set("material","iron");

   }
        init_sword(12);
        setup();
}

