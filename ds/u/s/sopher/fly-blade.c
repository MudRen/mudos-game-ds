#include <ansi.h>
#include <combat.h>
inherit SKILL;
inherit SSERVER;

void sp_attack0(object me, object victim, object  weapon, int damage);
void sp_attack1(object me, object victim, object  weapon, int damage);
void sp_attack2(object me, object victim, object  weapon, int damage);
void sp_attack3(object me, object victim, object  weapon, int damage);
void sp_attack4(object me, object victim, object  weapon, int damage);
void sp_attack5(object me, object victim, object  weapon, int damage);
void sp_attack6(object me, object victim, object  weapon, int damage);
int str=this_player()->query_str();
int con=this_player()->query_con();
int dex=this_player()->query_dex();
int sp_value;

string *parry_msg = ({
"�ھסT�ھסT�ھסT�סT�סT\n"
        });

string *unarmed_parry_msg = ({
"���O�Q$n��}�F�C\n",
"���G�Q$n�׶}�F�C\n",
});

string *nine_dragon = ({
HIC"             ���������         �u���@�D�M�����V$n���y ��� �z\n",
HIC"             ��  ��L  ��  ��       �u���@�D�M���׬�V$n���y �f�P�� �z\n",
HIC"           ���  ��ѡ�  ���       �u���@�D�M�����V$n���y �k�X(��)�z\n",
HIC"           ����  �v  ����       �u���@�D�M���פ��V$n���y �k���W �z\n",
HIC"           ��  ������  ��       �u���@�D�M���ѤU���W�V$n���y �f�� �z\n",
HIC"           ��    �㳰��    ��       �u���@�D�M���פ��V$n���y �����W �z\n",
HIC"             ���  �m  ���         �u���@�D�M�����V$n���y ���X(�f��) �z\n",
HIC"           ��  ��  ��  ��  ��       �u���@�D�M���׬�V$n���y �P�Ʊ� �z\n",
HIC"           �����h�����       �u���@�D�M����V$n���y ��� �z\n",
});

string *shasword = ({
});



mapping *action = ({
//1
        ([
                "action"     :
HIY"$N���_$w½�ۼ��g ,�ϥX�F���ѱs�C�y�����N�U�y �g�s�{ �z�T
"HIY"�����g�ۤƴݼv�Y���V$n�ӥh�T",
                "dodge"      :               -100,
                "parry"      :               -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack0 :),
                "damage_type":               "���"
        ]),
//2
        ([
                "action"     :
HIY"$N�������D ,�����b$n�����u�� ,���M�ϥX�F���ѱs�C�y�y �s�l�{ �z�T
"HIY"�q�W���|�_$w�A�F�U�h ,�u��$w�����a�G��$n�������T",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack1 :),
                "damage_type":               "���"
        ]),
//3
        ([
                "action"     :
HIY"$N�B�Y��� ,�H���֪��t�רB�J$n���e ,�ϥX�F���ѱs�C�y�y �s���{ �z�T
"HIY"$w���M���p�E������ѤU���W���V$n���",
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack2 :),
                "damage_type":               "�ζ�"
        ]),
//4
        ([
                "action"     :
HIY"$N��M����|�� ,�j�ܤ@�n�T�ϥX�F���ѱs�C�y�����N�U�y �s�_�{ �z�T
"HIY"�x�_�i�i���N�p�b�¤@��a�V$n�ñ٦ӥh"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                130,
                "force"      :                130,
                "post_action":                (: sp_attack3 :),
                "damage_type":               "�ζ�"
        ]),
//5
        ([
                "action"     :
HIC"$N�N��̪�$w���J�C�T�� ,�ϥX�F���ѱs�C�y�U�ޤM�N"HIR"�y ���s�{ �z"HIY"�T
�H���t�������X$w ,��$n�����W���h"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                140,
                "force"      :                140,
//                "post_action":                (: sp_attack4 :),
                "damage_type":               "�ζ�"
        ]),
