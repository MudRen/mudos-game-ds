inherit NPC;

void soldier_assist(object me);

void create()
{
  set_name("�Ӷ��u�H", ({ "caravan worker","worker" }) );
  set("gender", "�k��" );
  set("age", 28);
  set("long","�L�O�@���۰Ӷ��u�@���u�H�A���~�b�~�b�i�A�ֽ��Q�αo�K�µo�G�C");
  set("level",12);
  set("attitude", "friendly");
  setup();
}

void init()
{
  ::init();
  add_action("do_kill","kill");
}

int do_kill(string arg)
{
  object *inv, me = this_player();
  int i;

  if (!arg) return 0;
  if(present(arg, environment(me)) != this_object()) return 0;
  if( is_fighting(me) ) return 0;
  command("flop");
  command("scream");

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
