inherit ITEM;
#include <ansi2.h>
void create()
{ set_name(HIM"����"HIB"����"NOR, ({"ch_Pill","pill"}) );
  set_weight(1);
  set("unit", "��");
  setup(); }
void init()
{ add_action("do_eat", "eat"); }
int do_eat(string str)
{ object me = this_player();
  string name;
  name =HBBLU""HIW"�ä����"NOR;
  if("str == pill") {
  message_vision(HIB"�ڷR�����Y�U�ĤY\n"NOR, me);
  me->set("name",name);
  destruct(this_object());
  return 1; }}
