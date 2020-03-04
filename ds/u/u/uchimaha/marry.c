#include <ansi.h>
inherit NPC;

int do_action2(string index);
object girl, boy;

void create()
{
  set_name("���C�C", ({ "mrs. wang","wang" }) );
  set("gender", "�k��" );
  set("age", 52);
  set("long",@LONG

�o�O�@��M�����H���C���H�A�Ҧ��������B�߼y���ơA�u�n��o��]�ǿ��n�C

�p�G�Q���B�A�бN�z���Ƿs�Q�l�a��o��e�ӡA��J marry <��誺 id>
�p�o��褹�i�A���ƫK�꺡�F���A�C�H�|���z 10000 �T�j�� (�q�Ȧ榩)
����]�A�ìI��߼y�Ϥ����i�ѤU�A�p�G�O�n�R���B�٫����A�u�n�u���O
5000 �T�j���N�i(�q���W��)�C

<�Ъ`�N> �����~�p�Q���C�A�C�H�C�i�O���|�z�A��
LONG
);
  set("chat_chance",10);
  set("chat_msg",({
  (: command,"say �k�j��B�A�k�j���" :),
  (: command,"say �p�G���F���B�٫���ڭ��R�a(checkring)�a!":),
  (: command,"smile" :),
  (: command,"say �@���h�֬��йڡA�d���ֽt�@�u�o" :),
  (: command,"hoho" :),
}));
  set("level",1);
  set("attitude", "friendly");
  set("no_cast",1);
  set("no_kill",1);
  set("no_fight",1);
  setup();
}

void init()
{
  if(!userp(this_player())) return;
  add_action("do_marry","marry");
  //Uchimaha�[checkring
  add_action("do_checkring","checkring");
  // ���G�������@ girl->input_to() ���ʧ@ why ?
  add_action("do_yes",({"y"}));
  add_action("do_yes",({"yes"}));
  add_action("do_no",({"no"}));
}
int do_checkring(string arg)
{
        object me,ring;
        me=this_player();
        if(!objectp(ring=present("marry ring",me) ) );
          return notify_fail("you haved one marry ring\n");
        if(!me->can_afford(5000))
                return notify_fail("�z�ǡI�A�s�u���O�����Q���I�u�u�u�I\n");
         me->receive_money(-5000);
        if(!ring->can_move(me))
        {
        destruct(ring);
         return notify_fail("�A�n���ᱼ�@�ǪF��~�������B�٫��C\n");
        }
        else {
        message_vision("$N���F�@"+ring->query("unit")+ring->name()+"��$n�C\n",this_object(),me);
        ring=new("/open/always/marry_ring");
        ring->move(me);
        return 1;
        }

}
int do_marry(string str)
{
  object target, temp, ob = this_object(), me = this_player();

  if(query("action")) return notify_fail("�o���G���b��.\n");

  message_vision(HIC"$N���G$n�A�ڷQ�нбz���ڻ��@�ϱB�ơC\n"NOR,me,ob);
  if(me->query("class1") == "�ⶳ�x")
  {
    command("say �z�O�X�a�H�a�A���z�٫U�H��A���a");
    return 1;
  }
  if(me->query("marry_id") || temp = present("marry ring",me))
  {
    command("say �A�v�g���t���F��A�O�T�ߤG�N�� .... ");
    return 1;
  }
  if(me->query("gender") != "�k��")
  {
    command("say �ۥj�H�ӬҬO�k�軡�C�A�Z���k��X�����C���D�z�H�I");
    return 1;
 }
  if(!str)
  {
    command("say �@�H�O���a�h�Q�H�i���o���W�r��H");
    return 1;
  }
  if(me->query("age") < 18)
  {
    command("snort");
    command("say �p�̧̡A�o�̤��O���A���a��A�A�٬O�h�O�B����a�C");
    return 1;
  }
  if(me->query("bank/past") < 10000)
  {
    command("snort");
    command("say ���C�C����a���J����D�C");
    write("[�z�Ȧ�s�ڦܤ֭n�� 10000 �T�j���C]\n");
    return 1;
  }
  message_vision(HIC"$N���G�o�W�s "+str+" �C\n"NOR,me);

  if(!target = find_player(str))
  {
    command("hmm");
    command("say �n���S�o��h�Q��A�z�Ц^�a�C");
    return 1;
  }
// alickyuen �@�X�ק�
  if(target->query("age") < 18)
  {
    command("snort");
    command("say �o�i�٬O�@�ӥ����~���p�h�Q�C..���M�A...");
    return 1;
  }
  if(target->query("gender") != "�k��")
  {
    command("puke");
    command("say �o����͡A�p�G�z���P���ʪ��ɦV�A�i�O�ӧ�ڳo�ѤӱC ok ? -.-#");
    return 1;
  }

  if(userp(target) && environment(target) == environment(ob))
  {
    boy = me;
    girl = target; 
    set("action",1);
    command("hmm");
    call_out("do_action1",3);
    return 1;
  }

  command("say �A�O�� "+str+" �ܡH�a�o�ӳo�̡A�ڷ|���A���C���C");
  command("snicker");
  return 1;
}

void do_action1()
{
  object ob = this_object();
  string index;

  if(environment(boy) != environment(ob))
  {
    command("flop");
    command("say �k��]�F�A�o���˨ƴN��F�C");
    delete("action");
    delete("asking");
    return;
  }
    if(environment(girl) != environment(ob))
  {
    command("??");
    command("say �o��h�Q�i�u�`�ۡA�@�w�����N�����F�C");
    delete("action");
    delete("asking");
    return;
  }
  command("look "+girl->query("id"));
  command("say �G�M�O�ѽ�ΫQ.... �ݧڸ߰ݤk�誺�N���C");
  tell_object(girl,HIC"�p�@�N����"+boy->name(1)+"�@�d�l�A�åͥå@�ܷR�����ܡH [yes/no]\n"NOR);
  set("asking",1);
  return;
}

