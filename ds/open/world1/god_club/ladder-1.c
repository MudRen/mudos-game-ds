inherit ROOM;

string *members = ({ });

void create()
{
        set("short", "諸神塔─第一層");
        set("long", @long
這座高聳入雲的巨塔就是傳說中遠古諸神所建造的「諸神塔」。
由於諸神之力的影響，這座巨塔能夠通到神境每個地方，而現在所在
的位置是諸神塔的第一層，走上樓梯可以通道第二層。你向西南方看
去，發現一間武器之屋；東南方則是防具之屋。再往南走，會到達神
境的會議大廳和道具之屋。

long);
        set("exits", ([
  "north" : __DIR__"entrance",
    "up" : __DIR__"ladd-2",
  "southwest" : __DIR__"room_wp.c",
  "southeast" : __DIR__"room_eq.c",
  "south" : __DIR__"boardroom.c",
  "northeastup" : __DIR__"vip_room.c",
]));
        set("light", 1);
        setup();
        set("stroom", 1);
}
/*
int valid_leave(object me, string dir)
{
        if( dir == "northeastup" && !wizardp(me) )
        {
                if( load_object(__DIR__"vip_room.c") )
                {
                          if( member_array(getuid(me), members) != -1 || getuid(me) == "deaon" )
                        {
                                tell_room(this_object(), me->name()+"的身形漸漸隱沒..\n", ({ me }));
                                me->move(__DIR__"vip_room.c");
                                tell_room(load_object(__DIR__"vip_room.c"), me->name()+"從底下漸漸上升至此地。\n", ({ me }));
                                return 1;
                        }
                        else return notify_fail("你沒有得到 tear 的許\可無法進入。\n");
                }
                else return notify_fail("方向出口房間有誤。\n");
        }
        else return ::valid_leave(me, dir);
}

void init()
{
         if( getuid(this_player()) == "deaon" )
        {
                add_action("do_control", "control");
        }
}

int do_control(string arg)
{
        if( !arg ) return notify_fail("格式: control <人名>\n");
        if( member_array(arg, members) != -1 )
        {
                members -= ({ arg });
                write("刪除可進出人物 "+arg+"。\n");
                return 1;
        }
        else
        {
                members += ({ arg });
                write("增加可進出人物 "+arg+"。\n");
                return 1;
        }
        return notify_fail("格式: control <人名>\n");
}
string *query_members() { return members; }
*/
