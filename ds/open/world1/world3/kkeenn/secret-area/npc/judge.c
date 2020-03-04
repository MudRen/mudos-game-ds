#include <ansi.h>
#include <command.h>
inherit NPC;
int do_divorce2(string index);
object ppl2, ppl1;

void create()
{
  set_name(HIW"�j�k�x"NOR, ({ "big judge","judge" }) );
  set("gender", "�k��" );
  set("age", 28);
  set("long",@LONG
�L�O��ڪk�x���j�k�x�A�M�q�k�k���������ơA�L���[���Q���}��
���׬O�k��Τk��A�L�@�ߤ@���P���A���H�����A�ҥH�b�L�G�Q�K
�����ɭԡA�N��W�F��ڪk�x�ּƪ����k�̤��@�A�L�̱`�f�z����
�K�O�k�k���B�ơA���L���q�����B�ä��ݭn�ХL�A�j�����ХL���O
���F�n���B.....(divorce �H)
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
  (: command,"say �k�k����...�۳B���n�N�Ӥ��}..." :),
  (: command,"sigh" :),
  (: command,"say ���n�ӫj�j...�Q���N���a.." :),
  (: command,"sob" :),
     }));
  set("level",1);
  set("attitude", "friendly");
  set("no_cast",1);
  set("no_kill",1);
  setup();
}

void init()
{
  seteuid(getuid(environment()));
  if(!userp(this_player())) return;
  add_action("do_divorce","divorce");
  add_action("do_yes",({"y"}));
  add_action("do_yes",({"yes"}));
  add_action("do_no",({"no"}));
}
int do_divorce(string str)
{
  object target, temp, ob = this_object(), me = this_player();

  if(query("divorcing")) return notify_fail("�o���G���b��.\n");

  message_vision(HIC"$N���G$n�A�ڷQ�нбz���ڿ�z���B�ƶ��a�C\n"NOR,me,ob);
  if(me->query("bank/future") < 15000)
  {
    command("snort");
    command("say ���k�x�O�ݭn���D�^�O���C");
    write("[�z�Ȧ�s�ڦܤ֭n�� 15000 �T�q�l���C]\n");
    return 1;
  }
  if(!str)
  {
    command("say �@�H�Q�i�O�֡H�i���L���W�r��H");
    return 1;
  }
  if(!target = find_player(str))
  {
    command("hmm");
    command("say �n���S�o��B�ͳ�A�z�Ц^�a�C");
    return 1;
  }
  if(!target == me->query("marry_id"))
  {
    command("hmm");
    command("say �B��....�o��B�ͬO�A���t���ܡH");
    return 1;
  }
  if(userp(target) && environment(target) == environment(ob))
  {
    ppl1 = me;
    ppl2 = target; 
    set("divorcing",1);
    command("hmm");
    call_out("do_divorce1",3);
    return 1;
  }

  command("say �A�O�� "+str+" �ܡH�a�o�ӳo�̡A�ڷ|���A�D�����D���C");
  command("snicker");
  return 1;
}

void do_divorce1()
{
  object ob = this_object();
  string index;

  if(environment(ppl1) != environment(ob))
  {
    command("flop");
    command("say �D�i�]�F�A�o��Ʊ��N��F�C");
    delete("divorcing");
    delete("asking");
    return;
  }
  if(environment(ppl2) != environment(ob))
  {
    command("??");
    command("say �o��Q�i���@�಴�N�����F�H");
    delete("divorcing");
    delete("asking");
    return;
  }
  command("look "+ppl2->query("id"));
  command("say �G�M�O....�ݧڸ߰ݳQ�i�C");
  tell_object(ppl2,HIC+ppl1->name(1)+"���X���B�ӽСA�аݧA�P�N�ܡH [yes/no]\n"NOR);
  set("asking",1);
  return;
}

int do_yes()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("y");
    return 1;
  }
  return 0;
}

int do_no()
{
  if(this_player() == ppl2 && query("asking"))
  {
    do_divorce2("n");
    return 1;
  }
  return 0;
}

int do_divorce2(string index)
{
  object ob = this_object();
 object obj1,obj2;
  if(index == "y")
  {
    message_vision(HIR"\n[$N�j�誺��: �L�ҿסI�B���ӴN���B�a�I]\n\n"NOR,ppl2);
    command("say �Ӧn�F�I�Q�i�P�N�F�I�u�O���ߧA�̡I");
    if(ppl1->query("bank/future") < 15000)
    {
      command("say ������D�^�O����....");
      command("flop");
      command("ack");
      command("say ��ӬO�a���J?! ���x�ݨ����F�A�J�M�p���o��Ʊ��N��F�a�C");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    if(environment(ppl1) != environment(ob))
    {
      command("flop");
      command("say ��i�]�F�A�o��Ʊ��N��S���L�a�C");
      delete("divorcing");
      delete("asking");
      return 1;
    }
    if(!objectp(obj1 = present("marry ring", ppl1)))
    {
      command("flop");
      command("say "+ppl1->name(1)+"�A�A�����B�٫��O�H");
      return 1;
    }
        if(!objectp(obj2 = present("marry ring", ppl2)))
    {
      command("flop");
      command("say "+ppl2->name(1)+"�A�A�����B�٫��O�H");
      return 1;
    }

    message("system",
HIR"\n\t��ڪk�x���j�k�x�ﲳ�ŧG�D�G
\n\n\t\t"HIC"�y���i"+ppl1->name(1)+"�M"+ppl2->name(1)+"�]���۳B���X�A���x���������L�Ǫ��B�����Y�I�z\n\n"NOR,users());

    ppl1->delete("marry_id");
    ppl2->delete("marry_id");
    ppl1->add("bank/future",-15000);
    tell_object(ppl1,HIG"[�j�k�x��z���F 10000 �T�q�l����D�^�O�C] \n"NOR);

    if(objectp(obj1 = present("marry ring", ppl1)))
    {
        message_vision(HIG"[�j�k�x�q�A���W�j�X�@�u���B�٫�]\n"NOR, ppl1);
        destruct(obj1);
    } 
    if(objectp(obj2 = present("marry ring", ppl2)))
    {
        message_vision(HIG"[�j�k�x�q�A���W�j�X�@�u���B�٫�]\n"NOR, ppl2);
        destruct(obj2);
    } 

    ppl1->save();
    ppl2->save();
    delete("divorcing");
    delete("asking");
    return 1;
  }
  message_vision(HIC"\n[$N��M���n�F�n�Y]\n\n"NOR,ppl2);
  command("say �Q�i���P�N�C�A���N��F�A�o��ƴN�즹����a�C");
  delete("divorcing");
  delete("asking");
  return 1;
}

void reset()
{
  delete("divorcing");
  delete("asking");
  command("say �A�Ӫ������A���Ѥ����A�Q���B���ѶX���C");
}

