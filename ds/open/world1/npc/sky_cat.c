inherit NPC;

void create()
{
        set_name("天貓", ({ "sky cat", "cat" }) );
        set("race", "beast");
        set("level",37);
        set("age", 4);
        set("evil",-20);
        set("unit","隻");
        set("long", @LONG
幽雅的姿態，加上敏捷的動作，不時還會挨到你身邊撒嬌
，讓你實在不忍心下手殺牠。
LONG
);
        set("limbs", ({ "頭部", "身體", "後腳","前腳"}));
        set("verbs", ({ "crash","hoof","bite" }));
        setup();
}


