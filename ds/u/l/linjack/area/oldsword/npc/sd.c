#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�����W���M��",({"unknown blade man","man"}));
	set("long" ,
    "���H�Ѳ���Ž, �������p���t, ���o�Q��Q��, �H���K�ؤT�o, �Q�����j, \n"
    "���L�A�o�L�k�{�X�L�쩳�O���@�즿�򤤪�����, ���L�A���D�̦n�٬O�ַS�L\n"
    "����, �@�ݴN���D���H���D���q�H��, �A�γ\\�i�H�ݰݥL�O��?(say �A�O��).\n"
    );
	set("attitude", "peaceful"); 
	set("level",51);
	set("age",58);
	set("chat_chance",10);
    set("chat_msg",({
			 (:command,"exert dragonblade":),
			 (:command,"exert dragonfist":),
			 (:command,"exert dragonsteps":)}));
	set("chat_chance_combat",70);
	set("chat_msg_combat",({(:command,"exert dragonfist dragon-voice":),
				(:command,"exert dragonsteps":),
				(:command,"exert dragonblade":)}));
	set_skill("unarmed",90);
	set_skill("blade",90);
	set_skill("dodge",95);
	set_skill("force",90);
	set_skill("parry",90);
	set_skill("dragonblade",95);
	set_skill("dragonfist",95);
	set_skill("dragonsteps",95);
	set("guild_gifts",({6,7,2,5}));
	setup();
	carry_object(__DIR__"eq/dragonblade")->wield();
	carry_object(__DIR__"eq/dragonring")->wear();
	carry_object(__DIR__"eq/dragonbelt")->wear();
	carry_object(__DIR__"eq/dragonboots")->wear();
	carry_object(__DIR__"eq/dragoncloth")->wear();
	carry_object(__DIR__"eq/dragoncloak")->wear();
	carry_object(__DIR__"eq/dragonarmor")->wear();
}
void init()
{
	add_action("do_say","say");
}
int do_say(string arg)
{
	object me,obj;
	me=this_player();
	obj=this_object();
	if(arg=="�A�O��" && me->query_temp("talk/whoareyou") < 4)
	{
		if(me->query("level") < 25 && me->query_temp("talk/whoareyou") < 4) 
		{
			command("hmm");
			command("say �ݨӧA�٨S�����ݧڬO�֡C");
			me->add_temp("talk/whoareyou",1);
		}
		else if(me->query("level") > 24 && me->query("level") < 41 && me->query_temp("talk/whoareyou") < 4)
		{
			command("hmm "+me->query("id"));
			command("say �դU����Q�F?");
			me->add_temp("talk/whoareyou",random(2));
		}
		else if(me->query("level") > 40)
		{
			command("look "+me->query("id"));
			command("say �ڤD�C���C�s -- �s�S��! �դU�Y�@�N�P�ڤ�դ��, �N���@�o�_�ڧa!");
			obj->set_name("�s�S��",({"shout tan long","long"}));
			obj->set("title",HIC"�C���C�s"NOR);
			command("fight "+me->query("id"));
		}
	}
	else if(arg=="�A�O��" && me->query_temp("talk/whoareyou") > 3)
	{
		command("angry");
		command("say �Чo! �A�䦺!");
		obj->kill_ob(me);
	}
	else return 0;
}
