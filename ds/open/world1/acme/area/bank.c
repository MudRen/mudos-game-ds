// Room: /u/a/acme/area/bank.c

inherit ROOM;

void create()
{
	set("short", "�U������");
     set("light",1);
	set("long", @LONG
�o�̬O�@�������A���f�a�ۤ@�Ӥj���B�A�������F�@�|�Z�v�A�o��
�����N�O�ѫ����}�@�����H�Ϊ������C
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "���B" : "���B�W���g�ۡy�U�������z�|�Ӷª��j�r�C\n"]));
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"street5",
]));
    set("objects",([
        __DIR__"npc/wan" : 1,
             __DIR__"npc/guard" : 3,
    ]) );
          set("room_type","bank");        //�Ȧ����
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}

