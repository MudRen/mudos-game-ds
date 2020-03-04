// Room: /open/world1/tmr/advbonze/hill8.c

inherit ROOM;

void create()
{
	set("short", "�ⶳ�p-�W�ѱ���f");
	set("long", @LONG
�A�����b�ⶳ�p�W�ӡu�W�ѱ�v��f�A�A�i�H�ݨ쩵�۩��_�ӳq
���s�����@�`�@�`�ѵM�۱�A�A��_�F�Y���s����F�L�h�A���M�o�{
�۱�����Ʀʱ�A�d��Ӷ��ۮp�����q�J���A�ݼˤl�}�O���ꪺ�H�A
�O�L�k���W�p�����C
LONG
	);
	set("current_light", 1);
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"hill9",
  "south" : __DIR__"hill7",
]));
	set("outdoors", "forest");

	setup();
	replace_program(ROOM);
}
