inherit NPC;

void create()
{
        set_name("祥獅", ({ "mascot lion", "lion" }) );
        set("race", "beast");
        set("level",33);
        set("age", 12);
        set("evil",-20);
        set("unit","隻");
        set("long", @LONG
一身金毛，散發著祥和氣息的獅子，乃是傳說中的瑞獸，
可以為人帶來好運。
LONG
);
        set("limbs", ({ "頭部", "身體", "後腳","前腳"}));
        set("verbs", ({ "crash","hoof","bite" }));
        setup();
}

