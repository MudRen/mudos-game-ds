// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "�˳ưQ���U");
 set("long", @LONG
�o�̬O�Ův�Q�׸˳Ƽg�k�M�o��s�˳ƪ��a��A���F�O�ϰ��s
�ǡC�n�[�ݸ˳ƪ`�N�ƶ��п�J < about equip >  �a�W���X��
²�檺�˳ơA�A�i�H�� < more �˳ƦW > �Ӭݵ{���C 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
	"east"   : __DIR__"hall_area",
	"south"   : __DIR__"hall_material",
 ]));
 set("objects",([
 "/u/l/luky/obj/fighterneck":1,
 "/u/l/luky/npc/eq/blackjacket":1,
 "/u/l/luky/npc/wp/kaisan_b":1,
 "/u/l/luky/npc/eq/detectring":1,
 "/u/l/luky/npc/wp/gun":1,
 "/u/l/luky/npc/wp/bullet":1,
 "/u/l/luky/npc/wp/bow":1,
 "/u/l/luky/npc/wp/arrow":5,
 "/u/l/luky/npc/item/dump":1,
 "/u/l/luky/npc/item/beer":1,
 "/u/l/luky/npc/item/pill1":1,
 "/u/l/luky/obj/torch":1,
 SHENGSAN2"aovandis/npc/food/cola":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/equip_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="equip")
 {
   if( file_size("/doc/wiz/equip.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/equip.txt") );
    write("\n");
   } else write(" SORRY. �����ɩ|���إ�. \n");
  return 1;
 }
 return 0;
}