inherit NPC;
inherit SELLMAN;

void create()
{
  set_name("���p�G", ({ "waiter" }) );
  set("gender", "�k��" );
  set("age", 22);
  set("long","�@�Ӷ]�󪺩��p�G�C\n");
  set("level",1);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
"���p�G���_�F�٥��A���F���y�W���N���C\n",
"���p�G��M�Q�_�o�٥���~���L�a�O�A���T�y�F�@�w�N���C\n",
}) );

  set("sell_list",([
__DIR__"obj/obj12" : 5,
__DIR__"obj/obj13" : 5,
__DIR__"obj/obj14" : 5,
]));
set("no_kill",1);
set("no_cast",1);
set("no_fight",1);
  setup();
  carry_object(__DIR__"obj/obj26");
}

void init()
{
  add_action("do_list","list");
  add_action("do_buy","buy");
}
