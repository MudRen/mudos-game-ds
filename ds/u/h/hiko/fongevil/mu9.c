inherit ROOM;
void create()
{
        set("short", "�s�D");
        set("long",@LONG
�A�w�g�i�H�����ݨ�s�Y�F�A�ݨӸӬO�֨�s���F�A���M�H���j����
�A���ǩ_�ǡA�Ѯ𳺵M�����ܤơA�O�Aı�o�n�����j�ǡA�ݨӤs�W�]�\��
���M�`���F��A�_�䦳�@�������s�W�A�n��h�O�U�s�C
LONG
        );
  
set("exits", ([
  "northwest" : __DIR__"mu10",
  "southdown" : __DIR__"mu8",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}
 





