inherit ROOM;
void create()
{
        set("short", "�s�D");
        set("long",@LONG
�o�̤w�g�O���q�s�W���D���F�A�Pı���G�٭n���@�q�ɶ��A�i�O�u��
�����Ҥ����A���A�߱��ٺ�r���A�]�����ӻᬰ���Z�A�ݨӭn��s�W�ӥi
�`�٤��֮ɶ��A�_�䦳�@�������s�W�A�F�n��h�O�U�s�C
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu7",
  "southeast" : __DIR__"mu5",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





