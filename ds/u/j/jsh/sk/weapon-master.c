/*************************************************/
/*  Skill �L���j�v           Date:2003.4.7       */
/*  Editor - Jangshow        Lv 50 new sk        */
/*  ����:�̦� sk �����C�ӨM�w�W�[�ɶ������u      */
/*************************************************/ 
#include <ansi.h>
#define SKILL_NAME "�L���j�v"
inherit SKILL;
inherit SSERVER;

int exert(string arg)
{    
     int sk_lv,damage;
     object me=this_player(); 
     sk_lv=me->query_skill("weapon-master"); 
     weapon=me->query_temp("weapon"); 
     damage=me->weapon*(1+0.03*sk_lv); //�o�榳���D,�A��@�U,weapon�������O�ڨS��
     if(me->query("level") < 50 ) return notify_fail("�A�����Ť�����C\n"); 
     if(me->query("str") < 70 ) return notify_fail("�A���O�q�����Ө������ޯ�C\n");  
     if(!weapon) return notify_fail("�A�⤤�S���Z���A�p��Ӵ��ɧ����O�H\n"); 
      message_vision(HIW"$N�����@�G�A�W�[�F�⤤�����ˤO�C\n"NOR,me); 
     { 
      me->add("damage",damage); //�����O��data�Oԣ?
       �˳ƪZ����,���ɤ������O=(�Z�������O)*(1+0.03*sk_lv)
     }      me->improve_skill("weapon-master",2+random(me->query_int()/5)); 
      return 1;
} 
void DE_ADD(object me)
{ message_vision("$N�����������t�H�C\n",me);me->receive_damage("max_hp",); return;}   
int valid_learn(object me)
{
        return 1;
} 

int improve_limite(object ob)
{
        return 100;
}

int practice_skill(object me)
{
        return 1;
}

