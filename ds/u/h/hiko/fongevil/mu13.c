inherit ROOM;
void create()
{
        set("short", "�b�s�y");
        set("long",@LONG
�o�̤w�g�O�b�s�y�F�A�b�A���e���ۤ@����ΡA���M����²��o��
��T�A�i�H�ݱo�X�ӫسy���H�������륩�A������װž���A�ݨӫD
�`���H�Pı�ΪA�A��b���a���H�ӫܷR�M���A�n�䪺���q���s�U�C
LONG
        );
  
set("exits", ([
  "enter" : __DIR__"yu_home",
  "southdown" : __DIR__"mu12",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





