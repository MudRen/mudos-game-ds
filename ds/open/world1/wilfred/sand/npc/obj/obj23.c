// �o�������b�g wilfred@DS

#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIW"�۬W"NOR,({"stone"}));
  set_weight(99999);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","�@�ӥ۬W -- ���O�۬W, ���p���O�q���C���� item");
  }
  set("no_get",1);
  set("no_sac",1);
  setup();
}
/*
void init()
{

}
*/