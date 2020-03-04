// NPC: /d/ruzhou/npc/xi-laifu.c  ��߮b�X�{���ߨӺ֦ѪO
// llm 99/07/09

#include <ansi.h>

inherit NPC;
int ask_party();
void start_party(object ob,object me);
int do_start();
int do_serve();
void finish_party(object me,object ob);
int give_money(object me,object ob);
int do_kill(string arg);
int do_exert(string arg);
int do_steal(string arg);

void create()
{
	set_name("�ߨӺ�",({"xi laifu","xi","laifu" }));
   set("title", "�ﻫ�ӦѪO");
   set("age", 42);
   set("gender", "�k��");
   set("attitude", "friendly");
   set("combat_exp", 50000);
   set_skill("unarmed", 100);
   set_skill("dodge", 100);
   set_skill("parry", 100);
   set("per", 20);

	set("inquiry", ([
		"name": "�ߨӺ֨������D�G���p�i�W�r���I�֮�A�m�ߦW�Ӻ֡A�N�O�o�����ѪO�C\n",
		"here": "�ߨӺַn�Y�̸��a���G���ڭ̪ﻫ�ӥi�O���L�Q�����W�ӡA��߮b�ٱo�n�ӧڭ̳o���C��\n",
		"�b" : (: ask_party :),
		"�߮b" : (: ask_party :),
		"�u" : (: ask_party :),
		"�s�u" : (: ask_party :),
		"�߰s" : (: ask_party :),
		"�s�b" : (: ask_party :),
		"party" : (: ask_party :),
		]) );
   setup();
   carry_object("/d/beijing/npc/obj/pink_cloth")->wear();
}

