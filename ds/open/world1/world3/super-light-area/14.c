inherit ROOM;
void create()
{
     set("short","�׷������y�Ĥ@�h�z");
      set("long",@LONG
�o�̬O�����ƪ��׷����𪺲Ĥ@�h�A�ܩ��㪺�o�̪������H���O�d�~
�e���ʦ~���H��u�ۡA�ݨӳ����Ӧn�S�A�A�N�|���J�i�h�������Ҧa�A
�O���y���ڰ򪺤H�m�\�Ϊ�....
LONG);
set("exits",([
       "down":__DIR__"13.c",
       "up":__DIR__"15.c",
]) );
set("objects",([
__DIR__"npc/lv2_king"    :1
]));
        set("world", "future"); 
setup();
}
