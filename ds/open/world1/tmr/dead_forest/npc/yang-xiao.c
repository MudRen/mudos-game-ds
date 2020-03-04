// �C�m����(rainbow-arrow) Quest
#include <npc.h>
#include <ansi.h>
#include <skill.h>

void create()
{
        set_name( "���S" , ({ "yang xiao","xiao"}) );
        set("long",@long
�@�@���S�O�@�ӧ��Ӫ����~�k�l�A���o�^���D�Z�A�����z�S�۫L�q
����A�������H��A���^���𷧡A���H�@���N�ߥͦn�P�C���L�L�y
��D�`�a�աA�I�l��P�����Z�A�ݤf����A�W�]�g���F��{�A���G
���F���Y�������ˡC
long
);
        set_race( "strength" );
        set("age", 35 );
        set_attr( "str" , 25 );
        set_skill( "axe" , 120);
        set_skill( "dodge" , 100 );
        set_skill( "unarmed" , 100 );
        set_skill( "parry" , 100 );
        set("chat_chance", 5 );
        set("chat_msg", ({
                        "���S���ۻy�D�G�u�Q���줵��n�ũR�󦹡A���Ī����ߧ��ӦA�]�S�k�l��{�F.....�v\n",
			"���S���M�@�P�a�y�F�_�ӡA�y�W�@�}�C�@�}�ժ��A���G�֭n�����ˤl......\n",
        }));
        setup();
        set_level( 20 );
        carry_object(__DIR__"obj/wu-cloth")->wear();
        carry_object(__DIR__"obj/steel-boots")->wear();
}

void relay_say(object ob, string arg)
{
  	   object letter;
  	   // �w�Ǳo�C�m���ڪ��H�A�h�����A�ѤF
  	    if( ob->query_learn("rainbow arrow") ) return;
		if( ob->query_temp("quest-yang-xiao") == 2 ) return ;
        if( arg=="���ߧ���")  {
        	do_chat(
        		({
        			"���Sť��o�|�Ӧr����A�H�Y�b�F�n�@�|��....\n",
        			"���S�n�F�n�Y���D�G�u��...���ɦA���o�]�S�ΤF�A�p���ڤ߸̲o�����ϦӬO�t�@��ư�...�v\n",
	            })
            );
            return ;
        }
        if( arg=="�t�@���")  {
        	do_chat( ({
        			"���S�ĤF�f��A���D�G�u�ڦۤQ�����}�a����A�N�A�]�S���^�a�ݧڥ��ˤF...�v\n",
        			"���S�b��۪��~�A�~�򻡹D�G�u�p���w�g�G�Q�Ӧ~�Y�F�A�ڷQ�ڤw�g�˭���¡�A�L�k�^�a�F...�v\n",
        			"���S�y�F�@�U�A���G���F����M�w�A�ݹD�G�u�����O�_��·ЧA���Ӧ��H�v\n",
	            }) );
            ob->set_temp("quest-yang-xiao" , 1);
            return ;
        }
        if( ob->query_temp("quest-yang-xiao") == 1 ) {
    		if( arg=="�n") {
		       	do_chat( ({
"���S�߹D�G�u���N�·ЧA���ڱN�o�ѫH�e�浹�ڦѥ��A�n���o�٪��D�ڳo�Ӥ����l�ܬO�Q���o...�v\n",
        				"���S�u�z�v�a�@�n�R�F�j�f�A��A�u�����D�ٯଡ�h�[...\n",
	        	    })     );
	            letter = new(__DIR__"obj/letter" );
	            letter->move( ob );
	            ob->set_temp("quest-yang-xiao" , 2);
    		}
    		if( arg=="���n") {
		       	do_chat(({ "���S�H�M���D�G�u���]�L���A�N�����Z�A���ɶ��F�C�v\n", })   );
	            ob->delete_temp("quest-yang-xiao");
    		}    	
		}
       if( ob->query_temp("quest-yang-xiao") == 3 && arg=="�w�g��̧A�F" ) {
	            if( ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
					// �ޯ��I�Ƥ���
					do_chat( ({
						(: command(":D") :) ,
"���S��M�D�`���������D�G�u�u�O���§A�������F�A�ڦp���w�O�N�������A�ꤣ������i�H�^��...�v\n" ,
						 "���S�D�G�u���Y�|�O�o�A���j���j�w�A�u�ߨӥ@�A���F...�v\n" 
					}) );
					ob->delete_temp("quest-yang-xiao");
				} else {
					do_chat( ({
						(: command(":D") :) ,
						"���S�㨣�D�`���������D�G�u�u�O���§A�������F�A�ڦp���w�O�N�������A�ꤣ������i�H�^��...�v\n" ,
			  		 	"���S�D�G�u���Y�|�O�o�A���j���j�w�A�u�ߨӥ@�A���F...�v\n" 
						"���S�y�F�@�y�D�G�u�ڳo�঳�M�a�Ǫ����ǡA�����A�O�_������Q�ǡH�v\n" 
					}) );
					ob->set_temp("quest-yang-xiao" , 4);
				}
			return;
		}
       if( ob->query_temp("quest-yang-xiao") == 4 ) {
			if( arg=="�Q") {
				tell_object( ob , CYN "���S���b�A����A�N�f�Z�ֳt�a��L�@�M....\n" NOR );
   	            if(ob->query("skills_point") + 3 >  SKILL_MAX_POINT )  {
					tell_object( ob , CYN "(���O�A����ť�����L���������e...)\n" NOR );
				}
				else {
					tell_object( ob , CYN "\n(�A���G���u�C�m���ڡv�o�ӧޯ঳�Ӫ�B���{�ѤF...)\n" NOR );
					tell_object( ob , HIY "\n(�A���ޯ��I�ƴ�֤T�I�F�C)\n" NOR );
                    ob->improve_skill( "rainbow arrow" , ob->query_attr("int") );
				    ob->add("skills_point" , 3 );
				}
				ob->delete_temp( "quest-yang-xiao" );
				return;
			}
			if( arg=="���Q") {
				do_chat( ({ "���S�D�G�u���n�A�A���j���j�w�A���Y�u���ӥ@�A���F...�v\n" }) );
				ob->delete_temp( "quest-yang-xiao" );
				return;
			}
		}
}

