#include <ansi.h>
inherit NPC;
void say_delay1(object me);
void say_delay2(object me);
void nod_delay(object me);
void create()
{
        set_name("��K���C��", ({ "swordsman","man" }) );
        set("nickname", "�ڱ����K���_��");
        set("gender", "�k��" );
        set("long",
            "�@�ӲV���s�𪺸��z���~�k�l�A���q�L���̤��i�ݥX�@����������C\n"
            "�o�����L�O�b�~�T��ơA�u���L�����@�M�@�M�U�{�A�n�����|�K�@�ˡC\n"
           );
        set("age",45);
        set("level",30);
        set_skill("dodge", 80);
        set_skill("parry", 70);
        set_skill("sword", 85);
        set_skill("hungchen-sword", 100);
       set("chat_chance", 5);
        set("chat_msg", ({
                "��K���C�ȧu�D�G���Э|�|�A�����z�z�A�u���تŤ@���n�F...........\n",
                "��K���C�ȧu�D�G���ͥ��F�A�ߵL���Z�A�@�����b�@�p���F...........\n",
                "��K���C�ȧu�D�G���ɨ����A�ڤ��Ʒn�A�ۤѶ«�ͱo���H...........\n",
                "��K���C�ȧu�D�G�ӥ����ơA�R��ľP�A��s��qѡ���~�ئѡI...........\n",
        }));
        set("inquiry", ([
            "��": "���I�I�ݥ@�������󪫡H\n",
        ]) );
        setup();
	carry_object(__DIR__"wp/hung");
}
void init()
{
        object me,obj;
        me=this_player();
        obj=this_object();
        add_action("do_say","say");
        add_action("do_nod","nod");
        if(objectp(obj=present("wine",me) ) && me->query_temp("quest/wine") == 0 )
        {
          call_out("wine",2,obj);
        }
        if(me->query_temp("quest/wine") == 8)
        {
          call_out("wine2",2,obj);
        }
}
void wine()
{
    object me;
    me=this_player();
    message_vision("��K���C�ȬݨӦn���Q$N���W���Y�˪F��l�޵ۤF�A�@���`����$N�C\n",me);
    say("��K���C�Ȼ��G�o��"+RANK_D->query_respect(me)+"�A���s�ܡH\n");
    command("lick");
}
int accept_object(object who, object ob)
{
           object me,book;
           me=this_player();
        if( ob->query("water_remaining") == 0 ) return notify_fail("��K���C�Ȼ��D�G�s�I�s�I�s�I�ڥu�n�s�I\n");
           if( ob->name() != "�N�M�l" )
           {
		message_vision("$N���F��K���C�Ȥ@��"+ob->query("name")+"�C\n",me);
		say("��K���C�Ȥ@���ӺɡA���D�G�o�Ӥ��O"+ob->query("name")+"���A�o�s�����@�P�a�A�ܤ��K�H��...\n");
             	command("sigh");
             	destruct(ob);
             	return 1;
           } 
           else {
             if(me->query_temp("quest/wine") == 0)
             {
message_vision("$N���F��K���C�Ȥ@��"+ob->query("name")+"�C\n",me);
              say("�����g�X���˪����~�A�}�l�ӲӪ��~���C\n");
              say("��K���C�Ȥ@��ܵۿN�M�l�A�@�䤣�����j�ġG�n�s�I�n�s�I\n");
               me->set_temp("quest/wine",1);
               destruct(ob);
               return 1;
             }
             else {
               message_vision("��K���C�ȬݨӦ��G�Q$N��K�F�A�L�̶}�l���Ъ����ۤ@�ǧAť\n",me);
               say("���M�����r�y�A�U�U�k�k�����uť��@�����еۡu�p�S�v�o�ӦW�r�C\n");
               if(book=me->query_temp("notebook"))
          	 book->add_quests_note("SadSworder","�C�ȾK�ɴ��_�F�p�S�o�ӤH..�γ\\�����Ӱݰݤp�S������[say �p�S?]�C");
               me->set_temp("quest/wine",2);
               destruct(ob);
               return 1;
             }
           }
}
int do_say(string arg)
{
      object me,obj;
    me=this_player();
    obj=this_object();
    if( !me->query_temp("quest/wine") >1 ) return 0;
    if(!arg) return 0;
    else {
         if(strsrch(arg,"�p�S")!=-1 && me->query_temp("quest/wine") == 2 && !busy)
         {
           	busy=1;
		call_out("say_delay1",0,me);
		return 0;
         }
         else {
           if(strsrch(arg,"������")!=-1 && me->query_temp("quest/wine") ==4 && !busy)
           {
           	busy=1;
		call_out("say_delay2",0,me);
		return 0;
           }
        }
    }
}

