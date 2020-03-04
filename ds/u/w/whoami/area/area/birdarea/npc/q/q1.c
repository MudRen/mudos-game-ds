#include <ansi.h>
inherit NPC;
void create()
{
        set_name("���I�a",({ "explorer" })); 
        set("gender", "�k��" );
        set("long","�@�ӱq�~�a�Ӧ������I�a�A���G�i�H�q�L���W�ݥX���֪������E\n");
        set("level", 10);
        set("age",38+random(8));
        set("chat_chance", 8);
        set("chat_msg", ({
           (: random_move :),
        }) );
        set("no_fight",1); 
        set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
        setup();
}

void init()
{
  add_action("do_no_ask","ask");
}

int do_no_ask()
{
  write("�Х� say <��ͪ��覡> �Ө��o�һݱ����C\n");
  return 1;
}

void relay_say(object me, string str)
{
  object ob = this_object();
  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"����") != -1)
  {
    command("think");
    if ( (this_player()->query("level")) >= 45 && (ob->query_temp("pe")) <= 1){
    command("sigh");
    command("say �o��j�L..�p�̦��@�ƬۨD..");
    message_vision
(YEL"���I�a���R�ڻ��ǻ������]��"HIW"�E"HIY"��"NOR+YEL"���n�X�{�b�o"HIW"�F�_"NOR+YEL"�A�L����..\n"NOR,me);
    message_vision
(YEL"���I�a���R�٬߱�o��j�L��N"HIW"�E"HIY"��"NOR+YEL"���ѡA�åB�N�����ּ��U���ڡI\n"NOR,me);
    } else {    
    command("dunno");
    command("say �ڨS���򱡳��i�H���A..�O�ӧ�ڤF..");
    }
  } 
  if(strsrch(str,"�E��") != -1)
  { 
    command("hmm"); 
    switch(random(10)){
    case 0..3:
    command("say ���i�O�@�ثܮ��ƪ��Ǫ�..");  
    command("say ���h�~�e���g�X�{�b�o�@�W�A���ɥi�u���O�H�����E�T..");   
    command("say ��ӥ��Q�@�ӭ^���ΫʦL�N�A�ʦL�F�_��..");  
    break;
    case 4..6:
    command("say ���i�O�@�ثܮ��ƪ��Ǫ�..");  
    command("say �����o�\\�h�ا��N..�����̵������٬O�ܨ��N..");  
    break;
    default:    command("say �����ӴN�b���񪺬}�̰ڡH");   
    command("say ����O�ڪ����������ܡH");  
    command("think");  
    break;    }
  } 
  if(strsrch(str,"��") != -1)
  { 
    command("hmm"); 
    command("say �S��..�ڴN�O�n������.."); 
    command("say �ܩ�ڭn���Ӱ�����..�o�A�N�������D�F.."); 
  } 
  if(strsrch(str,"�^��") != -1)
  { 
    command("think"); 
    command("say ���ӭ^���κɤF�������O�q�A���ӤF�@�ɪ��M��.."); 
    command("say �̫�]���F..�u�O�F���_���å�.."); 
  }  
  if(strsrch(str,"�ʦL") != -1)
  { 
    command("say �S��..�E����ɪ��T�Q�ʦL��F"); 
    command("say �ܩ�L������|�A�������F�L�ӡA�ڴN���M���F"); 
  }  
  if(strsrch(str,"�ܨ��N") != -1)
  { 
    command("say �E���`�`�Q�ΤH�ʪ��z�I�ܨ��������k..��H�F�i�}��..�l���L���O�q..");  
    command("say �n�O�A�ݨ���k�X�{�b���ӥX�{���a��..�O�h��..�L�N�O�E�������I�I");  
    this_player()->set_temp("can_k",1);
  }
  if(strsrch(str,"�}") != -1)
  { 
    command("say �}..�H"); 
    command("say �S����..�E�����ӴN�b�o���񪺬}�̰�..?"); 
    this_player()->set_temp("can_enter",1);
  }  
return;
}
int accept_object(object who, object ob)
{
        object tob, gift;
        tob = this_object();
        if( ob->query("id")!="fox fur" || query_temp("pe") ){
        command("say �ڤw�g���F��A���L�A�n���ڡA���٬O���U�a�E");
        command("smile");
        }else{
        set_temp("pe",1);
        command("say �u�O�ӷP�§A�F�A"+RANK_D->query_respect(who)+"�I\n");
        command("say �o�ӪF�赹�A�A�N��@�O���S�a�I");
        gift=new(__DIR__"scroll");
        message_vision("$N���X�@��"+ gift->query("name") +"��$n\n", tob, who);
        gift->move(who);
        call_out("delay",600,this_object());
        set("long","�@�ӱq�~�a�Ӫ����I�a�A���N�ۥL��W���֡C\n");
        }       
        return 1;
}

void delay(object tob)
{
delete_temp("pe");
        set("long","�@�ӱq�~�a�Ӫ����I�a�A���G�i�H�q�L���W�ݥX���֪������E\n");
        return;
}


