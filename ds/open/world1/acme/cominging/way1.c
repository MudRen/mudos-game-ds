inherit ROOM;

void create()
{
	set("short", "���D");
	set("long", @LONG
�A����o�A�o�{�٬O���ǩx�L���ʡA���ɦ��ǥ����e�ӥӭޡA�Ϊ�
�O���A���a�ۤj�c�����ȯ]�_�e�Ӱ^�m�A�٦��ǸH�ȱ��b�a�W�A�o��
�]�S�H�ߡC
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"way2",
  "south" : __DIR__"bigdoor",
]));
	set("no_clean_up", 0);
	set("item_desc",([
]));
        set("light",1);
	setup();
	replace_program(ROOM);
}
