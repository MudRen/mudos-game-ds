// shanlu2.c �s��
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�s��");
        set("long", @LONG
�e���n�����@�Ӥj�s���A����o�̡A���h�F�ǡA�����O�f��C
�譱�O�@���s�����s���A���æb�s���A�n�b�]���ٯu�ݤ��X�ӡC
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southwest" : __DIR__"shanlu1",
                "northup"   : __DIR__"cuipinggu",
        ]));
        set("objects", ([
                "/clone/medicine/vegetable/badou" : random(2),
        ]));

	set("coor/x", -3140);
	set("coor/y", 10);
	set("coor/z", 10);
	setup();
        replace_program(ROOM);
}
