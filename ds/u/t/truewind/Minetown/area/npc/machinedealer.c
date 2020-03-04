#include <path.h>
inherit NPC;
int quest();
inherit SELLMAN;

void create()
{
	set_name("�����ѳ�", ({"machine dealer","dealer"}) );
	set("long", @LONG
���׼t���޲z���A�Ӧ۬P�p�`������@�z�t�A�]�����s�Q�Q������
�������q���ӡC�̪���׼t�o�ͤF�@�ǩǨơA�A�p�G�Q���D�o����o
�ͪ��Ʊ��A�i�H�յ۸�L���(talk with dealer)�C
LONG
);
	set("race", "�H��");
	set("title","�V�Y����");
	set("age", 210);
	set("level", 25);
        set("no_fight",1);
        set("storeroom", __DIR__"shop/shop1.c");
        set("sell_list",([
        __DIR__"obj/pill" : 10,
]) );
        set("chat_chance", 5);        
        set("chat_msg", ({
       (: command("say �n�Q�ܰs��...�C") :),
       (:command("why"):),
       (: command("say �o�̪��u�@�L�ᦺ�F...") :),
       (: command("say �n�O�䤣��N�o�����l�N����o�ʤF�I") :),
        }));
        set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I
                �u�n�O��o���l�̪��H�A���i�H�ݧڡC");
	setup(); 

}

void init()
{
        ::init();
        add_action("do_buy","buy");
        add_action("do_list","list");
        add_action("do_sell","sell");
        add_action("do_no_ask","ask");
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"�·G") !=-1)
    command("say �W�Ӥ�P�p�`�����Ӫ��{�ɧ����A�i�H��L��ѡC");
  if(strsrch(str,"��") !=-1)
    command("say �L�檺�i���s�̾J�F�A�̪�s�檺�L�ק�O�s�H�٤����f!!");
  if(strsrch(str,"�N�o��") !=-1)
    command("say �N�O�ڨ��l���N�o���ڡA�j�b�]�����b�͵��ګr���F���ˤl�C");
  if(strsrch(str,"�q�u���Ĥl") !=-1)
    command("say �L�����˵����Ǧ⪺�j�b�ͫr���F�A�{�b�u�n�y�����Y�C");
  if(strsrch(str,"�p�v") !=-1)
    command("say ���өǤH�ѬO��ۤv���b�p�и̡A��A�@�w�����D�I");
  if(strsrch(str,"�b��") !=-1)
    command("say �n�j���I�I�٫r�˧ڡI�I�@���Ǧ⪺�j�b�͡A��ޮt���h�j�I");
  if(strsrch(str,"�L��") !=-1)
    command("say �褣�O���ܡA�o���l�̦n�Y���״N�O�񺸷s�檺�L�פF!!");
  if(strsrch(str,"�i���s") !=-1)
    command("say �񺸦ۤv�S�s���n�s�A�A�]���ӳܳܬ�!!");
  if(strsrch(str,"�q�u") !=-1)
    command("say �]���o�̬O�p�����Ҫ��q�ϡA���ܦh�U�a�Ӫ��u�H�b�o�̤u�@�C");
  return;
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

int accept_object(object who,object ob)
{
        object pill;

        if(ob->name()!= "�T���N�o��")  return 0;
        else {
                
          if(this_object()->query_temp("give_pill")) 
          {
            command("say �ڪ��T���N�o���w�g��^�ӤF.. ���A�٦��H");
            command("? "+who->query("id"));
            command("say �A���h�汼�n�F��");
            return 0;
          }
          
        message_vision("$N��$n�|�_�Ӧb�ѳ����e�̤F�̡�C\n",who,ob);
        destruct(ob);
        command("say ��C������§A�ա�A�_�F���b�ͰڡH�H");
        command("thank "+who->query("id"));
        command("say �ӡ�K�K�㵹�A�n�Ϊ��I
            (�ѳ�������F����A�⤤...�C)
            (�Aı�o�ۤv�S�h�F�@�ǫ_�I�g��C)");
        this_player()->add("exp",(this_player()->query("level") * 500) + (random((this_player()->query("level")*100))+1000));
        pill=new(__DIR__"obj/pill2");
        pill->move(who);
        pill=new(__DIR__"obj/pill2");
        pill->move(who);
        set("chat_msg",({
        "�����ѳ����������˵ۧN�o���A�S�s�S������C\n",
        (:command("idle"):),            
        }) );
        set_temp("give_pill",1);
        return 1;
        }

}

void reset()
{
//      if(!dealer) return;
        delete_temp("give_pill");
        set("chat_msg",({
        (: command("say �n�Q�ܰs��...�C") :),
       (:command("why"):),
       (: command("say �o�̪��u�@�L�ᦺ�F...") :),
       (: command("say �n�O�䤣��N�o�����l�N����o�ʤF�I") :),
        }));
        set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I
                �u�n�O��o���l�̪��H�A���i�H�ݧڡC");
}
