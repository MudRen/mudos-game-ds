inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("[Magic-Card]������", ({ "boss" }) );
  set("gender", "�k��" );
  set("age", 22);
  set("long","�P�űmø��������A�M���c�� Magic �ȵP�C\n");
  set("level",1);
  set("attitude", "friendly");
  set("sell_list",([
  __DIR__"bag1" : 20,  // �ثe�c�檺�������� 1 �Ӫ���
  __DIR__"bag2" : 20,  // �ثe�c�檺�������� 2 �Ӫ���
  __DIR__"bag3" : 20,  // �ثe�c�檺�������� 3 �Ӫ���
  __DIR__"bag4" : 20,  // �ثe�c�檺�������� 4 �Ӫ��� , �o�Ӫ����n�P�� baal �j�O����
  __DIR__"box"  : 10,
  __DIR__"browse_card_set" : 10,   // �P�� cominging �j�O����
  ]) );
 setup();
}

void init()
{       
  add_action("do_list","list");
  add_action("do_buy","buy");
}

