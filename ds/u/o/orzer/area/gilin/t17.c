inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�o�̤w�g�O�˪L�F�䪺�����A�Pı���۵L�n���R�q�P�A���G�w�R��
�����H���I�L�k�m�H�A�Aı�o���ǵL�k�ήe���޲��A�F�_�i�H�~�򩹪F
��e�i�A�F�n�h�O�^�Y�A���@�D�Y�����L���H�v�C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t23",
  "southeast" : __DIR__"t16",]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











