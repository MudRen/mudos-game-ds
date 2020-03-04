#include <path.h>
#include <ansi.h>
inherit NPC;

void heal();
string hero();

void create()
{
  set_name(HIC"�C��"HIW"���s"NOR,({"blue-eye white dragon","dragon"}) );
  set("long",
  HIW"\n�o�O�@�������ƤQ�ت����s\n"
  HIW"\n�䳷�ժ����ߡA���G�����x�ۤ@�h�ȥ�\n"
  HIC"\n�C�⪺�������a�ۤ@���F��\n"
  NOR""WHT"\n\t�o���s���D�O�u�@�U�s�j�ӡA�s�s���ޱ��̡H�L�q�o���C\n\n"NOR
  );
  set("race", "beast");
  set("unit","��");
  set("age",700);
  set("level",65);
  set("attitude", "heroism");
  set("limbs", ({ "�Y��", "����","�ݳ�","����","����","�I��" }) );
  set("verbs", ({ "bite","claw" }) );
  set("max_hp",27000+random(3000));
  set("Merits/bar",6);
  set("Merits/bio",5);
  set("Merits/wit",3);
  add("addition_armor",50);
  add("addition_damage",70);
        set("chat_chance",7);
        set("chat_msg",({
  (: heal :),
}));

  setup();
  set_living_name("dragon_war");
 // carry_object(__DIR__"wp/wp10")->wield();
 // carry_object(__DIR__"eq/eq22")->wear();
}

void init()
{
::init();
  add_action("do_guard","go");
}

int do_guard(string arg)
{
  if(!userp(this_player())) return 0;
  if(arg == "west" || arg == "east")
  {
    if(!this_object()->visible(this_player()))
      message_vision(HIW"��$N�����N�N���Q�q�����ǳq�L$n"HIW"�ɡA�o�Q$n"HIW"�Χ��ھצ�F�C\n"NOR,this_player(),this_object());
    else
    message_vision(HIW"��$N�չϱq$n"HIW"�����ǳq�L�ɡA�Q$n"HIW"�������פF�^�ӡI�I\n"NOR,this_player(),this_object());
    write(HIG"[�ݨӥ��ݥ��˨e�F�A�_�h�O�Q�q�L�o��]\n"NOR);
    if(!random(4))
    {
      message_vision(HIR"$N�j�q�@�n�A�C�⪺��������j���A�������µ�$n���Y�N�O�@���I�I\n"NOR,this_object(),this_player());
      kill_ob(this_player());
    }
    return 1;
  }
  return 0;
}
void heal()
{
  if(query("hp") > query("max_hp")) return;
  add("hp",200+random(100));
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(9))
  {
    me->start_busy(2);
    target->add_busy(1);
    message_vision(HIC"\n��M���A$N"HIC"�������ɮg�X�_�������~�I\n\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  return 0;
}

void do_super(object me)
{
  // �o�̪� me �O�� this_object()
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision("\n$N"HIW"���E�_�@�����Y����q�A���f�@�i�A�H�Y�r�M�ɵo�X\n\n\t�y-- �Q  �g  ��  �� -- �z�I�I\n\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
        if( inv[i]->is_corpse() ) continue;
      damage = random(250)+250;
      message_vision(HIW"$N�����G�D�զ�P�K�]�� .... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
    else
 {
      message_vision(HIR"\n$N�b�@�����Q�N�����u .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}

int receive_damage(string type,int cost)
{
  object ob,me;
  int i;
  ob = this_object();
  me = this_player();

  // ����
  if(!random(8))
  {
    if(ob->is_busy()) ob->add_busy(-10);
    message_vision(HIW"\n�i"HIR"�C�����s�������I"HIW"�j\n"NOR,ob);
    if(me->query("level") > 40)
    {
 COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+3);
      if(query("hp") < query("max_hp")) add("hp",60+random(40));
    }
    else
      if(me->query("level") > 30) 
      {        COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),random(2)+2);
         if(query("hp") < query("max_hp")) add("hp",15+random(15));
      }
      else
        if(me->query("level") > 24)
        {
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+2));
        }
        else
          COMBAT_D->do_attack(ob,me,ob->query_temp("weapon"),(random(2)+1));
  }

  ::receive_damage(type,cost,me);
  return 0;
}


void die()
{
  object ob, me = this_player(), env, accept, *obs = users(), obj, war_room;
  int temp, i;
  string msg;

  if( !ob = query_temp("last_damage_from") )
  ob = this_player(1);
  if( !ob )
  {
    ::die();
    return;
  }

  ob->add_temp("hero",3);
  ob->add("popularity",8);

  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query_temp("mission_accept")) accept = obs[i];
  if(!accept) accept = ob;

  message("world:world1:vision",
  HIW"\n�i�Z�L�����j"+
  "�W�j���s�y�C��  ���s�z���b" +ob->name(1)+ "���⤤�C\n\n",users());
  env = environment(me);
  temp = NATURE_D->which_world(env);
  message("world:world1:vision","\t" +NATURE_D->game_time(temp)+
  HIG"\n\t�i" +accept->name(1)+ "������Ѿ��ѤH���ӿաA���w�F�U�s�j�ӡI�I�j�C\n\n"NOR,users());

  msg = hero();
  message("world:world1:vision",
  HIC"\t�ڭ̷P�¤U�C�Z�L����惡�����Ȫ��^�m�A�o�ǫi�h�̪��W�r�N�û����Q�H�̩Ҭy�ǡG\n"NOR +msg,users());

  tell_object(ob,HIC"[�A�o���B�~�� 8 �I�n��!!]\n"NOR);


  war_room = load_object(WD_PAST+"sand/room92");
  war_room->end_war(1);

  ::die();
  return;
}

