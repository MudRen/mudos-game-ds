// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "�C�۵�D");
	set("long", @LONG
�@���ѫC�۾Q�]�Ӧ�����D�A��D�Ǧ��@�y�J���A��Ҩ蹺������
�O�������--�d�z���զաA���ޥu�O�@�y�J���A�o�]�ϤH�P������
�����Y�A����i�H�X���A�F�䤣���B���@�y�Q���C
LONG);
	set("outdoors", "land");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wood1",
  "east" : __DIR__"road13",
]));
	set("item_desc",([
	"�J��" : "�@�y�J���W�J��۷��վB���Ұ������v���C\n" ]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
