// This is a room made by roommaker.
inherit ROOM;
void create()
{
 set("short", "�ʨ���");
 set("long",@LONG
�o�̶º����Q���A���򳣬ݤ���A�u���@�ǷL�z�����I�|�B�ƨ��ƥh�A
�ϩ��O�����@��A�C���w��A����ӡC�����V�ӶV�j�A�A���զ��]�]������
�����@�T�C�o�̪��ͪ��Q���u���A�䤤���F�R�������ʪ����j�ͪ��A�A��
�Y�֤w�g���ѦۥD���}�l�o�¡A�򴤵ۧA���Z���H�����H�ɳ��|�V�A�i�}��
�����P�R�r�~�C

LONG
);
 set("exits", ([ 
   ]));
 set("hide_exits", ([
  "north" : __DIR__"sea30",
  "south" : __DIR__"sea28",
  ]));
 set("no_clean_up", 0);
 //set("outdoors",1);
 setup();
 replace_program(ROOM);
}