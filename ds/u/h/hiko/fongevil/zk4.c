inherit ROOM;
void create()
{
        set("short", "�s���Ŧa");
        set("long",@LONG
�o�̬O�s�����Ŧa�A�|�P�ݨӤQ�����m�A�i�O�o���Q���h���p�g��A
�ݨӸӬO�ø����X�a�A���Ŧa�F���h�A���������G���@�ӿ��A������
�̬O�����򪺡A�F�_�䶳��·¶�A�ݨӬO�Ӥp�C�C
LONG
        );
  
set("exits", ([
  "east" : __DIR__"zk9",
  "northeast" : __DIR__"zk5",
  "southeast" : __DIR__"zk3",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

