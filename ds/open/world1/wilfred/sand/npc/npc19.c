inherit NPC;

void create()
{
  set_name("�Ӷ��O��", ({ "caravan guard","guard" }) );
  set("gender", "�k��" );
  set("age", 28);
  set("long", @LONG
�L�O�@��Q�ШӫO�@�Ӷ��O�ߡA���~��۰Ӷ��|�B�b���A���H��I���y�A
�@�ܤj���A�������o�ۤ@�ѭ^��A�ݨӨëD���P�����C
LONG
);
  set("level",25);
  set("attitude", "heroism");
  set_skill("blade",60);
  set_skill("dodge",70);
  set_skill("parry",60);
  setup();
  carry_object(__DIR__"wp/wp4")->wield();
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
  command("say �����ʨ���Y�W�ӤF�H �䦺�I");

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

