// Room: /u/t/truewind/Minetown/area/minetown2.c

inherit ROOM;

void create()
{
	set("short", "�q����");
	set("long", @LONG
�o�̬O�q���j�����񪺤@���Ŧa�A�@�D�]���q�����𩹦詵����
�h�C�ѪŤ����X���}�B�����L�A���G�f���F�@�ǳf���C�A�o�{����
�Ů���G���I���@�ˡC�a�W�٦��@�Ǻ޽u�_�X�C
LONG
	);
	set("outdoors", "land");
	set("outdoors","land");
	set("no_clean_up", 0);
	set("item_desc", ([ /* sizeof() == 1 */
  "�L�ͪ��ө��t��" : "�A�ݨ�@���޽u�q�g���_�X�A���ݬO�ӳz�����p�y�A�o�O�a���U�ҮI
�]�A��޾ɷL�ͪ��o�����ө��t�ΡC
",
]));
	set("current_light", 3);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"minetown6",
  "east" : __DIR__"minetown1",
  "south" : __DIR__"minetown4",
]));

	setup();
	replace_program(ROOM);
}
