#include <ansi.h>
inherit NPC;
void consider();
void create()
{
	set_name("�ۤV�H", ({ "stone man", "stone", "man" }) );
        set("nickname", "�L�۩ǳ�");
	set("gender", "�k��");
     set("level",40);
	set("age", 130);
	set("long",
		"�ۤV�H�ݨӦ~�Ƥw���A�d�ۤ@�Y�զ���v�M�@����GŽ�A\n"
                "�B��۵ۥզ�����A������h�A���������H�٥H�����찭\n"
                "�y�F�A�L�O�b�ʦ~�e�O�H�D�����x���Z�L�ǳǡA�@�M�u�L\n"
                "�ۤM�k�v�a���A�L�H��X��k�A���O�b�����Q�~�e�A\n"
                "�o��Z�L�ǳǴN�����n�θ�A�q������W�ǻ����_�A���L\n"
                "�Q���a�����F�A���L�����W�m�Z�\\���D�󰪹ҬɡA������\n"
                "���A���L���b��B�A�Ҭ���ơA�o���֤H���D�A�γ\\�A�i\n"
                "�h�ݰݥL�C\n"
           );
	set("attitude", "peaceful");
        set("talk_reply","�A�̦n�O�ӷЧڡI");
        set("inquiry", ([
            "���n�θ�" : "�A����ݧڳo���D�I�H\n"
            "            �ڦb�o��׽m�Z�\\�A���K�ެY���W���ڡI�I",
            "�Y��" : "�ۤV�H���D�G�K�K�I�I�o�L�i�^�i�C",
            "����" : "�x�I�H�A�]���D���ǡI�H���D�e�w�X�{�F�����I�H\n"
            "            �ں١A�o���ٷ|�M��H�N������A�Ӧb���줧�W��\n"
            "            �m�䤺���A�ڤT�Q�~�e�Ө즹�a�A�o�{�o�̪��p��\n"
            "            ���`�H�N�A�ӵۦ��Ǫ��ߩʡA��o���j�۫d���F�A\n"
            "            ���ۦ��ǤW���A�@���N���F�T�Q�~�F�C",
            "����" : "�ڦb�o���T�Q�~�ҨD���N�O�o�ѩ��٪������F�C",
        ]) );
        set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
          (:command("exert stone-blade"):),
	}) );
	set_skill("unarmed", 120);
	set_skill("blade", 100);
     set_skill("stone-blade",100);
	set_skill("force", 100);
	set_skill("parry", 100);
	set_skill("dodge", 100);
	setup();
         carry_object(__DIR__"wp/s_blade")->wield();
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if(ob->name()!="�Ȥ������F��")
        {
           command("bag "+who->query("id"));
           command("say �ѤҨä��ݭn�o�ӪF��C");
           return 0;
        }
        else {
         destruct(ob);
           command("say �x�I�H�Ӧn�F�I�I�ڲש�o�즹�����F�I");
           command("say �p���@�ӡA�m�\\�i�|�ƥb�\\���r�I");
           command("jump");
//           if(who -> query_temp("kill_devil")>0 || who -> query_skill("stone-blade") >0)
//           {
//             command("say �o��"+RANK_D->query_respect(who)+"�A��b�O�P�E���ɡA�ڴN��o�M�u�L�ۤM�k�v�Щ�A�a�I");
//             message_vision("($N�Ӥߪ��ǲߥۤV�H�ҶǱª��u�L�ۤM�k�v�C)\n",who);
//             who->set_skill("stone-blade",1);
//           }
//           else {
             if(obj->query_temp("give_blade")>0)
             {
               command("say �ڤ]�S����F�赹�A�F�A�A�ۭӨ�n�۬����a�I");
             }
             else {
               command("say �o�˧a�I�ڧ�o��M�e���A�C");
               command("give blade to "+who->query("id"));
               obj->set_temp("give_blade",1);
             }
//           }
           return 1;
        }

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
				command("say " + RANK_D->query_respect(enemy[i]) + "�J�M�ϧL�b�M�b�U�ŤⱵ�ۥ��K���q�C");
				command("wield blade");
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
		command("unwield blade");
	}
}
