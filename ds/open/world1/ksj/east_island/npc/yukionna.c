#include <ansi.h>
inherit NPC;
varargs int receive_damage(string type, int damage, object who);

mapping *combat_action = ({
        ([  "action":       "$N�����j�X�@�f�H��A������ı��$n��$l�����еۤ@�h�B��",
                "attact_type":  "wit",
                "damage_type":  "���",
        ]),
        ([  "action":       "$N�����a�A$n�Ҧb���a���W��t���X�y�U���B��",
                "attact_type":  "wit",
                "damage_type":  "���",
        ]),
        ([  "action":       "$N����s���A�Ƥ��U�Q�����B���V$n��$l",
                "attact_type":  "wit",
                "damage_type":  "�ζ�",
        ]),
        ([  "action":       "$N���Ϋ�ۡA�L�ƦB���q$N���ǭ����}�ӡA���V$n",
                "attact_type":  "wit",
                "damage_type":  "������",
        ]),
        ([  "action":       "$N�k�⻴���A�Ť������X�Ʊ��B�W�����V$n��$l",
                "attact_type":  "wit",
                "damage_type":  "����",
        ]),
});

mapping query_action()
{
  return combat_action[random(sizeof(combat_action))];
}

void create()
{
  set_name(HIW"���k"NOR, ({"yukionna"}) );
  set("long",@LONG
���k�|�b�ɭ������]�ߥX�{�A�|�N���p�߼����o���H�[�H���`�A���M
�o�O�@��ٽ�������z���զ٬��k�A���O�u�n�Q�o���B�N�𮧧j��A
�N�|���W��t�N��A�ڻ��b����~�A�Y�O�ݨ캵���ܥu�n�˦��N��
���w�L�ơA�U�@�����F���k���ܡA�u�n�˧@�S�ݨ��N�i�k�L�@�T��I
LONG
);
  set("race", "�H��");
  set("unit","��");
  set("age",130);
  set("attitude", "aggressive");
  set("gender", "�k��" );
  set("level",45);
  set("Merits/wit",5);
  set("int",60);
  set_skill("unarmed",50);
  set_skill("dodge",70);
  set_skill("parry",30);
  add("addition_armor",80);
  set_temp("apply/hit",30);
  set_temp("apply/dodge",30);
  setup();
  set("default_actions", (: call_other, __FILE__, "query_action" :));
  set("actions", (: call_other, __FILE__, "query_action" :));
  carry_object(__DIR__"eq/ice-silk-cloth")->wear();
}

void init()
{
  ::init();
  if( environment(this_player())->query("no_kill") ) return;
  if( environment(this_player())->query("no_fight") ) return;
  if(!this_object()->visible(this_player())) return;
  if(userp(this_player()) )
    this_object()->kill_ob(this_player());
}

int special_attack(object me, object target, int hitchance)
{
  if(!me || !target) return 0;
  if( !random(7) )
  {
    message_vision(HIC"���k���W��"HIW"�����N"HIC"�o�X�ũM���ե��A�v���F���k���˶աC\n"NOR,me);
    me->receive_heal("hp", 250);
  }
  if(me->is_busy()) return 0;
  if( !random(8) )
  {
    me->start_busy(2);
    target->add_busy(2);
    message_vision(HIW"\n���k�����o�X���j�H��A�ϥX"HIC"�i�B�W���ɡj"HIW"�|�P�y�ɾh�_�j��\n"
       +"���a�۵L�ƾW�Q���B���A���|���K��ŧ�h�I�I\n\n"
       +"  ��X"HIC"��"HIW"�D"HIC"��"HIW"�X �D"HIC"��"HIW"�O�X��X"HIC"��"HIW"�D�X �D�O�C��X\n"
       +"  "HIC"��"HIW" �D�O�X��X "HIC"��"HIW"�D�D�O�X��X�D"HIC"��"HIW"�X"HIC"��"HIW"�X��X\n"
       +"  �X�� �D��D�O�X�� "HIC"��"HIW"�X �D�O"HIC"��"HIW"�X��X�D�X�X \n"
       +"  ��X�D�X"HIC"��"HIW" �D�O�X��X�D�X��X�D"HIC"����"HIW"�X �D�O\n"
       +"  �X�D"HIC"��"HIW"�X �D"HIC"��"HIW"�O�� �D��D�O�X�X�D�X�X�D"HIC"��"HIW"  \n"
       +"  �D�O�X��"HIC"��"HIW"�X�D�X��X�D"HIC"��"HIW"�X �D�O�X��X�D�X \n"
       +"  �D�O�X��X"HIC"��"HIW"�D�X�D��O�X�X�X�D��O�X��"HIC"��"HIW"�X\n\n"NOR,me);

    call_out("do_super",1,me);
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

  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] == me) continue;
    if(living(inv[i]) )
    {
      if( inv[i]->is_corpse() ) continue;
      if( inv[i]->query_temp("invis")>2 ) continue;
      damage = 300 - (inv[i]->query_armor() ) +random(100);
      if( me->query("hp") < me->query("max_hp")/6 )
        damage = damage + random(100);
      if(damage<0) damage =0;
      message_vision(HIR"$N�Q�U�Q�p�M�b���B���αo�����˲��ֲ֡D�D�D"HIR"("+damage+")\n"NOR,inv[i]);
      inv[i]->receive_damage("hp", damage, me);
      inv[i]->add_busy(2);
      COMBAT_D->report_status(inv[i]);
    }
  }
  me->start_busy(1);
  return;
}

varargs int receive_damage(string type, int damage, object who)
{
  int val;

  if( damage < 0 ) error("F_DAMAGE: �ˮ`�Ȭ��t�ȡC\n");
  if( type!="hp" && type!="mp" && type!="ap" )
    error("F_DAMAGE: �ˮ`�������~( �u��O hp, mp, ap�䤤���@ )�C\n");
  if( objectp(who) && type=="hp")
    set_temp("last_damage_from", who);

  if(random(100)<30)
  {
    damage/=3;
    message_vision(HIW "\n$N�f�R�H�𾮻E���@���B�ޡA�ץh�F�j�b���ˮ`�C\n" NOR,this_object());
  }
  if(objectp(who) )
    ::receive_damage(type,damage,who);
  else
    ::receive_damage(type,damage,who);
  return damage;
}

void die()
{
  object ob;
  if( !ob = query_temp("last_damage_from") )
    ob = this_player(1);
  if( !ob ) 
  {
    ::die();
    return;
  }
 
  switch( random(10) )
  {
    case  0..2:
          new(__DIR__"eq/ice-bracelet")->move(this_object());
          break;
  }
  ::die();
  return;
}
