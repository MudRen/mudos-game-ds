#include <ansi.h>
#include <path.h>
inherit ITEM;

void create()
{
  set_name("�X��", ({"tomb"}) );
  set("long",@LONG
�@�y�X�ӡA�X�ӥ|�P��z�������۷��b�A�ӸO�W�g�ۡi��V�D���l�j
���ӡC
LONG
);
  set_weight(1000);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("no_get",1);
    set("no_drop",1);
    set("no_sac",1);
    set("unit", "�y");
    set("volume",1000);
    set("value",500);
  }
  setup(); 
}
