inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A�~�򪺫e�i�ۡA�o�̪��H�������z�A�]���A�Pı����ۦb����
�ͪ��]�ݰ_�Ӥ������A���D������F��v�T�F�˪L���޲��𮧡A�ݨ�
�O���H�b��ܴ˪L�����F��A�]���A�Q�ݬݹ��O�֡C
LONG
        );
        set("exits", ([
  "north" : __DIR__"t7",
  "southeast" : __DIR__"t3",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}









