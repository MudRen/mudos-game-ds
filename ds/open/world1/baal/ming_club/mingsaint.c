inherit ROOM;
void create()
{
 set("short","明教聖地");
 set("long",@LONG
這裡是明教教主、光明聖使和各堂主討論教內大事的地方，聖地
的中央聳立著雄雄的聖火，壁上提了一個【明】字，萬年不滅的聖火
照亮著四周，旁邊堆滿了奇珍異寶，四周排滿了一個一個石碑，上面
刻的全是各門派的上乘心法，其中有一個石碑特別高大，上面刻著明
教中不為人知的秘密。
LONG
    );
 set("exits",([ "down": __DIR__"fire",
             "up": __DIR__"leaderroom",
    ]));
        set("objects", ([
                __DIR__"box.c" : 1,
        ]));

        set("no_kill",1);
        set("light",1);
 setup();
        set("stroom",1);
}
int valid_leave(object me, string dir)
{
        if( dir=="up" && CLUB_D->check_member("ming",getuid(me))  < 5&&wizardp(me)&&CLUB_D->check_member("sky",getuid(me))<6 )
                return notify_fail("非幫主不能進入幫主專用間。\n");
        return ::valid_leave(me, dir);
}
//edit by -jangshow
//這裡該有個board
//have 聖火秘言碑(Fire-secret board)
//no describe

