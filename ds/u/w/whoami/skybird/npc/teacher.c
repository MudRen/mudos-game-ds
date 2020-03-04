#include <net/dns.h>
#include <ansi.h>
inherit NPC;

string *teach_msg = ({
"�H���W���Q�G�g���A�H���Q�G�Ӥ�A���T�ʤ��Q���`�A�H���@���E","�H���W���T�ʤ��Q�@�ӥ޹D�A���G�b�Q�G���u���g�v�M���B������ߤW�E","�T�����x�ޡA�����X�����A�e���t�Ӥs�A�ӨR�X�[�ޡA�����P�����A�q�̨æC�ʡE",
"�X��Ϊk��A�X�I�Ϊk�I�A�T�ʤ��Q�ޡA���X�Q�G�Z�C",
"�v�f�p���F�A���p���⳷�A�_�歰�u���A����ж}���C�ܤH�i�Ǳ¡A��H�������C",
"���M���T�ʤ��Q�ӥޤ��h�A���X�o�Q�G�ӥޡA�u�n���m���B�西�T�A�N����f����v�F�C",
"�o�ǥ޹D�O�_�褧���ҶǱª��C�]���A�w�@��i�޹D�A�s���곣�i�H���}�C","�ܤH�i�Ǳ¡A��H�������A�N�O���A�u����е����Ǧn���̤l�A���O�n�̤l�A�N����ХL�C",
"�T���ޡG�ݩ󨬶����G�g���X�ޡA���O�@�ӫD�`���n���޹D�A�i�ΥH�O�i�A�]�i�ΥH�v�f�����n�޹D�E",
"���x�ޡG�O�������G�g���l�ޡA���b�}���ĤG���B�ĤT�����������o�Ӹ}�X�l�W�����A�̥D�n�i�ΥH�v���|�ϦB�N���{�H�E","�����ޡG�O�b��y�W�����⶧���j�z�g���X�ޡA��M����k�O�G���u�y�L�s���_�ӡA���x��ۦۤv����Ŧ�A���u�W�̰����o�@���g���u�N�٬��u�⶧���j�z�g�v�A�b�o�Ӹg���W������y�s�s�B���޹D�N�s���u�����ޡv�E",
"�X���ޡG�⶧���j�z�g����ޡA���n�d���޹D�A�O�b����W���@�ӫD�`�j���޹D�A��m�b�j����򭹫��������o�Ӫ�f�A��f�}�e���W���@�o�C","�X�[�ޡG�ݩ󨬤Ӷ��H�ָg���g�ޡA�u�������ѬP�Q�G�ޡv����3�ӻH�ָg���޹D�A�e���B�Ӥs�٦��X�[�A��m�b���~�諸���P���򵬪������E",
"�����ޡG�O�b�x�g���޹D�A�b�v���y�U�Y�㪺�ϯäW����A�O�@�Ӻ��j���޹D�A�����ޤW�����٦׫D�`���Ϋp�A�n�Ϋܪ����w�~����ަ�A�����ɭԬƦܭn�Ψ줻�o�����w�C",
"�����u�G���ֶ��x�g���X�ޡA�����e�U�観�@�����s�H���A�H���᭱���@�����A�s���u�����v�A����������]�N�O�@�Ӥp���Y�A�o�Ӥp���Y���e�U��A���Ӭ}�A�N�٤��������u�C",
"�q�̥ޡG�O�߸g�����ޡA�b��äW��@�o�A�]�N�O�����W�@�o����m�A���ޥi�H�v���u�����n���X�v�H�ξҴo���ݳo�@�����߲z�h������f�C","�C�ʥޡG�O�͸g�����ޡA�e��j����P�����A�ӭ�������b��ê��W����������t�N�O�o�ӥޡA�i�ΥH�v���Y�h�A�٥i�H�v���M���·��E",
});

void do_teach();
void create()
{
  set_name("�F�N�s",({"teacher"}) );
  set("long","\n");
  set("age",58);
  set("level",25);
  set("gender","�k��");
  set("race","�H��");
  set("chat_chance",30);
  set("chat_msg",({
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
  (: do_teach :),
  }));
  set("talk_reply","�Q�Ǧ����޹D�譱�����ѴN�Ч�(sit)�a�E\n");
  setup();
}

void init()
{
  ::init();
  add_action("do_sit","sit");
  if (this_player()->query_temp("do_sit") ) this_player()->delete_temp("do_sit");
  this_object()->set_heart_beat(1);
}

void do_teach()
{
  object ob = this_object(), *student;
  int i;

  if(ob->is_fighting() ) return;
 
  student = all_inventory(environment(ob));
  if( sizeof(student) < 1 ) return;

  command("say " +teach_msg[random(17)] );

  for(i=0;i<sizeof(student);i++)
  {
    if( userp(student[i]) && student[i]->query_temp("do_sit") )
    {
       if( student[i]->query_temp("netdead") == 1 ) continue;
       if( student[i]->query_skill("acupuncture_cognition") > 70 ) continue;
       if(random(4))
       {
         message_vision(CYN"���Ѯv���@�f�ܡA$N���G�Y���Ү��C\n"NOR,student[i] );
         student[i]->improve_skill("acupuncture_cognition",random(student[i]->query_int())+1);
         if (student[i]->query("class1") == "�ѱ���")
         student[i]->improve_skill("acupuncture_cognition",random(student[i]->query_int())*2);
       }
    }
  }
  return;
}

int do_sit()
{
  object me;
  me=this_player();
 
  if(me->query_temp("do_sit")) return notify_fail("�A�w�b�ǲߥ޹D�{���F�C\n");
  if (me->is_fighting() ) return notify_fail("�A�����ۥ��[�A�S�žǥ޹D�{���C\n");
  if(me->is_busy() ) return notify_fail("�A�����ۡA�S���žǥ޹D�{���E\n");

  message_vision("$N��F�ӪŦ짤�U�A�}�l�ǥ޹D�{���F�C\n",me);
  me->set_temp("do_sit",1);
  return 1;
}

