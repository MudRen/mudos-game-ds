#include <npc.h>
#include <ansi.h>
#include <skill.h>

inherit F_VILLAGER;

void create()
{
        set_name("�G�l�q", ({ "zheng zi tong","zi","tong","zheng", }) );
                set("long",@long
    �G�l�q�O���W�����C�N����A�L�۳Ъ��u���C�N�v��Ӥ��ءA�۩۳�
�O�j�}�j��A�j����²�䦳�O�A�̾A�X�O�q�j�����Ǫ�۪��H�ϥΡC�G�l
�q�����G�G�����A�d�ۤ@�Y�b����Ӫ��Y�v�A��ۤ@���l�ˡA�I�ۤ@���
�C�A�����Ӫ����L���`���ɯd�ۤ@�����N�A���H������`���Pı�C
long
);
        set_race("strength");
        set("age", 35);
        set_stat_maximum("gin", 400);
        set_stat_maximum("hp", 300);
        set_stat_maximum("nina", 100);
                set_attr("str",25);
                set_attr("cor",20);
                set_attr("strength",40);
                set_skill("parry",80);
                set_skill("dodge",80);
        set_skill("sword",80);
                set_skill("attack sword",80);
                map_skill("sword","attack sword");

        set("title","���C�N����");
        setup();
		set_level(10);
        do_heal();
    	carry_object(__DIR__"obj/white-sword")->wield();
}

int accept_fight(object ob)
{
        return 0;
}

/* Quest:�i�Ǩ� �u���C�N�v �C�k */
void relay_say(object ob, string arg)
{
        if( ob->query_learn("attack sword")  )      return;
            if( strsrch(arg,"���C�N")!=-1 )
                {
                         if( ob->query_attr("str") < 15 ) {
                message_vision(CYN"�G�l�q�W�U���q�F$N�X���A�N���D�G�u�̧A��L�������O���ˤl�A����Ǳo�ڪ����ީO�C�v\n"NOR,ob);
                                return ;
                        }
           /* �ǲߧޯ��I�Ƥ���     */
                        if(ob->query("skills_point")+1 >  SKILL_MAX_POINT ) {
                    message_vision(CYN"�G�l�q�n�F�n�Y���D�G�u�A���ǹL�s�A�ڳo�I�L���p�޴N���ҧA�O�߾ǤF�C�v\n"NOR,ob);
                                return;
                        }
            message_vision(CYN"�G�l�q�W�U���q�F$N�X���A�߹D�G�u�@�A���j�O���A�p�G�A�u�Q�n�Ǫ��ܡA�ڤ����i�H�Ǳ§A�X�ۡC�v\n"NOR,ob);
                        ob->set_temp("duli_forest/zheng-zi-tong",1);
                        return ;
                }
                if( arg=="���Q"
                        && ob->query_temp("duli_forest/zheng-zi-tong") )
                {
		        message_vision(CYN"�G�l�q�n�n�⻡�D�G�u�A���Q�ǡA�N�O�A�ӷЧڤF�C�v\n"NOR,ob);
                        ob->delete_temp("duli_forest/zheng-zi-tong");
                        return ;
                }

                if( arg=="�Q"
                        && ob->query_temp("duli_forest/zheng-zi-tong") )
                {
            message_vision(CYN"�G�l�q���D�G�u�������n�A�A�@�J�ӤF�a�C�v\n"NOR,ob);
            message_vision(CYN"�G�l�q���_�⤤���C�A�񹺤F�ƩۡA$N�����O��C�ۨC���C\n"NOR,ob);
                        ob->add("skills_point",1);
            tell_object(ob,HIG"(�A���ޯ�ǲ��I�ƪᱼ�@�I�C)\n" NOR);
                        ob->improve_skill("attack sword",100);
                        ob->delete_temp("duli_forest/zheng-zi-tong");
                        return ;
                }
        
}
