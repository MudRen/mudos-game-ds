// room-su1.c 

inherit ROOM;
string look_sign(object me);

void create()
{
        set("short", "蘇魯克的家");
        set("long", @LONG
由於蘇魯克的妻子十年前被強盜害死，只剩下蘇魯克和他兒子蘇普兩
人，所以屋裡亂七八糟的。但蘇魯克並不在意，因為他覺得像他這樣的草
原漢子是不能去做女人們做的事情的。火堆一旁的大掛毯上掛著兩兩張精
致的羊毛毯子。
LONG
        );
        set("exits", ([
            "northeast" : __DIR__"shuijing",
        ]));


        set("objects", ([
                    __DIR__"npc/su" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
