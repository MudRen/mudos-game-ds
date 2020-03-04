// Room: /open/world1/tmr/frost/court1.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-���x");
	set("long", @LONG
�A�����b�D�[�������x�A���x���D�[���������������A�i�q���D�[�U
�B���ؿv�C����ӻ��A�[���ؿv�����H�y���[�Φ۵M���[��j���A�ؿv��
���]�����Ůt�O�A�i���������ؿv�B�j���ؿv�Τp���ؿv�T�ӵ��šC�|�g
���ҲM�զw���A���L���D�H���ˤ��a��A���n�۩I�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"temple1e2",
  "north" : __DIR__"court2",
]));
	set("current_light", 1);
	set("no_clean_up", 0);
         set("objects", ([
                __DIR__"npc/taoist2":2,
        ]) );


	setup();
	replace_program(ROOM);
}
