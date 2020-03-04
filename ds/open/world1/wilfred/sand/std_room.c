// �o�O�n�@���~����, ���񿪥۰}����  wilfred@DS

#include <ansi.h>
#include <room.h>
inherit ROOM;

string find_item();

void setup()
{
  ::setup();
  set ("short","���w�q");
  set ("long","���w�q");
  set("no_clean_up", 0);
  set("no_recall",1);
  set("index",0);
}

void change(int index)
{
// �쥻�� mapping �����G���󳣫��w������ƪ��ƪk, �u�n��Ψ�� string �}�C�ӧ@

  string *str1 = ({
"���w�q",HIW"����"NOR,HIC"�S��"NOR,NOR""WHT"����"NOR,HIY"���"NOR,
HIW""BLK"�[��"NOR,HIB"�_��"NOR,HIR"����"NOR,HIG"�I��"NOR
});

  string *str2 = ({
"\n���w�q\n\n",
"\n�o�O�@�Ӭ۷���G���a��A�զ⪺���u�X�M���벴�C\n\n",
"\n�@�}�}�D���j�L�ӡA�O�H�믫���ġA�ݨӳo�̬O�𮧪��n�a��C\n\n",
"\n�o�̬O�@����A����O�Ȧ⪺�A�O�H�Ǵe�C\n\n",
"\n�񲴥|�g�ɬO�g���⪺���ۡA�ݨӨS����M�I�C\n\n",
"\n�ﭱ�ӨӪ��O���N���®�A�X�G���⤣���L���C\n\n",
"\n�o�̹p�n�����A�����٦��p���q�y�|�B�y«�ۡC\n\n",
"\n�o�̥|�B���U�N�۩_�������K�A�䰪���O�H�߯�����C\n\n",
"\n���B�ɬO�d�h�A�����٦���⪺����Q�X�A�O�H�@�áC\n\n"
});

  set("index",index);

  set("short",str1[query("index")]);
  set("long",str2[query("index")]);
}

void init()
{
  object me = this_player();
  int index = random(10)+1;
  int i, damage;

  delete("item_desc");
  me->start_busy(1);
  if(!living(me)) return;
  switch(query("index"))
  {
    case 1 : if(!random(5))
             message_vision(HIW"�b�����B��������M�{�F�@�U�A�^�^�@�h���A���G�ݨ�@�ӻȦ⪫�~�H\n"NOR,me);
             set("item_desc",([ "�Ȧ⪫�~" : (: find_item :) ]));
             break;
    case 3 : message_vision(NOR""WHT"�����M�ɺ��_�ӡI$N�@�Ӥ��p�ߡA�Q�R�˦b�a�A�n�b�Ѫ����_�ӡI\n"NOR,me);
             me->start_busy(7);
             break;
    case 6 : message_vision(HIB"�z�a�I��"+chinese_number(index)+"���q�y�µ�$N�ĤF�L�ӡA$N�o�򦳧l�ޤO�H�I\n\n"NOR,me);
             for(i=0;i<index;i++)
             {
               damage = random(20)+1;
               message_vision(HIB"$N�G�D�q�y�����A�Q�q�o�z�z�j�s�I ("+damage+")\n"NOR,me);
               me->add("hp",-damage);
             }
             call_out("tender",10,me);
             break;
    default : break;
  }
}

int room_effect(object me)
{
  if(!living(me)) return 1;
  switch(query("index"))
  {
    case 2 : if(!random(4))
             message_vision(HIC"�@�}�D���j�ӡA�j�b$N���y�W�A$Nı�o�믫�n�F�\\�h�C\n"NOR,me);
             if(me->query("maxhp") > me->query("hp")) me->add("hp",20);
             break;
    case 7 : message_vision(HIR"$N��פ������A�Q�N�o�ֶ}�׺�I\n"NOR,me);
             me->add("hp",-30);
             me->apply_condition("blooding", me->query_condition("blooging")+5);
             break;
    case 8 : message_vision(HIG"$N���p�ߧl�J�F�@�I������A�n���Y������I\n"NOR,me);
             me->add("hp",-30);
             me->apply_condition("poison", me->query_condition("poison")+5);
             break;
    default : break;
  }
  return 1;
}

string find_item()
{
  object me = this_player();
  if(random(3) || me->query_temp("find_item"))
  {
    message_vision(HIW"$N�J�ӱ�h�A�o�{��ӥu�O�����Y�C\n"NOR,me);
    this_object()->delete("item_desc");
    return "";
  }
  message_vision(HIW"\n$N�o�{�@�ӻȦ⪺�c�l�I�I\n\n"NOR,me);
  new(__DIR__"npc/obj/obj22")->move(this_object());
  this_object()->delete("item_desc");
  me->set_temp("find_item",1);
  return "";
}

void tender(object me)
{
  if(!me) return;
  if(me->query("class1") == "�ⶳ�x")
    message_vision(HIW"\n�y�F�I�I�z$N��M�S�Q�@�}��p�����A$N�����Y��M�G�F�_�ӡI\n\n"NOR,me);
  else
    message_vision(HIB"\n�y�F�I�I�z$N��M�S�Q�@�}��p�����A�Q�q�o�����o�¡I\n\n"NOR,me);
  me->add("hp",-100);
  return;
}
