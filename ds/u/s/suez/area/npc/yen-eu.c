//���G�ƪ�
#include <ansi.h>
inherit NPC;
void yen();
void create()
{
	set_name(HIG"�C��"NOR,({"yen-eu","yen"}) );
	set("long","�@�ӥ����O�˪��ѤH�A�Ⲵ�n���R���F����A�ݨ����������F�C\n");
	set("age",50);
	set("level",60);
	set("race","�H��");
        set("exp", 7000); //���M���Ű��A���O�u���|�����@��HP�A�ҥH���w�g��ȡC
                          //�]���k�N���M�i�H����A�G�ݭn�]�w�C
        
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say �ɨ�K�K�ɨ�K�K�K�K"):),
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

	set("talk_reply","�ڪ��ˤw�g�S�ϤF�K���O�b�ڦ����e���󭫭n���ơK�СK�����ڡK�y�y�K�n�ܡS");
	setup();

	carry_object(__DIR__"wp/yun-tsang")->wield();
}
void init()
{
        int hpx;
        ::init();
        hpx= this_object()->query("max_hp");
        this_object()->set("hp",hpx*1/4);
        add_action("do_kill","kill");
        add_action("do_backstab","backstab");
        add_action("do_steal","steal");
        add_action("do_nod","nod");
}
int do_nod()  
{
//      object me;
//      me=this_player();
//       if(me->query_temp("quest/story") > 0)     return    notify_fail("�ݨ�A�p���ۤߡA�C�֯h�Ϊ��y�W�S�X�w�������e�C\n");
       
      call_out("yen",1,this_object());
    

}
void yen()
{

 int i;
 object obj;
 i = this_object()->query_temp("del");
 obj = this_object();

 switch(i){

  case 0:
            command ("say �h�³o��...�y�y...�o��ƻ��Ӹܪ�...");

            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 1:
            command ("sigh");
            command ("say �ڴ��O�����@�ɪ��j�s�A�P��ɺK�P���D�ú٬P�v���١K");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 2:
            command ("say �Q�l�~�e�A�ڭǱO���F�t�~�@�s�j�H�A�o��F�@�i�O�����@�Z\�\\��\��\���K�y�T�y�T");
            say ("�C�ֻ���@�b��M�y���ܱo�ܵh�W���ˤl....\n");

            obj->set_temp("del",i+1);
            call_out("yen",5 ,obj);
            break;
  case 3:
            command ("say ���F�o�ӵ��@�Z\�\\�A�ڭ̪�O�n�X�~�ӴM��ݨ��Ѿl�������K�ש�o��F�@�ǽu���K");
            say ("�C�ֻ���o�̡A��M�@�P���y�F�_�ӡA�̫�y�X�F�@�j�f�¦�T\n");
            obj->set_temp("del",i+1);
            call_out("yen",5 ,obj);
            break;
  case 4:
            command ("say �K�K�K�ݨӧڤ]�����[�F�A�ݨӷ����F�n�ͪ����������`�����F�K");
            say ("�C�֬ݵ۪g��������x�Ϋe�̡A�S�X�F�@�٭W�ߪ����e�C\n");       
            obj->set_temp("del",i+1);
            call_out("yen",3 ,obj);
            break;
  case 5:
            command ("say �ڭ̬��F�o���n�_�ӡA�N�o�ˡK�p����ߪ��ڤ@�㤧�U���F�L�K�M�L���K�P���K");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 6:
            command ("say �ګ�����M�ᮬ�A�����@�Z\�\\��b�ӻ��H�F�K�ڴN�a�ۤ@�����o�c�X�ӴM��K");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 7:
            command ("say �����g�L�h�֭W���K�y�y�K�ٳQ���]�妨�o�ˡK�ש���F�ݨ��Ѿl�������ðΪ��a��K�K");
           say("�C�֤@�仡�@����ۨ��W�b�H���ˤf�C\n");
            command ("say ���G�o�o�{�F�覭�N�Q�O�H�����F�K�K�K");
           say("�C�ֻ��������j���_�ӡA���ۯ��۬�M�z�@�n�A�S�åX�@�j�f�A��C\n");
            obj->set_temp("del",i+1);
            call_out("yen",5 ,obj);
            break;
  case 8:
            command ("say �K�K�K�ɭԧ֨�F�K�K�o�̦��ӪF��K�·ЧA�K�K�N�o�ӥ浹�K�P�����l�t�K�K");
            obj->set_temp("del",i+1);
            call_out("yen",2 ,obj);
            break;
  case 9:
            command ("say �s�K���K���L�v�K�L�O�K�K�P�����K�j�̤l�K�O�ɨ઺�K�y�y�T�T");

            obj->set_temp("del",i+1);
            call_out("yen",7 ,obj);
            break;
  case 10:
            command ("say �p�G�A�J��K�ɨ�K�i�D�o�K�R�藍�_�o�K�藍�_�o�K�y�y");
            this_player()->set_temp("quest/story",7);
            obj=this_object()->carry_object(__DIR__"obj/old_stone");
            if(obj->name()!="�j�Ѫ����J")
            {
               say ("�C�֮��X�@�ӥ��J�A�����J�o��M�Ƭ������I�I�u���C�֧b�b����ۤ�W�������C\n");
               command ("say �Ѥѳsū�o�����|�]�����ڡK�sū�o�����|�]�����ڡK");
               say ("�C�ֻ��ۻ��ۡA�n���U�ӷU�C�L�K�N�o�ˡK�a�ۮ��릺�F�K\n");
               ::die();
             }
               else
             {
               command("give stone to " + this_player()->query("id") );
               command("say ���U�A�K�F�K�o�ˡK���`��K�F�K�F�K���@�K");
               say("�C�ֻ����A��M�@�x���ۤv�����F\�\\��\���T�T\n");
               ::die();
              }
 
            break;
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
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;
  say ("�C�֫r��ְ���۹D�G�u�i�c����l�I�ڴN�⦺�]�����}�A��A�I�I�I�v\n");
  do_last();
}  
int do_backstab(string arg)
{ 
  object obj;
  obj=this_object();
  if (arg != "yen" && arg !="yen-eu" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;
  say ("�C�֫r��ְ���۹D�G�u�i�c����l�I�ڴN�⦺�]�����}�A��A�I�I�I�v\n");
  do_last();
}  
int do_steal(string arg)
{ 
  object obj;
  obj=this_object();
  if (arg != "yen" && arg !="yen-eu" )  return 0;
  if(!this_player()) return 0;
  if(environment(this_player())!=environment(obj)) return 0;
  say ("�C�֫r��ְ���۹D�G�u�i�c����l�I�ڴN�⦺�]�����}�A��A�I�I�I�v\n");
  do_last();
}  