inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A����F���˪L����_��e�i�A�w�g�i�H�����ݨ�L�����G���ӫ�
�v�A�����D�|�O����˪��H��b���a�A�Q�����ӬO�����Z���H�~�|���
��b�o�M���������˪L���A�o�̪��H��w�g�Y�����L�F�C
LONG
        );
        set("exits", ([
  "southeast" : __DIR__"t7",
  "northwest" : __DIR__"t9",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}










