#include <ansi.h>
inherit SELLMAN;
inherit NPC;

void create()
{
  set_name( "����", ({ "sailorman"}));
  set("long", "�@�ӥ����}�꽴�Y������������A�y��ô�F���s�M�A�����F�@��\n"
             +"�j�|���U�A�ݼˤl���ӬO�Ƭy��o��Ӫ��A�L���b�|�B�°⪫�~�C\n\n"
             +"  �ݦs�f�Х� <list> \n"
             +"  �n�R�F��� <buy ���~> <buy �ƶq ���~> \n\n"
     );
  set("level",30+random(3));
  set("title","���Y����");
  set("gender", "�k��");
  set("race", "�H��");
  set("age", 42);
  set("combat_exp",30000);       
  set("evil",-30);              
  set_skill("blade",70);         
  set_skill("parry",40);    
  set_skill("dodge",60);   
  set("attitude", "peaceful");  
  set("talk_reply","�ȤH�ӶR�I�F��a�A���O�u�������~�r..");
  set("sell_list",([   
      __DIR__"eq/deerskin-gloves"  : 20, 
      __DIR__"eq/deerskin-boots"   : 20, 
      __DIR__"eq/cow-skin-hat"   : 20,  
      __DIR__"eq/feather-surcoat"   : 20,
      __DIR__"eq/sky-bead"   : 5,  
     ]) );
  set("chat_chance", 15 );  
  set("chat_msg", ({     
      "����ۨ��ۻy���D�G�������M�o�{�F"HIW"��@�q"NOR"�A���O�j�P��"HIW"���y"NOR"�o�ϱo\n"
     +"                  �㿴������}�H�A�ƴ��b�q�~�C\n",
      "����ۨ��ۻy���D�G�����D�䥦�H�ͦ��p��H�j�������k�@�T�a�C\n",
      "����E���a���D�G�S�̡̭�ڤ@�w�|�^�h��A�̪��D�D�B�P��B�P�P\n"
     +"                ���ڦY���D�D�@�w�D�D\n",
      "���⮳�X�@��"HIC"�Ŧ���Y"NOR"���D�G��D�D���I���l�F�A�����D�ٯण��ΡH\n",
     (:command("sigh"):),
     }) );
  set("inquiry/��@�q","����M�M�j���m�A���ɤT�~�A�b�F�����W�o�{���p�q�A\n"
                      +"�ڻ��O�W�j�ɥN�j���}���ϱo��y�s�}������ܦ��p�q�A�q�W�ͦs��\n"
                      +"�L�����H�Q�������~�A�ѩ��Ӯq�Q�s���]��A�N�⦳�H�o�{�o�Ӯq\n"
                      +"�]�����D�䤤���t���Ѧa�A�y�Ƥ��_�G�u���H�Q���C\n"NOR);
  set("inquiry/�ۦ�","�o�O�ڦb�q�W�ͬ����j�b�~�A�n���e���~��쪺��q�u��\n"
                    +"�A���a�o���_���ۦ�A�ڤ~��^��j���q�C\n"NOR);
  set("inquiry/���y","���ɫ᥻�Ӯ������R�L�i�A�֪��D��M�i�ܬ���A������\n"
                    +"�O���ͩR�����A�n���R���]���A��b�O�ӥi�ȤF�I\n"NOR);
  set("inquiry/�Ŧ���Y","�o�ӬO�ڪ��_���A������]���|��A���I���D���F�ڡI\n"NOR);
  setup();
  carry_object(__DIR__"eq/sea-stone");
  carry_object(__DIR__"eq/sailorman-blade")->wield();
}

void init()
{
  ::init();
  add_action("do_list","list");
  add_action("do_buy","buy");

  if(userp(this_player()))
  {
    message_vision(YEL"\n$N�Ӳ��n�����D�G��@�q�W���n�h�é_���~�A���e�̥��`���|���_\n"
                      "�ӡA�u�|�b�S����F��g�L�ɤ~�|�]�X�ӡC\n\n"NOR, this_object());
  }
}

int accept_object(object who,object ob)
{
  object obj,journal;
  obj=this_object();

  if(ob->query("id") == "captain's hat")
  {
    if(obj->is_busy() || obj->is_fighting())
      {
        command("whisper "+who->query("id")+" �ڨS�šA�O�ӷЧڡC\n");
        return 0;
      }
    message_vision("$N��������@�� "+ob->query("name")+"�A�û����b�}�]�ҵo�ͪ��ơC\n",who);
    command("sigh");
    message_vision("���⻡�D�G��Ӳ���]�J�`�F�C�o����x�O����@���ܭ������A�쥻\n"
                   "�n�ٵ�����A�{�b�گd�ۤ]�S�ΤF�A�N���A������a�C\n",who);
    obj->start_busy(2);
    destruct(ob);
    journal=new_ob(__DIR__"eq/red-journal");
    journal->move(obj);
    command("give journal to "+ this_player()->query("id") );
    return 1;
  }
  return 0;
}
