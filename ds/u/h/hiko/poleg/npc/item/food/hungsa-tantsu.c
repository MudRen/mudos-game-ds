#include <ansi.h>
inherit ITEM;
inherit F_FOOD;
void create()
{
  set_name(HIR"���N�}�L��"NOR, ({ "hungsa tantsu","tantsu" }) );
  set_weight(3000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�@�ؤ����@�X���Ʋz�A�Y�_�ӱa�ǷL�����A�o�S�������Ъ�\n"
                "�����D�`�S��A�O��Ź���R���A�B�]��O�ѤU�������@�C\n");
    set("unit","��");
    set("value",2000);
    set("heal_hp",30);
    set("heal_mp",80);
    set("food_remaining",15);
  }
  setup();
   set("no_sell",1);
   set("no_sac",1);
}







