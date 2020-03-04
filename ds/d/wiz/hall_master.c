// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "��žɮv�d�ҩж�");
 set("long", @LONG
�o�̬O��žɮv�d�Ҫ��ж��C�C����J[1;33m about master[m �w����g�ɮv��
��k�P�`�N�ƶ��C
LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "north"   : __DIR__"hall_master2",
    "south"   : __DIR__"hall_guild",
 ]));
 set("objects", ([ /* sizeof() == 1 */
	"/u/s/shengsan/npc/bluemaster": 1,
	]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
// replace_program(ROOM);
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="master")
 {
   if( file_size("/u/s/shengsan/npc/bluemaster.c")>0 )
   {
    this_player()->start_more( read_file("/u/s/shengsan/npc/bluemaster.c") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}
