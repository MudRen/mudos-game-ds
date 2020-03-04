// Room: /u/l/luky/room/pearl_37.c
inherit ROOM;
void init();
void create()
{
set("short", "[1;32m�׹D�|�j�U[m");
set("long", @LONG

�u�l��b�j�U���j�z�ۦa�O�W�o�X�M�ܪ��u�ذաA�ذաv�^�T�A
�ۦW�����]�Ԫ���(Figure)�N��b���B�W��A�L�k��ɪ��|�����]�G
���ۺ��J���t���~���C�m����(Window)�A�i���O�@���_���ɻE��ǡA
���L�o�̳̯�ޤH���������L������@�ƪ��j���F...

LONG
);
set("objects",([
__DIR__"npc/academician":1,
]));
set("exits", ([ /* sizeof() == 1 */
"up" : __DIR__"pearl_40",
//  "down" : __DIR__"pearl_41",
"east" : __DIR__"pearl_25",
"west" : __DIR__"priest",
]));

set("item_desc",([
"figure":@NOTE
�ǻ�����l�Ԫ��������ϡA�b�׹D�|�ئ����e�Ф@��u�H�ɩ�(Sala)
�J�s�Ӧ��A���ǼC�]���G�Ƹ�L�������s..
NOTE
,
"window":"�m������@�V�O�а󤤤��i��ʤ����A���L���B���I�S�O�A�W��
�yø�F�\\�h�ǻ������G�ơC\n",
"clock":"�o�@��ƪ������G�S������������_�詵���A���@�@�[�ध��
�A�����@�y�`�Ŧ⪺��(blue_clock)�������o�X�_�Ǫ��n���H\n",
"�j��":"�o�@��ƪ������G�S������������_�詵���A���@�@�[�ध��
�A�����@�y�`�Ŧ⪺��(blue_clock)�������o�X�_�Ǫ��n���H\n",
"blue_clock":"�o�y�Ŧ⪺���ݨӤ]�L�S�O�A���ť�������n(sound)�i��O��ı�a�C\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
set("hour",11);
set("min",46);
set("time",0);
}

void init()
{
 add_action("do_listen","listen");
 add_action("do_checkt","checktime");
 add_action("do_time","settime");
}

int do_listen(string arg)
{
 object me;
 me=this_player();
 if(!arg) return notify_fail("�A�nť����?\n");
 if(arg=="sound")
 {
  message_vision("$N�����Ŧ�j������Τ�ť�F�@�|��C\n",me);
  write("�A�o�{�o�������n���������L�����C..�ӥB����j�n.. �A�J�Ӥ@��.. \n");
  write("��o�����S���譱.. �ɰw�M���w���i�H�H�N�ó](settime)..�A�i�H�ݬ�\n");
  write("�ثe�o�����]�w���ɶ�(checktime)�C\n");
 }
 return notify_fail("�Ať�F"+arg+"�b�Ѥ]ť���X����߱o�C\n");
}

int do_checkt()
{
 int hour,min;
 hour=query("hour");
 min=query("min");
 write("�{�b�������ɶ��O "+hour+"�I"+min+"���C\n");
 return 1;
}

int do_time(string arg)
{
 object me,paper;
 string arg2;
 int num,min,hour,time;
 me=this_player();
 if(!arg) return notify_fail("�榡: \nsettime hour [�Ʀr]\nsettime min [�Ʀr]\n");
 if(sscanf(arg, "%s %d", arg2, num)==2)
 {
  if(arg2=="hour") 
  {
   if(num>12 ||num<1) return notify_fail("�A�a�����~���o�خɶ��a?!\n");
   set("hour",num);
   message_vision("$N�����Ŧ�j���e�����F���w�@�U�C\n",me);
   write("[�دY!] �ɶ��]�w�����C\n");
  //call_out("checkt",1);
  } 
  if(arg2=="min")
  {
   if(num>60 ||num<0) return notify_fail("�A�a�����~���o�خɶ��a?!\n");
   set("min",num);
   message_vision("$N�����Ŧ�j���e�����F���w�@�U�C\n",me);
   write("[�دY!] �ɶ��]�w�����C\n");
  // call_out("checkt",1);
  }
  hour=query("hour");
  min=query("min");
  time=query("time");
  if(time==0 && hour==7 && min==7) set("time",1);
  if(time==1 && hour==6 && min==3) set("time",2);
  if(time==2 && hour==12 && min==0)
  {
   if(paper=present("paper",me))
   {
    message_vision("$N���X�Ȥ��ӵۤW�����: �|��L��, ���[�ɪk, �Ѧa����, �ѧڮt��!!\n",me);
    message_vision("$N�⤤���Ȥ��r�M�Ƭ��@�D�ť�.. �g�J�F�j������!!\n",me);
    destruct(paper);
    message_vision("[1;33m\n\n���㾴�㾴�㾴�㾴����\n[37m��M�����������T�F�_��!!\n[m",me);
    message_vision("\n  �Ŧ⪺�j���w�w���V�Ჾ�ʡC�X�{�F�@�Ӧa�}!! \n",me);
    set("exits/down", __DIR__"pearl_41");
   } else 
   {
    message_vision("$N�Ŧ�j���̤F�@�U�C\n",me);
    write(" �A�Pı���G�O�֤F����B�J��..\n");
    set("time",0);    
   } 
  }
  return 1;
 }
 return 0;
}

