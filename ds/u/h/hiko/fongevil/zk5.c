inherit ROOM;
void create()
{
        set("short","�s���p�C");
        set("long",@LONG
�A�Ө�F�p�C�W�A�o�̵����Q���M���A�o�̵M�L�k�ݲM��Ӥs�^�A��
���@�h���t������B���A�����u�A�ϧA�P��L�k�F�ѡA�F�_��ݨӬO�ө�
�h���p�ءA�Ӧ�n�h�O�ӪŦa�C
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"zk6",
  "southwest" : __DIR__"zk4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

