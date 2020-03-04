#include <ansi.h>
inherit NPC;

int quest();

void create()
{
  set_name("�a�ѥ�", ({ "student" }) );
  set("gender", "�k��" );
  set("long",@LONG
�Q�~���H�L�H�ݡA�@�|���W�ѤU���C�L���V�O��Ū�ѡA���H�D���n�\�W�C
LONG
);      
  set("age",22);
  set("level",8);
  set("race","human");

  set("chat_chance", 20);
  set("chat_msg", ({
"�Ů𤤬�M�Ǩӽa�ѥͨ{�l���B�P�n�C\n",
(: command("say �ڭn�n�n�V�OŪ�ѡA�N�ӦҨ��x���K���T�Y��F... �a�m���Ѥ��ѥ��]�|�H�ڬ��a..") :),
(: quest :),
}));

  set("chat_chance_combat", 50 );        
  set("chat_msg_combat", ({
(: command("help!") :),
}) );
  set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
  setup();
  set("mirror_number",2);
  carry_object(__DIR__"eq/eq8")->wear();
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
    message_vision("$N���_���g�A�n�Y�̸���Ū�F�_�ӡC\n",ob);
  else command("say �n�j��... �־j����.. �Q�Y��...");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"��") != -1)
  {
    command("drool");
    command("say ���C�C�@�����γ̦n�Y�F���n�Q�Y����");
  }
  if(strsrch(str,"���g") !=-1)
    command("say ���g�O�ۥj�H�ӳ̰��j���d�۰�.. ���g�Ҩ������Ѧa�ܲz�A�U���ۥͬ۫g�A�|�ɸ`��A���椣�F���g���ĭz���då�C");
  if(strsrch(str,"��") !=-1 && strsrch(str,"���g") !=-1)
  {
    if(ob->query_temp("item_give"))
      command("say �ڥ��ӬO���h�@�����g���A���L�v�g��"+ob->query_temp("item_give_who")+"�F�A�A������i�H��L�n�C");
    else
    {
      command("say �n�a�A�J�M�A����g�o�򦳿���A�ڴN���A�@���a�C");
      new(__DIR__"obj/obj3")->move(ob);
      command("give "+me->query("id")+" easy book");
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
    command("say �����M�a�A���ڦ��Ӯ�I"+ob->name(1)+"�ڤ��ব�C");
    call_out("no_give_money",1,who,ob,ob->query_amount());
    return 1;
  }
  if(ob->query("id") != "rice ball" )
  {
    command("?");
    write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
    return notify_fail("");
  }
  if(this_object()->query_temp("pass_quest"))
  {
    command("say �A�e�Y���ӰڡH�i�O�ڤv�g���F�C�A�ڭn�ݮѤF�A�Ц^�a�C");
    write("["+this_object()->name(1)+"��"+ob->name(1)+"�ä��P����]\n");
    return notify_fail("");
  }
  command("flip " +who->query("id"));
  call_out("eat_temp",2);
  command("say ���.... �A�u�O�ϩR���H.. �ڤ]�Sԣ�n�����A���A�o�e�A�a�A�ЧA�ȥ����U...�C");
  new(__DIR__"obj/obj15")->move(this_object());
  command("give " +who->query("id")+ " mirror");
  this_object()->set_temp("pass_quest",1);
  return 1;
}

void eat_temp()
{
  set("hp",270);
  command("eat ball");
  command("eat ball");
  command("eat ball");
  command("eat ball");
  command("eat ball");
  command("eat ball");
  return;
}

int re_quest()
{
  this_object()->delete_temp("pass_quest");
  this_object()->delete_temp("item_give");
  this_object()->delete_temp("item_give_who");
  call_out("re_quest",900);
  return 1;
}

void no_give_money(object who, object ob, int index)
{
  command("give " +who->query("id")+ " " +index+ " " +ob->query("id"));
}
