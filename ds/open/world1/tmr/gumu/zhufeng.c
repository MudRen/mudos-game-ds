// zhufeng.c
// Java Oct.10 1998

inherit ROOM;

void create()
{
        set("short", "終南山主峰");
        set("long", @LONG
此時你已身在終南山主峰，視野更為廣闊。往低望去，群山盡皆匍
匐在腳下。重陽宮的翠綠琉瓦在山腰處，晶瑩生輝。只見不少殿宇散佈
于山坳間，景色頗為美妙。一塊巨石 (stone)立在一旁，似乎刻了什麼
東西。往西和南各是一條山路。
LONG    );
        set("item_desc", ([
                "stone"  :
"
                於人妄矯重異要佐子
                今傳跡矯陽人伴漢房
                終入復英起與赤開志
                南道知雄全異松鴻亡
                山初非姿真書游舉秦
                ，，，，，，，，，
                殿二收乘高造功\屹曾
                閣仙心時視物成然進
                凌此活或仍不拂天橋
                煙相死割闊輕衣一下
                霧遇墓據步付去柱履
                。。。。。。。。。
"
        ]));
        set("outdoors", "forest");
        set("exits", ([
                "westdown"  : __DIR__"shanlu2",
                "southdown" : __DIR__"shanlu1",
        ]));
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

