#include <room.h>
#include <ansi.h>
inherit ROOM;

void do_change(string str);

void create()
{
	set("short",HIC"葦月愛之屋"NOR);
	set("long",@LONG
這裡是魔法門世界中的高級住宅區
不是普通人住的起的喔
愛之屋售價:
一間房		50萬 coin
buyhome  <購買愛之屋>
myhome   <回到愛之屋>
setlong  <修改家long>�>
setshort <修改家short>�>
LONG
);
	set("exits",([
	"down":"/open/clc/start/enter",
	]));
	set("objects",([
	]));
	set("light",1);
	setup();
}

void init()
{
	add_action("do_home","myhome");
	add_action("do_buy","buyhome");
	add_action("do_setlong","setlong");
	add_action("do_setshort","setshort");
}

int do_buy()
{
	object env,me;
	string file,str;
	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(me->query("coin")<500000)
                return notify_fail("你身上沒有那麼多錢。\n");
	if(file_size(file)!=-1)
                return notify_fail("你已經有一間屋子了。\n");
	str = @ROOM_CODE
#include <room.h>
#include <ansi.h>
inherit ROOM;
inherit "/std/saveeq";

void create()
{
ROOM_CODE
	;

	str +=sprintf("set(\"short\",HIG\""+me->query("name")+"的愛之屋\"NOR);");
	str +=@ROOM_CODE2
        set("long",@LONG
這間房間能儲存身上的道具或是裝備
目前能save 10件道具......歡迎大家找bug
方法:
putin  名稱
getout 編號
list
LONG);
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}

ROOM_CODE2
	;
	write("建造 "HIR + me->query("name") + NOR" 的愛之屋....");
	if( write_file(file, str) )
	{
		write("成功\\n");
		me->add("coin",-500000);
	}	
	me->set("item/item1","");
	me->set("item/item2","");
	me->set("item/item3","");
	me->set("item/item4","");
	me->set("item/item5","");
	me->set("item/item6","");
	me->set("item/item7","");
	me->set("item/item8","");
	me->set("item/item9","");
	me->set("item/item10","");

return 1;
}

int do_home()
{
	object env,me;
	string file,str;
	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("你沒有買房子怎麼回家啊。\n");
	me->move(file);
	write("\n經過一天的奔波, 終於回到溫暖的小窩了\n");
	
return 1;
}


int do_setlong()
{
	object env,me;
	string file,str;

	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("你沒有房子。\n");

        me->edit( (: call_other, __FILE__, "do_change" :) );

	return 1;
}

void do_change(string str)
{
	object me,room,env;
	string file,nf;
	me=this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	nf = @ROOM_CODE

#include <room.h>
#include <ansi.h>
inherit "/std/saveeq";
inherit ROOM;

void create()
{
ROOM_CODE
	;
	nf += sprintf("\tset(\"short\", %O);\n", new(file)->query("short") );
	nf += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", str );
	nf += @ROOM_CODE2
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}
ROOM_CODE2
	;
	rm(file);
	write("修改 愛之屋....");
	if( write_file(file, nf) ) {
		write("Ok......\n");
		if(!find_object(file))
			return ;
		destruct(find_object(file));
		return ;
	} else
		return notify_fail("你沒有修改房子的權利, 通知eeman處理。\n");

	return ;
}

int do_setshort(string str)
{
	object room,env,me;
	string file,nf;

	me = this_player();
	env = environment(this_player());
	file = file_name(env) + "/" + me->query("id") + ".c";

	if(file_size(file)==-1)
                return notify_fail("你沒有房子。\n");

	if(!str || str=="")
                return notify_fail("setshort <敘述>。\n");

	nf = @ROOM_CODE

#include <room.h>
#include <ansi.h>
inherit "/std/saveeq";
inherit ROOM;

void create()
{
ROOM_CODE
	;
	nf += sprintf("\tset(\"short\", %O);\n", str );
	nf += sprintf("\tset(\"long\", @LONG\n%sLONG\n\t);\n", new(file)->query("long") );
	nf += @ROOM_CODE2
        set("exits",([
	"back":"/open/eeman/room",
        ]));
	set("light",1);
	setup();
}
ROOM_CODE2
	;
	rm(file);
	write("修改 愛之屋....");
	if( write_file(file, nf) ) {
		write("Ok......\n");
		if(!find_object(file))
			return 1;
		destruct(find_object(file));
		return 1;
	} else
		return notify_fail("你沒有修改房子的權利, 通知eeman處理。\n");

	return 1;
}
