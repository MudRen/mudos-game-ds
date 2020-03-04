// Room: /open/world1/tmr/freezetaoism/observatory2.c

inherit ROOM;

void create()
{
	set("short", "�H���D�[-�ȴ[��");
	set("long", @LONG
�o�O�@�����W�D�[���I���C�ȥ𮧪��[�СA���M�Ф��]��²���F�ǡA
���ѵ��f��X�h�����A�����u�s�ٷL���A���H�I��v���R���[�P�A�n�O
�b�o��~��A����F�L���O�@�ؼ�ƪ��ɨ��C
LONG
	);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"observatory",
]));
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/man":2,
        ]) );


	setup();
	replace_program(ROOM);
}
