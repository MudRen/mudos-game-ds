// caoyuan4.c ���
inherit ROOM;
void create()
{
        set("short", "�j���");
        set("long", @LONG
�A���i�F�o�M�����������j���A�}�U�O�o�p���C��A�n�������ٯu
���n���A�ݨӶR�ǰ��ӥN�B��O���n�D�N�C
LONG);
        set("exits", ([
		  "south" : __DIR__"caoyuan3",
		  "west" : __DIR__"caoyuan5",
        ]));
        set("outdoors", "land");
        setup();
        replace_program(ROOM);
}
