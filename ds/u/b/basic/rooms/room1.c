inherit ROOM;

void create()
{
        set("short", "晴子的客廳");
        set("long", @LONG
這裡是晴子專門跟一些老朋友相聚在一起的地方，客廳左邊有一幅畫
上面有晴子最心愛的女人的照片，右邊有一陶瓷，上面刻著一條龍，
頗為氣派的。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "north" :"/u/b/basic/rooms/room2",
  "west" : "/u/b/basic/workroom",
]));
        set("no_clean_up", 0);
        set("light",1);
        setup();
        replace_program(ROOM);
}
