inherit NPC;

void create()
{
        set_name("白蟻", ({"ant"}) );
        set("long",@LONG
一隻肥肥胖胖的白蟻，在樹幹上爬來爬去，不停地啃食神木。
LONG);
        set("unit","隻");
        set("race", "beast");
        set("limbs", ({ "頭部", "身體", "顎齒"})); 
        set("verbs", ({ "bite","poke","crash" })); 
        set("age", 1);
        set("level",5);
        setup();
}
