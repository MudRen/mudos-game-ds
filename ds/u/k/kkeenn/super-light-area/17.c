inherit ROOM;
void create()
{
       set("short","�׷������y�ĥ|�h�z");
      set("long",@LONG
�o�̴N�O�ǻ������Ӽh�F�A�঳�����o�̪��H���O�g�LG�EH������
�ί��֡A�ݰ_�ӳo�䵹�H�@�ѱj�j�������P�A���O�|�P�ƨӰ}�}���P�֡A
�b�ж����������g�X�@��j��ե��A�q�ե����������X�@��ѨϡH
LONG);
set("exits",([
      "up":__DIR__"18.c",
      "down":__DIR__"16.c",
] ) );
set("objects",([
__DIR__"npc/lv5_king"        :1,
]));
set("outdoors","land");
        set("world", "future"); 
setup();
}
