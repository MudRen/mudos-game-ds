// bing.c ���L

inherit NPC;

void create()
{
	set_name("���L", ({ "song bing", "bing" }));
	set("age", 22);
	set("gender", "�k��");
	set("long", "�j���x�L���Z������M�Z�L�H�h�ۤ�A�������u�x����A�ѤU�Ĥ@�C\n");
	set("attitude", "peaceful");
//	set("vendetta_mark", "authority");
//      set("pursuer", 1);

	set("str", 24);
	set("dex", 16);
	set("combat_exp", 20000);
	set("shen_type", 1);

	set_skill("unarmed", 40);
	set_skill("changquan", 40);
	set_skill("dodge", 40);
	set_skill("parry", 40);
	set_skill("blade", 40);
	set_skill("force", 40);
      map_skill("unarmed", "changquan");
//      map_skill("blade", "wuhu-duanmendao");

	set_temp("apply/attack", 40);
	set_temp("apply/defense", 40);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 40);

        set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		"���L�ܹD�G�j�x�N���A�����y�Ϥ����H\n",
		"���L�ܹD�G�]�o�F�M�|�]���F�q�A�A�٬O�֧֧���N��I\n",
	}));
	setup();
//    carry_object("/clone/weapon/gangdao")->wield();
//    carry_object("/d/city/npc/obj/junfu")->wear();

}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

int accept_fight(object me)
{
	command("say �j�ݧڥ��Q��H���o�A���Ѻ�A�˾`�C\n");
	me->apply_condition("killer", 500);
	kill_ob(me);
	return 1;
}