void say_delay1(object me)
{
	object book;
	busy = 0;
	if(!me) return;
	if(environment(me) != environment(this_object()) ) return;
	say("��K���C�ȳﶡ�o�X�u�B�v���@�n�A�Ⲵ�����ۧA�ݡC\n");
        command("say �x�I�H"+RANK_D->query_respect(me)+"�A�{�Ѧo�I�H");
        if(book=me->query_temp("notebook"))
        book->add_quests_note("SadSworder","�C�Ȱݰ_�p�S����..�γ\\�������I�Y�H�K��ť�p�S�������C");
        me->set_temp("quest/wine",3);
        return;
}
void say_delay2(object me)
{
       object book,shawl;
	busy = 0;
	if(!me) return;
	if(environment(me) != environment(this_object()) ) return;
              command("sorry");
              this_object()->set("name","������");
              command("say �b�U�ëD�¤߬ۿf�A��b�O....");
              say("�����мۤF�f�𻡹D�G���s�L���A�����L�s�A���s�Ѧb�A�H�ͤ@�֡C\n");
              say("��������D�G"+RANK_D->query_respect(me)+"�A���A�N�|���ժ�...\n");
              shawl=new(__DIR__"obj/shawl");
              shawl->move(me);
              message_vision("�����е�$N�@�Ӹh���C\n",me);
              if(book=me->query_temp("notebook"))
              	book->add_quests_note("SadSworder","�����Ъ��h��.. �γ\\���Ӯ����p�S�ݬݡC");
              me->set_temp("quest/wine",5);
        return;
}
int do_nod(string arg)
{
        object me;
      me=this_player();
      if(me->query_temp("quest/wine") ==3 )
      {
           	busy=1;
		call_out("nod_delay",0,me);
		return 0;
      }
}
void nod_delay(object me)
{	
	object book;
	busy = 0;
       	if(!me) return;
	if(environment(me) != environment(this_object()) ) return;
       say("��K���C�ȬݨӤ@����W�������ˤl�A�L�w�w���C�U�Y�I�u�F�@�|�C\n");
       say("��K���C�Ȯ��_�F�⤤�����мC�A�ݤF�ݡA�������T�y�S�X�ŬX�������C\n");
       tell_object(me,"(�A�ݨ�o�@��C�A���A�Q�_�F��誺���]�A�L�s���O���O�����ЩO�H)\n");
       if(book=this_player()->query_temp("notebook"))
           book->add_quests_note("SadSworder","���мC�~�M�b�C�Ȥ⤤..���D�L�N�O������? [�Q�ݥL�N��: say �A�O������?]�C");
       me->set_temp("quest/wine",4);
       return;
}
void wine2()
{
      int i,exp,j;
      string *msg;
      object me,obj,book;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("suicide");
      switch( i ) {
          case 0:
            message_vision("( $N�@�I�쯺���СA�N��Ʊ����g�L�@���@�Q���i�D�L�F�C )\n",me);
            say("�����вH�H�����G�Q����o�ܤ����s�Ӿ��|��������...\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 1:
            say("�����Щ޼C�X�T�A�|�_�C�H��@���A�@�C���F�A���᪺���...\n");
            command("say �o��"+RANK_D->query_respect(me)+", �o�C�۴N�ǤF�A�a...\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 2:
            say("�����Ш��Υ|�B�Ʃ����w�A�@�b������i���мC�k�j�t�F�@�M�C\n");
            message_vision(" ( $N�c�c���O�U�Ҧ����C�� )\n",me);
              if(me->query_skill("hungchen-sword") == 0)
               {
                me->set_skill("hungchen-sword",11);
                     }
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 3:
            say("�����йĹD�G�S���H�i�H�u���ݯ}���СA�ߦ�....\n");
            command("sigh");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 4:
            say("�����г��u�D�G���Э|�|�A�����z�z�A�u���تŤ@���n�F...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",2,obj);
            break;
          case 5:
            say("�����г��u�D�G���ͥ��F�A�ߵL���Z�A�@�����b�@�p���F...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",2,obj);
            break;
          case 6:
            say("�����г��u�D�G���ɨ����A�ڤ��Ʒn�A�ۤѶ«�ͱo���H...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",2,obj);
            break;
          case 7:
            say("�����г��u�D�G�ӥ����ơA�R��ľP�A��s��qѡ���~�ئѡI...........\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",5,obj);
            break;
          case 8:
            say("�����д��_�⤤���C�A���ۤw����l�@�F�A�L�̱a�ۤ@���Y�W�����e�C\n");
            say("�����Ц۱��F�I�I�I\n");
            obj->set_temp("suicide",i+1);
            call_out("wine2",3,obj);
            break;
          case 9:
            me->delete_temp("quest/wine");
            if(book=me->query_temp("notebook"))
            {
		book->add_quests_note("SadSworder","�����Ц]���������W�Ӧ۱��F�A���e�ñN�C�k�Ǳµ��ڡA���Ȳש�i�@�q���C");
            	if(!book->query_step("SadSworder"))
            	{
			book->set_quests("SadSworder",1);
			msg=book->query_quest_note("SadSworder");
			j=sizeof(msg);
			write(sprintf("%s���ߧA�����F�o�ӥ��ȡA�A�������׬O: %d%%\n",HIC,(100*j/9)));
			exp= j*10000+random(10000);
			write(sprintf("%s�A�o��F%d�I�g��ȡA�åB�n�洣�@�F%d�I�C\n\n%s",HIW,exp,j,NOR));
			me->add("exp",exp);
			me->add("popularity",j);
			me->save();
		}
            }
            ::die();
            break;
        }
}
