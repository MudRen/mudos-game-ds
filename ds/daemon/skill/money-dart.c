/* 九瀑連環鏢 (money-dart) Advanced Thief 用技能
  By Tmr 2002/04/05
 
  改成純特攻技
  Update by tmr 2006/11/22
 */


#include <ansi.h>
inherit SKILL;
inherit SSERVER;


int exert(object me, object target, string arg)
{
     return notify_fail("「九瀑連環鏢」更新中，暫時關閉。\n");
}

int valid_learn(object me) {    return 1;   }

int practice_skill(object me) { return 1; }

int improve_limite(object ob)
{
    return 30 + ob->query_dex();
}


