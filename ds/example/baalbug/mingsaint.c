inherit ROOM;
void create()
{
 set("short","明教聖地");

 set("long",@LONG
這裡是明教教主、光明聖使和各堂主討論教內大事的地方，聖地的
中央聳立著雄雄的聖火，壁上提了一個【明】字，萬年不滅的聖火
照亮著四周，旁邊堆滿了奇珍異寶，四周排滿了一個一個石碑，上
面刻的全是各門派的上乘心法，其中有一個石碑特別高大，上面刻
著明教中不為人知的秘密。
LONG
    );
 set("exits",([ "test":"/open/world1/tmr/area/hotel",
    ]));
        set("no_kill",1);
        set("light",1);
 setup();
  call_other("/obj/board/ming_fire_secret_b" , "???");
        set("stroom",1);
}
//這裡該有個board
//have 聖火秘言碑(Fire-secret board)
//no describe
