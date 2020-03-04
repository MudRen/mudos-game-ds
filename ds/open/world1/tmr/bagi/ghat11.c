// Room: /open/world1/tmr/bagi/ghat11.c

inherit ROOM;

void create()
{
	set("short", "�L�a");
	set("long", @LONG
�A�����b�@�B��e�諸�L�a�̡A�|�P�򺡤F�p���W�`�����w����A�p
���m�B���Q�άO�����Q���`�����@�H��ءA�쥻����ӫ¶դ��_���H���b
���ѩ�L�쪺���j�A���զ��G�N���ĳ\�h�F�C
LONG
	);
	set("outdoors", "snow");
	set("no_clean_up", 0);
	set("current_light", 4);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ghat12",
  "southeast" : __DIR__"ghat10",
]));

      set("objects",([
         __DIR__"npc/woodman":1,
      ]) );

	setup();
	replace_program(ROOM);
}
