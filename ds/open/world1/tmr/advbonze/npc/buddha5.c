#include <ansi.h>
#include <path.h>

inherit NPC;

void create()
{
        set_name( "���]ù�~" ,({"fu-mo luo hang","fu-mo","lo","hang"}) );
        set("long",@LONG
�b�A���e���O��ɤ��������W�����]ù�~�A���p�Ӧ򯪨��ǱM�ޥh�����]
���u�@�A�㦳�L�W�����q�O�C���]ù�~��󰵴c�����ǡA�O�q����U�d�����A
���߸z���}���H�ΰʪ��A�h�O�O�R���[�A�@���]�@�w���j�ӥ[�`�C
LONG
);
        set("age",200);
        set("race","�H��");
        set("title","�L��");
        set("level",40);
        set("attitude", "friendly");   //�͵��� NPC�C
		set("gender", "�k��" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        setup();
        set_living_name("buddha-war-jingang");
                set("combat_exp",500000);
		carry_object(__DIR__"eq/cloth")->wear();
        carry_object(__DIR__"eq/boots")->wear();
}

void die()
{
        object ob,me;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);

        if( !ob ) 
        {
                ::die();
                return;
        }
		me=this_object();
		message_vision(
		HIR "\n$N�j�P�����`���ߡA�P�ϥL�κɥ������O�q���X�̫�@���I�I\n\n"
	   +HIY "$N�ϥX�p�ӤE���Ĥ���" + HIY "�u����ѡv�A�@���E���L�P����l����$n���e��h�I�I\n\n" NOR
	   	,me,ob);
                 if( random(10)>4) {
			message_vision(HIR "$N���H���סA�����a�Q�����ƤV�����I�I\n" NOR,ob );
			ob->set("hp",ob->query("max_hp")/10);
	        COMBAT_D->report_status(ob);
			tell_room(ob,CYN +"(" + ob->query("name")+"�a�ۤ@�D�A�婹�n���F�L�h...)\n" NOR,ob);
			ob->move(TMR_PAST"advbonze/summit1.c");
                        tell_room(environment(ob),ob->query("name")+"�����g���A�媺���F�L�ӡA�u�I�v���@�n�L�b���a�W�C\n",ob);
			ob->start_busy(1);
		} else {
			message_vision(HIW "$N�j�j�a���פF�o�P�R�@���A���]�y���~�o�a��...\n" NOR,ob );
		}
        tell_object(ob,HIG"\t�A�o��G�I�n��C\n"NOR);
        ob->add("popularity",2); //�n��

        ::die();
        return;
}
