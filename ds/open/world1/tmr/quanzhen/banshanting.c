// banshanting.c �b�s�F
// Winder Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "�b�s�F");
        set("long", @LONG
�o�̬O�b�s�y���@�Ӥp�D�F�A�C�ȭ̪��s�����֤F�A�N����s��
�o�̨ӧ��@���A���@���}�C�q�o�̬ݤU�h�A��n�i�H�ݨ��A�̮p���p
���C
LONG
        );
        set("outdoors", "zhongnan");
        set("exits", ([
                "southdown" : __DIR__"shijie5",
        ]));

        set("objects",([
                __DIR__"npc/youke" : 2,
        ]));

	set("coor/x", -3150);
	set("coor/y", 140);
	set("coor/z", 170);
	setup();
        replace_program(ROOM);
}