string hero()
{
  object *obs = users();
  object *inv;
  object *hero;
  object *maxhero = allocate(4);
  int *arr;
  int i, j, k, temp;
  string msg = " ";

  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query_temp("hero")) j++;

  arr = allocate(j);
  hero = allocate(j);

  j = 0;
  for(i=0;i<sizeof(obs);i++)
    if(obs[i]->query_temp("hero"))
    {
      arr[j] = obs[i]->query_temp("hero");
      hero[j] = obs[i];
      j++;
    }

  for(i=0;i<sizeof(hero);i++)
{
    k = 0;
    for(j=0;j<sizeof(hero);j++)
    {
      if(i == j) continue;
      if(arr[i] >= arr[j]) k++;
    }
    temp = sizeof(hero) - k;
    if(temp > 3) continue;
    maxhero[temp] = hero[i];
  }

  for(i=1;i<sizeof(maxhero);i++)
  {
    if(maxhero[i])
    switch(i)
    {
      case 1 : msg += HIW"\t�ѭ����ϡG " +maxhero[i]->name(1)+ " (�n�� +5)\n"NOR;
               maxhero[i]->add("popularity",5);
               break;
      case 2 : msg += NOR""WHT"\t���s�N�x�G " +maxhero[i]->name(1)+ " (�n�� +4)\n"NOR;
               maxhero[i]->add("popularity",4);
               break;
 case 3 : msg += HIW""BLK"\t�_�±N�x�G " +maxhero[i]->name(1)+ " (�n�� +3)\n"NOR;
               maxhero[i]->add("popularity",3);
               break;
    }
  }

  msg += CYN"\t�ͱ��䴩�G ";
  j = 1;
  for(i=0;i<sizeof(hero);i++)
  {
    if(hero[i] == maxhero[1] || hero[i] == maxhero[2] || hero[i] == maxhero[3]) continue;
    if(j) msg += hero[i]->name(1)+ "\n";
      else msg += "\t           " +hero[i]->name(1)+ " (�n�� +2)\n";
    hero[i]->add("popularity",2);
    j = 0;
  }
  if(j) msg += "\n";

  inv = all_inventory(environment(this_object()));
for(i=0;i<sizeof(inv);i++)
  {
    if(!userp(inv[i])) continue;
    for(j=0;j<sizeof(hero);j++)
if(inv[i] == hero[j])
      {
        k = 1;
        break;
      }
      else k = 0;
    if(k) continue;
    msg += "\t           " +inv[i]->name(1)+ " (�n�� +1)\n";
    inv[i]->add("popularity",1);
  }
  msg += ""NOR;

  for(i=0;i<sizeof(hero);i++)
    hero[i]->delete_temp("hero");

  return msg;
}