int do_yes()
{
  if(this_player() == girl && query("asking"))
  {
    do_action2("y");
    return 1;
  }
  return 0;
}

int do_no()
{
  if(this_player() == girl && query("asking"))
  {
    do_action2("n");
    return 1;
  }
  return 0;
}

int do_action2(string index)
{
  object ob = this_object();
  if(index == "y")
  {
    message_vision(HIR"\n[$N�C�U�Y�۬��F�y�A�L�L���I�F�I�Y]\n\n"NOR,girl);
    command("say �Ӧn�F�I�k�赪���F�I�u�O���ߧA�̡I");
    if(boy->query("bank/past") < 10000)
    {
      command("say ��������]����....");
      command("flop");
      command("ack");
      command("say ��ӬO�a���J?! �ѮQ�ݨ����F�A�J�M�p���o���˨ƴN��F�a�C");
      delete("action");
      delete("asking");
      return 1;
    }
    if(environment(boy) != environment(ob))
    {
      command("flop");
      command("say �k��]�F�A�o���˨ƴN��F�C");
      delete("action");
      delete("asking");
      return 1;
    }
    message("system",
HIR"\n\t���M�@�D�Ϥ��ĤW��....\n\n"HIW"�Ѫ��z�X���ꪺ����A�٬O�n�ݡA�u������ƥX�@�D�r��...\n\n\t\t"HIC"�y����"+boy->name(1)+"�M"+girl->name(1)+"�q�������ҩd�A�å@���R�����C�z\n\n"NOR,users());

    boy->set("marry_id",girl->query("id"));
    girl->set("marry_id",boy->query("id"));

    boy->add("bank/past",-10000);
    tell_object(boy,HIG"[���C�C��z���F 10000 �T�j������]�C] ���߮���!\n"NOR);

    tell_object(boy,HIG"[���C�C���A�@�u���B�٫�]\n"NOR);
    tell_object(girl,HIG"[���C�C���A�@�u���B�٫�]\n"NOR);
    new("/open/always/marry_ring")->move(boy);
    new("/open/always/marry_ring")->move(girl);

  boy->save();
  girl->save();
    delete("action");
    delete("asking");
    return 1;
  }
    message_vision(HIC"\n[$N��M���n�F�n�Y]\n\n"NOR,girl);
  command("say �k�褣�����C�A���N��F�A���i�j�H�����C");
  delete("action");
  delete("asking");
  return 1;
}


void reset()
{
  delete("action");
  delete("asking");
  command("say �u�藍��A���ѥ��L�F�A�Q���B���ѶX���C");
}


