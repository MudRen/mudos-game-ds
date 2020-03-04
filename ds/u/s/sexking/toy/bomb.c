#include <ansi.h>
inherit ITEM;

void create()
{
  set_name("��h�u",({"boom"}));
  set_weight(5000);
  set("long","�¤O�j�j����h�u, �n��X�h�Х� throw [��V]  �� throw");
  set("value",10);
  set("no_get","�³J!�ֳQ�����F�٤��ְk!�ٷQ�߰_�ӣ�!");
  set("no_sac", 1);
   setup();
}

void init()
{
  add_action("do_throw","throw");
}

int do_throw(string str)
{
  object me = this_player(), ob = this_object();
  object env = environment(me), target, rope;
  mapping exit = env->query("exits");

  if(!env) return notify_fail("�|�B�@���·t�A�A�L�k��ʡC\n");
  if(me->is_busy()) return notify_fail("�A���b��.\n");
  if(!str)
  {
    target = environment(me);
    str = "HERE";
  }
  else
  {
    if(undefinedp(exit[str])) return notify_fail("�o�̨S���o�Ӥ�V�C\n");
    if( !target = find_object(exit[str]) ) return notify_fail("�A�o�{�Ʊ����j��F�A���S�����W�ӡA�̦n���ֳq���Ův�C\n");
  }

  message_vision(HIW"$N(Radio): Fire in the hole!! ("+str+")�C\n"NOR,me);
  call_out("do_move",1,ob,target);
  me->add_busy(1);
  return 1;
}

void do_move(object ob, object target)
{
  if(!ob->move(target)) return;
  tell_room(target,HIW"���@����h�u���F�L�ӡC\n"NOR);
  call_out("boom",1,target);
}

void boom(object target)
{
  object *obs = all_inventory(target);
  int i, damage;
  string name;

  tell_room(target,HIY"\n�@�n�F�M���T!\n\n"NOR);

  for(i=0;i<sizeof(obs);i++)
  {
    if(!living(obs[i])) continue;
    if(obs[i]->query("id") == "master") continue;
    damage = random(300)+100;
    obs[i]->receive_damage("hp",damage);
    tell_room(target,"�z���¤O�y��"HIC+obs[i]->name(1)+NOR"("+damage+")�I���ˮ`.\n");
    (this_player()) ? name = this_player()->name(1) : name = "�Y�H";
    obs[i]->set_temp("temp/death_type",HIR"[�Q"+name+"����]"NOR);
}
  destruct(this_object());
}

