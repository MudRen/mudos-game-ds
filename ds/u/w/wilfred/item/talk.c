inherit ITEM;
#include <ansi.h>
void create()
{ set_name("������",({"talk"}));
 set("no_drop",1);
 set("no_sell",1);
 set("no_give",1);
  setup(); }
void init()
{ call_out("talk",1);
  this_object()->set_temp("invis",1); }
void talk()
{ this_player()->add("talk_point",5);
this_player()->set("name",HIW BLK"�·t�j�K����"NOR);
  call_out("talk",15);

  return; }
int query_autoload() {  return 1; }
