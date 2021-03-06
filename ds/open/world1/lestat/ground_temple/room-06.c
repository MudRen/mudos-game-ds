inherit MOBROOM;

void create()
{
        set("short", "地底神殿遺跡");
        set("long", @LONG
寬廣的地下道路裡，陰森森的感覺遍佈你全身上下每一個毛孔，
不知從何處吹進來的風，冷颼颼地，更加增添詭異的氣氛，偶然幾隻
老鼠從你腳邊溜過，但也隨即被不知名的生物所補殺。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
                   "west" : __DIR__"room-05",
                   "north" : __DIR__"room-10",
                   "southwest" : __DIR__"room-03",
        ]));
        set("chance",80);
        set("mob_amount",3);
        set("mob_object",({
           __DIR__"../npc/sky_cat",
        }) );
        set("light",0);
        set("no_recall","神殿內部的磁場遮蔽了所有的傳送力量。");
        set("no_clean_up", 0);
        setup();
}

