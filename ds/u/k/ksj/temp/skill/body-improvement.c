/*************************************************/
/*  Skill �뵬�V��           Date:2003.4.7       */
/*  Editor - Jangshow        Lv 50 new sk        */
/*  ����:�̦� sk �����C�ӨM�w�W�[�ɶ������u      */
/*************************************************/ 
#include <ansi.h>
#define SKILL_NAME "�뵬�V��"
inherit SKILL;
inherit SSERVER;

int exert(string arg)
{   
     object me=this_player();
     //�o�榳��S�����@�ˡA���٬O�g�@�U�n�F
     if(me->query("level") < 50 ) return notify_fail("�A�����Ť�����C\n"); 
     if(me->query("con") < 70 ) return notify_fail("�A����褣���Ө������ޯ�C\n");   
     message_vision(HIW"$N�B�_�W�j���뵬�V�����N�A�j�j���ɤF���C\n"NOR,me); 
     {
     //�� 4 �h
        if(me->query_skill("body-improvement") <= 25)
        {
          me->add("max_hp",200);
          call_out("DE_ADD",120,me);
        }
        else if(me->query_skill("body-improvement") <= 50) 
        {
          me->add("max_hp",200);
          call_out("DE_ADD",180,me);
        }
        else if(me->query_skill("body-improvement") <= 75) 
        {
          me->add("max_hp",200);
          call_out("DE_ADD",240,me);
        }
        else if(me->query_skill("body-improvement") >=100) 
        {
          me->add("max_hp",200);
          call_out("DE_ADD",300,me); 
        }
        else return 1; 
      }
      me->improve_skill("body-improvement",1+random(me->query_int()/5)); 
      return 1;
} 
void DE_ADD(object me)
{ message_vision("$N���ݤ@�n�A�����F�뵬�V�����N�C\n",me);me->receive_damage("max_hp",200); return;}   
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
