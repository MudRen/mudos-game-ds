// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "�ޯ�Q���U");
 set("long", @LONG
�o�̬O�Ův�Q��¾�~�ޯ�g�k�M�o��s�ޯ઺�a��A����O¾�~
��s�ǡC�n�[�ݧޯ�`�N�ƶ��п�J < about skill > 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "west"   : __DIR__"hall_guild",
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
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}
