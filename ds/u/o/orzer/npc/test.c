inherit NPC; 
void create()
{
        set_name("測試用打者", ({ "test man","man" }) );
        set("race", "野獸");
        set("age", 30);
        set("level",50);
        set("long", "一個專門測試的打者，看來雄壯威武。\n");  
        set("max_hp",9999999);
        set("hp",9999999);
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        setup();
}



