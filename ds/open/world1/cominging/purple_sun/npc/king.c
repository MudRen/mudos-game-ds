#include <ansi.h>

inherit NPC;
int ghost_kill(object ob)
{
    object target;

	target = ob->select_opponent();
    if( !target) return 1;
	if(ob->is_busy() ) return 1;
	switch(random(3) ) {
	case 0:
         message_vision(HIM "$N��q�s�s�A��W����յ��@�S���C�U��...\n" NOR,ob);
		ob->attack();
		ob->attack();
		ob->attack();
	break;
	case 1:
		message_vision(RED "$N�i�L�S�X�Q���A�w�ͥͫr�U$n�ӤW�@�����פU��....\n" NOR,ob, target);
		ob->receive_heal("hp", ob->query("hp")/10 );
        target->receive_damage("hp", 50 + random(50), ob);
	break;
	default:
		message_vision(HIY "$N�i�j�f�o�X�@�n���ƪ��s�n�A$n�n���~���L�n�L�O......\n" NOR,ob, target);
		target->add_busy(1);
	break;
	}
	return 1;
}


void create()
{
        set_name("�~������" ,({"animal king","king"}) );
        set("long",@LONG
�~�������O�ʦ~�e�N�b�b�����s�����c�h�ݪ��@���~�H�ڡA
�Ѥ@�����H���٩I�L�����c��D�C�~�������Ϊv�@�s�ݻŪ��g
�~�A���͵L�ơA���F��C���ӱo�����|���X�O���U�A�~�N�~
�������ʦL�b�������a��C
LONG
);
        set("age",200);
        set("race","ogre");
        set("title",HIR"���c��D"NOR);
        set("level",45);
        set("attitude", "aggressive");
        set("gender", "�k��" );
        set_skill("parry",100);
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set_skill("blade",100);
      set("chat_chance_combat",30);
	set("chat_msg_combat",({
		(: ghost_kill,this_object() :),
	}) );

        setup();
        set_living_name("animal-war-object");
		if(random(100)<30)
			carry_object(__DIR__"wp/king-blade")->wield();
		else carry_object(__DIR__"wp/king-blade2")->wield();
		carry_object(__DIR__"eq/copper-armor")->wear();
           carry_object(__DIR__"obj/organ");
           carry_object(__DIR__"obj/stomach-bag");
             carry_object(__DIR__"obj/king-head");
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
        HIM "\n\t�~�������{�����ڹ��"+ob->name(1)+HIM"�o�ͧC�I����s�A�R���L�ɪ�����C\n\n"+NOR
        ,users());
            ob->add("popularity",3); //�n��
         tell_object(ob,HIG"�A�o��T�I�n��F�C"NOR);
        ::die();
        return;
}
