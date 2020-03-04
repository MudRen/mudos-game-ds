#include <ansi.h>
#include <weapon.h>
#include "/open/world1/wilfred/sand/npc/wp/std_fist.c"

void create()
{
  set_name(CYN"�ͤ�"NOR, ({ "corpse fist","fist" }) );
  set_weight(7000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long",
        "��H�t��Ӧ��ɡA�b���𪺼v�T�U�A�f�|���X�y���A��|���X���A\n"        "�]���K�N�W���ͤ��A���W���۱j�j�����C\n"
        );
    set("material", "iron");
    set("value",6500);
    set("volume",4);
    set("limit_int",18);
    set("limit_str",30);
  }  
  set("weapon_prop/int",1);
  set("weapon_prop/hit",10);
  init_fist(60);
  setup();
}



