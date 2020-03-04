#include <net/dns.h>
#include <ansi.h>
inherit NPC;

string *teach_msg = ({
"�b�o�̤U�l�A�y�áz�A�H�������覡���Ϲ��^���C",
"�o�ɦp�G���y�H�z�A�ڭ̥H�y�y�z�U���A���u���P�ɤ����C",
"��}�l�X��H�P��A�T�T���D�A�]�i�H�y�p���z�A�p���@�Ӱ}�a�����C",
"�b�o�̤��n�Τp���B���A���H�y�j���B���z�i��A�p�G���p���B�����E�Q�E���ۡA����j���B���K���@�ʤ�C",
"���l�Hí�A�ߥH�R�A���[�j���A�~�O�P�Ӥ��D�C",
"�ѽL�W�������٤����y�Ѥ��z�A�l�|���٧@�P��C",
"������i�k�ʡA�n�����n�ڰ�A�H�D�������u�սL���C",
"�U��x�ɭn��M�T���A�H������h�p�Ŧa���D�C",
"�﫳������U���¤l�A�դl�A�¤���U�A�O���y����z�C",
"��X�@�����L�k�I�J���Ŧa�A�٬��y���z�A�q�`�����֦��G�����C",
"�����O�L�a�������a�A������Q���j�A��a�]�۷�í�T�C",
"�ɱ`�m�ߡA�~��ϴ�����i�B�C",
"���ѥ��Ш�o�̡A�O�o�^�h�n�h�m�ߡC",
"�Y�L���i�﫳�ɡA�ۦ�G���A�ƴ��СA�]�O���ۤv��O�W�j����k�C",
"�o�̡A���k�䨾�u���ŵ�A�H�|�����y���z�A�q�ǰ����C",
"���𮧤@�U�A�ܤf��..... �A�̦ۦ�N�ڭ�~�ұЪ���a�t�m�@�M�C",
});

void do_teach();
int quest();

void create()
{
  set_name("���]�{ �q��",({"oniska"}) );
  set("long",@LONG
���몺���k�l�Ať���Ӧۻ���������A���Ѧ��@�ѷ��j�����ۤΨg
���A�b�L���ͩR�̡A��Ѫ����Ȥj��@���ƪ��C�{�b�L�������v�����ڦV
�y���G��ޡz���ҬɡC
LONG
);
  set("title",HIC"�y���G��ޡz"NOR);
  set("age",1000);
  set("level",10);
  set("gender","�k��");
  set("race","�H��");

set("chat_chance",20);
  set("chat_msg",({
(: do_teach :),
(: do_teach :),
(: quest :),
(: do_teach :),
"���]�{ �q�����_�ѵ��A�C�C���b�ѽL�W���F�X���l�C\n",
(: do_teach :),
}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  carry_object(__DIR__"eq/eq5")->wear();
  carry_object(__DIR__"eq/eq11")->wear();
  set("mirror_number",6);
}

void init()
{
  ::init();
  add_action("do_sit","sit");
  add_action("do_no_ask","ask");
  if (this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
  this_object()->set_heart_beat(1);
}

void do_teach()
{
  object ob = this_object(), *student;
  int i;

  if(ob->is_fighting() ) return;
 
  student = all_inventory(environment(ob));
  if( sizeof(student) < 1 ) return;

  command("say " +teach_msg[random(16)] );

  for(i=0;i<sizeof(student);i++)
  {
    if( userp(student[i]) && student[i]->query_temp("do_sit") )
    {
       if( student[i]->query_temp("netdead") == 1 ) continue;
if(random(4))
       {
         message_vision(CYN"���Ѯv���@�f�ܡA$N���G�Y���Ү��C\n"NOR,student[i] );
         student[i]->improve_skill("chess",random(3)+1);
       }
    }
  }
  return;
}

int do_sit()
{
  object me;
  me=this_player();
 
  if(me->query_temp("do_sit")) return notify_fail("�A�w�b�ǳ�ѤF�C\n");
  if (me->is_fighting() ) return notify_fail("�A�����ۥ��[�A�S�žǳ�ѡC\n");
  if(me->is_ghost()) return notify_fail("���H����ǳ�ѡC\n");
  if(me->is_busy() ) return notify_fail("�A�����ۡA�S���žǳ�ѡC\n");

  message_vision("$N��F�ӪŦ짤�U�A�}�l�ǳ�ѤF�C\n",me);
  me->set_temp("do_sit",1);
  return 1;
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
    message_vision("$N��z�F�@�U�ୱ�C\n",ob);
  else command("say �W�����ӴѽL����o�����F... �˸���..");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�ѽL") !=-1)
    command("say �N�O�@�Ӥ�s�ѽL�A�W���e�ۤQ�T���Q�T�����u�C");
  if(strsrch(str,"���") !=-1)
    command("say �p�G�A�u���Q�ǳ�ѡA����Ч�(sit)�a�A�ڨӱЧA�w�۪���¦�C");
  if(strsrch(str,"���]�{") !=-1)
    command("say �O�H�ڴN�O���]�{�A�p�G�n�ǳ�ѡA�i�H�ӧ�ھ�(sit)�C");
  if(strsrch(str,"�i�å�") !=-1)
    command("say �L�O�ڪ��B�͡A�²ª��ܥi�R�C");
  if(strsrch(str,"�w��") !=-1)
    command("say �ҿת��w�۴N�O��Ѹ��l����¦�ޥ��A��Ѫ��ԳN�ܤƬҥѩw�ۦӨӡA�Ѿ��ѤH�ثe�]����ھǩw�ۡA�L�Z���w�﫳���A�A�i�H��L�U�ѡC");
  return;
}

int accept_object(object who, object ob)
{
  if( ob->query_amount() > 0 )
  {
    message_vision("$N���X"+chinese_number(ob->query_amount())+"�T"+ob->name(1)+"("+ob->query("id")+")��$n�C\n",who,this_object());
    command("say ����"+ob->name(1)+"�ڡH�ڤ��ʿ��A�A���^�h�a�C");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") != "chessboard" )
  {
    command("say �o�O����F��..... ?");
    write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say �u�O�����§A�F�A���L�ڪ��ѽL�v�g��^�ӤF�A�A�٬O�d�ۦۤv�Χa�C");
    return notify_fail("");
  }
  command("say �Ӧn�F�A�u�O���§A�A�ڰe�A�o�ӷ���S�a");
  destruct(ob);
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  call_out("re_quest",900);
  return 1;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
