inherit ROOM;
void create()
{
        set("short", "�s���Ŧa");
        set("long",@LONG
�o�O�@���s���p�|�A�F���@���������s���A�ݨӤQ�������q�J���A�i�H
�Q���L�k�k����W�A�Ӥp�|�Ǫ���L�K���Z�K�A���M�L�~�����벴�A�o����
�L�k���z�䤺�A�F�_��@���·t�A���G�O�@���s�L�C
LONG
        );
  
set("exits", ([
  "northeast" : __DIR__"zk17",
  "southwest" : __DIR__"zk19",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}

 


