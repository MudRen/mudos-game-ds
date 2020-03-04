// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "¾�~�ޯ�Q���U");
 set("long", @LONG

  �o�̬O�Ův�Q��¾�~�ޯ�g�k�M�o��s�ޯ઺�a��M���W�O�]���|ĳ�ǡM
���U�O���ȰQ���U�C���F�����ɮv���d�ҡM�n�[�ݧޯ�`�N�ƶ��п�J
[1;32m about skill[m�C�o�өж������ɮv���ޯ�i�H������¾�~���H�ǲߡM�n
���D�g�k����J[1;33m about master[m�C
LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "east"   : __DIR__"masterroom",
    "down"   : __DIR__"hall4",
    "up"     : __DIR__"hall6",
 ]));
 set("objects", ([ /* sizeof() == 1 */
	"/u/s/shengsan/npc/swimmaster": 1,
	]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/skill_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
	if(arg=="skill")
	{
		if( file_size("/doc/wiz/skill.txt")>0 )
		{
			this_player()->start_more( read_file("/doc/wiz/skill.txt") );
			write("\n");
		}
		else write(" SORRY. �����ɩ|���إ�. \n");
   		return 1;
	}
	else if(arg=="master")
	{
		if( file_size("/u/s/shengsan/npc/swimmaster.c")>0 )
		{
			this_player()->start_more( read_file("/u/s/shengsan/npc/swimmaster.c") );
			write("\n");
		}
		else write(" SORRY. �����ɩ|���إ�. \n");
		return 1;
	}
	return 0;
}
