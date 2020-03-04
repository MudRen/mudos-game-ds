// Room: /u/l/lestia/area/map_7_5.c

inherit ROOM;

void create()
{
	set("short", "�F�۱�-�j���J�f");
	set("long", @LONG

�y�F�۷��z�E�E�E�E���ݨ쪺�T�Ӥj�r�N�O�F�۷����P�СA�q�~���
�_�ӫܩ��㪺�P�Ц��b�����@�A�i�O�٬O�i�H�ݥX�ӷ��몺�貪�A�u�F�۷�
�v�T�r�ݰ_�ӻa�l���O�A���G�O�ѦW�a�ҮѼg�A�j���Ǧ��G�ڻݥѤG�H�~��
�X�ꪺ�۬W�A�W�l�W����ۺ�����J���A�J�������e�n���O�b�D�����F�۱�
�����v�C

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"map_7_6",
  "north" : __DIR__"map_6_5",
  "west" : __DIR__"map_7_4",
  "south" : __DIR__"map_8_5",
]));
	set("current_light", 3);

	setup();
	replace_program(ROOM);
}
