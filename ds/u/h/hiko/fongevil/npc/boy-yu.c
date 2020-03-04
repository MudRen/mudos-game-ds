#include <ansi.h>
inherit NPC;
int go_way();
void create()
{
  set_name("�p�y", ({ "boy yu","yu" }) );
  set("gender", "�k��" );
  set("long",@LONG
    �Q���^�𪺤@�Ӥp�Ĥl�A��������Ӫ��A�����j�j��ꪺ�A���W
    ��ۤQ�����ݨӤQ���o�o�A�O�H�@�ݳ��w�W�L�A�i�O��������
    �ݨ�o�S���������ǡA�]�\�O�������a���C
LONG
);      
  set("age",12);
  set("level",10);
  set("race","human");
  set("go_home",1);
  set("chat_chance", 10);
  set("chat_msg", ({
(: command("say �u�n���r�A��B���O�S���L���F��O�C") :),
(: command("say �ݷݴN�O�R�~�H�A�ѬO�����H�X�Ӫ�") :),
(: command("say �X�Ӧn�ǤѤF�A�����D�ݷݷ|���|�ܥͮ��") :),
"�p�y���b�a�W�Q���ּ֪��۵ۺq�A�C\n",
(: command("hug") :),
(: command("say ť���a�̪��񪺶ø����W�����ǡA�����O����˪��O�A�u�Q�ݬݡC") :),
}));

  set("talk_reply","�~�����@�ɯu�n����A�R�R����ѬO���~���ܮ��ƩO�H\n");
  setup();
  set_living_name("outboy");
  call_out("go_way",60);
}

int go_way()
{
  object ob = this_object();
  if(ob->is_busy())
  {
    remove_call_out("go_way");
    call_out("go_way",10);
    return 1;
  }

  ob->set("go_home",0);
  command("say ��A�o�̬ݪ��t���h�F�A�ӥh�O�B�F�C");
  random_move();
  switch(random(4))
  {
    case 0 : command("say �h�ѫ�����ݬݳ³��n�o...");             ob->move("/open/world1/acme/area/farm1");
             command("say ��..�p�³���...");
             break;
    case 1 : command("say ť����s���Ӥs�}�A�ڥh�ݬݦn�o...");
             ob->move(__DIR__"../holl-n");
             command("say �z..�n�_�S����r�I");
             break;
    case 2 : command("say �B�F�����L�W�Ӧn���ܦn���A�ڥh�}�}�n�o...");
             ob->move("/open/world1/cominging/area/herohouse");
             command("say �u���[���a��I�����O�֪��ӧr�H");
             break;
    case 3 : command("say �y�ᨺ���n�l�����ͳJ�F�S�A�h�ݤ@�U�n�F...");
             ob->move("/open/world1/acme/area/backyard");
             command("say �j�T...�o�䪺�n�l�u�j���r..");
             break;
  }
  call_out("go_way",120);
  return 1;
}

int accept_object(object who, object ob)
{

  object npc=this_object();
  if(npc->is_busy() || npc->is_fight())
    return notify_fail("�p�y���G���b���C\n");
 if(ob->query("id") == "re letter" && who->query_temp("get_mission"))
  {
    if(npc->query("go_home"))
    {
      command("flop");
      command("say �ڤw�g�^�a�o�A�A���ڳo������O�H");
      return notify_fail("");
    }
    destruct(ob);
    command("say �o... �o�O���˪���Ѷ�");
    command("say �n�a�A���Q�A�����o�A�ڴN�^�a�@��");
    message_vision(HIW"\n[$N��^�a�h�F]\n\n"NOR,npc);
    remove_call_out("go_way");
    npc->move(__DIR__"../yu_home");
    who->delete_temp("get_mission");
    who->set_temp("pass_mission",1);
    npc->set("go_home",1);
    return 1;
  }
  else
  {
   if( ob->query("id") != "re letter")
     {
       command("say ���¤F�A�i�H���h�R�}�o�C");
       command("jump");
       destruct(ob);
     }   
   else
     {
       command("say �A�ݰ_�Ӧn���c�A�ڤ��۫H�A�C");
       random_move();
       return notify_fail("");
     }  
  }
}















