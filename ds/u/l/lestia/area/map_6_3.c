// Room: /u/l/lestia/area/map_6_3.c

inherit ROOM;

void create()
{
	set("short", "靈幻教-大殿旁廳");
	set("long", @LONG

這裡是靈幻教大廳兩旁的廳堂，專門給普通教徒或旅客歇息的地方，擺
設平常但不失一派之風，幾個身穿白色勁裝的教徒正坐在椅子上聊天，一張
普通的桌子上擺著點心，你如果餓了可以拿幾塊來吃。

LONG
	);
	set("no_clean_up", 0);
	set("world", "undefine");
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"map_6_2",
  "south" : __DIR__"map_7_3",
]));
	set("current_light", 2);

	setup();
}
void init()
{
   add_action("do_take","take");
}
int do_take(string arg)
{
object obj,me;
    int count,i;
string xx;
    me = this_player();
xx = "/u/l/lestia/area/obj/cookie";
    if( me->query("class1") != "靈幻教" ) return notify_fail("你不是靈幻教的教徒，不能拿這個點心。\n");
    if( !arg) return notify_fail("你要拿什麼？\n");
    //if(sizeof(objectp(present("cookie",me)))>2 ) return notify_fail("你太貪心了吧，吃完再拿吧。\n");
    if(arg == "cookie" )
    {
        if(objectp(present("cookie",me)))
        {
            for(i=0;i<sizeof(all_inventory(me));i++)
            {
if(base_name(all_inventory(me)[i])==xx) count ++;
                if(count >= 2) return notify_fail("你太貪心了吧，吃完再拿吧!!\n");
            } 
        }
 new(xx)->move(me);
        write("你從桌上拿起一塊香香的點心。\n");
        return 1;
    }
}


