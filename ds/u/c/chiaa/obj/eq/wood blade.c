//u/c/chiaa/obj/eq/wood blade.c

#include <weapon.h> //�w�q�Z��
#include <ansi.h>   //�w�q��X
inherit BLADE;   //�j�g

void create()
{
  set_name(YEL"��M"NOR,({"wood blade","blade"}) );
  if (clonep() )
             set_default_object(__FILE__);
    else {
      set("unit","��");//�Z�������
      set("long","�@��Τ��Y�覨���M\n");//�Z���ԭz
      set_weight(100);//�Z�������q
      set("value",15);//�Z��������
      set("material","wood");  //���� 
      }
        init_blade(5);     //�Z�������O 
setup();
}
