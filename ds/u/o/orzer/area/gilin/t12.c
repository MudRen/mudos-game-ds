inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�Ө�F�˪L���F���A�o�̪�����쳣�@�L���O�A�Pı�N���O��
�`���ˤl�A�|�P������I�I���A���G�����ۦ��a�ä��O����n�a��A��
�ަp���A�]�٬O���@�N���A�F��M�_��i�H�~��e�i�C
LONG
        );
        set("exits", ([
  "north" : __DIR__"t20",
  "southeast" : __DIR__"t13",
  "southwest" : __DIR__"t1",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








