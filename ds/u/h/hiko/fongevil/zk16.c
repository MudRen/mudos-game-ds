inherit ROOM;
void create()
{
        set("short","�s�����L");
        set("long",@LONG
�s�L�����W���V����s�A�n�������Y�F�A�O�H���g��M�^��A�Pı�n
���|���������Ƶo�͡A�L���a�����פ����A���ӬƬ������A��_���@���s
�D�A�F�n�h�O���t���s�L�C
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"zk15",
  "southeast" : __DIR__"zk17",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}


