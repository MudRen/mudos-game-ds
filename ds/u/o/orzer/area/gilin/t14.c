inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�Ө�F�˪L���F�n��A�o�̪����Q���}�֡A�Pı���ӹ�l����
�l�A�q�F�n��ǨӤ@�}�}�����n�A������F��b�I��ۧA�e�h�A�]�\��
�ӫe�h�ݬݡA�F�n���@�����i�H�~��e�i�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"t13",
  "southeast" : __DIR__"t28",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}










