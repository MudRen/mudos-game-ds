// Room: /open/world1/tmr/advbonze/hill14.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�ѱ�");
	set("long", @LONG
�A�����b�ⶳ�p�W�ӡu�W�ѱ�v�W�A�A�i�H�ݨ쩵�۩��_�ӳq��
�s�����@�`�@�`�ѵM�۱�A�A��_�F�Y���s����F�L�h�A�ݼˤl�u��
�U����T�Q�Ӷ����۱���C�ѩ󱵪�F�s���A�A���ɥi�ݨ�@���ն�
���������E�F�L�ӡC
LONG
	);
	set("current_light", 5);
	set("no_clean_up", 0);
	set("outdoors", "forest");
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill15",
  "southdown" : __DIR__"hill13",
]));

	setup();
	replace_program(ROOM);
}
