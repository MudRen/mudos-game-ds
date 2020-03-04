#include <ansi.h>
#include <path.h>
inherit NPC;

int quest();

void create()
{
  set_name("�ѹ�", ({ "servant" }) );
  set("gender", "�k��" );
  set("long",@LONG
�L�O�Ѿ��ѤH���]�l�A�P�ɤ]�R��ѹ����u�@�A�ۤp����جV�A��Ѿ��N��
�ͤF���j������A�]���q�`�L���s�L���ä��Ѿ��ѤH���y�v���z�C
LONG
);      
  set("age",7);
  set("level",3);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
(: command("sigh") :),
(: command("inn") :),
(: quest :),
}));

  set("chat_chance_combat", 30 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  carry_object(__DIR__"eq/eq2")->wear();
  set("mirror_number",5);
  call_out("re_quest",900);
}

void init()
{
  add_action("do_no_ask","ask");
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

int quest()
{
  object ob = this_object();

  if(ob->query_temp("pass_quest"))
    message_vision("$N���b�J�Ӫ���s���g�����e�C",ob);
  else command("say �v���ѬO���ǧڰʥL�����d�A���ڤ]�Q�ǤѾ��N�r...");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object(), obj;
  if( !userp(me) ) return;
  if( me == this_object() ) return;

  if(strsrch(str,"�Ѿ��N") !=-1)
    command("say �N�O����W�[�ѷN�A�U���a�z���@���ǰݧr�A��s�Ѿ��N�ݭn�@�����g�Ӱt�X�A���v�����ǧڮ��L���ѧr....");
  if(strsrch(str,"���g") !=-1)
    command("say ���g�O�ۥj�H�ӳ̰��j���d�۰�.. ���g�Ҩ������Ѧa�ܲz�A�U���ۥͬ۫g�A�|�ɸ`��A���椣�F���g���ĭz���då�C");
  if(strsrch(str,"�v��") !=-1)
  {
    command("say �ڮv���СЦP�ɤ]���ä��A�Ѿ��ѤH�A�W�ѤU�a�L�Ҥ����L�Ҥ���O�A�ڳ̱R���L�F�C");
    command("say �A�n��ڮv���ܡH�L�{�b�i��b�R�߫F�άO��ߤp�Ψ��̡A�A�h���̧��ݧa�C");
    command("say �x... ����A�L�]���i��h���]�{�������̤F");
    command("say ��A�Ϊ̧ڮv���v�g�b�^�a�����W�F�A�ڤ��T�w��.... ����! �F�������Y�ڧA���");
  }
  if(strsrch(str,"�ѽL") !=-1 )
  {
    if(ob->query_temp("item_give"))
      command("say �ѽL�v�g��"+ob->query_temp("item_give_who")+"�F�A�L���n���ڮ��h�١A�u�O�Ӧn�H�C");
    else
    {
      command("say ��A�o�O���]�{�������ѽL�A�W���v����L�ɥh�A�ѤF�١A�A���ڮ��h�٧a�C");
      new(__DIR__"obj/obj2")->move(ob);
      command("give "+me->query("id")+" chessboard");
      ob->set_temp("item_give",1);
      ob->set_temp("item_give_who",me->query("name"));
    }
  }
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N���X"+chinese_number(ob->query_amount())+"�T"+ob->name(1)+"("+ob->query("id")+")��$n�C\n",who,this_object());
    command("say �v��������æ��O�H���F��A"+ob->name(1)+"�٧A���\n");
    command("give " +who->query("id")+ " " +ob->query("id"));
    return 1;
  }
  if(ob->query("id") != "easy book" )
  {
    command("say �o�O����r�H�v��������æ��O�H���F��");
    write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say �ڤv�g���@���F���㤣�ΤF�����§A���C");
    return notify_fail("");
  }
  destruct(ob);
  command("thank " +who->query("id"));
  command("say �A�u�n�A�o�˧ڴN�i�H��s�Ѿ��N�F����F"+RANK_D->query_respect(who)+"�A�o�O�ڪ��_���A�W���b���F�D�W�ߨ쪺�A�e�A���");
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  return 1;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest",900);
  return 1;
}

