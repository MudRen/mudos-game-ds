inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�A���b�s���W�w�w���e�i�ۡA�ѩ�s���U�p�A�ҥH���ӤQ�������W
�A�өP��ݨӻᬰ��D�A�i��O�o�����H�s�E�~�B���������A�]���֦�
�H��A�e�����@�����W���p�|�C
LONG
        );
        set("exits", ([
  "northup" : __DIR__"m3",
  "southwest" : __DIR__"m1",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}



