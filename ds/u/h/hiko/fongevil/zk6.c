inherit ROOM;
void create()
{
        set("short","����");
        set("long",@LONG
���a�O�Ѥs���j���j�k�y�������ءA�����ݨӦ��p�M�d�@��A�ӥB��
���������Z�A���_�Ӧ��p��b���a�A�i�O�����U�p�u�o�@�H�Ӽe�A���_��
�Ƭ����I�A�F�_�O�@�ﳥ�L�A��n�i�H�ݨ��@�y�p�C�C
LONG
        );
  
set("exits", ([
  "southwest" : __DIR__"zk5",
  "northeast" : __DIR__"zk23", 
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}




