inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A����F�˪L����n��A���e�ݥh���G�@���g��A�Q�����@�p����
���B����A�ݤ��M�e��쩳���ۤ���F��A���G������O�q�v�T�۳o��
�����i�H�ݨ�����M�@�ѴH���ۡA�Pı������O�q����۴H��L�k��
�����X�i�X�ӡA�o�̦���Ӧu�áA�ݨӬO�L�k�e�i�F�C
LONG
        );
        set("exits", ([
  "south" : __DIR__"t10",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











