/*****************************************************/
/* WIND CLASS NEW SKILL          DATE:2003.5.24      */
/* EDITOR:Jangshow               NOTE:NO WEAPON SK   */
/* 一段時間後,看ppl的反應,再看要不要開御劍           */
/*****************************************************/
#include <ansi.h>
#define SKILL_NAME "索星奧義"
inherit SKILL;
inherit SSERVER;

int exert(object me, string arg)
{
    write("-索星關閉- 玩家 aass angel windstorm sayso 看到我時請 tell 我 -by js-\n");

    return 1;
}

