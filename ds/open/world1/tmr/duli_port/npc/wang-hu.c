#include <npc.h>
#include <ansi.h>
#include <skill.h>
inherit F_VILLAGER;
void create()
{
        set_name("����", ({ "wang hu","hu" }) );
        set("long",@long
�b�A���e���O�@������٦׵��ꪺ�k�H�A���W��ۤ@��¸���u�ȤM�v
�r�˪��Z���A�A�ݥL���W�a�ۦ���A���b�o���f�|�B�i��A���G�b��M��
��@�ˡC
long
);
        set_race("human");
        set("age", 24);
        set_stat_maximum("gin", 150);
        set_stat_maximum("hp", 200);
        set_skill("blade",60);
        set_skill("dodge",100);
        set_skill("silver-blade steps",80);     
        map_skill("dodge","silver-blade steps");


        set_attr("str",25);
        set("chat_chance", 5);
        set("chat_msg", ({
                "����Ԧ�F�@�Ӹ��L���H�A�߰ݤF�L�@�ǨƱ���A�S�n�n�Y���F�^�ӡC\n",
                "������ۻy�D�G�u�Ĥ@������쩳�b����O�H�H�u�O����....�v�C\n",
        }));

        set("title","�ȤM�����{");
        setup();
		set_level(10);
        carry_object(__DIR__"obj/silver-blade")->wield();
          carry_object(__DIR__"obj/fighter-cloth")->wear();

}

int accept_fight(object ob)
{
        do_chat("����o�N���F���A���D�G�u�N���A�ոէڳo�ӷ��y�H���F�`�a�I�I�v \n");
        return 1;
}
void init()
{
        object me=this_player();
        if( me->query_learn("silver-blade steps") )
		command("bow "+me->query("id"));
}


/* Quest:�i�Ǩ� �ȤM�����k ���\ */
void relay_say(object ob, string arg)
{
        if( ob->query_learn("silver-blade steps")  )      return;
        if( strsrch(arg,"�Ĥ@�����")!=-1 ) {
                 do_chat("����W�o�D�G�u�O�r�A�ڭn�h�ѥ[���~���y�H����A���O�@���䤣��C�v \n");
                ob->set_temp("duli_port/wang-hu",1);
                return;
        }
        if( strsrch(arg,"���_��s�W���@�ʤj���쨫�h")!=-1
         && ob->query_temp("duli_port/wang-hu")==1 )
        {
                message_vision(CYN"����V�_�䪺��V��F��A���M�����D�F����@�ˡA�߹D�G�u�u�O���§A���ڳo�Ӥj���C�v \n"NOR,ob);
                message_vision(CYN"������ۻy�D�G�u�����ӫ���§A�O�H�H�v \n"NOR,ob);
				/* �ǲߧޯ��I�Ƥ���	*/
                                  if(ob->query("skills_point")+1 >  SKILL_MAX_POINT ) {
			        message_vision(CYN"���괧�F����A���_�䪺�D�����F�L�h�C\n" NOR,ob);
		            ob->delete_temp("duli_port/wang-hu");
	                destruct(this_object());
				}
                message_vision(CYN"�����ۧA�ݹD�G�u�����A�O�_�Q�n�������@�M���\�O�H�H�v\n" NOR,ob);
                ob->set_temp("duli_port/wang-hu",2);
                return;
        }
        if( strsrch(arg,"���Q")!=-1  && ob->query_temp("duli_port/wang-hu")==2 )
        {
                message_vision(CYN"����ĹD�G�u���n�a�A���ڴN���@�B�F�C�v\n"NOR,ob);
                message_vision(CYN"���괧�F����A���_�䪺�D�����F�L�h�C\n" NOR,ob);
                ob->delete_temp("duli_port/wang-hu");
                destruct(this_object());
                return;
        }

        if( strsrch(arg,"�Q")!=-1  && ob->query_temp("duli_port/wang-hu")==2 )
        {
                message_vision(CYN"����߹D�G�u���n�A�ڳo�ӤH�����s�����������C�v\n"NOR,ob);
                message_vision(CYN"����b$N����Ӳ����F�X�y�ܡA���G�b�Ǳ¤���f�Z�C\n" NOR,ob);
                message_vision(CYN"���괧�F����A���_�䪺�D�����F�L�h�C\n" NOR,ob);
                ob->delete_temp("duli_port/wang-hu");
                ob->improve_skill("silver-blade steps",100);
                                /* �w�ǲߧޯ��I�Ƥ@�I   */
                                ob->add("skills_point",1);
                                tell_object(ob,HIG"(�A���ޯ�ǲ��I�ƪᱼ�@�I�C)\n" NOR);
                destruct(this_object());
                return;

        }

}
