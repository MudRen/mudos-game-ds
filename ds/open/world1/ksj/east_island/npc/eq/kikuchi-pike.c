#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
  set_name("����j", ({ "kikuchi pike","pike" }) );
  set_weight(4500);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("limit_str",20);
    set("limit_skill",15);
    set("limit_lv",10);
    set("unit", "��");
    set("long", "�����j���@�ءA�M�y�]�p���歱���b�C\n");
    set("value",1500);
    set("volume",5);
    set("material","steel");
  }
  init_fork(30,TWO_HANDED);
  setup();
}
