inherit ITEM;

void create()
{
  set_name("sk3�~������", ({ "sk3 lotion","lotion" }) );
  set_weight(400);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long", "�o�O�ثe�̺Z�P�����~,��(use)�F�ݰ_�ӷ|�ܦ~���C\n");
    set("unit", "�~");
  }
  set("value", 30000);
  set("lotion_remaining", 2);  // �]�w�i�ϥΪ�����
  setup();
}

void init()
{
  add_action("do_use","use");
}

int do_use()
{
  object me=this_player(),ob=this_object();

  me->add("age", -1);  // �]�w�n�^�_����ƭ�

  ob->add("lotion_remaining",-1);
  if(!ob->query("lotion_remaining"))
  {
    message_vision("$N�N������$n����F,��ӤH�ܱo�K�����y�C\n",me,ob);
    destruct(ob);
    return 1;
  }
  message_vision("$N���_�@�~$n�b�y�W���������,���G�~���F�_�ӡC\n",me,ob);
  return 1;
}

