inherit ROOM;
void create()
{
        set("short", "�p�|");
        set("long",@LONG
�A���b�@���p�|���A�譱�O�s���������a�V�A�ݨӮ�~�O�H��߰ʾz�A
�p�|�������ܱT�򤣼e�A���A�n��`�N�}�U��e�i�A�Ӧ�_���@�ӪŦa�A��
�ӥi�H�e�h��ͤ@�U�A���F�n��i�ݨ�@���p���C
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"zk4",
  "southeast" : __DIR__"zk2",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 

