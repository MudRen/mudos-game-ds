inherit ROOM;
void create()
{
        set("short","���F�˪L�谼");
        set("long",@LONG
�A�~��V�˪L�����ڶi�A�˪L���N�s�ʪ��]���ᬰ���M�`�A�ϩ���
�Ӵ˪L������F�A�G�A�|�P������I�I���A�o�˪��˪L��b�O���H����
�_�l�A�]���]���A�Q�@�d�s���A��_�M��n���U���@�����C
LONG
        );
        set("exits", ([
  "northwest" : __DIR__"t6",
  "southwest" : __DIR__"t4",
  "east" : __DIR__"t2",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}







