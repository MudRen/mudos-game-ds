inherit ROOM;
void create()
{
        set("short","���F�˪L�F��");
        set("long",@LONG
�A�~��V�˪L�F���ڶi�A�˪L���N�s�ʪ��]���ᬰ���M�`�A�ϩ���
�Ӵ˪L������F�A�G�A�|�P������I�I���A�o�˪��˪L��b�O���H����
�_�l�A�]���]���A�Q�@�d�s���A�F�_�M�n���U���@�����C
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t15",
  "northwest" : __DIR__"t12",
  "south" : __DIR__"t14",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}








