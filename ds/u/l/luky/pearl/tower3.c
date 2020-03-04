// This is a room made by roommaker.
#include <ansi.h>
#include <path.h>
inherit ROOM;

void create()
{
set("short", "������T��");
set("long", @LONG
�@���W�ӧA�ߨ�`�N��@�y�������J���C�o�@�y�������O�J�����J���D�`
���Ͱ�, �ݮݦp�ͪ��������Y���`���ۧA, �ϧA���ۥD���C�U�Y���׶}͢����
�u�C�o�̦��|�ӵ���åB���O��ǥ|�Ӥ��, �i�H�ܲM�����ݨ��P�����Ҫ���
�p, �O�ӫD�`�u�}���A����ҡC
LONG
);
set("objects",([
__DIR__"npc/towersoldier":2,
__DIR__"npc/towerleader":1,
]));
set("exits", ([ 
  "down" : __DIR__"tower2",
]));
set("item_desc",([
"statue":@NOTE
�@�Ӯ������W�b���J��, �J�����k���ۤ@�������⪺�ʪ�, �A�J�Ӥ@�ݤ~��
�D����ӬO�@���j�s��..�J���e����F�@�ӨѮ�(Table), �Ψө�m���~�C
NOTE
,
"�J��":@CNOTE
�@�Ӯ������W�b���J��, �J�����k���ۤ@�������⪺�ʪ�, �A�J�Ӥ@�ݤ~��
�D����ӬO�@���j�s��..�J���e����F�@�ӨѮ�(Table), �Ψө�m���~�C
CNOTE
,
"table":"�@�ӥ|�}���j�ۮ�, �W���٩�F�\\�h���p����..�ǩǪ�..\n"
"�γ\\�A�Ӧn�n���լd�ݬݡC\n",
"�Ѯ�":"�@�ӥ|�}���j�ۮ�, �W���٩�F�\\�h���p����..�ǩǪ�..\n"
"�γ\\�A�Ӧn�n���լd�ݬݡC\n",
]));
set("no_clean_up", 0);
setup();
 load_object(__DIR__"npc/halfshark1");
 load_object(__DIR__"pearl_12");
 load_object(__DIR__"pearl_1");
 load_object(__DIR__"pearl_8");
 load_object(__DIR__"pearl_10");
}

void init()
{
 object ob;
 ob=this_object();
 add_action("do_search","search");
 add_action("do_put","put");
 if(!ob->query("WarStart") && !ob->query("startcheck"))
 {
  ob->set("startcheck",1);
  call_out("war_check",50);
 }
}

int do_search(string arg)
{
 object me,obj;
 me=this_player();
 if(!arg) return notify_fail("�A�n�j�d����?\n");
 if(arg=="table" || arg=="�Ѯ�" || arg=="��l")
 {
  if(query_temp("cork")) return notify_fail("�A�S���o�{����F��.\n");
  write ("�A�o�{�F�@�Ӥ�c�l, �c�l�W���٦��@�Ӥp�}(Hole)�C\n",me);
  return 1;
 }
 if(arg=="hole" || arg=="�p�}" || arg=="�}")
 {
  if(query_temp("cork")) return notify_fail("�A�S���o�{����F��.\n");
  write ("�o�Ӭ}���j�p�M�s�~�l���~�f�j�p�t���h, �̭��n���äF����F��C\n",me);
  return 1;
 }
 return 0;
}

int do_put(string arg)
{
 object me,cork;
 mixed msg;
 me=this_player();
 if(query_temp("cork")) return 0;
 msg=({
  "\n�p��c�}�l�o�X�ǳ\\���D�u�n...�ḭ̂ʤF�_��!!\n"NOR,
  "\n�p��c:"+HIY+" ��.. �n���L��..�֨S��F..��..�����F��..\n"NOR,
  "\n�I! ���@�n.. ��c�Q���ӯ��H!! \n"NOR,
  });

 if(arg=="cork in hole")
 {
  cork=present("cork",this_player());
  if(!cork) return notify_fail("�A�S���o�˪F��.\n");
  message_vision("$N�γn��뻴�����c�l�W���p�}..\n",me);
  call_out("delay_msg",3,msg[0]);
  call_out("delay_msg",7,msg[1]);
  call_out("delay_msg",10,msg[2]);
  call_out("do_clone",11,me);
  set_temp("cork",1);
  destruct(cork);
  return 1;
 }
 return 0;
}

int delay_msg(string str)
{
 tell_object(this_object(),str);
 return 1;
}

int do_clone(object me)
{
  object obj;
  obj=new(__DIR__"npc/turtlef");
  obj->move(this_object());
  tell_object(this_object(),HIY"�@���j���t�C�C���q�}��������F�X��..\n"NOR);
  tell_object(this_object(),HIY"�j���t���D: �O���@�ӯʼw���å��ڪ��q��յ�������?!\n"NOR);
  return 1;
}

void war_check()
{
 object ob;
 ob=this_object();
 remove_call_out("war_check");
 if(ob->query("war")==2)
 {
  shout(HIC"\n\n �����ڭ���: "HIW" ��?! �٦��ܦh���H���b���a�W?? �ܦn!!!\n\n"NOR);
  shout(HIW"            ���ٵ�����?! ���ڭ̤@�f��⨺�ǦۥH���O���H����������!! ������..\n\n"NOR);
  new(__DIR__"npc/halfshark")->move(__DIR__"sand1");
  new(__DIR__"npc/halfshark")->move(__DIR__"sand1");
  ob->delete("war");
  ob->delete("startcheck");
  ob->set("WarStart",1);
  call_out("war_report",50);
 } else
 if(ob->query("war")==1)
 {
  shout(HIC"\n\n �����ڭ���: "HIW" �K�K�K... ���ӥi�c�����������ש󦺤F!!\n\n"NOR);
  shout(HIW"                 �ڰ��j���l����!! ���ڭ����}�o�Ӷ·t���㪺�a��, �h�j�֦��[�@�f�a!!! \n\n"NOR);
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_1");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_12");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_12");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_1");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_8");
  new(__DIR__"npc/halfshark1")->move(__DIR__"pearl_10");
  ob->set("war",2);
  call_out("end_war",600);
  call_out("war_check",150);
 } else call_out("war_check",50);
 
}

void war_report()
{
 object obj1, where1;
 remove_call_out("war_report");
 if(this_object()->query("WarStart"))
 {
  obj1=find_living("halfshark");
  if(obj1) where1=environment(obj1);
  if(!where1)
  {
   remove_call_out("end_war");
   shout("\n\n"+HIM"               �����@�ڥ����Q���^�����h�F\n\n"NOR);
   this_object()->delete("WarStart");
   return;
  }
  else
  {
   call_out("war_report",30);
  }
 }
}

void end_war()
{
 object obj1, where1;
 remove_call_out("end_war");
 remove_call_out("war_check");
 remove_call_out("war_report");
 this_object()->delete("WarStart");
 while(obj1=find_living("halfshark"))
 {
 	where1=environment(obj1);
 	if(where1)
 	{
   		message_vision("$N�j���X�n�K���}�F.\n",obj1);
	}
	destruct(obj1);
 }
 shout("\n\n"+HIM"               �����@�ںR���F������..\n\n"NOR);
 return;
}