#include <ansi.h>
#define LUKY		"/u/l/luky/"
//inherit F_CLEAN_UP;
inherit ITEM;
void create()
{
	object ob, obj;
	seteuid(getuid());
	set_name(HIM"龍宮寶盒"NOR,({"box"}));
        if( clonep() )
        set("unit", "個");
        set("long",HIG"一個古老的盒子。"NOR"這是大龍蝦從海龍王的宮殿裡偷來的。\n"
	"你可以趁牠不注意的時候偷拿牠的寶貝喔..(get [東西] from box)\n");
        set("value", 1);
        set("no_sac", 1);
        set("no_get", 1);
        set_max_encumbrance(999999);
obj = this_object();
ob=new("/u/l/luky/npc/eq/blackjacket");
ob->move(obj);
ob=new("/u/l/luky/npc/wp/kaisan_b");
ob->move(obj);
ob=new("/u/l/luky/npc/item/bag");
ob->move(obj);
ob=new("/u/l/luky/obj/fighterneck");
ob->move(obj);

setup();
}

void init()
{
add_action("do_shakebox","shakebox");
}

int do_shakebox(string arg)
{
object box,ob,me;
string str,file;
me=this_player();
box=this_object();
if( wiz_level(me) < 5) return notify_fail("突然間, 寶盒吐出一隻螃蟹夾住你的鼻子...\n");
if(!arg) return notify_fail("要搖什麼東西出來?\n");
arg+=".c";
if( file_size(arg) < 0 ) return notify_fail("沒這個東西\n");
ob=new(arg);
ob->move(box);

  file = "/u/l/luky/box.log";
  str = sprintf("[%s] shake %s(%s)on %s\n",geteuid(me),ob->query("name"),arg,ctime(time()));
  if(file_size(file) < 0) write_file(file, str);
  else if(strsrch(read_file(file), sprintf("[%s] shake %s(%s)on %s\n",geteuid(me),ob->query("name"),arg,ctime(time())))  == -1)
  write_file(file, str);

tell_object(this_player(),"你搖了搖寶盒...盒子裡突然多出一個"+ob->query("name")+"來!\n");
return 1;
}

