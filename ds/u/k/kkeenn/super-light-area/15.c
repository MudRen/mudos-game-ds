inherit ROOM;
void create()
{
      set("short","�׷������y�ĤG�h�z");
      set("long",@LONG
�o�̥|�P�R���ۤ@�Ѹ��Ԫ��𮧡A�ϩ��Ѧa�U�����b�o���ܪ��Ƿt�A
���`���z�O���G�b��өж��̡A�b�o�س����ͳJ���a��A���M���H�b�@��
�R�R���[��A�Q�o�̪���^�d���w�Y��V�A���G�ܪY��o�صh�W�����I
LONG);
set("exits",([
      "up":__DIR__"16.c",
      "down":__DIR__"14.c",
] ) );
set("objects",([
__DIR__"npc/lv3_king"      :1
]));
set("outdoors","land");
        set("world", "future"); 
setup();
}
