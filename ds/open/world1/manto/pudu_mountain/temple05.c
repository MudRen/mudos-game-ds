inherit ROOM;

void create()
{
        set("short", "�Q�L");
        set("long", @LONG
�o���Q�L�n������x�A�_�ʰѤѤ����p�A����ѬO�U�V�`�W�C�Q�L��
�b��ŦӥX�C��괶��x�����Ҧb�άO�@���b��Ŧa�����C�N�檺�H����
�ƳQ�_�ݪ��ѩ��ҩڡA���B�Q�L���O������M�C�L���ذʡA�C�Q�n�̡A�o
�]ť����Q�ܤ��n�C
LONG
        );
        set("exits", ([ 
  "north" : __DIR__"temple08",
  "south" : __DIR__"temple04",
]));
        set("outdoors","land");
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
