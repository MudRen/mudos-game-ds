#include <ansi.h>
#include <armor.h>
inherit ARMOR;

void create()
{
    set_name(HIY"���iù�����Z��"NOR ,({ "apollo armor","armor" }) );
  set("long",@LONG
�Ӷ����Ъ��iù��۪��Z�ҡA�Z�ҤW�観�Ӷ��ϮסA���G�p�誺��
�o�X���ꪺ�����C
LONG
);
    set_weight(5000);
  if ( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("material", "gold");
    set("volume",7);
    set("unit", "��");
    set("value",20000);
    set("light",1);
  }
  set("limit_con",50);
  set("armor_prop/armor",30);
  set("armor_prop/shield",30);
  set("armor_prop/con",4);
  set("armor_prop/dodge",-10);
  setup();
}
void init()
{
if( this_player()->query_temp("armor/armor") == this_object() ) {
        if(!this_object()->query_light()) this_object()->start_light(1);
}
}
int query_autoload() { return 1; }
