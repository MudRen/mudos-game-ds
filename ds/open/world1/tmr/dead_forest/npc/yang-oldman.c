// ���S���� - �ѤC�m����Quest
#include <npc.h>
#include <ansi.h>

inherit F_VILLAGER;

void create()
{
        set_name( "�Ѱ��H", ({ "old woman" , "woman" }) );
        set_race("human");
        set("age", 70);
        set("long",@long
    �o�O�@��D�`���믫���Ѱ��H�A���@�o�������z�A�n���ߩ�������
�}�ߨƨ����H�}�ѡC
long
        );
        set("chat_chance", 5 );
        set("chat_msg", ({
			(: command("sigh") :) ,
			(: command("glare") :) ,
        }));
        setup();
        carry_money("coin", 50);
}

int accept_object(object me, object ob)
{
	   if( ob->query_learn("rainbow arrow") ) return 0;
       if( !ob->id("_RAINBOW_ARROW_QUEST_") || is_fighting() ) {
              do_chat((: command, "say �A���ڳo�ӷF���H" :));
              return 0;
       }
    	me->set_temp( "quest-yang-xiao" , 3 );
		do_chat( ({
			"�Ѱ��H�H�Y�N�ѫH��}�ӡA�ӲӾ\Ū\.....\n" ,
			"�����Ѱ��H���\\�������y�X��沴�\\�A�㨣�����D�`���E��...\n" ,
			"�Ѱ��H�⮳�ۮѫH�A���ۻy�D�G�u�Q����ڪ��S��|�b�H�@�A�ڦ��N��̥L��~�����a�X���F...�v\n" ,
			"�Ѱ��H�����a�C�n���D�G�u�ڤw�g��̥L�F...�ڤw�g��̥L�F...�ڤw�g��̥L�F...�v\n" ,
			(: tell_object , me , CYN"(�A�t�Q���ӭn�N�o�Ӧn�����i�D���S�~�O�C)\n" NOR :) ,
			( : destruct , ob : ),
		}) );
       return 1;
}

void relay_say(object ob, string arg)
{
	object letter;
	// �w�Ǳo�C�m���ڪ��H�A�h�����A�ѤF
	if( ob->query_learn("rainbow arrow") ) return;
	if( arg=="���S" ) {
		do_chat( ({
			 "�Ѱ��H�R�צa�ڤl�ݹD�G�u���O�A����ڨ઺�W�r�ܡH�o��h�~�ӦѰ��@�����S���L���U����...�v\n"
			 , (: command( "sob") :)
		 }) );
	return;
	}
}