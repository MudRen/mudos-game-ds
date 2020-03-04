inherit ROOM;

void create()
{
        set("short", "洞口");
        set("long", @LONG
你走到一個山洞前面，左右兩邊都刻滿了詩詞歌賦，文彩豐富，內容
深動，洞前有一小盞的油燈在照明，上方刻著兩個深深的烙字，「古墓」
你一眼望去，裡面盡是一片的黑暗，一片無止盡的黑暗，如果你有照明設
備的話，也許可以看的比較清楚。
裡面還有一段路。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room2",
  "east" : "/open/world1/cominging/purple_sun/psin3",
]));
        set("objects", ([ /* sizeof() == 1 */
          __DIR__"prey" : 1,
]));
        set("outdoors","land");
        set("light",1);
 set("no_clean_up", 0);

        setup();

}

