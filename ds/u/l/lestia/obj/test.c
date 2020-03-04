inherit NPC;

void create()
{
  set_name("�����k", ({"jinchai nu", "nu", "girl"}) );
  set("gender", "�k��" );
  set("age", 20);
  set("long","�@��h�ܯ����t���A���Ȼ��S�p�ݪ����k�C\n");

  set("combat_exp", 2500);
set("define_look","�ݰ_�ӷQ���A�W");
  set("str", 15);
  set("attitude","heroism");

  setup();
  //carry_object("/d/obj/cloth/skirt")->wear();
}

void init()
{
  add_action ("do_sleep","sleep");
  remove_call_out ("says");
  call_out("says",random(3),this_object());
}

void says (object me)
{
  string *msgs = ({
    "$N�Y�Y�@���A�׼L�ݵۧA�C\n",
    "$N�t���߯ߦa��A���K�K�ڡK�K\n",
    "�ݨ�$N�ܷQ��A�K�K�p�G�A�@�N�A�]�ФU�@�� sleep �R�O�C\n",
    "$N��ۧA�|�ߦa�@���A�I�F�I�Y�C\n",
    "$N�ܷQ��A�K�K\n",
    "$N��A�����@���C\n",
  });
  message_vision (msgs[random(sizeof(msgs))],me);
  remove_call_out ("says");
  call_out("says",random(40),me);
}

int do_sleep ()
{
  object me = this_object();
  object who = this_player();
  message_vision ("$N�O��$n�X�n������A���ѱo�߾K���g�K�K\n\n",who,me);
  who->command_function("remove all");
  who->start_busy(3,3);
  remove_call_out ("get_fainted");
  call_out ("get_fainted",1,who,me);
  remove_call_out ("says");
  call_out("says",40,me);
message_vision ("$N�O��$n�X�n������A���ѱo�߾K���g2�K�K\n\n",who,me);
  return 1;
}

void get_fainted (object who, object me)
{
  object *objs = all_inventory(who);
  int i = sizeof (objs);
  message_vision ("$N��$n�����a�@���C\n\n",me,who);
  who->unconcious();
  while (i--)
  {
    object obj = objs[i];
    message_vision ("$N�q$n���W���X"+obj->query("name")+"�C\n",me,who);
    obj->move(me);
    destruct(obj);
  }
}

