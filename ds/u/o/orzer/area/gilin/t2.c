inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A�Ө�F�˪L���谼�A�o�̪�����쳣�@�L���O�A�Pı�N���O��
�`���ˤl�A�|�P������I�I���A���G�����ۦ��a�ä��O����n�a��A��
�ަp���A�]�٬O���@�N���A����i�H�~��e�i�C
LONG
        );
        set("exits", ([
  "west" : __DIR__"t3",
  "northeast" : __DIR__"t1",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}







