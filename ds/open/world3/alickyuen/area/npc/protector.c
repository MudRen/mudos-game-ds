inherit NPC;
void create()
{
set_name("�u��",({"guard"}));
set("long", " �o�O�t�d�u�óo���K���a���u�áA�A�i��H�����L���ؼФF�I\n");
set("race","�H��");
set("age", 30);
set("level", 25);
set("max_hp", 5000);
set("max_mp", 5000);
set("max_ap", 5000);
set("attitude", "killer");
set("evil", 99);
set("combat_exp",100);
        set("chat_chance_combat", 100);
setup();
carry_object(__DIR__"obj/moon_clip");
}
