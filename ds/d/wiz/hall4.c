// Room: /d/wiz/hall4.c

inherit ROOM;

void create()
{
 set("short", "���ȰQ���U");
 set("long", @LONG

  �o�̬O�Ův�Q�ץ��ȼg�k�M�o��s���Ȫ��a��M���W�O�ޯ�Q���U�M
���U�O�Ǫ��Q���U�C �n�[�ݥ��Ȫ`�N�ƶ��п�J < about quest > 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall3",
    "up"     : __DIR__"hall5",
    "hole"   : __DIR__"quest1",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 set("objects",([
 __DIR__"npc/boy2":1,
 ]));
 setup();
 call_other("/obj/board/quest_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="quest")
 {
   if( file_size("/doc/wiz/quest.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/quest.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}