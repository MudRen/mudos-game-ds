#include <ansi.h>
inherit NPC;

void create()
{
  set_name(RED"���s��"NOR, ({"red pig","pig"}) );
  set("long",@LONG
�@�إͪ��b�s�̩ΰ���a�a�����ޡA�ͩʬ۷��ĵ�A�y�����j
��ʫK�k���ԤԡAť�����ު��קe�A����A�׽��A���A�O���W
�ŮƲz�����ơA�]���򷥬������A������ۤ�����C
LONG
);
  set("race", "beast");
  set("unit","��");
  set("age",1);
  set("level",1);
  set("limbs", ({ "����" }) );
  set("verbs", ({ "bite" }) );
  setup();
}

void init()
{
  object ob = this_object(), me = this_player();
  if(!ob->visible(me)) return;
  message_vision(HIR"$N"HIR"ĵı�즳�H�a��A�@�ȷϪ��k���L�ܤF�C\n"NOR,ob);
  destruct(ob);
}

