#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
  set_name( "���^��" , ({ "bamboo stick","stick" }) );
  set_weight(200);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("unit", "��");
    set("long", "�˻s�b���A�������@�ΡA���`�Q�Ψӧ@���ѤH�a���ĤT���}�C\n");
    set("material", "bamboo");
    set("value",400);
    set("volume",1);
  }
  init_staff(8);
  setup();
  set_temp("broken",1);
}

void attack(object me, object victim)
{
  ::attack();
  if(!me) return;
  if(!victim) return;
  if(random(3)) add_temp("broken",1);
  if(query_temp("broken") > 10)
  {
    message_vision(HIW"\n�y�ԡz���@�n�A$N�q���_����I�I\n\n"NOR,this_object());
    if( stringp(this_object()->query("equipped")) ) this_object()->unequip();
    destruct(this_object());
  }
  return;
}
