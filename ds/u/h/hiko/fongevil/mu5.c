inherit ROOM;
void create()
{
        set("short", "�s�D");
        set("long",@LONG
�o�̤w�g�O���q�s�W���D���F�A�Pı���G�٭n���@�q�ɶ��A�i�O�u��
�����Ҥ����A���A�߱��ٺ�r���A�]�����ӻᬰ���Z�A�ݨӭn��s�W�ӥi
�`�٤��֮ɶ��A��_�䦳�@�������s�W�A�n��h�O���s�y�C
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"mu6",
  "southdown" : __DIR__"mu4",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





