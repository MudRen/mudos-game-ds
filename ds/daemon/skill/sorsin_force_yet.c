/*****************************************************/
/* WIND CLASS NEW SKILL          DATE:2003.5.24      */
/* EDITOR:Jangshow               NOTE:NO WEAPON SK   */
/* �@�q�ɶ���,��ppl������,�A�ݭn���n�}�s�C           */
/*****************************************************/
#include <ansi.h>
#define SKILL_NAME "���P���q"
inherit SKILL;
inherit SSERVER;

int exert(object me, string arg)
{
    write("-���P����- ���a aass angel windstorm sayso �ݨ�ڮɽ� tell �� -by js-\n");

    return 1;
}

