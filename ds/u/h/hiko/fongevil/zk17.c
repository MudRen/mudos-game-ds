inherit ROOM;
void create()
{
        set("short", "�s�����L");
        set("long",@LONG
�A����s�����L�a�A���e�Ҩ����O���t����L�A�B�٦������}�}�jŧ
�K���A�o�X��㪺���n�A���A�Pı�򰩮��M�A�譱��h���G���ӿ��A��
�����̬O�����򪺡A��_���O�@���s�L�C
LONG
        );
  
set("exits", ([
  "west" : __DIR__"zk13",
  "northwest" : __DIR__"zk16",
  "southwest" : __DIR__"zk18",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 

