inherit ROOM;
void create()
{
          set("short","��v�Ϥp��");
          set("long",@LONG
�o�̬O��L��v�Ϫ��@���p���A�糣�O�q����v�Ϫ��ߤ@���q�D�C�o
�̪���v�]�p������X�A�i��u�O�Ψӵ��q�u�̦��a�A���M�p���A���O
�ݨӥͬ��]�I���@�@�ѳơC
LONG
          );
               set("world", "future");
        set("outdoors","desert");
	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"digging_street2",
  "east" : __DIR__"digging_street4",
]));

	setup();
	replace_program(ROOM);
}
