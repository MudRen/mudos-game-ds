inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("�p��", ({ "jang sha","jang","sha" }) );
  set("gender", "�k��" );
  set("age", 22);
  set("long","�@�ӱM����S���������C\n");
  set("level",1);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
"�p���j�n�[�ܵ�: �������S���O�̦��W���A�U��Ӭݬݧr�C\n",
"�p���V�O�����������A�S�X�{�u���żˡC\n",
}) );

  set("sell_list",([
__DIR__"item/fresh-soup" : 5,
__DIR__"item/red-laver" : 5,
__DIR__"item/sea-rice" : 5,
__DIR__"item/tedder-fish" : 5,
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


