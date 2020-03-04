// Room: /open/world1/tmr/bagi/ghat5.c

inherit ROOM;

void create()
{
	set("short", "�L�D");
	set("long", @LONG
�A�����b�@���L�D�A�}�U��ۿn�~�w�[�����a�A���檺�s���U���o��
���a���H�N�A���ƪ������U���F�����¶աC�D����Ǫ���L��O�Q����
���л\��F�A�����K�����౴�Y�ӥX�A�b�U�դ����y�K�@����N�C
LONG
	);
	set("outdoors", "snow");
	set("no_clean_up", 0);
	set("current_light", 2);
	set("world", "past");
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"ghat10",
  "southeast" : __DIR__"ghat3",
]));

      set("objects",([
         __DIR__"npc/woodman":1,
      ]) );

	setup();
	replace_program(ROOM);
}
