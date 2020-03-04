// Room: /u/a/acme/area2/t17.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�G�h]");
	set("long", @LONG
�o�̤@�����¡A�|�P�@�L�O���A�u��N���Ӧ�A�o�̪����A�`
��A�R�o�A�V������l�A�̦n�������}�o�ӤH���Һ��C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"t18",
  "south" : __DIR__"t16",
]));
        set("objects",([
           __DIR__"npc/lessname" : 1,
        ]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
