#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("�p�~�l",({"secret bottle","bottle"}));
    set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  { 
    set("long","�@�Ӥp�p���~�l�A�̭��˵۲����b�~�զ⯻���A�H�۷n�̤@�����\n"
               "��������ӨӡC\n");
    set("value",50);
  }
  set("no_put",1);
  setup();
}

void init()
{
  add_action("do_use","use"); 
  add_action("do_look","look"); 
}

int do_look(string str)
{
  object ob=this_object(),me=this_player();
  if(!str || str != "bottle") return 0;
  me->add_temp("bottle_checked",1);
  tell_object(me,ob->query("long"));
  return 1;
}
int do_use(string str)
{
  object ob = this_object(), me = this_player(),*target;
  int x;
  target = all_inventory(environment(me));
  if(!str || str != "bottle") return 0;
  if( environment(me)->query("no_fight") )
  return notify_fail("�A���ݥ|�P�@�����M�A���A���n�N��b�o�̶��ġE\n");
  message_vision("$N��~�l�����զ⯻�����x�@�q...\n",me);
  me->add_temp("using",1); 
  for(x=0;x<sizeof(target);x++){
    if( target[x]->query("no_fight") ) continue;
    if( target[x]->query_temp("using") ) continue;
    if( target[x]->query_temp("invis") ) continue;
    if( target[x]->is_corpse() ){
    message_vision("$N�걼�F..\n",target[x]);
    destruct(target[x]);
    } else {
    if( !living(target[x]) || userp(target[x]) ) continue; 
    message_vision("$N�Q�Q���F\n",target[x]);
    target[x]->receive_damage("hp",random(500));
    target[x]->apply_condition("poison", target[x]->query_condition("poison")+ (25+random(25)));
    if( target[x]->is_fighting(me) ) continue;
    target[x]->kill_ob(me);
    me->kill_ob(target[x]);
    }
  } 
  me->delete_temp("using",1);
  destruct(ob);
  return 1;
}