//6
        ([
                "action"     :
HIY"$N�@�ӭ˨��� ,�p�p�j�����¶��$n������ ,�ϥX�F���ѱs�C�y�y �s���{ �z�T
"HIY"$N�Q�ΰj�ߤO���j�ۨϵ�$w��V$n������n�`"NOR,
                "dodge"      :                -100,
                "parry"      :                -100,
                "damage"     :                150,
                "force"      :                150,
//                "post_action":                (: sp_attack5 :),
                "damage_type":               "���"
        ]),
//7
         ([     "action"     :
HIY"$N�E�뾮�� ,��M�B�Y���C�ĦV$n  ,�ϥX�F���ѱs�C�y�����N�U�y �E�Y�s�{ �z�T
"HIY"�u���M���p����E�{ ,�Ʀ��E�����s���V$n",
                "parry"      :                -100,
                "dodge"      :                -100,
                "damage"     :                150,
                "force"      :                150,
                "post_action":                (: sp_attack6 :),
                "damage_type":                "���",
           ]),
});

int valid_learn(object me)
{

       if( !me->query_temp("weapon")){
        tell_object(me,"�m���ѱs�C�y���ݥ�����M�C\n");
        return 0;
                                     }

        return   1;
}

int exert(string usage)
{
        return ( usage=="blade" || usage=="parry" );
}


mapping query_action(object me, object *weapon)
{

 int skill_level,limit,i;

 skill_level = (int)(me->query_skill("fly-blade",1));
 limit= skill_level;

        if (limit < 15)
        return action[random(1)];
        else if (limit < 30)
                return action[random(2)];
        else if (limit < 45)
                return action[random(3)];
        else if (limit < 60)
                return action[random(4)];
        else if (limit < 75)
                return action[random(5)];
        else if (limit < 90)
                return action[random(6)];
        else
          return action[random(7)];
}

void sp_attack0(object me, object victim, object  weapon, int damage)
{
  int i, lose;
  sp_value = 5 * me->query("level") / victim->query("level") + 1;
  if( sp_value > 10)  sp_value = 10;
lose = random(str/4+con/8);
  if( lose > 5 )  lose = 5;
  message_vision(HIR"�L�������u��$n���F�L�h�T\n"NOR, me, victim);
  for(i = 0; i < lose; i++)
  {
  victim->receive_damage("hp",random(sp_value/2),me);
  COMBAT_D->report_status(victim);
  }
  if(random(victim->query("psy") / 2 + victim->query("dex") ) < 20)
  {
  message_vision(HIY"$n�Q���u������ ,�@�ɤ߶äj�ݤ߯����w�C\n"NOR,me,victim);
  victim->start_busy(1);
  }
}

void sp_attack1(object me, object victim, object  weapon, int damage)
{
    sp_value = str + con / 2 +dex /4;
    if(victim->query("level") < ( me->query("level") / 3 ) ) {
    message_vision(HIR"$n�Ө����F�s�l�{�������ө��֭˦a�C\n"NOR, me, victim);
victim->set("hp",-1);
    victim->set(",mp",-1);
    COMBAT_D->report_status(victim);
    victim->set_temp("unconcious", 1);
    return 0;
    }
    if(victim->query("level") < ( me->query("level") * 2 / 3 ) ) {
message_vision(HIY"$n�]�s�l�{�������ө������Y ,�@�ɯ���í�C\n"NOR, me, victim);
    victim->start_busy(2);
    victim->receive_wound("hp",random(sp_value/4));
    COMBAT_D->report_status(victim);
    return 0;
    }
   if(victim->query("level") < ( me->query("level") * 4 / 3) ){
   message_vision(HIY"$n�]�s�l�{�������v�T�ӷ�F�@�U�C\n"NOR,me ,victim);
   victim->start_busy(1);
   return 0;
   } else {
   message_vision(HIC"$n���G�S����ƻ�v�T���ˤl�C\n"NOR,me ,victim);
   return 0;
   }
}

void sp_attack2(object me, object victim, object  weapon, int damage)
{
    sp_value =random(con+str/4+dex);
    message_vision(HIC"$N��զp�� ,�u��$n���"HIR"�"HIW"�"HIR"�"HIW"�"HIC"�|�q "NOR);
    victim->receive_damage("hp",sp_value/4,me);
    COMBAT_D->report_status(victim);
}

void sp_attack3(object me, object victim, object  weapon, int damage)
{
    int i ,lose;
    sp_value =random(str)+10;
    lose = random(str/2+dex/8+con/4)+str/2;
    if( lose > 7 ) lose = 7;
    message_vision(HIW"�u��$n�Q�C�v�M���ҳ� ,�E�ݤ��U�N�p�s�_�@�� ,���v�|�g ,�p���|�q"NOR);
    for(i = 0; i < lose; i++ )
    {
victim->receive_damage("hp",sp_value ,me);
    COMBAT_D->report_status(victim);

}
   if(random(victim->query("psy") / 2 + victim->query("int") ) < 40)
   {
   message_vision(HIR"$n���W�M�˦h�B ,�ݮ����w ,�@�ɰʼu���o�C\n"NOR,me,victim);
   victim->start_busy(3);
   }
   victim->start_busy(2);
}
void sp_attack4(object me, object victim, object  weapon, int damage)
{
    int i;

    message_vision(HIR"
$N�X��½�����D�A�װj�C�y�A�����F�ʨϥX"HIW"�y���V�i���z"HIR"�A�K��
���N�g�b�A������{�L�k�ۨ�A�C�����ۡA�s�ꦨ�L�ƵL�έ��b�A�d
�ר����}����"NOR,me,victim);
me->set_temp("conti",1);
    for(i=0; i<3 ;i++)
    COMBAT_D->do_attack(me, victim, me->query_temp("weapon"), TYPE_QUICK);
    me->delete_temp("conti");

}
void sp_attack6(object me, object victim, object  weapon, int damage)
{
  string do_action;
  string arg;
  mixed all;
  object *enemy,who,room,weaponn,obj;
  string actionn;
  int i,j,force;

  force=me->query("force",1);
  enemy = me->query_enemy();
i=random(sizeof(enemy));

message_vision(HIR"
�w���� ,�M�W�x�x���N ,�M�����p�V��G�H
     $N�@�n�j�� ,�⤤�U�M�S�����s�R�ѡA�M�ۤd���u�b�@����$n�w�������s�Q�]�S�T
\n"NOR,me,victim);
    for(j=0; j < 9; j++) {
       do_action = nine_dragon[j];
              actionn += do_action;

       if( weaponn=me->query_temp("weapon") )
       actionn = replace_string(actionn, "$w", weaponn->name());
       message_vision(actionn, me, enemy[i]);
         if( random(me->query("level")) > random(enemy[i]->query("level"))/6 ) {
       message_vision("\n$N�{������ ,���W���ɦh�X�F�@�D��O�O���M���T\n" , enemy);
       enemy[i]->receive_wound("hp",random(100)+100,me);
       me->add("force",-30);
       COMBAT_D->report_status(enemy[i]);
                             }
else message_vision("\n$N�H��M�֡A���I�a�{�L�T\n" , enemy[i]);
                }
}

