#include <ansi.h>
inherit NPC;
void consider();
void create()
{
	set_name("��L�j�v", ({ "fung ying bonze", "bonze"}) );
	set("gender", "�k��");
     set("level",35);
	set("age", 60);
	set("long","�L�O�@��o�D�����A��������|�b���B�C\n");
        set("talk_reply","�^���Q�x�󦹡A�L�k�樭�ڡI�ڬݧA�O�����W�����C");
        set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: consider :),
	}) );
	set_skill("unarmed", 80);
	set_skill("staff", 70);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 90);
	setup();
        carry_object(__DIR__"wp/staff")->wield();
        carry_object(__DIR__"eq/b_cloth")->wear();
        carry_object(__DIR__"eq/neck")->wear();
        carry_object(__DIR__"eq/b_boots")->wear();
}
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
				command("say " + RANK_D->query_respect(enemy[i]) + "�J�M�ϧL�b�M�ѯǪŤⱵ�ۥ��K���q�C");
				command("wield staff");
				command("say �i�ۧa�T");
				break;
			}
		}
	}
	if( !flag && query_temp("weapon") ) {
		if( sizeof(enemy) > 1 )
			command("say ��... �J�M" + chinese_number(sizeof(enemy)) + "�쳣�O�Ť�M�ѯǲz��^���T");
		else
			command("say �J�M" + RANK_D->query_respect(enemy[0]) + "���ϧL�b�M�ѯǦ۵M�^���T\n");
		command("unwield staff");
                command("come");
	}
}
