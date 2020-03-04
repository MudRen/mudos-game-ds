#include <npc.h>

inherit F_SOLDIER;

void create()
{
    set_name("守衛統領", "duli police captain", "police","captain");
    set_race("human");
    set_skill("twohanded sword", 60);
    set_skill("blunt", 100);
    set_skill("sword", 100);
    set_skill("parry", 90);
    set_skill("unarmed", 80);
    set_skill("dodge", 90);
    set_skill("blade", 70);
    set_skill("berserk", 150);
    set("title","杜尼森林");
    set("long",@long
    這是一個負責管理進入杜尼港北邊森林入口的守衛統領，由於近年來
傳聞森林裡有吃人的妖魔鬼怪，使得人心惶惶，所以當局警政機關特派幾
孔武有力的警察擔任保護安全的責任。而這個統領就算是一隊守衛小組的
組長，負責發號施令。
long
);
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
        (: command, "berserk" :)
    }));
    setup();
    set_level(20);
    carry_object("/d/obj/longpike")->wield("twohanded pike");
    carry_object("/d/obj/armor")->wear();
}
void init()
{
    ::init();
    add_action("intercept", "go");
    add_action("intercept2", "north");
}
int accept_fight(object ob)
{
        return 1;
}

int intercept(string arg)
{
    if( (arg!= "north") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "將你攔了下來。\n");
    do_chat((: command, "say 迷霧森林裡魔獸出沒，閒雜人等不要隨意進去。":) );
    return 1;
}
int intercept2()
{
    if(!this_player()->visible(this_object()) ) return 0;
    write( name() + "將你攔了下來。\n");
    do_chat((: command, "say 迷霧森林裡魔獸出沒，閒雜人等不要隨意進去。":) );
    return 1;
}

