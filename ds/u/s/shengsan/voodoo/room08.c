inherit ROOM;

void create()
{
	set("short", "�s��");
	set("long", @LONG
�۷�e�諸�s���A�A�i�H�ݨ즳�Ѯv���b�s�������оɱЮ{�̪Z���C
�b�A���e��ݨ�F�@���C�۶��A�۶����W�٦��@�ӵP��A���O�ѩ�Z��
�L���A�ݤ��M���W�����D�r�O�p��C
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	    "east" : __DIR__"room06",
	    "south": __DIR__"room07",
            "up"   : __DIR__"room09",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);

	setup();
	replace_program(ROOM);
}
