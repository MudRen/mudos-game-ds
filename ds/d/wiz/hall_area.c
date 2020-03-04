// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "�ϰ��s��");
 set("long", @LONG
�A�ݨ�o�ӥզ⪺�ж���B���O�@�|�|���������m�M��s���i�A  
�o�̴N�O�Ův�̤��G�s�ϰ�M�j���̵o��s�F�����a��A�p�G�A�O�s
�i�H���A�̦n����o�̪��񪺤��i�ݧ��C�ڤ۰ϰ쪺�Ův�������o��
�ϰ�~�����ɯšA�]�~��V�󰪯Ū��{���Ч@�D�ԡA�][1;37m�ߦ��ϰ�q
�L�f�d�åB�q�L��¦�Ҹժ��Ův����i�J�W�����ж���s¾�~�ޯ�M
�Ԫ����g�k[0m�C�����ϰ쪺�򥻳W�w�P�`�N�ƶ��Х� < [1;34mabout area[m > 
�d�ߡC

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall1",
    "up"     : __DIR__"hall_guild",
    "east"   : __DIR__"hall_room",
    "west"   : __DIR__"hall_equip",
    "north"   : __DIR__"hall_quest",
    "south"   : __DIR__"hall_npc",
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/area_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="area")
 {
   if( file_size("/doc/wiz/area.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/area.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}

int valid_leave(object me, string dir)
{
	if( dir=="up" && wiz_level(me)<=wiz_level("(apprentice)") )
		return notify_fail("�u�������Ův(Wizard)�~��W�h���ӳq��¾�~��s�Ǫ��ӱ�C\n");
	return ::valid_leave(me, dir);
}