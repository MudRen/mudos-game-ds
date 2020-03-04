// master.c

inherit NPC;
inherit F_MASTER;

void consider();

void create()
{
	set_name("�d����", ({ "master scholar", "master", "scholar" }) );

	set("gender", "�k��");
	set("age", 32);
	set("long",
		"�d����ͩ�ʫ����W���Z�L�@�a�M�L�����W�O�d�ت��M���O�]���ͩʳ߷R\n"
		"�|�B�C���M�E�۸��u����v�M�|�B�C�s�����M���滨�ǲ��H�C�Ʀ~�e�~��\n"
		"����d���Ӧ����B�Ȭ����s���x���M���O�߷R�ƪy���өʤ��M����M�O��\n"
		"���ϱJ�Y�h���w�C\n" );

	set("attitude", "peaceful");
	create_family("�B�Ȭ�", 7, "�x���H");

	set("str", 26);
	set("cor", 30);
	set("int", 24);
	set("cps", 30);

	set("force", 3000);
	set("max_force", 1600);
	set("force_factor", 20);

	set("combat_exp", 1000000);
	set("score", 200000);
/*
	set("chat_chance_combat", 80);
	set("chat_msg_combat", ({
		(: consider :),
		(: exert_function, "powerup" :),
		(: exert_function, "recover" :)
	}) );
*/
	set_skill("unarmed", 60);
	set_skill("sword", 90);
	set_skill("force", 80);
	set_skill("parry", 90);
	set_skill("dodge", 100);
	set_skill("literate", 150);
	set_skill("perception", 80);

	setup();
}

/*
void init()
{
	add_action("do_swear", "swear");
}

void attempt_apprentice(object me)
{
	if( me->query_temp("pending/celestial_swear") ) {
		command("say �h���L�q�M�Y���o�}��u���W�M�K�O���ۨD�ڤ]�S�ΡC");
		return;
	} else {
		command("say �ڤѨ������W���Y�M" + RANK_D->query_respect(me)
			+ "�p�G�u�����ߡM�B�o�ӻ}(swear)�ӡC");
		me->set_temp("pending/celestial_swear", 1);
	}
}

int do_swear(string arg)
{
	if( !this_player()->query_temp("pending/celestial_swear") )
		return 0;
	if( !arg ) return notify_fail("�A�n�o����}�S\n");
	this_player()->set_temp("pending/celestial_swear", 0);
	message_vision("$N�o�}�D�R" + arg + "\n", this_player());
	if( strsrch(arg, "�u") >=0 && strsrch(arg, "���W") >=0 ) {
		command("smile");
		command("say �o�N�O�F�C\n");
		command("recruit " + this_player()->query("id"));
	} else {
		command("say �A�o���O���򰭻}�M�O�H���ڨSť��T");
	}
	return 1;
}

int recruit_apprentice(object ob)
{
	if( ::recruit_apprentice(ob) )
		add("apprentice_availavble", -1);
}
*/
void consider()
{
	int i, flag = 0;
	object *enemy;

	enemy = query_enemy() - ({ 0 });
	for(i=0; i<sizeof(enemy); i++) {
		if( !living(enemy[i]) ) continue;
		if( enemy[i]->query_temp("weapon") ) {
			flag++;
			if(	!query_temp("weapon") ) {
				command("say " + RANK_D->query_respect(enemy[i]) + "�J�M�ϧL�b�M�b�U�ŤⱵ�ۥ��K���q�C");
				command("wield sword");
				command("say �i�ۧa�T");
				break;
			}
		}
	}
	if( !flag && query_temp("weapon") ) {
		if( sizeof(enemy) > 1 )
			command("say ��... �J�M" + chinese_number(sizeof(enemy)) + "�쳣�O�Ť�M�b�U�z��^���T");
		else
			command("say �J�M" + RANK_D->query_respect(enemy[0]) + "���ϧL�b�M�b�U�۵M�^���T\n");
		command("unwield sword");
	}
}
