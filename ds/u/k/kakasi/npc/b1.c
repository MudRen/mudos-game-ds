#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIC"我是高手"NOR, ({ "super bonze","bonze" }) );
        set("level",30);
        set("race","人類");
        set("gender","男性");
        set("age",15);
        set("title",HIY"叫我高手"NOR);
        set("long","他是自稱高手的高手\n");
        set("chat_chance", 3 );

        setup();
carry_object("open/world1/acme/bonze/npc/wp/staff2")->wield();
}
void init()
{
       ::init();
        add_action("do_guard", "go");
}

int do_guard(string arg)
{

        if( (arg!= "enter") || !this_player()->visible(this_object()) ) retur
n 0;
        write( name() + "將你檔了下來。\n");

           say("我是高手說："HIC"這是凌雲禁地快給我滾\n"NOR);
        return 1;
}
