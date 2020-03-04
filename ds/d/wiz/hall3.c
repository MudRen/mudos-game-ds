// Room: /d/wiz/hall3.c

inherit ROOM;

void create()
{
 set("short", "�Ǫ��Q���U");
 set("long", @LONG

  �o�̬O�Ův�Q�שǪ��g�k�M�o��s�Ǫ����a��M���W�O���ȰQ���U�M
���U�O�˳ưQ���U�C �n�[�ݧޯ�`�N�ƶ��п�J < about mob > ,�o
�̤]���ѤF���նüƪ��\�� <random �Ʀr>,�i�H���A��F�Ѷüƪ��d
��μg�k�C 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall2",
    "up"     : __DIR__"hall4",
 ]));
 set("objects",([
  "/u/l/luky/npc/passenger":1,
  __DIR__"npc/playboy":3,
 "/u/s/shengsan/npc/groundmob":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/mob_b", "???");
}

void init()
{
 add_action("do_help","about");
 add_action("do_random","random");
}

int do_help(string arg)
{
 if(arg=="mob")
 {
   if( file_size("/doc/wiz/mob.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/mob.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}

int do_random(string arg)
{
 string result;
 int p,i;
 if(!arg) return notify_fail(" �Ϊk: random <�Ʀr�d��>\n");
 if(sscanf(arg, "%d", p)!=1)
	return notify_fail(" �Ϊk: random <�Ʀr�d��>\n");
 result=sprintf("�H�U������100�� random(%d) �����G:\n",p);
 for(i=0;i<20;i++)
 {
  result+=sprintf("%-8d  %-8d  %-8d  %-8d  %-8d\n",random(p),random(p),random(p),random(p),random(p));
 }
 write(result);
 return 1;
}