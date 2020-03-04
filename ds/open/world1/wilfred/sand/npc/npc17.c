inherit NPC;
inherit SELLMAN;

void soldier_assist(object me);

void create()
{
  set_name("�Ӷ�����", ({ "caravan boss","boss" }) );
  set("gender", "�k��" );
  set("age", 30);
  set("long", @LONG
�L�O�@��g�`���ӷɿ��P�Y�s�����ӤH�A���~�b�~�b�i�A�ֽ��Q�αo
�K�µo�G�A�]�\�A�i�H��L�R�I�F�� <�ݦs�f: list   �R�F��: buy>�C
LONG
);
  set("level",10);
  set("attitude", "friendly");
  set("chat_chance", 20);
  set("chat_msg", ({
(: command("say �ӨӨӡA�ݬݤW�n���f�~�A�O�Һ��N�C") :),
"�Ӷ���������F��S�A���F���y�W�����C\n",
(: command("smile") :),
}) );

  set("sell_list",([
__DIR__"obj/obj9" : 10,
__DIR__"obj/obj10" : 5,
__DIR__"obj/obj11" : 20,
__DIR__"eq/eq16" : 2,
__DIR__"eq/eq17" : 2,
__DIR__"eq/eq18" : 2,
]) );
  setup();
  add_money("coin",500);
}

void init()
{
  ::init();
  add_action("do_list","list");
  add_action("do_buy","buy");
  add_action("do_kill","kill");
}

int do_kill(string arg)
{
  object *inv, me = this_player();
  int i;

  if (!arg) return 0;
  if(present(arg, environment(me)) != this_object()) return 0;
  if( is_fighting(me) ) return 0;
  command("say ���H������֨ӱϧڭ�����");

  inv = all_inventory(environment());
  for(i=0;i<sizeof(inv);i++)
  {
    if(inv[i] ==  this_object()) continue;
    inv[i]->soldier_assist(me);
  }
  return 0;
}

void soldier_assist(object me)
{
  if( !living(this_object()) || is_fighting(me) ) return;

  switch(random(2))
  {
    case 0: command("say �i�c�I�����d�����T�A�A�����٦����k�ܡH\n"); break;
    case 1: command("say �ޡT�A�Q�F����S"); break;
  }
  kill_ob(me);
  me->fight_ob(this_object());
}
