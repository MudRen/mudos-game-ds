#include <ansi.h>
inherit NPC;
void create()
{
 set_name("����",({"fisher"}));
 set("long",@LONG
�@�ӱ`�b�������Ȧ��X������, �ݰ_�Ӥ@�ƷT�ܭW�y��
�ˤl, ���G���ܦh���и�...
LONG
    );
 set("attitude", "peaceful");
 set("age",26);
 set("evil",-10);
 set("gender","�k��");
 set("level",9);
 set_skill("hammer", 20);
 set("chat_chance",10);
 set("talk_reply","�̪񳣧줣�쳽....�ݨӫ��̭n�h�ܦ�_���F, �o�˧a, �u�n�S�̥i�H��쳽, �ڥH�������@�b�ʶR...�p��?\n"NOR);
 set("chat_msg", ({"���ӹĤF�@�f����....\n",
 }));
 setup();
 carry_object(__DIR__"../eq/cloth")->wear();
}

int accept_object(object who,object ob)
{
	object obj = this_object(),me=this_player();

        if(ob->name()=="����")
        {
		if(obj->is_busy() )
		{
			command("whisper "+who->query("id")+" �лդU�y�ݤ@�U...");
			return 0;
		}
		message_vision("$N���F���Ӥ@��"+ob->query("name")+"�C\n",who);
	
		obj->start_busy(1);
		destruct(ob);
		command("smile");
		add_money("coin",70);
		command("give 70 coin to "+me->query("id"));
		return 1;
	}
        else if(ob->name() =="�U����")
        {
		if(obj->is_busy() )
		{
			command("whisper "+who->query("id")+" �лդU�y�ݤ@�U...");
			return 0;
		}
		message_vision("$N���F���Ӥ@��"+ob->query("name")+"�C\n",who);
		obj->start_busy(1);
		destruct(ob);
		command("smile");
		add_money("coin",200);
		command("give 200 coin to "+me->query("id"));
		return 1;
        }
        else if(ob->name()=="������")
        {
		if(obj->is_busy() )
		{
			command("whisper "+who->query("id")+" �лդU�y�ݤ@�U...");
			return 1;
		}
		message_vision("$N���F���Ӥ@��"+ob->query("name")+"�C\n",who);
		obj->start_busy(1);
		destruct(ob);
		command("smile");
		add_money("coin",160);
		command("give 160 coin to "+me->query("id"));
		return 1;
        }
        else if(ob->name()=="�C����")
        {
		if(obj->is_busy() )
		{
			command("whisper "+who->query("id")+" �лդU�y�ݤ@�U...");
			return 1;
		}
		message_vision("$N���F���Ӥ@��"+ob->query("name")+"�C\n",who);
		obj->start_busy(1);
		destruct(ob);
		command("smile");
		add_money("coin",150);
		command("give 150 coin to "+me->query("id"));
		return 1;
        }
        else return 0;
}
