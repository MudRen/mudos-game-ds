inherit ROOM;
void create()
{
      set("short","�׷������y�ĤT�h�z");
      set("long",@LONG
�o�̪����n����o�����F�A��ӪŶ��n����ɥ��V�b�@�_�A���O����
�L�����۹ҡA��M�@�n���񦡪��z���}�a�F�o�@�������R�A�@���Z�˪�
�����X�Ĩ�A���e�A�b�A���e�ۤƦ��@�������H�A�צ�F���W���ӱ�C
LONG);
set("exits",([
      "up":__DIR__"17.c",
      "down":__DIR__"15.c",
] ) );
set("objects",([
__DIR__"npc/lv4_king"        :1,
]));
set("outdoors","land");
        set("world", "future"); 
setup();
}
