#include <ansi.h>

inherit NPC;
inherit __DIR__"ghost-forest";

void create()
{
        set_name("�L�k" ,({"ghost wu-won","won"}) );
        set("long",@LONG
�L�k�����ڰ��_�˪L�������A�ͩʥ��ݬ����C�ƤQ�~�e�A�L�k��]�u
�O�w���פ骺�C�~�l�̡A�����G���g���L�G���H�Ȫ��ơA���Ӥ@�]�����A
����ǥͫe�ҾǪ��Z�\�A�b���ɤ��I����B�A��v��Q�G�����v���H���A
��Q�X�~�e�A�������󪺳Q�ʦL�b���_�˪L��....
LONG
);
        set("age",200);
        set("race","�H��");
        set("title","����");
        set("level",40);
        set("attitude", "aggressive");
        set("gender", "�k��" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("staff",100);
	set("chat_chance_combat",50);
	set("chat_msg_combat",({
		(: ghost_kill,this_object() :),
	}) );

        setup();
        set_living_name("ghost-forest-war-ghost");
//        carry_object(__DIR__"eq/gold_helmet")->wear();
//        carry_object(__DIR__"eq/silver_armor")->wear();
//        carry_object(__DIR__"wp/copper_cane")->wield();

}

void die()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) 
        {
                ::die();
                return;
        }
 
                message("world:world1:vision",
        HIB"\n���� �L�k�b�{���e�o�X�@�n�o�ۡG�u�ڷ|�A�^�ӧ�"+ob->name(1)+"���o�����������I�I�I�v\n\n"+NOR
        ,users());
          ob->add("popularity",2); //�n��
        ::die();
        return;
}
