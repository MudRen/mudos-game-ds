// xiuxishi.c �𮧫�
// Java Oct.10 1998

inherit ROOM;

void create()
{
	set("short", "�𮧫�");
	set("long", @LONG
�o�O���ܤj���ж��A���u�D�`���t�C�Ш��S�����\�O���F��A�u��
�����@�i�p��A���٩�ۤ@�i���B�o�εΪA�A���j�ɡA�ɤW���Q�Ȥ]��
�z�o����䪺�A�ݵ۴N���H�Q��ı�C
LONG	);
	set("exits", ([
		"east" : __DIR__"mudao02",
	]));

        set("objects", ([ /* sizeof() == 1*/
         "/open/world1/obj/pot" : 1,
        ]));      

	setup();
	replace_program(ROOM);
}
