inherit ROOM;
void create()
{
	set("short", "����");
	set("long", @LONG
�@���sô�q���P��v�Ϫ������C�ѩ��q�����Ů�D�`�ÿB�A�b������
�Ǧ��j�����Ů�M�s���A��Υi��V���@�n�N��Ϲj���A�O��~���o���
�A���ͬ����ҡC
LONG
	);
	set("world", "future");
	set("no_clean_up", 0);
        set("item_desc",([
        "��V���@�n":
"�Ѥ@�ؽ��誫��s�����A�u�����G��M�T��q�L�A�ϱo����F����j\n"
"�ÿB�Ů𪺮ĪG�C\n",
        ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"digging_road3",
  "south" : __DIR__"digging_street3",
]));

	setup();
	replace_program(ROOM);
}
