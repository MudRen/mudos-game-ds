inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("���c", ({ "fish seller","fish","seller" }) );
  set("gender", "�k��" );
  set("age", 37);
  set("long","�@�ӳc�溮�򪺤H�A�b�L�o�i�H�R��\\�h�s�A�����C\n");
  set("level",1);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
"���c�j�n�۵�: ����������O�̷s�A���A�]���N�L�˼˩y�r�C\n",
"���c�Ӥߪ��B�z�۳��סA�⤣�X�A���a�賣�h���C\n",
}) );

  set("sell_list",([
__DIR__"item/flyfish-meat" : 5,
__DIR__"item/grig-meat" : 5,
__DIR__"item/shark-meat" : 5,
__DIR__"item/sifu-meat" : 5,
__DIR__"item/liuye-meat" : 5,
__DIR__"item/sandling-meat" : 5,
__DIR__"item/yue-meat" : 5,
]));
set("no_kill",1);
set("no_cast",1);
set("no_fight",1);
  setup();
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}




