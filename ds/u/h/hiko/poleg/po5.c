inherit ROOM;
void create()
{
        set("short", "�y������f");        
        set("long",@LONG
�A�ݨ�@�s���Ҧb�V�O�u�@�A�ݨӳo�̤w�g�O��f�F�A��B�O�@��
�����M�@�Ǥu��A�a�W�]���@�ǦH�誺���Q���b�a�W�A�i�H�D��@�p
�����{���A�_��O�y��������f�A����h�O���|�A���|�O�ݩ�@�غ���
�̹ε�������A�i�H�@�_�����~�ĩM�ѨM�ưȡC
LONG
        );
        set("exits", ([
  "north" : __DIR__"po6",
  "south" : __DIR__"po4",
  "west"  : __DIR__"po5w",
]));
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
        replace_program(ROOM);
}



