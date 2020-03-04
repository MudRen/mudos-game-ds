// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "���~����Ų�w��");
 set("long", @LONG
�o�̬O�Ův�Q�׸˳Ƨ���g�k�M�o��s���誺�a��A���_�O�ж�
�Q���U�C�n�[�ݧ���`�N�ƶ��п�J < about material > �C

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "north"   : __DIR__"hall_equip",
 ]));
 set("objects",([
// "/u/l/luky/obj/fighterneck":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/material_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="material")
 {
   if( file_size("/doc/wiz/material.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/material.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}