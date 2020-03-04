#include <ansi.h>
#include <combat.h>
inherit NPC;

void heal();
void create()
{
  set_name(HIR"�岴"WHT"�f���s"NOR, ({"blood-eye dragon","dragon","_BLOOD_EYE_DRAGON_"}) );
  set("long",@LONG
�W�j�]�~�A���ۦ���������T�������Ω��ۯ�t�Ǫ�����A�̯S�O��
�O�Y�W�@��V�e�f�������j��A�ڶǻ��O���W�j�H���B�δ��z�N�e
�ަܪd�h�����A�A�s�_�ӧ�A�~�N�e�����b�d�h���U�C
LONG
);
  set("gender", "����");  
  set("race", "beast");
  set("unit","��");
  set("age",3000);
  set("level",60);
  set("attitude", "aggressive");
  set("evil",100);
  set("title",RED"  �]�~ "NOR); 
  set("limbs", ({ "�Y��", "����","�ݳ�","����","�e��","���","���l" }) );
  set("verbs", ({ "bite","crash","claw" }) );
  set("Merits/bar",10);
  set("Merits/bio",9);
  set("Merits/wit",4);
  set("Merits/tec",4);
  add("addition_damage",100+random(10));
  add("addition_armor",200);
  set("chat_chance", 35);
  set("chat_msg", ({
     (: heal :),
     }));
  set("chat_chance_combat",20);
  set("chat_msg_combat", ({
   HIR"�岴"WHT"�f���s"NOR"�i�}�ƺ��y�������L�A�o�X�@�}�_�Ѫ��R�q�C\n",
   HIR"�岴"WHT"�f���s"NOR"���l�L�ʡA�Φ��@�ѱj���A�ϧA�X�G������}�C\n",
   HIR"�岴"WHT"�f���s"NOR"���e�}��b�a�W�y���@�}�̰ʡC\n",
     }) );
  setup();
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper1");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper2");
        if(random(100)>95) // 5%
                carry_object(__DIR__"eq/treasure-paper3");

  set_living_name("_NPC_BLOOD_EYE_DRAGON_");
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
  if( this_player()==this_object()->query_temp("last_opponent") )
  {
    message_vision(HIG"(�w������)"HIR"�岴"WHT"�f���s"NOR"���������V$N�A$N�@�ɶ������k�h���H�����I�I\n"NOR,this_player() );
    this_player()->add_busy(random(2)+1);
  }
}

void heal()
{
  if( query("hp")+500 < query("max_hp") )
  {
    message_vision("$N���W�o�X�H�H�������C\n",this_object());
    add("hp",250+random(200));
    return;
  }
  return;
}

int special_attack(object me, object target, int hitchance)
{
  if(!me) return 0;
  if(me->is_busy()) return 0;

  if(!random(8))
  {
    me->start_busy(2);
    target->add_busy(1);
    message_vision("\n$N��M����F�ʧ@�A�Y�W���T�����������o�X"HIR"����"NOR"�I�I\n"NOR,me);
    call_out("do_super",2,me);
    return 1;
  }
  else if(!random(8))
  {
    me->start_busy(1);
    target->add_busy(3);
    message_vision("\n$N"HIW"���W�F�b�šA���l�r�Oݵ�ʡI�I\n"NOR,me);
    call_out("do_super2",1,me);
    return 1;
  }
  else if(!random(8))
  {
    message_vision( "$N�o�X�@�}��q�C\n", me );
    COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 4);
    COMBAT_D->report_statue(target);
    return 1;
  }
  return 0;
}

void do_super(object me)
{
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision("\n$N"HIR"���T���������E�X�j�P��������W�A�V�|�P���g�I�I\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(200)+350-(inv[i]->query_armor());
      message_vision(HIR"$N�Q���W���������������ۤ��J��.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
/*    else
    {
      message_vision(HIR"\n$N�b�@�����N�����u .... \n\n"NOR,inv[i]);
      destruct(inv[i]);
    }
*/
  }
  me->start_busy(2);
  return;
}

void do_super2(object me)
{
  // �o�̪� me �O�� this_object()
  object *inv;
  int i, damage;
  inv = all_inventory(environment(me));
  if(!inv) return;
  if(!me) return;

  message_vision(HIW"\n�Ŷ�����y�ļ��ް_�F�кu�u�A�~�ө޾𨫥ۡA�٬O��H�I�I\n"NOR,me);
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = random(100)+50;
      message_vision(HIW"$N�Q��y���_�b�b�Ť�½�u�A���a�ɤw�O�Y��������½��.... "HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      COMBAT_D->report_status(inv[i]);
    }
  }
  return;
}

int receive_damage(string type,int cost)
{
  object ob,me;
  ob = this_object();
  me = this_player();
  ::receive_damage(type,cost,me);
  return 0;
}

void die()
{
  object ob,eqp;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
  message("world:world1:vision",
    HIG"\n\t�i��@�q�j�G"+RED"�W�j�]�~  "HIR"�岴"HIW"�f���s"HIW"  �Q�^�i��"+ob->name(1)+"�����F...\n\n"+NOR
    ,users());
  ob->add("popularity",7);      
  tell_object(ob,HIG"�A�o�� 7 �I�n��C"NOR);
  if( random(5000) )
    eqp=new(__DIR__"eq/inverse-horn-helmet");
  else
    eqp=new(__DIR__"eq/blood-eye-dragon-armor");
  eqp->move(this_object());
  ::die();
  return;
}
