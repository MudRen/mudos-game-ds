inherit ROOM;
void create()
{
        set("short","�s�D");
        set("long",@LONG
�A���b�s�D�W�A�oı���a�n�����H�׾�L�A�s�D�W�٦��۶��A�ݨӦ�
�a�H�e�Ӧ��i�椰��ơA�n�Q�Ψ�s�D�ӹB�e�F��A�i��O�j�N���A��
�_����h���ۤ@�ﳥ�L�A�n�䦳�ۨ�����e�C
LONG
        );
  
set("exits", ([
  "north" : __DIR__"zk23",
  "southeast" : __DIR__"zk14",
  "southwest" : __DIR__"zk8",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




