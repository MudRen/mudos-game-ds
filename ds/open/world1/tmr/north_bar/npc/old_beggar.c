#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�Ѥ^��",({ "old beggar","beggar" }) );
        set("long","�@�Ӧ~�ѡB��A�}�ꪺ�^��, ���b�^�Q�ۡC\n");
        set("race","�H��");
        set("age",70);
        set("level",1);
        set("attitude","friendly");
        set("no_fight", 1);
        set("chat_chance",10);
        set("chat_msg",({
        "�Ѥ^���Q���i�������ĵ�..\n",
        }) );
        setup();                
}

void clear() {
		if(!this_object()) return;
        delete_temp("give-jude");
}

int accept_object(object who,object ob)
{
        object jude;

        if(ob->name()!="�����U")  return 0;

          if( query_temp("give-jude") ) 
          {
            command("say �h�¡I�����w�g���H���ڧ�^�F��F...");
            command("thank "+who->query("id"));
            return 0;
          }
          
        destruct(ob);
        message_vision("$N���F�Ѥ^���@�f$n�C\n",who,ob);
        command("say �o�O�ڮa�Ǫ��_�����I�I..�ש���F...");
        command("kneel "+who->query("id"));
        command("say �u���D�`�P��..���F�^���������A�ڨ��W���@���ɡA���p�N�e�������a�C");
        jude=new(__DIR__"item/jude");
        jude->move(who);
        set_temp("give-jude",1);
        call_out("clear",600);
        return 1;
}

int talk_action(object me)      //talk �ɷ|���榹�禡.
{
	if(query_temp("give-jude")) {
		command("say �ڱ����F��w�g���F�A���¡C");
		return 1;
	 }

	switch(random(2))
    {
		case 0: command("say ��..���f�U�l�쩳�]�h���F...");
			break;
		case 1: command("say �аݦ��֦��ݨ�@���ɶܡH");
     }
	 return 1;
}

