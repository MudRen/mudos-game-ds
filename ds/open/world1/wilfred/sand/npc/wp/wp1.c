#include <ansi.h>
#include <weapon.h>
#include "std_fist.c"

void create()
{
  set_name(HIC"���"NOR, ({ "single fist","fist" }) );
  set_weight(2000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", HIC"�@�뮱�M�Ҧ����A�ߦ��W��A�G�W�����C\n�����Z���R�Τ��Z���A�˳Ʃ�k����K�i�ϤK�����y�r��w���s�z�A�¤O�j�j�C\n"NOR);
    set("material", "iron");
    set("value",3000);
    set("volume",3);
    set("limit_int",15);
    set("weapon_prop/str",1);
  }
  init_fist(50);
  setup();
}
