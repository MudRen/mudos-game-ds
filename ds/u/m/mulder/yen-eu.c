#include <ansi.h>
inherit NPC;
void create()
{
	set_name(HIG"�C��"NOR,({"yen-eu","yen"}) );
        set("long","�@�ӥ����O�˪��ѤH�A�Ⲵ�n���R���F����A�ݨ����������F�C\n");
	set("age",50);
	set("level",60);
	set("race","�H��");
        
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say ������..������ڷ|����k��...."):),
		(:command("sigh"):),
		(:command("sob"):),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say �ڤ��঺�I���٦��S�������ơA�ڵ��藍�঺�I�I"):),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",100);
	set_skill("sword",100);

	set("talk_reply","�ڪ��ˤw�g�S�ϤF...���O�b�ڦ����e���󭫭n����...��...������...�y�y....�n��?");
	setup();

	carry_object(__DIR__"area/naboo/npc/wp/lasersword")->wield();
}

void init()
{
        int i;
        object ob;
        ::init();
        i= this_object()->query("max_hp");
        this_object()->set("hp",i*9/10);
        ::init();
        add_action("do_kill","kill");
        add_action("do_backstab","backstab");
        add_action("do_steal","steal");
        add_action("do_nod","nod");
       this_object()->set("hp", 170);
}
void do_nod(object obj)
{

            command ("say �h�³o��...�y�y...�o��ƻ��Ӹܪ�...");

            command ("sigh");
            command ("say �ڥ��O�K�P���D���ܥ�...");
            command ("say �o�]ť�H�p�H�����ӱN�K�P���������n�H�����F�X��!");
            

            command ("say �y�y....�S�Q�줤�~�J�W�F�K�P���D....");
            command ("say �L�S�o�{�ڰ��F�o�F���٫ܮ�Ԫ��۫ݧ�....");
            command ("say �ڳo�T�ߪ��ͪ��F��ȥL�o�{...");
            command ("say �y�y....�ڳ��M....�ڳ��M...");
            say ("�C�ֻ���@�b��M�y���ܱo�ܵh�W���ˤl....\n");

            command ("say �ڳ��M�X�L���`�N�ɱ��F�L!!");
            command ("say ���Ȧp��....�L�̤l���ӱϥL...���G��..���F�L���K�P��...���...");
            command ("cry");


            command ("say ��...���p�H�F�ڻ�...��o�F��...����o...���˪L...");
            command ("say �N��i�E�H�Ѯc...�o��ܰ��L�W���Z�L���D.......�y�y");
            command ("say �ڳ��M�̶̪��۫H�F.....�b�o���˪L��F�n�X�Ӥ�....");
            command ("say ���G....�Q�@�s���]���ǥ����o��......�y�y");


            command ("say �ڲ{�b�֦��F......�~�oı��ڳQ�F�F....�u�O�³J....���O��?");
            command ("say ���F....�@����....����....���F�ܥ�....���F�K..�K�P��....�P�O�F...��...�ڤ@�@���H...�y�y");
            command ("say ��..��..����..�]..���ா�^�F...�ܤ�...�⨺�H���ٵ�...�K�P��...�l�t...");
            command ("say �s..��..���L�v....�L�O..�K�P����..�j�̤l..�O�ɨ઺...�y�y");


            command ("say �p�G�A�J��....�ɨ�....�i�D�o....�R�藍�_�o....�藍�_�o...�y�y");
            this_player()->set_temp("quest/story",7);
            obj=this_object()->carry_object(__DIR__"obj/old_stone");
            if(obj->name()!="�j�Ѫ����J")
            {
               say ("�C�֮��X�@�ӥ��J�A�����J�o��M�Ƭ������I�I�u���C�֧b�b����ۤ�W�������C\n");
               command ("say �Ѥѳsū�o�����|�]������......�sū�o�����|�]������.....");
               say ("�C�ֻ��ۻ��ۡA�n���U�ӷU�C�L....�N�o��....�a�ۮ��릺�F....\n");
               ::die();
             }
               else
             {
               command("give stone to " + this_player()->query("id") );
               command("say ���U�A...�F.....�o��....���`��....�F�F...���@...");
               say("�C�ֻ����A�@�x���ۤv�����F\�\\��\���I�I�C�֦��F....\n");
               ::die();
              }
 
}
void do_last()
{  
  int dex,dodge;
  object me;
  me=this_player();
  dodge=me->query_skill("dodge");
  dex=me->query_dex(); 
  if((dodge+dex)<random(70))
  {

     message_vision(HIG"
              �C�ֱN�������O�q������C�W�A�ĤO�V$P���h�I�I
              �u��$P�{�����ΡA�@����C���N$P�s�H�a�Ҩ��I\n"NOR,me);
     me->die();
     say (GRN"�C�֤@�ۨϥX�A�K�����ʡA���O���F�A�����ۮh�H�������b���a�C\n"NOR);
     ::die();
   }      
	else{
        message_vision(RED"\n�C�־ĤO�@�������A����R��ƤɡA�^�˦b�a�C\n"NOR,me);
 	me->start_busy(7);
        say (HIR"�C�֫�몺���D�G�u�Ѥ��a��@�@�A���ũR�󦹡C�����ڡI�����ڡI���O�o�F��ڵ����|�������J��H�⤤�I�I�v\n"NOR);
        say (HIR"�C�֯��_�Ӥj�q�@�n�I���Ⱚ�|�V�ѡA�N�o�˯���...���F...�u���L�⤤\��\�U\�\\�h�ۮh�A�H�ۦ護�j�V�ѻڡC\n"NOR);

        ::die();
        }
}
int do_kill(string arg)
{ 
  object obj;
  obj=this_object();
if (arg != "yen" && arg !="yen-eu" )  return 0;
  if(!this_player()) return 1;
   if(environment(this_player())!=environment(obj)) return 1;
  say ("�C�֫r��ְ���۹D�G�u�i�c����l�I�ڴN�⦺�]�����}�A��A�I�I�I�v\n");
  do_last();
}  

