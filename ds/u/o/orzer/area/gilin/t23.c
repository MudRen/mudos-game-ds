inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�o�̤w�g�O�˪L�F�䪺�����A�Pı���۵L�n���R�q�P�A���G�w�R��
�����H���I�L�k�m�H�A�Aı�o���ǵL�k�ήe���޲��A�F��i�H�~�򩹳�
�F��e�i�A��n�h�O�^�Y�A���@�D�Y�����L���H�v�C
LONG
        );
        set("exits", ([
        "east" : __DIR__"t24",
        "southwest" : __DIR__"t17",
        ]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}












