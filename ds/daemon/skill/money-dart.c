/* �E�r�s���� (money-dart) Advanced Thief �Χޯ�
  By Tmr 2002/04/05
 
  �令�¯S���
  Update by tmr 2006/11/22
 */


#include <ansi.h>
inherit SKILL;
inherit SSERVER;


int exert(object me, object target, string arg)
{
     return notify_fail("�u�E�r�s����v��s���A�Ȯ������C\n");
}

int valid_learn(object me) {    return 1;   }

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    return 30 + ob->query_dex();
}


