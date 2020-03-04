#include <ansi.h>

inherit NPC;
void create()
{
        set_name("�ѤH",({ "old man","man" }) ); 
        set("long","�@�ө~��b�y�������ѤH�A�ڻ��L�~���ɦ��G���L���֪����W�A\n"
                   "�n���٥h�L�ǻ��������ޡA���L�o�Ǧh�b�L�k�d�ҤF�E\n");
        set("race","�H��");
        set("title",HIR"�y����"NOR);
        set("age",60+random(20));
        set("level",25);
        set("attitude","friendly");

        set_skill("dodge",50);
        set_skill("unarmed",50);
        set_skill("parry",50);
      
        set("chat_chance_combat",80);
        set("chat_msg_combat",({
                                (:command,"say �ڥi�O�ѷ�q���O�I�Q�ոլݶܡH":),
        }));
        set("chat_chance",20);
        set("chat_msg", ({
                          (:command("sing") :),
                          (:command("yawn"):),
        }));
        setup();
        add_money("coin",500+random(500));           
        set("talk_reply","�p�G�A�P�ڥ�� <say> �|�o�{�N�Q���쪺������I\n");
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
  object who = this_player();  if( !userp(me) ) return;
  if( me == this_object() ) return;
  if(strsrch(str,"���W") != -1)
  { 
    command("oh"); 
    command("say �ڦb���޸̱��F���֪����W�O�I"); 
    command("think");  }   
  if(strsrch(str,"����") != -1)
  { 
    command("fear"); 
    command("say ���쨺�ڴNı�o���ơI"); 
    command("say ���̥i�u���O�Ӹ޲����a��O�I");
    command("say �̭����ۤ����W�A�B���W�A�ƪ��W�A�r���W�A�٦��N�O�������g�c�I");  }   
  if(strsrch(str,"�����W") != -1)
  { 
    command("fear"); 
    command("say �����W��.."); 
    command("say ���i�O�|������L���H�Q�X���V��..");
    command("say �ڨ��W�N�ٯd�۳Q�N�˪�����..");
  }   
 if(strsrch(str,"�B���W") != -1)
  { 
    command("fear"); 
    command("say �B���W��.."); 
    command("say ���i�O�|��J�I�̦R�X�H��A���L�᪺�I�ѷm�a��..");
    command("sigh"); 
    command("say ��ڦP�檺�H�A�N���@�ӳQ�����F..");
  }   
 if(strsrch(str,"�ƪ��W") != -1)
  { 
    command("fear"); 
    command("say �ƪ��W��.."); 
    command("say �d�U�O�S�쥦�I");
    command("say �n�O�L�o�_�ƨӡA���i�O�ܮ��ƪ��O�I");
  }   
 if(strsrch(str,"�r���W") != -1)
  { 
    command("hmm"); 
    command("say ����b��..�r���W..�ڤ]�٨S���L�O.."); 
    command("say �o�O�ڬݦa�W��������G���ۤ��r����H�Ӱ�������..");
  }   
 if(strsrch(str,"�g�c") != -1)
  { 
    command("say ���ޥ����N�O�Ӥj�g�c��.."); 
    command("say �ڥ��S�@�w���i�`..�ڭ̭n�X�o�e�ݤF�n�X�ӤH..�L�̪����k�����ۦP..");
    command("say �ӥB�b�����ɭԡA�ٷ|���}�}����{���A�d�o�A�Y��������..");  
    me->set_temp("can_enter",1); }   
 if(strsrch(str,"���k") != -1)
  { 
    command("say �N��A�������@�ˤF��.."); 
    command("eh " +who->query("id"));
 }   
 if(strsrch(str,"�P�檺�H") != -1)
  { 
    command("hmm"); 
    command("say ��ڭ̤@�_�X�o���H�A�u�Ѩ�ӤH�^�ӡA�@�ӴN�O�ڡA�t�@�ӴN�O�o�ӧ����^��..");
 }   
 if(strsrch(str,"�^��") != -1)
  { 
    command("oh"); 
    command("say �L��E���������L�{�ٯu�O��m�ڡI�A�S�ݨ�u�O�ӥi���F�I"); 
    command("say �̫�L�٩ޤU�F�E�����@�������O�I");
 }   
return;
}

