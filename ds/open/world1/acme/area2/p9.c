// Room: /u/a/acme/area2/p9.c

inherit ROOM;

void create()
{
	set("short", "�����~");
	set("long", @LONG
�o�̴N�O�����~�F�A���Фl���O�Ѧˤl�ҷf�\�Ӧ��A��W�����F�ϵe
�ֵ��A�����˻s�p��W��Х|�_�˼˭ѥ��A�k�M�O�ӮѩСA�b�����~�~��
�O�@�j�����˪L�C�b�p��W�A�i�ݨ�@�i�ůȡA�W�Y�g�F�X��r�C
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "out" : __DIR__"start",
]));
       set("light",1);
set("objects",([
    __DIR__"npc/shi2" : 1,
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "�ů�" : "�W�Y�g�ۡu�L�����H�G�A�L�˥O�H�U�v�A���Q�r����C
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
