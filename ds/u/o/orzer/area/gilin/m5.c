inherit ROOM;
void create()
{
        set("short","�s��");
        set("long",@LONG
�o�̦A���e���N�O�p�Y�F�A����ۤ�a�դ���ɱסA�]���H����
�����M���U�h����ı�A�]���ܮe�����p�߽�šA�ݨ����ӧ֭n���X�p�|
�~�F�A�e��D���e�s�F�I�C
LONG
        );
        set("exits", ([
  "northdown" : __DIR__"m5-1",
  "southwest" : __DIR__"m4",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}




