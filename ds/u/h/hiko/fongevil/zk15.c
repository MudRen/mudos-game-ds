inherit ROOM;
void create()
{
        set("short","�s�D");
        set("long",@LONG
�A���b�s�D�W�A�oı���a�n�����H�׾�L�A�s�D�W�٦��۶��A�ݨӦ�
�a�H�e�Ӧ��i�椰��ơA�n�Q�Ψ�s�D�ӹB�e�F��A�i��O�j�N���A��
�F�n�M��_��h���ۤ@�ﳥ�L�C
LONG
        );
  
set("exits", ([
  "southeast" : __DIR__"zk16",
  "northwest" : __DIR__"zk23", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



