inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�ݤF�ݥ|�P�`�Pı���F��b�ݵۧA�A�i�O�o�䤣��ӷ��Ҧb�A�o
���A�ߤ����I���ӽ��A�`���I���Ҥ��w���ˤl�A�ݨӭn�n�n���Q��k
�����o�ر����A�]���A���_�F�믫�A�~��V�˪L�e�i�C
LONG
        );
        set("exits", ([
  "northwest" : __DIR__"t19",
  "south" : __DIR__"t12",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








