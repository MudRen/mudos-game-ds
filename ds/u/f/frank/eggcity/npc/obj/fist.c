#include <weapon.h>

inherit FIST;

void create()
{
    set_name("����",({"tiger fist","fist"}) );
   set("long","�@�ӮM�b��W���M��A�@�`�@�`�������i���|�ϫ��Y�M�i�h�A���M\n"
              "������L�Z���몺�㦳���ˤO�A���L�]�����F�C\n");
        set_weight(2000);
  if (clonep() )
             set_default_object(__FILE__);
    else {
        set("unit","��");
            set("value",600);
        set("material","iron");
      init_fist(30);
   }
setup();
}

