inherit NPC;

void create()
{
        set_name("蜜蜂", ({"bee"}) );
        set("long", "辛勤工作的蜜蜂, 嗡嗡的在你身邊飛來飛去..\n");
        set("race", "野獸");
        set("limbs", ({ "頭部", "身體", "翅膀", "後腳","腹部"})); //受攻部位
        set("verbs", ({ "bite","poke"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
        set("age", 2);
        set("level", 7);
        set("con",10);
        set("str",10);
        set("dex",10);
        set("int",10);
        setup();

}


