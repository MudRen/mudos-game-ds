// cave.c

inherit ROOM;

void create()
{
	set("short","�Ѧa�|�a�D");
	set("long", @LONG
��A�B�i�o�̡A�Pı�b���K�B���G���H���s���ۧA�A����ť����
�H�۵ۡG�u�Ѧ����\�A�a���a�b�A�Ѧa�����A�d�����k�C�v��ӳo��
�O�Ѧa�|�����k��A�ڻD�o�̬O�Ѧa�|�����Ѧa���k���Ҧb�A�æ��@
�s�����H��������C

LONG
	);
	set("objects",([
//__DIR__"item/greensword2" :1,
]));
	set("exits", ([
	"up": __DIR__"room36",
	]));
	set("objects", ([
		"/open/world1/npc/goldman4" : 1,
		"/open/world1/npc/goldman5" : 1,
		"/open/world1/npc/goldman6" : 1,
	]));
	set("light",1);
//        set("no_kill",1);
//set("no_goto",1); cancel two settings by alickyuen@ds 1)��golem 2)meaningness
	setup();
//	call_other( "/obj/board/sky_room05_b", "???" );
}
