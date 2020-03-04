inherit NPC;
void create()
{
        set_name("蚜蟲", ({ "aphid" }) );
        set("race", "beast");
        set("age", 1);
        set("level",5);
        set("long", @LONG
一隻微小的蚜蟲，在地上爬來爬去，牠的屁屁還傳來香香的味道。
LONG);
        set("max_hp",10);
        set("unit","隻");
        set("limbs", ({ "頭部", "身體" }) );
        set("verbs", ({ "bite","crash" }) );
        setup();
}

void die()
{
        object meat;
                meat=new_ob(__DIR__"obj/aphid_liquid");
                meat->move(this_object());
        ::die();
}
