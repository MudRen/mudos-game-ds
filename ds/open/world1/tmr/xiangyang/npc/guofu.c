// guofu.c
inherit NPC;

void create()
{
    set_name("郭芙", ({"guo fu", "guo", "fu"}));
    set("gender", "女性");
    set("age", 19);
    set("long", 
"她是郭靖黃蓉的大女兒，東邪黃藥師的大外孫女，
她雙眉彎彎，小小的鼻子微微上翹，臉如白玉，顏
若朝華。她服飾打扮也不如何華貴，只項頸中掛了
一串明珠，發出淡淡光暈，映得她更是粉裝玉琢一般。\n");
    set("attitude", "peaceful");
       
    set("per", 30);
    set("str", 18);
    set("int", 30);
    set("con", 21);
    set("dex", 26);

    set("qi", 1000);
    set("max_qi", 1000);
    set("jing", 500);
    set("max_jing", 500);
    set("neili", 500);
    set("max_neili", 500);
    set("jiali", 0);
       
    set("combat_exp", 50000);
    set("score", 0);
       
/*
    set_skill("force", 60);
    set_skill("bibo-shengong", 60);
    set_skill("unarmed", 60);
    set_skill("luoying-zhang", 60);
    set_skill("dodge", 80);
    set_skill("anying-fuxiang", 60);
    set_skill("parry", 60);
    set_skill("sword", 60);
    set_skill("luoying-shenjian", 60);
    set_skill("qimen-wuxing", 60);
       
    map_skill("force"  , "bibo-shengong");
    map_skill("unarmed", "luoying-zhang");
    map_skill("dodge"  , "anying-fuxiang");
    map_skill("sword"  , "luoying-shenjian") ;
*/
       
    setup();
//      carry_object("/kungfu/class/taohua/obj/ruanwei")->wear();
//      carry_object("/kungfu/class/taohua/obj/shudai")->wear();


}