void init()
{
   object me=this_player();
   ::init();
	if( interactive(me) && !is_fighting() )
   {
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
   add_action("do_serve", "kaixi");
   add_action("do_finish", "jieshu");
   add_action("do_start", "kaishi");
   add_action("do_kill", ({"kill","fight","hit","perform"}));
   add_action("do_steal", "steal");
   add_action("do_exert", "exert");
}

int greeting(object me)
{
	if( !me || environment(me) != environment() ) return;
   if(me->query_temp("married_party") )//�s�H
   {
   	write("�ߦѪO��A����D�G���߮b���m�o�t���h�F�A���ȤH�ӻ��F�z�ݧڳ߮b�N��F�I��\n");
   }
   else if(!query_temp("party_finish"))//�߮b�������A�Y�߰s���H
   {
      write("�ߦѪO�I�I�Y�G����I�z�ӦY�߰s�r�I�s�H��§���ѧڥN���A�浹�ڴN��C��\n");
   }
	else
   {
   	write("�ߦѪO�@����G���z�Y�n�A�C���I��\n");
   }
   return 1;
}

int accept_object(object me, object ob)
{
   int i;
	if(query_temp("party_finish"))
   	return notify_fail("�ߦѪO�����@���G���z�ӿ�F�A�߮b�w�g�����F�A�z�٬O�������s�H�a�I��\n");
   if (!ob->query("money_id"))
     	return notify_fail("�ߦѪO�K�F�K���Y�G���p�����N���ɿ��e�F��F�A�ܳ߰s�٬O���{�����n�I��\n");
   if(me->query_temp("marry_patty"))
   	return notify_fail("�ߦѪO�@�h�A�S���D�G���ۤv���ۤv�e§�H�]�S���o�˦Y���F���۪��Ƨa�I��\n");
   i = ob->value();
   CHANNEL_D->do_channel(this_object(), "chat",
	   sprintf("%s���P%s�M%s�s�B�j�ߡA�e�W�P§"+MONEY_D->price_str(i)+"�I\n",me->name(),query("name1"),query("name2")));
	add("chat_amount",1);//�f���û����z
	add("money",i);//�O���e�Ӫ�§����
   return 1;
}

int ask_party()
{
   object me,ob,wife;
   ob=this_object();
   me=this_player();
   if( me->query_temp("host_of_party") )
   {
   	message_vision("$N��$n���G���z���߮b���O���b�}�۶ܡH��\n", ob, me);
   	return 1;
   }
   if( (string)me->query("gender")=="�k��" )
   {
     message_vision("$N���۹�$n���D�G���C�C�O�H�s�����W�q�b�o�q�s�u�A�٬O�s�A���V�ҨӰݧa�I��\n", ob,me);
     return 1;
   }
	if( !me->query_temp("married_party") )
   {
   	message_vision("$N½�F½�b���A��$n��ê��ݹD�G���C�C�n�H�S���b�ڳo�����z�q�ߺ�A�|���|�d���F�H��\n", ob,me);
   	return 1;
   }
   if( !objectp(wife=present(me->query("couple/couple_id"), environment(me))) )
   {
   	message_vision("$N��$n���G�s�Q�l���S�ӡA�o�߮b��\�}�H\n", ob,me);
      return 1;
   }
   if( ob->query_temp("ready_to_party") )
   {
   	message_vision("$N��$n���n�N�䪺���G�ڳo���}�ۤ@�u�O�A�n���z����A�ӧa�I\n",ob,me);
   	return 1;
   }
   if( (string)environment(ob)->query("short")!="�ߺְ�" )
   {
   	message_vision("$N��$n���������G���藍�_�A���ڦ^����ƤF�A���a�I��\n",ob,me);
   	return 1;
   }
   if( me->query_temp("ready_to_ask") )
   {
   	message_vision("$N��$n���@�Ъ����D�G�����O�����F�ܡH�A��\�ݭӨS���I��\n",ob,me);
   	return 1;
   }
   me->set_temp("ready_to_ask",1);//�s���ݹL�F���O��
   ob->set_temp("ready_to_party",1);//�ѪO�}�l�O��
   me->set_temp("host_of_party",1);//�s�����O��
   me->delete_temp("married_party");
   call_out("start_party",1,ob,me);
}

void start_party(object ob,object me)
{
   command("chat* "+name()+"�@����D�G���}�d�@��Ȥd���A�s���K�H�H�۾K�A����ﻫ�Ӻa���a��" + me->query("name") +
		"\n�j�}�߮b�A����U��e�ӱ����I\n\n");
   message_vision("�ߦѪO�ਭ�S��$N�p�n�ݤF�L�y�C\n",me);
   write("�z�n�}�l�A�N��J kaishi�A�p�G�Q�}�u�A�N��J kaixi�A\n"
   "�j�a�Y���F�A�ܨ��F�N�i�H�����F(jieshu)�C");
   me->delete_temp("ready_to_ask");
   me->set_temp("ready_to_party", 1);//�s����ƶ}�l�O��
}

int do_start()
{
   object me,ob,usr,obj,*list;
   int i;
   me = this_player();
	ob = this_object();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"��A���G���A�S���O�s���x�I�ۤ��\�ۡH��\n");
   if( !ob->query_temp("ready_to_party") )
     return notify_fail(name()+"��A���G���}�l���\�r�A�{�b�S�S�H��B�b�I��\n");
   if( me->query_temp("party_start_already") )
     return notify_fail(name()+"�������a��A���G���A�ݳo���O�w�g�}�l�F���I��\n");

   message_vision("$N��$n�I�I�Y���G���ߦѪO�A�߮b�i�H�}�l�F�I��\n\n"
		"$n�ߨ�j�n�۵ۡG�����ȤH�W���ߡ��s��㡨\n\n",me,ob);
   me->set_temp("party_start_already", 1);//�s���w�g�}�l�O��
   me->delete_temp("ready_to_party");
   tell_room( environment(ob), HIY"�ߦѪO�S��@���A�L�ӱm��֤�ߨ�j�_�ԧo�B���_�߼֡C\n"NOR);

   list = all_inventory(environment(me));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       if( obj=new(__DIR__"obj/xijiu"))
       obj->move(usr);
   }
   tell_room(environment(usr), "\n�q���󨫥X�@�ƺ}�G�����m�֤k�A�̦�����C�ӤH���e�C\n"
		"���m�֤k�����A�@�M�r���߰s���ɷ��S���}�F�h�C\n");
   call_out("finish_party", 500, me,ob);
   return 1;
}

