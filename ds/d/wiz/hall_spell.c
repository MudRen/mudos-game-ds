// Room: /d/wiz/hall5.c

inherit ROOM;

void create()
{
 set("short", "�k�N�Q���U");
 set("long", @LONG
�o�̬O�Ův�Q��¾�~�k�N�g�k�M�o��s�k�N���a��A���F�O¾�~
��s�ǡC�n�[�ݪk�N�`�N�ƶ��п�J < about spell > 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "east"   : __DIR__"hall_guild",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/spell_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="spell")
 {
   if( file_size("/doc/wiz/spell.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/spell.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}