int do_serve()
{
   object ob=this_object();
   object me=this_player();
   object food;
   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"�ײ����F�A�@���D�G���D�H�S���ܡA�A�W���\�H�I��\n");
   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"��A�����G���٨S�i�D�ڶ}�l(kaishi)�A�ګ�\�n�}�u�H��\n");

   message_vision("$N�j�n�W�W�ۡG�W��A�W��I\n", me);

   tell_room(environment(me), "���ӰաI���|���Ӥp��p�q���󳽳e�ӥX�A�@�L�L�����Ϊԥߨ��\�W�F��C\n");
   if(food=new(__DIR__"obj/jiuyan"))
        food->move(environment(me));
   return 1;
}

int do_finish()
{
   object ob=this_object();
   object me=this_player();

   if( !me->query_temp("host_of_party") )
     return notify_fail(name()+"�����N�a���F�A�@���G���A�Y�A���A�����A�Ƥ��n�û��ܡI��\n");

   if( !me->query_temp("party_start_already") )
     return notify_fail(name()+"�������D�G���ߺᤣ�O�w�g�����F�ܡI��\n");
   message_vision("$N��$n���D�G���ȤH�Y�o�������A�Q���P�³ߦѪO���w�ơI��\n", me, ob);
   remove_call_out("finish_party");
   call_out("finish_party", 2, me,ob);
   return 1;
}

void finish_party(object me,object ob)
{
   int i;
   object *list,ob1,ob2,usr;

   message_vision(HIC"\n$N�j�n���D�G���p�p���b�A��C�Ѧ�A$n���߮b�N�������A�h�¤j�a���{�I\n"NOR, ob,me);
   command("gongxi " + me->query("id"));

   me->set_temp("party_finish",1);
   me->delete_temp("party_start_already");
   me->delete_temp("host_of_party");
	message("vision","\n�@�Ǫ����m�֤k�s���W�ӧ�s�u�W����ü�ѵ榬�B�z�b��U�h�C\n",environment(me));
   if(ob1=present("jiuxi", environment(ob)))
      destruct (ob1);
   list = all_inventory(environment(ob));
   i = sizeof(list);
   while (i--)
   {
       usr= list[i];
       ob2=new(__DIR__"obj/xitang");
       ob2->set("name",me->name()+"�M"+me->query("couple/couple_name")+"���߿}");
       ob2->move(usr);
   }
   tell_room(environment(usr), "\n�ߦѪO�h�J��U����p��߿}�@�]�]�a�o���C�@�ӤH�C\n");
   remove_call_out("give_money");
   call_out("give_money",1,me,ob);
}

int give_money(object me,object ob)
{
	if( !me || environment(me) != environment(ob) )
   {
   	message_vision("�ߦѪO��M�V�|�P�@�ݡG���x�H�H�h�����F�A�s�N����§�������n�F�H���@��\n"
      "�n���Y�@��V���󨫥h�A��p�B���m�֤k�]�@�����i�h�A�ߺְ�@�U�l�ŤU�ӤF�C\n",ob);
		ob->move("/u/llm/workroom");//���n����dest�A�H�Ƭd
	   return  1;
   }
   message_vision("\n�ߦѪO�������a����$N���e�A�@����A���䪺�p��p���L�Ӥ@�L�Ȩ�A�ߦѪO���D�G\n"
   "���o�O�p�i�N�G�즬�U���ȤH�e�W��§���A�@�@�O"+MONEY_D->price_str((int)ob->query("money"))+"\n"
   "�{�b�浹�z�A�i�o���n�I�������A�N���p�ƥ浹$N�C�M�Z�@�����i���󤣨��F�C\n",me);
	MONEY_D->pay_player(me,(int)ob->query("money"));
  	ob->move("/u/llm/workroom");//���n����dest�A�H�Ƭd
	return 1;
}

int do_kill(string arg)
{
   object me = this_player();
   object ob = this_object();

   if(!arg || present(arg,environment(ob))!=ob) return 0;

   message_vision("$N�y�⤣�j��A�n�H�ʤF�����I\n$n��$N���n�Y�G�o�j�ߪ���l�ʤ�z���\�ڡI\n", me,ob);
   return 1;
}

int do_exert(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N���������a�@�B��C\n$n��$N���F�@���A���G��Y�L���A���n�åΤ��\�I\n", me,ob);
   return 1;
}

int do_steal(string arg)
{
   object me = this_player();
   object ob = this_object();
   message_vision("$N���X��A�Q�n���I���\�C\n$n��$N�|�D�G��i�H�K���ѤƤ�I�s���ѡI\n",me,ob);
     return 1;
}
